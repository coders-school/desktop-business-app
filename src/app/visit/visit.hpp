#pragma once

#include <memory>
#include <set>
#include <string>

class Doctor;

class Visit : public std::enable_shared_from_this<Visit>
{
    Visit();
    static std::set<Visit *> visit_extent_;
    std::shared_ptr<Doctor> doctor_association_;
    std::string visit_information_;

  public:
    ~Visit();
    static std::shared_ptr<Visit> createVisit(std::shared_ptr<Doctor> doctor);
    static std::set<Visit *> getExtent();
    static void removeFromExtent(Visit *visit);
    void setDoctorAssociation(const std::shared_ptr<Doctor>& doctor);
    std::shared_ptr<Doctor> getDoctorAssociation() const;
    void setVisitInformation(const std::string& visit_information);
    std::string getVisitInformation() const;
};
