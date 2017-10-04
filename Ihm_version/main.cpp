

#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "dataparser.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    DataParser dataParser;
    QQmlContext* context = engine.rootContext();
    context ->setContextProperty("DataParser", &dataParser);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}
