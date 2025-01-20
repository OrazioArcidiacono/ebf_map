#include "ProtoManager.h"
#include <QFile>
#include <QByteArray>
#include <QString>
#include <QDebug>
#include "src/proto/ProtoLib.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>

ProtoManager::ProtoManager(QObject *parent) : QObject(parent) {
  }

QString ProtoManager::createServiceMessage(ServiceStatusType statusType) {
    fc::FCMessage fcMessage;

    // Utilizza CreateMessage per aggiungere un messaggio SERVICE_ANNOUNCE
    ProtoLib::ReturnStatus_t res = ProtoMessages::CreateMessage<
        ProtoLib::FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
        fcMessage,
        static_cast<fc::ServiceAnnounce_StatusEnum>(statusType) // Conversione esplicita
        );

    if (res != ProtoLib::ReturnStatus_t::RETURN_STATUS_OK) {
        qWarning() <<Q_FUNC_INFO<< "Errore nella creazione del messaggio.";
        return "";
    }

    return serializeFCMessage(fcMessage);
}

ProtoManager::~ProtoManager() {
    // Termina tutti i thread in modo sicuro
    for (auto thread : m_threads.values()) {
        thread->requestInterruption();
        thread->quit();
        thread->wait();
        delete thread;
    }
    m_threads.clear();
    qDebug() << "Tutti i thread terminati correttamente.";
}

QString ProtoManager::readMessage(const QString &serializedMessage) {
    fc::FCMessage fcMessage;

    // Decodifica Base64
    QByteArray decodedMessage = QByteArray::fromBase64(serializedMessage.toUtf8());

    // Deserializza il messaggio completo
    if (!fcMessage.ParseFromString(decodedMessage.toStdString())) {
        return "Errore nella deserializzazione del messaggio.";
    }

    // Controlla se ci sono messaggi disponibili
    if (fcMessage.messages_size() == 0) {
        return "Nessun messaggio trovato nel campo 'messages'.";
    }

    QString result;

    // Itera attraverso i messaggi e verifica il contenuto
    for (int i = 0; i < fcMessage.messages_size(); ++i) {
        const auto &anyMessage = fcMessage.messages(i);

        if (anyMessage.has_serviceannounce()) {
            // Crea un oggetto FCMessage temporaneo
            fc::FCMessage tempMessage;
            auto* newMessage = tempMessage.add_messages()->mutable_serviceannounce();
            *newMessage = anyMessage.serviceannounce();

            // Legge il messaggio utilizzando ProtoMessages::ReadMessage
            ProtoLib::Datatypes::ServiceStatusType status;
            ProtoLib::ReturnStatus_t res = ProtoMessages::ReadMessage<ProtoLib::FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
                tempMessage, status);

            if (res != ProtoLib::ReturnStatus_t::RETURN_STATUS_OK) {
                result += QString("Errore nella lettura del messaggio ServiceAnnounce al messaggio %1.\n").arg(i);
                continue;
            }

            QString serviceStatus = (status == fc::ServiceAnnounce_StatusEnum_ONLINE)
                                        ? "ONLINE"
                                        : "OFFLINE";
            result += QString("ServiceAnnounce trovato nel messaggio %1: Stato = %2\n").arg(i).arg(serviceStatus);
        }

        // Gestione RouteAnnounce
        else if (anyMessage.has_routeannounce()) {
            const auto &routeAnnounce = anyMessage.routeannounce();
            result += QString("RouteAnnounce trovato nel messaggio %1:\n").arg(i);
            result += QString("  Route ID: %1\n").arg(QString::fromStdString(routeAnnounce.route_id()));
            result += QString("  Descrizione: %1\n").arg(QString::fromStdString(routeAnnounce.description()));
            result += QString("  Tipo: %1\n").arg(routeAnnounce.type() == fc::ROUTE ? "ROUTE" : "POSITION");

            // Itera sui punti
            for (int j = 0; j < routeAnnounce.points_size(); ++j) {
                const auto &point = routeAnnounce.points(j);
                result += QString("  Punto %1: (%2, %3), Velocità: %4, Timestamp: %5, Nome: %6\n")
                              .arg(j + 1)
                              .arg(point.latitude())
                              .arg(point.longitude())
                              .arg(point.speed())
                              .arg(point.timestamp())
                              .arg(QString::fromStdString(point.name()));
            }
        } else {
            result += QString("Messaggio %1 non è di tipo ServiceAnnounce.\n").arg(i);
        }
    }

    return result;
}

