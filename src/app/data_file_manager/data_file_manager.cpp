#include "data_file_manager.hpp"
#include "clinic_facade.hpp"
#include "gender.hpp"
#include "paths.hpp"
#include "treatment.hpp"

void DataFileManager::promptDoctor(clinic_data::Workers::Doctor* new_doctor, const std::shared_ptr<Doctor>& doctor_data)
{
    new_doctor->set_name(doctor_data->getName());
    new_doctor->set_surname(doctor_data->getSurname());
    new_doctor->set_pesel(doctor_data->getPesel());
    new_doctor->set_gender(doctor_data->getGender());
}

void DataFileManager::promptReceptionist(clinic_data::Workers::Receptionist* new_receptionist,
                                         const std::shared_ptr<Receptionist>& receptionist_data)
{
    new_receptionist->set_name(receptionist_data->getName());
    new_receptionist->set_surname(receptionist_data->getSurname());
    new_receptionist->set_pesel(receptionist_data->getPesel());
    new_receptionist->set_gender(receptionist_data->getGender());
}

void DataFileManager::promptVisit(clinic_data::VisitsData::Visit* new_visit, const std::shared_ptr<Visit>& visit_data)
{
    if (!visit_data->getDoctor().expired())
    {
        clinic_data::VisitsData::Doctor* doctor = new_visit->mutable_doctor();
        auto doctor_data = visit_data->getDoctor().lock();
        doctor->set_name(doctor_data->getName());
        doctor->set_surname(doctor_data->getSurname());
        doctor->set_pesel(doctor_data->getPesel());
        doctor->set_gender(doctor_data->getGender());
    }
    if (!visit_data->getPatient().expired())
    {
        clinic_data::VisitsData::Patient* patient = new_visit->mutable_patient();
        auto patient_data = visit_data->getPatient().lock();
        patient->set_name(patient_data->getName());
        patient->set_surname(patient_data->getSurname());
        patient->set_pesel(patient_data->getPesel());
        patient->set_gender(patient_data->getGender());
    }
    if (!visit_data->getRoom().expired())
    {
        clinic_data::VisitsData::Room* room = new_visit->mutable_room();
        room->set_room_id(visit_data->getRoom().lock()->getRoomNumber());
    }
    new_visit->set_visit_information(visit_data->getVisitInformation());
    auto treatments = visit_data->getTreatments();
    for (const auto& treatment : treatments)
    {
        new_visit->add_treatments(toString(treatment));
    }
}

bool DataFileManager::anyVisitFieldUnavailable(const std::shared_ptr<Visit>& visit)
{
    return (visit->getDoctor().expired() || visit->getPatient().expired() || visit->getRoom().expired() ||
            visit->getVisitInformation().empty() || visit->getTreatments().empty());
}

void DataFileManager::clearFile(const std::filesystem::path& path, const std::string& file_name)
{
    FileManager file_manager(path, file_name, FileManager::FileMode::OutputTruncate);
}

