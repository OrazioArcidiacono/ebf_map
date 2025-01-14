# ------------------------------------------------------
# protobuf.pri
# ------------------------------------------------------

# Messaggio di debug
message("FC Protobuf is enabled")

# Specifica il percorso allo script shell
PROTO_SCRIPT = $$PWD/fc_generate_protos.sh

# Definisci un target personalizzato per generare i file Protobuf
GENERATE_PROTO_TARGET = generate_protos

# Aggiungi il target personalizzato a QMAKE_EXTRA_TARGETS
QMAKE_EXTRA_TARGETS += GENERATE_PROTO

# Definisci le dipendenze del target
GENERATE_PROTO.commands = bash $$PROTO_SCRIPT
GENERATE_PROTO.CONFIG += no_link
GENERATE_PROTO.target = $$OUT_PWD/gen_proto_done

# Imposta le dipendenze per assicurarsi che il target venga eseguito prima della build
PRE_TARGETDEPS += $$OUT_PWD/gen_proto_done

# Aggiungi i file generati a SOURCES e HEADERS
PROTO_FILES = $$files($$PROTO_DIR/*.proto)
for(protoFile, PROTO_FILES) {
    baseName = $$basename(protoFile)
    generatedCpp = gen_proto/$$baseName.pb.cc
    generatedH   = gen_proto/$$baseName.pb.h

    SOURCES += $$generatedCpp
    HEADERS += $$generatedH
}

# Link e include di Protobuf
LIBS += -L/usr/local/lib -lprotobuf
INCLUDEPATH += gen_proto
INCLUDEPATH += /usr/local/include
