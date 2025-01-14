#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "ProtoManager.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    app.setAttribute(Qt::AA_DontUseNativeMenuBar);
    QQuickStyle::setStyle("Fusion");

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    // Registra ProtoManager per l'uso in QML
    qmlRegisterType<ProtoManager>("fc.proto", 1, 0, "ProtoManager");

    engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
