#ifndef PROTOMANAGER_H
#define PROTOMANAGER_H

#include <QObject>
#include "gen_proto/FC_Control.pb.h"       // Include generato da Protocol Buffers

class ProtoManager : public QObject {
    Q_OBJECT
    Q_ENUMS(ServiceStatusType)

public:
    explicit ProtoManager(QObject *parent = nullptr);

    enum ServiceStatusType {
        SERVICE_STATUS_UNKNOWN = fc::ServiceAnnounce_StatusEnum_UNKNOWN,
        SERVICE_STATUS_ONLINE = fc::ServiceAnnounce_StatusEnum_ONLINE,
        SERVICE_STATUS_OFFLINE = fc::ServiceAnnounce_StatusEnum_OFFLINE
    };

    // Crea un messaggio FCMessage con un ServiceAnnounce impostato su ONLINE
    Q_INVOKABLE QString createServiceMessage(fc::ServiceAnnounce::StatusEnum statusType);

    // Legge un messaggio FCMessage serializzato
    Q_INVOKABLE QString readMessage(const QString &serializedMessage);

    // Crea messaggi multipli
    Q_INVOKABLE QString createMultipleMessages();

    // Metodo per ricevere una rotta completa da QML
   // Q_INVOKABLE void setRoute(const QString &routeId, const QString &description, const QVariantList &points);

signals:
    // Segnale per notificare la creazione di un messaggio
    void messageGenerated(const QString &message);

private:
    QString serializeFCMessage(const fc::FCMessage &message);
    fc::RouteAnnounce route_; // Oggetto RouteAnnounce per memorizzare la rotta

};

#endif // PROTOMANAGER_H
