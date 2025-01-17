#pragma once

#include "ProtoDefs.h"
#include "QtCore/qtpreprocessorsupport.h"
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
namespace ProtoLib {
  namespace Messages {
    namespace Private_Messages {


// local utility types redefinition
typedef ::ProtoLib::Datatypes::ServiceStatusType     ServiceStatusType;
typedef ::ProtoLib::Datatypes::RouteType             RouteType;

// definition of helper for assisted message building
template <FCMessageType_t t_msg_type>
struct MessageBuilder;

// specialization for ServiceAnnounce message
template <>
struct MessageBuilder<MSGT_SERVICE_ANNOUNCE> {
  static ReturnStatus_t build(FCMessageType& p_message, const ServiceStatusType p_service_status) {
    ReturnStatus_t l_res = ReturnStatus_t::RETURN_STATUS_OK;

    FCAnyType* l_fcAny = p_message.add_messages();
      ServiceAnnounceType* l_service_announce = l_fcAny->mutable_serviceannounce();

    // service status
    l_service_announce->set_status(p_service_status);

    return l_res;
  }
};

// specialization for RouteAnnounce message
template <>
struct MessageBuilder<MSGT_ROUTE_ANNOUNCE> {
  static ReturnStatus_t build(FCMessageType& p_message, const QString &jsonString) {

    // Decodifica il JSON
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
    if (jsonDoc.isNull() || !jsonDoc.isObject()) {
        return ReturnStatus_t::RETURN_STATUS_ERROR;
    }
    QJsonObject jsonObject = jsonDoc.object();

    // Aggiungi un messaggio RouteAnnounce a FCMessage
    auto* l_fcAny = p_message.add_messages();
    auto* l_routeAnnounce = l_fcAny->mutable_routeannounce();

    // Popola il messaggio RouteAnnounce
    l_routeAnnounce->set_route_id(jsonObject["route_id"].toString().toStdString());
    l_routeAnnounce->set_type(static_cast<fc::RouteTypeEnum>(jsonObject["type"].toInt()));
    if (jsonObject.contains("description")) {
        l_routeAnnounce->set_description(jsonObject["description"].toString().toStdString());
    }

    // Itera sui punti della rotta
    if (jsonObject.contains("points")) {
        QJsonArray pointsArray = jsonObject["points"].toArray();
        for (const QJsonValue& pointValue : pointsArray) {
            QJsonObject pointObject = pointValue.toObject();

            auto* point = l_routeAnnounce->add_points();
            point->set_latitude(pointObject["latitude"].toDouble());
            point->set_longitude(pointObject["longitude"].toDouble());
            point->set_timestamp(pointObject["timestamp"].toVariant().toLongLong());
            if (pointObject.contains("speed")) {
                point->set_speed(pointObject["speed"].toDouble());
            }
            if (pointObject.contains("name")) {
                point->set_name(pointObject["name"].toString().toStdString());
            }
        }
    }
      return ReturnStatus_t::RETURN_STATUS_OK;
  }
};

// specialization for NO message
template <>
struct MessageBuilder<MSGT_UNKNOWN> {
  static ReturnStatus_t build(FCMessageType& p_message, ...) {
    Q_UNUSED(p_message); // Contrassegna il parametro come inutilizzato
    return RETURN_STATUS_OK;
  }
};

} // Private_Messages
} // messages
} // ProtoLib


