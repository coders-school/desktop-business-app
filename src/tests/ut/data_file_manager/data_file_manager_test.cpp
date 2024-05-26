#include "data_file_manager_test.hpp"
#include "data_file_manager.hpp"
#include "paths.hpp"

TEST_F(DataFileManagerTestFixture, GivenDoctorIsSerializedToFile)
{
    std::string test_file_content = DataFileManager::printDoctors(PATH::TEST_WORKERS, "test_doctors.proto");
    std::string expected = "";
    EXPECT_EQ(test_file_content, expected);

    Doctor::createDoctor("Szczepan", "Kowalski", "80083169414", Gender::Male);
    DataFileManager::addDoctorToDatabase(PATH::TEST_WORKERS, "test_doctors.proto", Clinic::getDoctors().front());
    test_file_content = DataFileManager::printDoctors(PATH::TEST_WORKERS, "test_doctors.proto");
    expected = "Doctor: Szczepan Kowalski 80083169414 male\n";
    EXPECT_EQ(test_file_content, expected);

    DataFileManager::removeDoctorFromFile(PATH::TEST_WORKERS, "test_doctors.proto", Clinic::getDoctors().front());
    test_file_content = DataFileManager::printDoctors(PATH::TEST_WORKERS, "test_doctors.proto");
    expected = "";
    EXPECT_EQ(test_file_content, expected);

    Doctor::createDoctor("Andrzej", "Szczepanski", "59122991491", Gender::Male);
    DataFileManager::addDoctorToDatabase(PATH::TEST_WORKERS, "test_doctors.proto", Clinic::getDoctors().at(1));
    test_file_content = DataFileManager::printDoctors(PATH::TEST_WORKERS, "test_doctors.proto");
    expected = "Doctor: Andrzej Szczepanski 59122991491 male\n";
    EXPECT_EQ(test_file_content, expected);

    DataFileManager::removeDoctorFromFile(PATH::TEST_WORKERS, "test_doctors.proto", Clinic::getDoctors().at(1));
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
    DataFileManager::addReceptionistToDatabase(PATH::TEST_WORKERS, "test_receptionists.proto",
                                               Clinic::getReceptionists().front());
    test_file_content = DataFileManager::printReceptionists(PATH::TEST_WORKERS, "test_receptionists.proto");
    expected = "Receptionist: Szczepan Kowalski 80083169414 male\n";
    EXPECT_EQ(test_file_content, expected);

    DataFileManager::removeReceptionistFromFile(PATH::TEST_WORKERS, "test_receptionists.proto",
                                                Clinic::getReceptionists().front());
    test_file_content = DataFileManager::printReceptionists(PATH::TEST_WORKERS, "test_receptionists.proto");
    expected = "";
    EXPECT_EQ(test_file_content, expected);

    Receptionist::createReceptionist("Andrzej", "Szczepanski", "59122991491", Gender::Male);
    DataFileManager::addReceptionistToDatabase(PATH::TEST_WORKERS, "test_receptionists.proto",
                                               Clinic::getReceptionists().at(1));
    test_file_content = DataFileManager::printReceptionists(PATH::TEST_WORKERS, "test_receptionists.proto");
    expected = "Receptionist: Andrzej Szczepanski 59122991491 male\n";

    DataFileManager::removeReceptionistFromFile(PATH::TEST_WORKERS, "test_receptionists.proto",
                                                Clinic::getReceptionists().at(1));
    test_file_content = DataFileManager::printReceptionists(PATH::TEST_WORKERS, "test_receptionists.proto");
    expected = "";
    EXPECT_EQ(test_file_content, expected);
}

TEST_F(DataFileManagerTestFixture, GivenTempVisitIsSerializedToFile)
{
    auto test_file_content = DataFileManager::printVisits(PATH::TEST_VISITS, "test_temp_visits.proto");
    auto expected = "";
    EXPECT_EQ(test_file_content, expected);
    Doctor::createDoctor("Szczepan", "Kowalski", "80083169414", Gender::Male);
    Visit::createTempVisit(Clinic::getDoctors().front());
    Patient::createPatient("Andrzej", "Szczepanski", "59122991491", Gender::Male);
    Clinic::getTempVisit()->setPatient(Clinic::getPatients().front());
    std::vector<Treatment> treatments{Treatment::DentalBridges, Treatment::DentalFilling, Treatment::DentalImplants};
    Clinic::getTempVisit()->updateTreatments(treatments);
    Clinic::getTempVisit()->setVisitInformation("Test visit information");
    Room::createRoom(2137, Clinic::getWarehouse());
    Clinic::getTempVisit()->setRoom(Clinic::getRooms().front());

    DataFileManager::addTempVisitToDatabase(PATH::TEST_VISITS, "test_temp_visits.proto", Clinic::getTempVisit());
    test_file_content = DataFileManager::printVisits(PATH::TEST_VISITS, "test_temp_visits.proto");
    expected =
        "Visit:\nDoctor: Szczepan Kowalski 80083169414\nPatient: Andrzej Szczepanski 59122991491\nRoom: 2137\nVisit "
        "information: Test visit information\nTreatments: \n -dental bridges\n -dental filling\n -dental implants\n";
    EXPECT_EQ(test_file_content, expected);

    DataFileManager::removeVisitFromFile(PATH::TEST_VISITS, "test_temp_visits.proto", Clinic::getTempVisit());
    test_file_content = DataFileManager::printVisits(PATH::TEST_VISITS, "test_temp_visits.proto");
    expected = "";
    EXPECT_EQ(test_file_content, expected);
}
