#ifndef TEST_SERVICE_MESSAGE_H
#define TEST_SERVICE_MESSAGE_H

#include "src/proto/ProtoDefs.h"
using ProtoLib::Messages::FCMessageType;

// Una funzione helper per creare un messaggio di test
FCMessageType createTestMessage();

// Una funzione helper per leggere un messaggio da un input simulato
bool verifyReadMessage(const FCMessageType& message);

#endif // TEST_SERVICE_MESSAGE_H
