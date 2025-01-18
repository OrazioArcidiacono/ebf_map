#ifndef ROUTEFOLLOWER_H
#define ROUTEFOLLOWER_H

#include <QThread>
#include <QVector>
#include <QObject>
#include <QGeoCoordinate>
#include "gen_proto/FC_Control.pb.h"

class RouteFollower : public QThread
{
    Q_OBJECT

public:
    explicit RouteFollower(QObject *parent = nullptr);
    ~RouteFollower();
    /**
     * Configura il thread con i dati della rotta.
     * @param vehicleId L'ID del veicolo associato.
     * @param routePoints I punti della rotta che il veicolo deve seguire.
     * @param reverse Se true, il veicolo percorre la rotta in ordine inverso.
     */
    void setRoute(int vehicleId, const QVector<fc::RoutePoint> &routePoints, bool reverse);

signals:
    /**
     * Segnale emesso per aggiornare la posizione del veicolo.
     * @param vehicleId L'ID del veicolo.
     * @param position La nuova posizione del veicolo.
     */
    void updateVehiclePosition(int vehicleId, const QGeoCoordinate &position);


protected:
    void run() override;

private:
    QVector<fc::RoutePoint> m_routePoints; ///< I punti della rotta.
    int m_vehicleId; ///< L'ID del veicolo associato.
    bool m_reverse; ///< Se true, il veicolo percorre la rotta in ordine inverso.
    bool m_stop; ///< Flag per fermare il thread in modo sicuro.
};

#endif // ROUTEFOLLOWER_H
