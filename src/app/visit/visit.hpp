#pragma once
#include "visitStatus.hpp"
#include "treatment.hpp"
#include <memory>
#include <set>
#include <string>
#include <vector>

class Doctor;
class Patient;
class Room;

class Visit : public std::enable_shared_from_this<Visit>
{
    std::weak_ptr<Doctor> doctor_;
    std::weak_ptr<Patient> patient_;
    std::weak_ptr<Room> room_;
    std::vector<Treatment> treatments_;
    VisitStatus visit_status_;
    std::string visit_information_;

    Visit(const std::shared_ptr<Doctor>& doctor, const std::vector<Treatment>& treatments = {});

  public:
    std::weak_ptr<Doctor> getDoctor() const;
    std::weak_ptr<Patient> getPatient() const;
    std::weak_ptr<Room> getRoom() const;
    std::vector<Treatment> getTreatments() const;
    VisitStatus getStatus() const;
    std::string getVisitInformation() const;

    void setPatient(const std::shared_ptr<Patient>& patient);
    void setRoom(const std::shared_ptr<Room>& room);
    void setVisitInformation(const std::string& visit_information);
    void updateTreatments(const std::vector<Treatment>& new_treatments);
    void setStatus(VisitStatus visit_status);

    static void createVisit(const std::shared_ptr<Doctor>& doctor);
};