QString ProtoManager::createMultipleMessages() {
    fc::FCMessage fcMessage;

    // Aggiunge un primo messaggio ONLINE
    ProtoMessages::CreateMessage<ProtoLib::FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
        fcMessage, fc::ServiceAnnounce_StatusEnum_ONLINE);

    // Aggiunge un secondo messaggio OFFLINE
    ProtoMessages::CreateMessage<ProtoLib::FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
        fcMessage, fc::ServiceAnnounce_StatusEnum_OFFLINE);

    return serializeFCMessage(fcMessage);
}

QString ProtoManager::createRouteAnnounceMessage(RouteType routeType, const QString &jsonString) {
    fc::FCMessage fcMessage;
    ProtoLib::ReturnStatus_t res;

    res = ProtoMessages::CreateMessage<ProtoLib::FCMessageType_t::MSGT_ROUTE_ANNOUNCE>(fcMessage,jsonString,
                                                                                       static_cast<fc::RouteTypeEnum>(routeType));

    if (res != ProtoLib::ReturnStatus_t::RETURN_STATUS_OK) {
        qWarning() <<Q_FUNC_INFO<< "Errore nella creazione del messaggio.";
        return "";
    }

    return serializeFCMessage(fcMessage);
}

QString ProtoManager::serializeFCMessage(const fc::FCMessage &message) {
    std::string serializedMessage;

    // Serializza il messaggio
    if (!message.SerializeToString(&serializedMessage)) {
        qWarning() <<Q_FUNC_INFO<< "Errore nella serializzazione.";
        return "";
    }

    // Converte in base64
    QByteArray base64Message = QByteArray::fromStdString(serializedMessage).toBase64();
    emit messageGenerated(QString(base64Message));
    return QString(base64Message);
}

void ProtoManager::startThreadsForVehicles(int count, const QString &serializedMessage) {
    fc::FCMessage fcMessage;
    QByteArray byteArray = QByteArray::fromBase64(serializedMessage.toUtf8());
    if (!fcMessage.ParseFromString(byteArray.toStdString())) {
        qWarning() << "Errore nella deserializzazione del messaggio.";
        return;
    }

    if (fcMessage.messages_size() > 0 && fcMessage.messages(0).has_routeannounce()) {
        const auto &routeAnnounce = fcMessage.messages(0).routeannounce();

        QVector<fc::RoutePoint> routePoints;
        for (int i = 0; i < routeAnnounce.points_size(); ++i) {
            routePoints.append(routeAnnounce.points(i));
        }

        if (routePoints.isEmpty()) {
            qWarning() << "Nessun punto nella rotta.";
            return;
        }

        for (int i = 1; i <= count; ++i) {
            if (m_threads.contains(i)) {
                qWarning() << "Il thread per il veicolo" << i << "è già in esecuzione.";
                continue;
            }

            auto *thread = new RouteFollower(this);
            connect(thread, &RouteFollower::updateVehiclePosition, this, &ProtoManager::updateVehiclePosition);

            thread->setRoute(i, routePoints, i % 2 == 0);
            m_threads[i] = thread;

            QGeoCoordinate initialPosition(routePoints.first().latitude(), routePoints.first().longitude());
            emit addVehicle(i, initialPosition);

            qDebug() << "Thread avviato per veicolo ID:" << i;
            thread->start();
        }
    } else {
        qWarning() << "Nessun RouteAnnounce trovato nel messaggio.";
    }
}

void ProtoManager::testAddVehicle() {
    QGeoCoordinate startPosition(45.0703, 7.6869);  // Torino
    emit addVehicle(1, startPosition);
    qDebug() << "C++ - Veicolo aggiunto con ID 1 alla posizione" << startPosition;
    QTimer::singleShot(5000, this, &ProtoManager::testUpdateVehicle);
}

void ProtoManager::testUpdateVehicle() {
    QGeoCoordinate newPosition(45.0710, 7.6875);  // Nuova posizione
    emit updateVehiclePosition(1, newPosition);
    qDebug() << "C++ - Posizione aggiornata per veicolo ID 1 a " << newPosition;
}
