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
};
