TEMPLATE = app

QT += location widgets network

SOURCES += \
    main.cpp

RESOURCES += \
    EBFMap.qrc

QQmlApplicationEngine {
    qmlProtectModule("Qt.Network", 1);
}
