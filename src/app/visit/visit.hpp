#pragma once

#include "treatment.hpp"

#include <memory>
#include <set>
#include <string>
#include <vector>

class Doctor;

class Visit : public std::enable_shared_from_this<Visit>
{
    Visit(std::vector<Treatment> predictedTreatments);

    static std::set<Visit*> visit_extent_;
    std::shared_ptr<Doctor> doctor_association_;
    std::string visit_information_;
    std::vector<Treatment> treatments_;

  public:
    ~Visit();
    static std::shared_ptr<Visit> createVisit(std::shared_ptr<Doctor> doctor,
                                              std::vector<Treatment> predictedTreatments = {});
    static std::set<Visit*> getExtent();
    static void removeFromExtent(Visit* visit);
    void setDoctorAssociation(const std::shared_ptr<Doctor>& doctor);
    std::shared_ptr<Doctor> getDoctorAssociation() const;
    void setVisitInformation(const std::string& visit_information);
    std::string getVisitInformation() const;
    std::vector<Treatment> getTreatments() const;
    void updateTreatments(std::vector<Treatment> newTreatments);
};
