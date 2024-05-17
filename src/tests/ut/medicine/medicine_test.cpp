#include "medicine_test.hpp"

TEST_F(MedicineTest, MedicineIsNotExpiredCurrentYear)
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    int currentYear = now->tm_year + 1900;
    std::chrono::year_month_day expiration_date3{static_cast<std::chrono::year>(currentYear), std::chrono::December,
                                                 31d};
    std::shared_ptr<Product> notExpiredAnaesthetic =
        std::make_shared<Medicine>(std::string{"anaesthetic"}, price, amount, expiration_date3, storage_temperature,
                                   std::vector<std::string>{{"chemicals"}});
    EXPECT_FALSE(notExpiredAnaesthetic->isExpired());
}

TEST_F(MedicineTest, MedicineIsNotExpiredVariousYears)
{
    std::chrono::year_month_day expiration_date4{2100y, std::chrono::December, 31d};
    std::shared_ptr<Product> notExpiredAnaesthetic =
        std::make_shared<Medicine>(std::string{"anaesthetic"}, price, amount, expiration_date4, storage_temperature,
                                   std::vector<std::string>{{"chemicals"}});
    EXPECT_FALSE(notExpiredAnaesthetic->isExpired());
}


TEST_F(MedicineTest, MedicineGetInfoTest)
{
    auto infoVec = anaesthetic->getInfo();
    EXPECT_EQ(infoVec.at("expiration date"), "31.1.2030");
    EXPECT_EQ(infoVec.at("storage temperature"), "-10.000000 / 0.000000");
    EXPECT_EQ(infoVec.at("composition"), "chemicals, ");
}

TEST_F(MedicineTest, increaseAmountTest)
{
    anaesthetic->increaseAmount(100);
    EXPECT_EQ(anaesthetic->getAmount(), 200);
}

TEST_F(MedicineTest, decreaseAmountTest)
{
    anaesthetic->decreaseAmount(50);
    EXPECT_EQ(anaesthetic->getAmount(), 50);
}
