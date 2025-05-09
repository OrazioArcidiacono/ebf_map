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
        if (QThread::currentThread()->isInterruptionRequested()) {
            qDebug() << "Thread per veicolo" << m_vehicleId << "interrotto.";
            break;
        }

        const auto &point = m_routePoints[i];
        QGeoCoordinate position(point.latitude(), point.longitude());

        qDebug() << "Thread per veicolo" << m_vehicleId
                 << ": Punto " << i
                 << "Latitudine =" << point.latitude()
                 << "Longitudine =" << point.longitude()
                 << "Timestamp =" << point.timestamp()
                 << "Velocità =" << point.speed();

        emit updateVehiclePosition(m_vehicleId, position);

        QThread::msleep(1000);  // Riduci a 500ms per osservare meglio il movimento
    }

    qDebug() << "Thread per veicolo" << m_vehicleId << ": completato.";
}
