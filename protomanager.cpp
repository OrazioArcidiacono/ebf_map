#include "ProtoManager.h"
#include <QFile>
#include <QByteArray>
#include <QString>
#include <QDebug>

ProtoManager::ProtoManager(QObject *parent) : QObject(parent) {}

QString ProtoManager::createServiceOnlineMessage() {
    fc::FCMessage fcMessage;

    // Utilizza CreateMessage per aggiungere un messaggio SERVICE_ANNOUNCE
    ProtoReturnStatusType res = ProtoMessages::CreateMessage<FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
        fcMessage, ServiceStatusType::ServiceAnnounce_StatusEnum_ONLINE);

    if (res != ProtoReturnStatusType::RETURN_STATUS_OK) {
        qWarning() << "Errore nella creazione del messaggio.";
        return "";
    }

    return serializeFCMessage(fcMessage);
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
            ServiceStatusType status;
            ProtoReturnStatusType res = ProtoMessages::ReadMessage<FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
                tempMessage, status);

            if (res != ProtoReturnStatusType::RETURN_STATUS_OK) {
                result += QString("Errore nella lettura del messaggio ServiceAnnounce al messaggio %1.\n").arg(i);
                continue;
            }

            QString serviceStatus = (status == ServiceStatusType::ServiceAnnounce_StatusEnum_ONLINE)
                                        ? "ONLINE"
                                        : "OFFLINE";
            result += QString("ServiceAnnounce trovato nel messaggio %1: Stato = %2\n").arg(i).arg(serviceStatus);
        } else {
            result += QString("Messaggio %1 non è di tipo ServiceAnnounce.\n").arg(i);
        }
    }

    return result;
}


QString ProtoManager::createMultipleMessages() {
    fc::FCMessage fcMessage;

    // Aggiunge un primo messaggio ONLINE
    ProtoMessages::CreateMessage<FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
        fcMessage, ServiceStatusType::ServiceAnnounce_StatusEnum_ONLINE);

    // Aggiunge un secondo messaggio OFFLINE
    ProtoMessages::CreateMessage<FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
        fcMessage, ServiceStatusType::ServiceAnnounce_StatusEnum_OFFLINE);

    return serializeFCMessage(fcMessage);
}

QString ProtoManager::serializeFCMessage(const fc::FCMessage &message) {
    std::string serializedMessage;

    // Serializza il messaggio
    if (!message.SerializeToString(&serializedMessage)) {
        qWarning() << "Errore nella serializzazione.";
        return "";
    }

    // Converte in base64
    QByteArray base64Message = QByteArray::fromStdString(serializedMessage).toBase64();
    emit messageGenerated(QString(base64Message));
    return QString(base64Message);
}
