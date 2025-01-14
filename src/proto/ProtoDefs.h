#pragma once

// headers for FC-Protobuffers
#include "FC_Control.pb.h"
#include "FC_Service_Message.pb.h"


namespace ProtoLib {


namespace Messages {


// general messages
typedef ::fc::FCMessage             FCMessageType;              // :: global space
typedef ::fc::FCAny                 FCAnyType;

// service messages
typedef ::fc::ServiceAnnounce        ServiceAnnounceType;


} // Messages


namespace Datatypes {

// protobuffers enumerations
typedef ::fc::ServiceAnnounce_StatusEnum    ServiceStatusType;

} // Datatypes


// return type for the library
typedef enum : uint8_t {
    RETURN_STATUS_OK
    , RETURN_STATUS_ERROR
}ReturnStatus_t;


// message type enumeration
typedef enum : uint8_t {
    MSGT_SERVICE_ANNOUNCE
  , MSGT_UNKNOWN
}FCMessageType_t;

} // ProtoLib


