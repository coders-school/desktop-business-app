#pragma once
#include "../doctor/doctor.hpp"
#include "../receptionist/receptionist.hpp"
#include "../visit/visit.hpp"
#include <algorithm>
#include <memory>
#include <vector>

class Clinic
{
    inline static std::vector<std::shared_ptr<Doctor>> doctors_;
    inline static std::vector<std::shared_ptr<Visit>> visits_;
    inline static std::vector<std::shared_ptr<Receptionist>> receptionists_;

  public:
    static void appendDoctor(std::shared_ptr<Doctor> doctor);
    static void appendVisit(std::shared_ptr<Visit> visit);
    static void appendReceptionist(std::shared_ptr<Receptionist> receptionist);
    static std::vector<std::shared_ptr<Doctor>>& getDoctors();
    static std::vector<std::shared_ptr<Visit>>& getVisits();
    static std::vector<std::shared_ptr<Receptionist>>& getReceptionists();
    static void removeDoctor(std::shared_ptr<Doctor> doctor);
    static void removeVisit(std::shared_ptr<Visit> visit);
    static void removeReceptionist(std::shared_ptr<Receptionist> receptionist);
};