void DataFileManager::addDoctorToDatabase(const std::filesystem::path& path, const std::string& file_name,
                                          const std::shared_ptr<Doctor>& new_doctor)
{
    FileManager file_manager(path, file_name, FileManager::FileMode::OutputAppend);
    auto& output_file = file_manager.getFileRef();
    clinic_data::Workers::Doctors doctor_data;
    DataFileManager::promptDoctor(doctor_data.add_doctors(), new_doctor);
    doctor_data.SerializeToOstream(&output_file);

    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::addReceptionistToDatabase(const std::filesystem::path& path, const std::string& file_name,
                                                const std::shared_ptr<Receptionist>& new_receptionist)
{
    FileManager file_manager(path, file_name, FileManager::FileMode::OutputAppend);
    auto& output_file = file_manager.getFileRef();
    clinic_data::Workers::Receptionists receptionist_data;
    DataFileManager::promptReceptionist(receptionist_data.add_receptionists(), new_receptionist);
    receptionist_data.SerializeToOstream(&output_file);
}

void DataFileManager::addVisitToDatabase(const std::filesystem::path& path, const std::string& file_name,
                                         const std::shared_ptr<Visit>& new_visit)
{
    if (!DataFileManager::anyVisitFieldUnavailable(new_visit))
    {
        throw std::invalid_argument("Cannot add visit to database because some fields are blank");
    }
    FileManager file_manager(path, file_name, FileManager::FileMode::OutputAppend);
    auto& output_file = file_manager.getFileRef();
    clinic_data::VisitsData::Visits visit_data;
    DataFileManager::promptVisit(visit_data.add_visits(), new_visit);
    visit_data.SerializeToOstream(&output_file);
    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::addTempVisitToDatabase(const std::filesystem::path& path, const std::string& file_name,
                                             const std::shared_ptr<Visit>& new_visit)
{
    FileManager file_manager(path, file_name, FileManager::FileMode::Output);
    auto& output_file = file_manager.getFileRef();
    clinic_data::VisitsData::Visits visit_data;
    DataFileManager::promptVisit(visit_data.add_visits(), new_visit);
    visit_data.SerializeToOstream(&output_file);
    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::removeDoctorFromFile(const std::filesystem::path& path, const std::string& file_name,
                                           const std::shared_ptr<Doctor>& doctor)
{

    clinic_data::Workers::Doctors doctor_data;

    {
        FileManager file_manager(path, file_name, FileManager::FileMode::Input);
        auto& input_file = file_manager.getFileRef();
        if (!doctor_data.ParseFromIstream(&input_file))
        {
            throw std::invalid_argument("Error while parsing doctor data");
        }
        for (int i = 0; i < doctor_data.doctors_size(); i++)
        {
            if (doctor_data.doctors(i).pesel() == doctor->getPesel())
            {
                doctor_data.mutable_doctors()->DeleteSubrange(i, 1);
                break;
            }
        }
    }
    FileManager file_manager(path, file_name, FileManager::FileMode::OutputTruncate);
    auto& output_file = file_manager.getFileRef();
    doctor_data.SerializeToOstream(&output_file);

    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::removeReceptionistFromFile(const std::filesystem::path& path, const std::string& file_name,
                                                 const std::shared_ptr<Receptionist>& receptionist)
{
    clinic_data::Workers::Receptionists receptionist_data;

    {
        FileManager file_manager(path, file_name, FileManager::FileMode::Input);
        auto& input_file = file_manager.getFileRef();
        if (!receptionist_data.ParseFromIstream(&input_file))
        {
            throw std::invalid_argument("Error while parsing receptionist data");
        }
        for (int i = 0; i < receptionist_data.receptionists_size(); i++)
        {
            if (receptionist_data.receptionists(i).pesel() == receptionist->getPesel())
            {
                receptionist_data.mutable_receptionists()->DeleteSubrange(i, 1);
                break;
            }
        }
    }
    FileManager file_manager(path, file_name, FileManager::FileMode::OutputTruncate);
    auto& output_file = file_manager.getFileRef();
    receptionist_data.SerializeToOstream(&output_file);

    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::removeVisitFromFile(const std::filesystem::path& path, const std::string& file_name,
                                          const std::shared_ptr<Visit>& visit)
{
    clinic_data::VisitsData::Visits visit_data;

    {
        FileManager file_manager(path, file_name, FileManager::FileMode::Input);
        auto& input_file = file_manager.getFileRef();
        if (!visit_data.ParseFromIstream(&input_file))
        {
            throw std::invalid_argument("Error while parsing visit data");
        }
        for (int i = 0; i < visit_data.visits_size(); i++)
        {
            if (visit_data.visits(i).doctor().pesel() == visit->getDoctor().lock()->getPesel() &&
                visit_data.visits(i).patient().pesel() == visit->getPatient().lock()->getPesel() &&
                visit_data.visits(i).room().room_id() == visit->getRoom().lock()->getRoomNumber() &&
                visit_data.visits(i).visit_information() ==
                    visit->getVisitInformation()) // todo add calendar date to get individual visit
            {
                visit_data.mutable_visits()->DeleteSubrange(i, 1);
                break;
            }
        }
    }
    FileManager file_manager(path, file_name, FileManager::FileMode::OutputTruncate);
    auto& output_file = file_manager.getFileRef();
    visit_data.SerializeToOstream(&output_file);

    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::loadDataForDoctors()
{
    FileManager file_manager(PATH::WORKERS, "doctors.proto", FileManager::FileMode::Input);
    auto& input_file = file_manager.getFileRef();
    clinic_data::Workers::Doctors doctor_data;
    doctor_data.ParseFromIstream(&input_file);
    for (int i = 0; i < doctor_data.doctors_size(); i++)
    {
        Doctor::createDoctor(doctor_data.doctors(i).name(), doctor_data.doctors(i).surname(),
                             doctor_data.doctors(i).pesel(), toEnum(doctor_data.doctors(i).gender()));
    }

    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::loadDataForReceptionists()
{
    FileManager file_manager(PATH::WORKERS, "receptionists.proto", FileManager::FileMode::Input);
    auto& input_file = file_manager.getFileRef();
    clinic_data::Workers::Receptionists receptionist_data;
    receptionist_data.ParseFromIstream(&input_file);

    for (int i = 0; i < receptionist_data.receptionists_size(); i++)
    {
        Receptionist::createReceptionist(
            receptionist_data.receptionists(i).name(), receptionist_data.receptionists(i).surname(),
            receptionist_data.receptionists(i).pesel(), toEnum(receptionist_data.receptionists(i).gender()));
    }

    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::loadAllDataForWorkers()
{
    DataFileManager::loadDataForDoctors();
    DataFileManager::loadDataForReceptionists();
}

void DataFileManager::loadAllDataForVisits()
{
    FileManager file_manager(PATH::VISITS, "visits.proto", FileManager::FileMode::Input);
    auto& input_file = file_manager.getFileRef();
    clinic_data::VisitsData::Visits visit_data;
    visit_data.ParseFromIstream(&input_file);
    auto doctors = Clinic::getDoctors();
    auto patients = Clinic::getPatients();
    auto rooms = Clinic::getRooms();

    for (int i = 0; i < visit_data.visits_size(); i++)
    {
        auto doctor = std::find_if(doctors.begin(), doctors.end(), [&](const std::shared_ptr<Doctor>& doctor) {
            return doctor->getPesel() == visit_data.visits(i).doctor().pesel();
        });
        auto patient = std::find_if(patients.begin(), patients.end(), [&](const std::shared_ptr<Patient>& patient) {
            return patient->getPesel() == visit_data.visits(i).patient().pesel();
        });
        auto room = std::find_if(rooms.begin(), rooms.end(), [&](const std::shared_ptr<Room>& room) {
            return room->getRoomNumber() == visit_data.visits(i).room().room_id();
        });
        if (doctor != doctors.end() && patient != patients.end() && room != rooms.end())
        {
            Visit::createTempVisit(*doctor);
            auto visit = Clinic::getTempVisit();
            visit->setPatient(*patient);
            visit->setRoom(*room);
            visit->setVisitInformation(visit_data.visits(i).visit_information());
            std::vector<Treatment> treatments{};
            for (int j = 0; j < visit_data.visits(i).treatments_size(); j++)
            {
                treatments.push_back(toEnumTreatment(visit_data.visits(i).treatments(j)));
            }
            visit->updateTreatments(treatments);
        }
    }
    google::protobuf::ShutdownProtobufLibrary();
}

std::string DataFileManager::printDoctors(const std::filesystem::path& path, const std::string& file_name)
{
    std::string temp{};
    FileManager file_manager(path, file_name, FileManager::FileMode::Input);
    auto& input_file = file_manager.getFileRef();
    clinic_data::Workers::Doctors doctor;
    doctor.ParseFromIstream(&input_file);
    for (int i = 0; i < doctor.doctors_size(); i++)
    {
        temp += "Doctor: " + doctor.doctors(i).name() + " " + doctor.doctors(i).surname() + " " +
                doctor.doctors(i).pesel() + " " + doctor.doctors(i).gender() + "\n";
    }
    return temp;
}

std::string DataFileManager::printReceptionists(const std::filesystem::path& path, const std::string& file_name)
{
    std::string temp{};
    FileManager file_manager(path, file_name, FileManager::FileMode::Input);
    auto& input_file = file_manager.getFileRef();
    clinic_data::Workers::Receptionists receptionist;
    receptionist.ParseFromIstream(&input_file);

    for (int i = 0; i < receptionist.receptionists_size(); i++)
    {
        temp += "Receptionist: " + receptionist.receptionists(i).name() + " " +
                receptionist.receptionists(i).surname() + " " + receptionist.receptionists(i).pesel() + " " +
                receptionist.receptionists(i).gender() + "\n";
    }
    return temp;
}

std::string DataFileManager::printVisits(const std::filesystem::path& path, const std::string& file_name)
{
    std::string temp{};
    FileManager file_manager(path, file_name, FileManager::FileMode::Input);
    auto& input_file = file_manager.getFileRef();
    clinic_data::VisitsData::Visits visits;
    visits.ParseFromIstream(&input_file);

    for (int i = 0; i < visits.visits_size(); i++)
    {
        temp += "Visit:\n";
        temp += "Doctor: " + visits.visits(i).doctor().name() + " " + visits.visits(i).doctor().surname() + " " +
                visits.visits(i).doctor().pesel() + "\n" + "Patient: " + visits.visits(i).patient().name() + " " +
                visits.visits(i).patient().surname() + " " + visits.visits(i).patient().pesel() + "\n" +
                "Room: " + std::to_string(visits.visits(i).room().room_id()) + "\n" +
                "Visit information: " + visits.visits(i).visit_information() + "\n" + "Treatments: ";
        for (int j = 0; j < visits.visits(i).treatments_size(); j++)
        {
            temp += "\n -" + visits.visits(i).treatments(j);
        }
        temp += "\n";
    }
    return temp;
}
