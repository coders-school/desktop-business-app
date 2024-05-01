#pragma once
#include "../doctor/doctor.hpp"
#include "../patient/patient.hpp"
#include "../receptionist/receptionist.hpp"
#include "../room/room.hpp"
#include "../visit/visit.hpp"
#include "../calendar/calendar.hpp"
#include <algorithm>
#include <memory>
#include <vector>

class Clinic
{
    inline static std::vector<std::shared_ptr<Doctor>> doctors_;
    inline static std::vector<std::shared_ptr<Patient>> patients_;
    inline static std::vector<std::shared_ptr<Visit>> visits_;
    inline static std::vector<std::shared_ptr<Receptionist>> receptionists_;
    inline static std::vector<std::shared_ptr<Room>> rooms_;
    inline static std::shared_ptr<Calendar> calendar_;

  public:
    static void appendDoctor(const std::shared_ptr<Doctor>& doctor);
    static void appendPatient(const std::shared_ptr<Patient>& patient);
    static void appendVisit(const std::shared_ptr<Visit>& visit);
    static void appendReceptionist(const std::shared_ptr<Receptionist>& receptionist);
    static void appendRoom(const std::shared_ptr<Room>& room);
    static void appendCalendar(const std::shared_ptr<Calendar>& calendar);
    static std::vector<std::shared_ptr<Doctor>>& getDoctors();
    static std::vector<std::shared_ptr<Patient>>& getPatients();
    static std::vector<std::shared_ptr<Visit>>& getVisits();
    static std::vector<std::shared_ptr<Receptionist>>& getReceptionists();
    static std::vector<std::shared_ptr<Room>>& getRooms();
    static std::shared_ptr<Calendar>& getCalendar();
    static void removeDoctor(const std::shared_ptr<Doctor>& doctor);
    static void removePatient(const std::shared_ptr<Patient>& patient);
    static void removeVisit(const std::shared_ptr<Visit>& visit);
    static void removeReceptionist(const std::shared_ptr<Receptionist>& receptionist);
    static void removeRoom(const std::shared_ptr<Room>& room);
    static void removeCalendar();
};
