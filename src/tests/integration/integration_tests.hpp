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
};
