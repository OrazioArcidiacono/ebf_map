TEMPLATE = app

# Aggiungi i moduli richiesti
QT += quick quickcontrols2 positioning network

# Specifica il target e il nome del progetto
TARGET = FC_Map
CONFIG += qmltypes
QML_IMPORT_NAME = EBF_Map
QML_IMPORT_MAJOR_VERSION = 1
QML_IMPORT_PATH = $$PWD

# Specifica le directory delle risorse
SOURCES += \
    RouteFollower.cpp \
    gen_proto/*.pb.cc \
    ProtoManager.cpp \
    src/proto/ProtoLib.cpp
RESOURCES += \
    FCMap.qrc \
    fc_protoFile.qrc

# Aggiungi i file QML della struttura modulare
DISTFILES += \
    Main.qml \
    ProtoFile/FC_Control.proto \
    ProtoFile/FC_Service_Message.proto \
    components/MapView.qml \
    components/MenuBarView.qml \
    components/SearchBarView.qml\
    components/SimulationManager.qml \
    controllers/AppController.qml \
    fc_generate_protos.sh \
    fc_protobuf.pri \
    fc_tests.pri

# Specifica le impostazioni di build
CONFIG += c++17 qml_debug

DEFINES += FC_ENABLE_PROTOBUF
#DEFINES += FC_PROTO_ENABLE_TESTS

# Directory di output
DESTDIR = bin
MOC_DIR = build/moc
OBJECTS_DIR = build/obj
RCC_DIR = build/rcc

# Aggiungi eventuali definizioni necessarie
DEFINES += QT_DEPRECATED_WARNINGS

# Risoluzione dei percorsi relativi
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

# Abilita Protobuf solo se definito
contains(DEFINES, FC_ENABLE_PROTOBUF) {
    message("FC Protobuf is enabled.")
    include(fc_protobuf.pri)
} else {
    message("FC Protobuf is disabled.")
    INCLUDEPATH += gen_proto
    # Link e include di Protobuf
    LIBS += -L/usr/local/lib -lprotobuf
}

# Inclusione dei test solo se ENABLE_TESTS è attivo

contains(DEFINES, FC_PROTO_ENABLE_TESTS) {
    message("FC Protobuf testing is enabled.")
    include(fc_tests.pri)
} else {
    message("FC Protobuf testing is disabled..")
    SOURCES += main.cpp
}

INCLUDEPATH += /usr/local/include

 LIBS += \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_entry.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_flags.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_globals.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_initialize.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_internal_check_op.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_internal_conditions.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_internal_fnmatch.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_internal_format.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_internal_globals.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_internal_log_sink_set.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_internal_message.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_internal_nullguard.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_internal_proto.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_severity.dylib \
     /usr/local/Cellar/abseil/20240722.0/lib/libabsl_log_sink.dylib

HEADERS += \
    RouteFollower.h \
    gen_proto/*.pb.h \
    ProtoManager.h \
    src/proto/ProtoBuild.h \
    src/proto/ProtoDefs.h \
    src/proto/ProtoLib.h \
    src/proto/ProtoRead.h
