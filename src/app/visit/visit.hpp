#pragma once

#include <memory>
#include <set>
#include <string>

class Doctor;

class Visit
{
    Doctor& doctor_;
    std::string visit_information_;

  public:
    explicit Visit(Doctor& doctor);
    Visit& operator=(const Visit& other);
    // static void removeFromExtent(Visit* visit);
    // void setDoctorAssociation(const std::shared_ptr<Doctor>& doctor);
    Doctor getDoctor() const;
    void setVisitInformation(const std::string& visit_information);
    std::string getVisitInformation() const;
};
