#include "medicine.hpp"
#include "product.hpp"
#include "gtest/gtest.h"

const std::string name{"anaesthetic"};
constexpr int price{45};
constexpr int amount{100};
constexpr int expiration_date{10122025};
constexpr std::pair storage_temperature{-10, 0};

struct MedicineTest : ::testing::Test
{
    std::shared_ptr<Product> anaesthetic;

  protected:
    void SetUp()
    {
        const std::string name{"anaesthetic"};
        const std::vector<std::string> composition{"chemicals"};
        anaesthetic =
            std::make_shared<Medicine>(name, price, amount, expiration_date, storage_temperature, composition);
    }
};
