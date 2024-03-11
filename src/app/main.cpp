#include <QApplication>
#include "visit/visit.hpp"

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // std::shared_ptr<Doctor> doc{std::make_shared<Doctor>()}
    // Visit visit.createVisit(doc);
    // doc->getVisits().getClients().getName();
    // visit.addClient(client);
    return a.exec();
}
