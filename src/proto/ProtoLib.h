#pragma once


// headers for FC-Protofiles
#include "ProtoDefs.h"

// headers for proto messages handling support
#include "ProtoBuild.h"
#include "ProtoRead.h"


namespace ProtoLib {
  namespace Messages {


// gets the message type from the input message
// returns the type according to predefined enumeration type
FCMessageType_t GetMessageType(const FCMessageType& p_message);

// checks whether the type of input message equals that
// given as input through static templated parameter
template <FCMessageType_t t_msg_type>
bool IsMessageType(const FCMessageType& p_message) {
  return ( GetMessageType(p_message) == t_msg_type );
}

// creates message according to non-template input parameter
// and actual given parameters
template <FCMessageType_t t_msg_type, class...InputTypes>
ReturnStatus_t CreateMessage(FCMessageType& p_message, InputTypes&&...p_params) {
  typedef Private_Messages::MessageBuilder<t_msg_type> MessageBuilderType;
  return ( MessageBuilderType::build(p_message, std::forward<InputTypes>(p_params)...) );
}

// reads message according to non-template input parameter
// and actual given parameters
template <FCMessageType_t t_msg_type, class...InputTypes>
ReturnStatus_t ReadMessage(const FCMessageType& p_message, InputTypes&&...p_params) {
  typedef Private_Messages::MessageReader<t_msg_type> MessageReaderType;
  return ( MessageReaderType::read(p_message, std::forward<InputTypes>(p_params)...) );
}


} // Messages
} // ProtoLib



// namespace aliasing
namespace ProtoMessages  = ProtoLib::Messages;
namespace ProtoDatatypes = ProtoLib::Datatypes;



