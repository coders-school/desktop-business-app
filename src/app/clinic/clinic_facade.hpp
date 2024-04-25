#pragma once
#include "../calendar/calendar.hpp"
#include "../doctor/doctor.hpp"
#include "../patient/patient.hpp"
#include "../receptionist/receptionist.hpp"
#include "../visit/visit.hpp"
#include <algorithm>
#include <memory>
#include <vector>

class Clinic
{
    inline static std::vector<std::shared_ptr<Doctor>> doctors_;
    inline static std::vector<std::shared_ptr<Patient>> patients_;
    inline static std::vector<std::shared_ptr<Visit>> visits_;
    inline static std::vector<std::shared_ptr<Receptionist>> receptionists_;
    inline static std::shared_ptr<Calendar> calendar_;

  public:
    static void appendDoctor(const std::shared_ptr<Doctor>& doctor);
    static void appendPatient(const std::shared_ptr<Patient>& patient);
    static void appendVisit(const std::shared_ptr<Visit>& visit);
    static void appendReceptionist(const std::shared_ptr<Receptionist>& receptionist);
    static void addCalendar(const std::shared_ptr<Calendar>& calendar);
    static std::vector<std::shared_ptr<Doctor>>& getDoctors();
    static std::vector<std::shared_ptr<Patient>>& getPatients();
    static std::vector<std::shared_ptr<Visit>>& getVisits();
    static std::vector<std::shared_ptr<Receptionist>>& getReceptionists();
    static std::shared_ptr<Calendar>& getCalendar();
    static void removeDoctor(const std::shared_ptr<Doctor>& doctor);
    static void removePatient(const std::shared_ptr<Patient>& patient);
    static void removeVisit(const std::shared_ptr<Visit>& visit);
    static void removeReceptionist(const std::shared_ptr<Receptionist>& receptionist);
    static void deleteCalendar();
};
