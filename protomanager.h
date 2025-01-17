#ifndef PROTOMANAGER_H
#define PROTOMANAGER_H

#include <QObject>
#include "gen_proto/FC_Control.pb.h"       // Include generato da Protocol Buffers


class ProtoManager : public QObject {
    Q_OBJECT
    Q_ENUMS(ServiceStatusType)
    Q_ENUMS(RouteType)

public:
    explicit ProtoManager(QObject *parent = nullptr);

    enum ServiceStatusType {
        SERVICE_STATUS_UNKNOWN = fc::ServiceAnnounce_StatusEnum_UNKNOWN,
        SERVICE_STATUS_ONLINE = fc::ServiceAnnounce_StatusEnum_ONLINE,
        SERVICE_STATUS_OFFLINE = fc::ServiceAnnounce_StatusEnum_OFFLINE
    };

    enum RouteType {
        ROUTE_JSON = fc::RouteTypeEnum::ROUTE,
        POSITION = fc::RouteTypeEnum::POSITION
    };

    // Crea un messaggio FCMessage con un ServiceAnnounce
    Q_INVOKABLE QString createServiceMessage(ServiceStatusType statusType);

    // Legge un messaggio FCMessage serializzato
    Q_INVOKABLE QString readMessage(const QString &serializedMessage);

    // Crea messaggi multipli
    Q_INVOKABLE QString createMultipleMessages();

    // Metodo per creare un messaggio RouteAnnounce
    Q_INVOKABLE QString createRouteAnnounceMessage(RouteType routeType, const QString &jsonString);

signals:
    // Segnale per notificare la creazione di un messaggio
    void messageGenerated(const QString &message);

private:
    QString serializeFCMessage(const fc::FCMessage &message);
    fc::RouteAnnounce route_; // Oggetto RouteAnnounce per memorizzare la rotta

};

#endif // PROTOMANAGER_H
