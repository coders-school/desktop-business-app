#pragma once

#include "clinic_facade.hpp"
#include "doctor.hpp"
#include "patient.hpp"
#include "room.hpp"
#include "treatment.hpp"
#include "warehouse.hpp"
#include "gtest/gtest.h"

class IntegratonFixture : public ::testing::Test
{

  public:
    void fillWarehouseWithProducts()
    {
        auto warehouse = Clinic::getWarehouse();
        std::vector<std::shared_ptr<Product>> products{};
        warehouse->addProducts(products);
    }

    void prepareClinic()
    {
        Warehouse::createWarehouse();
        std::vector<Treatment> treatments{Treatment::TeethCleaning, Treatment::TeethWhitening};
        Room::createRoom(1, treatments, Clinic::getWarehouse());
        Doctor::createDoctor("Jan", "Kowalski", "80062378532", Gender::Male);
        Receptionist::createReceptionist("Agnieszka", "Winna", "99053033817", Gender::Male);

        fillWarehouseWithProducts();
    }
    void expectClinicWellPrepared()
    {
        const std::string doctor_name = "Jan";
        const std::string doctor_surname = "Kowalski";
        const std::string receptionist_name = "Agnieszka";
        const std::string receptionist_surname = "Winna";
        EXPECT_EQ(1, Clinic::getRooms().size());
        EXPECT_EQ(2, Clinic::getRooms().front()->getTreatments().size());
        const auto doctor = Clinic::getDoctors().front();
        EXPECT_EQ(1, Clinic::getDoctors().size());
        EXPECT_EQ(doctor_name, doctor->getName());
        EXPECT_EQ(doctor_surname, doctor->getSurname());
        const auto receptionist = Clinic::getReceptionists().front();
        EXPECT_EQ(1, Clinic::getReceptionists().size());
        EXPECT_EQ(receptionist_name, receptionist->getName());
        EXPECT_EQ(receptionist_surname, receptionist->getSurname());
    }

    void checkIfPatientCreatedAsExpected(const std::shared_ptr<Patient>& patient)
    {
        EXPECT_EQ(patient->getName(), "Jan");
        EXPECT_EQ(patient->getSurname(), "Kowalski");
        EXPECT_EQ(patient->getPesel(), "87071989652");
        EXPECT_EQ(patient->getGender(), Gender::Male);
    }

    void checkIfInitialAddressEmpty(const std::shared_ptr<Patient>& patient)
    {
        Address initial_address{patient->getAddress()};
        EXPECT_TRUE(initial_address.city_.empty());
        EXPECT_TRUE(initial_address.country_.empty());
        EXPECT_TRUE(initial_address.province_.empty());
        EXPECT_TRUE(initial_address.street_.empty());
        EXPECT_TRUE(initial_address.zip_code_.empty());
    }

    void checkIfPatientHasExpectedAddress(const std::shared_ptr<Patient>& patient, const Address& expected_address)
    {
        Address patient_address{patient->getAddress()};
        EXPECT_EQ(patient_address.city_, expected_address.city_);
        EXPECT_EQ(patient_address.country_, expected_address.country_);
        EXPECT_EQ(patient_address.province_, expected_address.province_);
        EXPECT_EQ(patient_address.street_, expected_address.street_);
        EXPECT_EQ(patient_address.zip_code_, expected_address.zip_code_);
    }
};
