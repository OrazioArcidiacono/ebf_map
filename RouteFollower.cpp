#include "RouteFollower.h"
#include <QDebug>
#include <QThread>

RouteFollower::RouteFollower(QObject *parent) : QThread(parent), m_stop(false) {}

RouteFollower::~RouteFollower() {
    m_stop = true;
    if (isRunning()) {
        quit();
        wait();
    }
}

void RouteFollower::setRoute(int vehicleId, const QVector<fc::RoutePoint> &routePoints, bool reverse) {
    m_vehicleId = vehicleId;
    m_routePoints = routePoints;
    m_reverse = reverse;
    m_stop = false;
}

void RouteFollower::run() {
    if (m_routePoints.isEmpty()) {
        qDebug() << "Thread per veicolo" << m_vehicleId << ": Nessun punto nella rotta.";
        return;
    }

    int start = m_reverse ? m_routePoints.size() - 1 : 0;
    int end = m_reverse ? -1 : m_routePoints.size();
    int step = m_reverse ? -1 : 1;

    for (int i = start; i != end; i += step) {
        if (m_stop) {
            break;
        }

        const auto &point = m_routePoints[i];
        QGeoCoordinate position(point.latitude(), point.longitude());

        // Log per debug
        qDebug() << "Thread per veicolo" << m_vehicleId << ": Punto " << i
                 << "Latitudine =" << point.latitude()
                 << "Longitudine =" << point.longitude()
                 << "Timestamp =" << point.timestamp()
                 << "Velocità =" << point.speed();

                                    // Emissione del segnale per aggiornare la posizione del veicolo
                                    emit updateVehiclePosition(m_vehicleId, position);

        // Attendi 100ms prima di passare al prossimo punto
        QThread::msleep(100);
    }

    qDebug() << "Thread per veicolo" << m_vehicleId << ": completato.";
}
