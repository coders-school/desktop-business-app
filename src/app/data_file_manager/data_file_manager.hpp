#pragma once
#include "clinic.pb.h"
#include "doctor.hpp"
#include "file_manager.hpp"
#include "patient.hpp"
#include "receptionist.hpp"
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

  public:
    static void addDoctorToDatabase(const std::filesystem::path& path, const std::string& file_name,
                                    const std::shared_ptr<Doctor>& new_doctor);
    static void addReceptionistToDatabase(const std::filesystem::path& path, const std::string& file_name,
                                          const std::shared_ptr<Receptionist>& new_receptionist);
    static void removeDoctorFromFile(const std::filesystem::path& path, const std::string& file_name,
                                     const std::shared_ptr<Doctor>& doctor);
    static void removeReceptionistFromFile(const std::filesystem::path& path, const std::string& file_name,
                                           const std::shared_ptr<Receptionist>& receptionist);
    static void loadDataForDoctors();
    static void loadDataForReceptionists();
    static void loadAllDataForWorkers();
    static std::string printDoctors(const std::filesystem::path& path, const std::string& file_name);
    static std::string printReceptionists(const std::filesystem::path& path, const std::string& file_name);
};
