#include <gtest/gtest.h>

#include "Clinic.hpp"
#include "PatientCollection.hpp"
#include "PatientsFactory.hpp"
#include "Serializer.hpp"
#include "VisitCollection.hpp"
#include "Warehouse.hpp"
#include "enumerations/allergen/Allergen.hpp"
#include "enumerations/sex/Sex.hpp"
#include "enumerations/specialization/Specialization.hpp"
#include "enumerations/treatment/Treatment.hpp"
#include "enumerations/treatment_state/TreatmentState.hpp"
#include "patient/Patient.hpp"
#include "patient/allergens/Allergens.hpp"
#include "patient/payments/Payments.hpp"
#include "patient/treatments/Treatments.hpp"
#include "personal_data/PersonalData.hpp"
#include "personal_data/address/Address.hpp"
#include "personal_data/pesel/Pesel.hpp"
#include "personal_data/phone_number/PhoneNumber.hpp"
#include "room/Room.hpp"
#include "staff/Staff.hpp"
#include "validators/PeselValidator.hpp"
#include "visit/Visit.hpp"

namespace
{

TEST(RoomConstructionTest, checkIfRoomCanBeConstructed)
{
    auto some_room = std::make_unique<clinic::room::Room>(1, nullptr);
    EXPECT_NE(some_room, nullptr);
    EXPECT_EQ(some_room->getNumber(), 1);
}

TEST(StaffConstructionTest, checkIfStaffCanBeConstructed)
{
    auto some_staff = std::make_unique<clinic::staff::Staff>();
    EXPECT_NE(some_staff, nullptr);
}

TEST(ClinicConstructionTest, checkIfClinicCanBeConstructed)
{
    auto some_staff = std::make_unique<clinic::staff::Staff>();
    auto some_room = std::make_unique<clinic::room::Room>(1, nullptr);
    std::vector<std::unique_ptr<clinic::room::iRoom>> rooms;
    rooms.push_back(std::move(some_room));

    auto some_clinic = std::make_unique<clinic::Clinic>(std::move(some_staff), std::move(rooms));
    EXPECT_NE(some_clinic, nullptr);
}

TEST(AddressCreationTest, checkIfAddressCanBeCreated)
{
    common::Address address{"Olsztyn", "Polska", "Warmińsko-Mazurskie", "Błotna 10/4", "00-100"};

    EXPECT_EQ(address.city_, "Olsztyn");
    EXPECT_EQ(address.country_, "Polska");
    EXPECT_EQ(address.province_, "Warmińsko-Mazurskie");
    EXPECT_EQ(address.street_, "Błotna 10/4");
    EXPECT_EQ(address.zip_code_, "00-100");
}

TEST(NameCreationTest, checkIfNameCanBeCreated)
{
    common::Name name{"Michał", "Janusz", "Boski"};

    EXPECT_EQ(name.first_name_, "Michał");
    EXPECT_EQ(name.second_name_, "Janusz");
    EXPECT_EQ(name.last_name_, "Boski");
}

TEST(PeselCreationTest, checkIfPeselCanBeCreated)
{
    common::Pesel pesel{"80062378532"};

    EXPECT_EQ(pesel.getPesel(), "80062378532");
    EXPECT_EQ(pesel.getSex(), common::sex::Sex::Male);
}

TEST(PhoneNumberCreationTest, checkIfPhoneNumberCanBeCreated)
{
    common::PhoneNumber phone_number{"+48", "100 200 300", "23", "400 500 600"};

    EXPECT_EQ(phone_number.cellphone_code_, "+48");
    EXPECT_EQ(phone_number.cellphone_number_, "100 200 300");
    EXPECT_EQ(phone_number.home_number_code_, "23");
    EXPECT_EQ(phone_number.home_number_, "400 500 600");
}

TEST(PersonalDataCreationTest, checkIfPersonalDataCanBeCreated)
{
    common::Name name{"Michał", "Janusz", "Boski"};
    common::Address address{"Olsztyn", "Polska", "Warmińsko-Mazurskie", "Błotna 10/4", "00-100"};
    common::Pesel pesel{"80062378532"};
    common::PhoneNumber phone_number{"+48", "100 200 300", "23", "400 500 600"};

    common::PersonalData personal_data{name, address, pesel, phone_number};

    EXPECT_EQ(personal_data.getName().first_name_, "Michał");
    EXPECT_EQ(personal_data.getName().second_name_, "Janusz");
    EXPECT_EQ(personal_data.getName().last_name_, "Boski");

    EXPECT_EQ(personal_data.getAddress().city_, "Olsztyn");
    EXPECT_EQ(personal_data.getAddress().country_, "Polska");
    EXPECT_EQ(personal_data.getAddress().province_, "Warmińsko-Mazurskie");
    EXPECT_EQ(personal_data.getAddress().street_, "Błotna 10/4");
    EXPECT_EQ(personal_data.getAddress().zip_code_, "00-100");

    EXPECT_EQ(personal_data.getPesel(), "80062378532");
    EXPECT_EQ(personal_data.getPhoneNumber().cellphone_code_, "+48");
    EXPECT_EQ(personal_data.getPhoneNumber().cellphone_number_, "100 200 300");
    EXPECT_EQ(personal_data.getPhoneNumber().home_number_code_, "23");
    EXPECT_EQ(personal_data.getPhoneNumber().home_number_, "400 500 600");

    EXPECT_EQ(personal_data.getSex(), common::sex::Sex::Male);
}

TEST(PeselValidatorCreationTest, checkIfPeselValidatorCanBeCreated)
{
    common::validators::PeselValidator pesel_validator;

    EXPECT_EQ(pesel_validator.Validate("80062378532"), "80062378532");
}

TEST(PatientsAllergensCreationTest, checkIfAllergensCanBeCreated)
{
    patient::Allergens patients_allergies;

    EXPECT_TRUE(patients_allergies.getAllergens().empty());
}

TEST(PaymentsCreationTest, checkIfPaymentsCanBeCreated)
{
    patient::Payments payments{10, 5, 0};

    EXPECT_EQ(payments.paid_, 10);
    EXPECT_EQ(payments.planned_, 5);
    EXPECT_EQ(payments.overdue_, 0);
}

TEST(PatientTreatmentsCreationTest, checkIfTreatmentsCanBeCreated)
{
    patient::Treatments treatments;
}

TEST(PatientCreationTest, checkIfPatientCanBeCreated)
{
    EXPECT_THROW(patient::Patient(), std::invalid_argument);
}

TEST(PatientCollectionCreationTest, checkIfPatientCollectionCanBeCreated)
{
    std::vector<std::unique_ptr<patient::iPatient>> patients;
    patient::PatientCollection patient_collection(std::move(patients));
}

TEST(VisitCreationTest, checkIfVisitCanBeCreated)
{
    visit::Visit some_visit;
}

TEST(VisitCollectionCreationTest, checkIfVisitsCollectionCanBeCreated)
{
    visit::VisitCollection visits_collection;
}

TEST(WarehouseCreationTest, checkIfWarehouseCanBeCreated)
{
    warehouse::Warehouse Warehouse;
}

} // namespace
