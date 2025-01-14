#ifndef PROTOMANAGER_H
#define PROTOMANAGER_H

#include <QObject>
#include "src/proto/ProtoLib.h"
#include "gen_proto/FC_Control.pb.h"       // Include generato da Protocol Buffers

typedef ProtoLib::ReturnStatus_t      ProtoReturnStatusType;
typedef ProtoLib::FCMessageType_t     FCMessageType_t;
typedef ProtoMessages::FCMessageType  FCMessageType;
typedef ProtoDatatypes::ServiceStatusType ServiceStatusType;

class ProtoManager : public QObject {
    Q_OBJECT

public:
    explicit ProtoManager(QObject *parent = nullptr);

    // Crea un messaggio FCMessage con un ServiceAnnounce impostato su ONLINE
    Q_INVOKABLE QString createServiceOnlineMessage();

    // Legge un messaggio FCMessage serializzato
    Q_INVOKABLE QString readMessage(const QString &serializedMessage);

    // Crea messaggi multipli
    Q_INVOKABLE QString createMultipleMessages();

signals:
    // Segnale per notificare la creazione di un messaggio
    void messageGenerated(const QString &message);

private:
    QString serializeFCMessage(const fc::FCMessage &message);
};

#endif // PROTOMANAGER_H
