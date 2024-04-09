#pragma once

#include "treatment.hpp"
#include <memory>
#include <set>
#include <string>
#include <vector>

class Doctor;
class Patient;

class Visit : public std::enable_shared_from_this<Visit>
{
    std::shared_ptr<Doctor> doctor_;
    std::shared_ptr<Patient> patient_;
    std::vector<Treatment> treatments_;
    std::string visit_information_;

    Visit(const std::shared_ptr<Doctor>& doctor, const std::vector<Treatment>& treatments = {});

  public:
    std::shared_ptr<Doctor> getDoctor() const;
    std::shared_ptr<Patient> getPatient() const;
    std::vector<Treatment> getTreatments() const;
    std::string getVisitInformation() const;

    void setPatient(const std::shared_ptr<Patient>& patient);
    void setVisitInformation(const std::string& visit_information);
    void updateTreatments(const std::vector<Treatment>& new_treatments);

    static void createVisit(const std::shared_ptr<Doctor>& doctor);
};
