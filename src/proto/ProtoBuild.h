#pragma once

#include "ProtoDefs.h"

namespace ProtoLib {
  namespace Messages {
    namespace Private_Messages {


// local utility types redefinition
typedef ::ProtoLib::Datatypes::ServiceStatusType     ServiceStatusType;

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

// specialization for NO message
template <>
struct MessageBuilder<MSGT_UNKNOWN> {
  static ReturnStatus_t build(FCMessageType& p_message, ...) {
    return RETURN_STATUS_OK;
  }
};

} // Private_Messages
} // messages
} // ProtoLib


