#include "data_file_manager_test.hpp"
#include "data_file_manager.hpp"
#include "paths.hpp"

TEST_F(DataFileManagerTestFixture, GivenDoctorIsSerializedToFile)
{
    std::string test_file_content = DataFileManager::printDoctors(PATH::TEST_WORKERS, "test_doctors.proto");
    std::string expected = "";
    EXPECT_EQ(test_file_content, expected);

    Doctor::createDoctor("Szczepan", "Kowalski", "80083169414", Gender::Male);
    DataFileManager::addDoctorToDatabase(PATH::TEST_WORKERS, "test_doctors.proto" ,Clinic::getDoctors().front());
    test_file_content = DataFileManager::printDoctors(PATH::TEST_WORKERS, "test_doctors.proto");
    expected = "Doctor: Szczepan Kowalski 80083169414 male\n";
    EXPECT_EQ(test_file_content, expected);

    DataFileManager::removeDoctorFromFile(PATH::TEST_WORKERS, "test_doctors.proto" , Clinic::getDoctors().front());
    test_file_content = DataFileManager::printDoctors(PATH::TEST_WORKERS, "test_doctors.proto");
    expected = "";
    EXPECT_EQ(test_file_content, expected);

    Doctor::createDoctor("Andrzej", "Szczepanski", "59122991491", Gender::Male);
    DataFileManager::addDoctorToDatabase(PATH::TEST_WORKERS, "test_doctors.proto" ,Clinic::getDoctors().at(1));
    test_file_content = DataFileManager::printDoctors(PATH::TEST_WORKERS, "test_doctors.proto");
    expected = "Doctor: Andrzej Szczepanski 59122991491 male\n";
    EXPECT_EQ(test_file_content, expected);

    DataFileManager::removeDoctorFromFile(PATH::TEST_WORKERS, "test_doctors.proto" , Clinic::getDoctors().at(1));
    test_file_content = DataFileManager::printDoctors(PATH::TEST_WORKERS, "test_doctors.proto");
    expected = "";
    EXPECT_EQ(test_file_content, expected);
}

TEST_F(DataFileManagerTestFixture, GivenReceptionistIsSerializedToFile)
{
    std::string test_file_content = DataFileManager::printReceptionists(PATH::TEST_WORKERS, "test_receptionists.proto");
    std::string expected = "";
    EXPECT_EQ(test_file_content, expected);

    Receptionist::createReceptionist("Szczepan", "Kowalski", "80083169414", Gender::Male);
    DataFileManager::addReceptionistToDatabase(PATH::TEST_WORKERS, "test_receptionists.proto" ,Clinic::getReceptionists().front());
    test_file_content = DataFileManager::printReceptionists(PATH::TEST_WORKERS, "test_receptionists.proto");
    expected = "Receptionist: Szczepan Kowalski 80083169414 male\n";
    EXPECT_EQ(test_file_content, expected);

    DataFileManager::removeReceptionistFromFile(PATH::TEST_WORKERS, "test_receptionists.proto" , Clinic::getReceptionists().front());
    test_file_content = DataFileManager::printReceptionists(PATH::TEST_WORKERS, "test_receptionists.proto");
    expected = "";
    EXPECT_EQ(test_file_content, expected);

    Receptionist::createReceptionist("Andrzej", "Szczepanski", "59122991491", Gender::Male);
    DataFileManager::addReceptionistToDatabase(PATH::TEST_WORKERS, "test_receptionists.proto" ,Clinic::getReceptionists().at(1));
    test_file_content = DataFileManager::printReceptionists(PATH::TEST_WORKERS, "test_receptionists.proto");
    expected = "Receptionist: Andrzej Szczepanski 59122991491 male\n";

    DataFileManager::removeReceptionistFromFile(PATH::TEST_WORKERS, "test_receptionists.proto" , Clinic::getReceptionists().at(1));
    test_file_content = DataFileManager::printReceptionists(PATH::TEST_WORKERS, "test_receptionists.proto");
    expected = "";
    EXPECT_EQ(test_file_content, expected);
}