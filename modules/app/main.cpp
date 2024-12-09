#include "connections/DoctorGraphicalInterface.hpp"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<DoctorGraphicalInterface>("DoctorApp", 1, 0, "DoctorModel");
    const QUrl url(u"qrc:/desktop-business-app/main.qml"_qs);
    engine.load(url);

    return app.exec();
}