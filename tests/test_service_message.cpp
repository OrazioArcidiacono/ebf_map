#include <gtest/gtest.h>
#include "src/proto/ProtoLib.h"

// Alias utili
typedef ProtoLib::ReturnStatus_t      ProtoReturnStatusType;
typedef ProtoLib::FCMessageType_t     FCMessageType_t;
typedef ProtoMessages::FCMessageType  FCMessageType;
typedef ProtoDatatypes::ServiceStatusType ServiceStatusType;

class ServiceMessageTest : public ::testing::Test {
protected:
    FCMessageType message;
    ServiceStatusType status;

    void SetUp() override {
        // Questo metodo è chiamato prima di ogni test
        message.Clear();
    }

    void TearDown() override {
        // Questo metodo è chiamato dopo ogni test
    }
};

// Test per la creazione del messaggio
TEST_F(ServiceMessageTest, CreateServiceMessage) {
    ProtoReturnStatusType res = ProtoMessages::CreateMessage<FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
        message, ServiceStatusType::ServiceAnnounce_StatusEnum_ONLINE
        );

    EXPECT_EQ(res, ProtoReturnStatusType::RETURN_STATUS_OK) << "Creazione del messaggio fallita";
    // Verifica il contenuto del messaggio
    EXPECT_EQ(message.timestamp(), 0);      // Il timestamp non è impostato, valore predefinito
    EXPECT_EQ(message.messages_size(), 1);  // Contiene un solo messaggio

}

// Test per la lettura del messaggio
TEST_F(ServiceMessageTest, ReadServiceMessage) {
    // Creazione del messaggio
    ProtoReturnStatusType res = ProtoMessages::CreateMessage<FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
        message, ServiceStatusType::ServiceAnnounce_StatusEnum_ONLINE
        );
    ASSERT_EQ(res, ProtoReturnStatusType::RETURN_STATUS_OK) << "Creazione del messaggio fallita";

    // Lettura del messaggio
    res = ProtoMessages::ReadMessage<FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(message, status);
    EXPECT_EQ(res, ProtoReturnStatusType::RETURN_STATUS_OK) << "Lettura del messaggio fallita";
    EXPECT_EQ(status, ServiceStatusType::ServiceAnnounce_StatusEnum_ONLINE) << "Lo stato del messaggio non corrisponde";
}

TEST_F(ServiceMessageTest,MultipleMessageInFCMessage){
    // Aggiungi il primo messaggio
    ProtoReturnStatusType res1= ProtoMessages::CreateMessage<FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
        message,ServiceStatusType::ServiceAnnounce_StatusEnum_ONLINE);
    ASSERT_EQ(res1, ProtoReturnStatusType::RETURN_STATUS_OK);

    // Aggiungi un secondo messaggio
    ProtoReturnStatusType res2 = ProtoMessages::CreateMessage<FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(
        message, ServiceStatusType::ServiceAnnounce_StatusEnum_OFFLINE
        );
    ASSERT_EQ(res2, ProtoReturnStatusType::RETURN_STATUS_OK);

    // Verifica il numero totale di messaggi
    EXPECT_EQ(message.messages_size(), 2);

    // Leggi i messaggi uno alla volta
    ServiceStatusType service_status;

    // Crea un oggetto FCMessage vuoto
    FCMessageType fc_message;
    if (message.messages(0).has_serviceannounce()) {
        // Ottieni il messaggio `ServiceAnnounce` e aggiungilo a `FCMessage`
        auto* new_service_announce = fc_message.add_messages()->mutable_serviceannounce();
        *new_service_announce = message.messages(0).serviceannounce();
    }

    res1 = ProtoMessages::ReadMessage<FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(fc_message, service_status);
    ASSERT_EQ(res1, ProtoReturnStatusType::RETURN_STATUS_OK);
    EXPECT_EQ(service_status, ServiceStatusType::ServiceAnnounce_StatusEnum_OFFLINE);

    fc_message.clear_messages();

    if (message.messages(1).has_serviceannounce()) {
        // Ottieni il messaggio `ServiceAnnounce` e aggiungilo a `FCMessage`
        auto* new_service_announce = fc_message.add_messages()->mutable_serviceannounce();
        *new_service_announce = message.messages(1).serviceannounce();
    }

    res2 = ProtoMessages::ReadMessage<FCMessageType_t::MSGT_SERVICE_ANNOUNCE>(fc_message, service_status);
    ASSERT_EQ(res2, ProtoReturnStatusType::RETURN_STATUS_OK);
    EXPECT_EQ(service_status, ServiceStatusType::ServiceAnnounce_StatusEnum_OFFLINE);

}
