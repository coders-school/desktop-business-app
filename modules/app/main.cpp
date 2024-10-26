#include "application.hpp"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Application* application_ = new Application(&app);
    // qmlRegisterSingletonInstance("com.company.desktopbusinessapp", 1, 0, "Application", application_);
    qmlRegisterType<Application>("com.company.desktopbusinessapp", 1, 0, "Application");

    const QUrl url(u"qrc:/desktop-business-app/main.qml"_qs);
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}