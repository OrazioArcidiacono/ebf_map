#include "ProtoLib.h"


namespace ProtoLib {

namespace Messages {


FCMessageType_t GetMessageType(const FCMessageType& p_message) {

    FCMessageType_t l_res = FCMessageType_t::MSGT_UNKNOWN;

    // message type retrievial
    FCAnyType l_fcAny = p_message.messages(0);

    // FC message: ServiceAnnounce
    if(l_fcAny.has_serviceannounce()) {
        l_res = FCMessageType_t::MSGT_SERVICE_ANNOUNCE;
    }

    return l_res;
}


} // Messages
} // ProtoLib


