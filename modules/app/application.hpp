#pragma once

#include "PersonalData.hpp"
#include "clinic/staff/receptionists/ReceptionistFactory.hpp"
#include "enumerations/sex/Sex.hpp"

#include <QObject>
#include <QUrl>
#include <qqml.h>

class Application : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString data READ GetData NOTIFY dataChanged)
  public:
    explicit Application(QObject* parent = nullptr);
    Q_INVOKABLE QString GetData() const
    {
        common::PersonalData peda{common::Name{"Anetka", "", ""}, common::Address{}, common::Pesel{"80062378532"},
                                  common::PhoneNumber{}};
        auto recept = clinic::staff::receptionist::createReceptionist(peda);
        return QString::fromStdString(recept->GetPersonalData().getName().first_name_);
    }
  signals:
    void dataChanged();
};