#ifndef PROTOMANAGER_H
#define PROTOMANAGER_H

#include <QObject>
#include "gen_proto/FC_Control.pb.h"       // Include generato da Protocol Buffers
#include <QVector>
#include <QGeoCoordinate>
#include "RouteFollower.h"


class ProtoManager : public QObject {
    Q_OBJECT
    Q_ENUMS(ServiceStatusType)
    Q_ENUMS(RouteType)

public:
    explicit ProtoManager(QObject *parent = nullptr);
    ~ProtoManager();
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

    /**
     * Avvia un thread per un veicolo specifico.
     * @param vehicleId L'ID del veicolo.
     * @param serializedMessage Il messaggio serializzato che contiene i dati della rotta.
     */
    Q_INVOKABLE void startThreadsForVehicles(int vehicleId, const QString &serializedMessage);

    Q_INVOKABLE void testAddVehicle();

public slots:
    void testUpdateVehicle();

signals:
    // Segnale per notificare la creazione di un messaggio
    void messageGenerated(const QString &message);
    /**
     * Segnale emesso quando un nuovo veicolo deve essere aggiunto in QML.
     * @param vehicleId L'ID del veicolo.
     * @param initialPosition La posizione iniziale del veicolo.
     */
    void addVehicle(int vehicleId, QGeoCoordinate initialPosition);
    /**
     * Segnale emesso per aggiornare la posizione di un veicolo sulla mappa.
     * @param vehicleId L'ID del veicolo.
     * @param position La nuova posizione del veicolo.
     */
    void updateVehiclePosition(int vehicleId, const QGeoCoordinate &position);


private:
    QString serializeFCMessage(const fc::FCMessage &message);
    fc::RouteAnnounce route_;                               // Oggetto RouteAnnounce per memorizzare la rotta
    QMap<int, RouteFollower*> m_threads; ///< Mappa per gestire i thread attivi dei veicoli.
};

#endif // PROTOMANAGER_H
