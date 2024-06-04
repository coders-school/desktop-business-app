#pragma once
#include "clinic.pb.h"
#include "doctor.hpp"
#include "file_manager.hpp"
#include "patient.hpp"
#include "receptionist.hpp"
#include "room.hpp"
#include "visit.hpp"
#include <filesystem>
#include <fstream>
#include <memory>

class DataFileManager
{
  private:
    static void promptDoctor(clinic_data::Workers::Doctor* new_doctor, const std::shared_ptr<Doctor>& doctor_data);
    static void promptReceptionist(clinic_data::Workers::Receptionist* new_receptionist,
                                   const std::shared_ptr<Receptionist>& receptionist_data);
    static void promptVisit(clinic_data::VisitsData::Visit* new_visit, const std::shared_ptr<Visit>& visit_data);
    bool static anyVisitFieldUnavailable(const std::shared_ptr<Visit>& visit);
    static void clearFile(const std::filesystem::path& path, const std::string& file_name);

  public:
    static void addDoctorToDatabase(const std::filesystem::path& path, const std::string& file_name,
                                    const std::shared_ptr<Doctor>& new_doctor);
    static void addReceptionistToDatabase(const std::filesystem::path& path, const std::string& file_name,
                                          const std::shared_ptr<Receptionist>& new_receptionist);
    static void addVisitToDatabase(const std::filesystem::path& path, const std::string& file_name,
                                   const std::shared_ptr<Visit>& new_visit);
    static void addTempVisitToDatabase(const std::filesystem::path& path, const std::string& file_name,
                                       const std::shared_ptr<Visit>& new_visit);

    static void removeDoctorFromFile(const std::filesystem::path& path, const std::string& file_name,
                                     const std::shared_ptr<Doctor>& doctor);
    static void removeReceptionistFromFile(const std::filesystem::path& path, const std::string& file_name,
                                           const std::shared_ptr<Receptionist>& receptionist);
    static void removeVisitFromFile(const std::filesystem::path& path, const std::string& file_name,
                                    const std::shared_ptr<Visit>& visit);
    static void loadDataForDoctors();
    static void loadDataForReceptionists();
    static void loadAllDataForWorkers();
    static void loadAllDataForVisits();
    static std::string printDoctors(const std::filesystem::path& path, const std::string& file_name);
    static std::string printReceptionists(const std::filesystem::path& path, const std::string& file_name);
    static std::string printVisits(const std::filesystem::path& path, const std::string& file_name);
};
