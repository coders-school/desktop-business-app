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
    Warehouse warehouse_{};

  public:
    void fillWarehouseWithProducts()
    {
        std::vector<std::shared_ptr<Product>> products{};
        warehouse_.addProducts(products);
    }

    void prepareClinic()
    {
        std::vector<Treatment> treatments{Treatment::TeethCleaning, Treatment::TeethWhitening};
        Room::createRoom(1, treatments, std::make_shared<Warehouse>(warehouse_));
        Doctor::createDoctor("Jan", "Kowalski", "88031110333");
        Receptionist::createReceptionist("Agnieszka", "Winna", "98010211354");

        fillWarehouseWithProducts();
    }
};
