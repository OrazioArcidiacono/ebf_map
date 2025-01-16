#pragma once

#include "ProtoDefs.h"
#include "QtCore/qtpreprocessorsupport.h"

namespace ProtoLib {
namespace Messages {
namespace Private_Messages {


// local utility types redefinition
typedef ::ProtoLib::Datatypes::ServiceStatusType     ServiceStatusType;


// definition of helper for assisted message building
template <FCMessageType_t t_msg_type>
struct MessageReader;

// specialization for ServiceAnnounce message
template <>
struct MessageReader<MSGT_SERVICE_ANNOUNCE> {
    static ReturnStatus_t read(const FCMessageType& p_message, ServiceStatusType& p_service_status) {
        ReturnStatus_t l_res = ReturnStatus_t::RETURN_STATUS_OK;

        FCAnyType l_fcAny = p_message.messages(0);

        // is message present?
        if( l_fcAny.has_serviceannounce() ) {
            ServiceAnnounceType* l_service_announce = l_fcAny.mutable_serviceannounce();
            p_service_status = l_service_announce->status();
        }
        else {
            l_res = RETURN_STATUS_ERROR;
        }

        return l_res;
    }
};

// specialization for NO message
template <>
struct MessageReader<MSGT_UNKNOWN> {
    static ReturnStatus_t read(const FCMessageType& p_message, ...) {
        Q_UNUSED(p_message); // Contrassegna il parametro come inutilizzato
        return RETURN_STATUS_OK;
    }
};

} // Private_Messages
} // Messages
} // ProtoLib


