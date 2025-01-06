#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    app.setAttribute(Qt::AA_DontUseNativeMenuBar);
    QQuickStyle::setStyle("Fusion");

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
