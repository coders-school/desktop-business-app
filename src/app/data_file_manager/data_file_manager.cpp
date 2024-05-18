#include "data_file_manager.hpp"
#include "paths.hpp"
#include "gender.hpp"

void DataFileManager::promptDoctor(clinic_data::Workers::Doctor* new_doctor, const std::shared_ptr<Doctor>& doctor_data)
{
    new_doctor->set_name(doctor_data->getName());
    new_doctor->set_surname(doctor_data->getSurname());
    new_doctor->set_pesel(doctor_data->getPesel());
    new_doctor->set_gender(doctor_data->getGender());
}

void DataFileManager::promptReceptionist(clinic_data::Workers::Receptionist* new_receptionist, const std::shared_ptr<Receptionist>& receptionist_data)
{
    new_receptionist->set_name(receptionist_data->getName());
    new_receptionist->set_surname(receptionist_data->getSurname());
    new_receptionist->set_pesel(receptionist_data->getPesel());
    new_receptionist->set_gender(receptionist_data->getGender());
}

void DataFileManager::addDoctorToDatabase(const std::shared_ptr<Doctor>& new_doctor)
{
    FileManager file_manager(PATH::WORKERS, "doctors.proto", FileManager::FileMode::OutputAppend);
    auto& output_file = file_manager.getFileRef();
    clinic_data::Workers::Doctors doctor_data;
    DataFileManager::promptDoctor(doctor_data.add_doctors(), new_doctor);
    doctor_data.SerializeToOstream(&output_file);

    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::addReceptionistToDatabase(const std::shared_ptr<Receptionist>& new_receptionist)
{
    FileManager file_manager(PATH::WORKERS, "receptionists.proto", FileManager::FileMode::OutputAppend);
    auto& output_file = file_manager.getFileRef();
    clinic_data::Workers::Receptionists receptionist_data;
    DataFileManager::promptReceptionist(receptionist_data.add_receptionists(), new_receptionist);
    receptionist_data.SerializeToOstream(&output_file);

    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::removeDoctorFromFile(const std::shared_ptr<Doctor>& doctor)
{

    clinic_data::Workers::Doctors doctor_data;

    {
        FileManager file_manager(PATH::WORKERS, "doctors.proto", FileManager::FileMode::Input);
        auto& input_file = file_manager.getFileRef();
        if(!doctor_data.ParseFromIstream(&input_file))
        {
            throw std::invalid_argument("Error while parsing doctor data");
        }
        for(int i = 0; i < doctor_data.doctors_size(); i++)
        {
            if(doctor_data.doctors(i).pesel() == doctor->getPesel())
            {
                doctor_data.mutable_doctors()->DeleteSubrange(i, 1);
                break;
            }
        }
    }
    FileManager file_manager(PATH::WORKERS, "doctors.proto", FileManager::FileMode::OutputTruncate);
    auto& output_file = file_manager.getFileRef();
    doctor_data.SerializeToOstream(&output_file);

    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::removeReceptionistFromFile(const std::shared_ptr<Receptionist>& receptionist)
{
    clinic_data::Workers::Receptionists receptionist_data;

    {
        FileManager file_manager(PATH::WORKERS, "receptionists.proto", FileManager::FileMode::Input);
        auto& input_file = file_manager.getFileRef();
        if(!receptionist_data.ParseFromIstream(&input_file))
        {
            throw std::invalid_argument("Error while parsing receptionist data");
        }
        for(int i = 0; i < receptionist_data.receptionists_size(); i++)
        {
            if(receptionist_data.receptionists(i).pesel() == receptionist->getPesel())
            {
                receptionist_data.mutable_receptionists()->DeleteSubrange(i, 1);
                break;
            }
        }
    }
    FileManager file_manager(PATH::WORKERS, "receptionists.proto", FileManager::FileMode::OutputTruncate);
    auto& output_file = file_manager.getFileRef();
    receptionist_data.SerializeToOstream(&output_file);

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
        Doctor::createDoctor(doctor_data.doctors(i).name(),
                            doctor_data.doctors(i).surname(),
                            doctor_data.doctors(i).pesel(),
                            toEnum(doctor_data.doctors(i).gender()));
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
        Receptionist::createReceptionist(receptionist_data.receptionists(i).name(),
                                        receptionist_data.receptionists(i).surname(),
                                        receptionist_data.receptionists(i).pesel(),
                                        toEnum(receptionist_data.receptionists(i).gender()));
    }

    google::protobuf::ShutdownProtobufLibrary();
}

void DataFileManager::loadAllDataForWorkers()
{
    DataFileManager::loadDataForDoctors();
    DataFileManager::loadDataForReceptionists();
}
