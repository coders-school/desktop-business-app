#include "medicine.hpp"
#include "product.hpp"
#include "gtest/gtest.h"

struct MedicineTest : ::testing::Test
{
    std::shared_ptr<Product> anaesthetic = std::make_shared<Medicine>(
        std::string{"anaesthetic"}, 45, 100, 10122025, std::pair{-10, 0}, std::vector<std::string>{{"chemicals"}});
};