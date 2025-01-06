TEMPLATE = app

# Aggiungi i moduli richiesti
QT += quick quickcontrols2 positioning network

# Specifica il target e il nome del progetto
TARGET = EBF_Map
CONFIG += qmltypes
QML_IMPORT_NAME = EBF_Map
QML_IMPORT_MAJOR_VERSION = 1
QML_IMPORT_PATH = $$PWD

# Specifica le directory delle risorse
SOURCES += \
    main.cpp

RESOURCES += \
    EBFMap.qrc

# Aggiungi i file QML della struttura modulare
DISTFILES += \
    Main.qml \
    components/MapView.qml \
    components/MenuBarView.qml \
    components/SearchBarView.qml\
    components/SimulationManager.qml \
    controllers/AppController.qml

# Specifica le impostazioni di build
CONFIG += c++17 qml_debug

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
