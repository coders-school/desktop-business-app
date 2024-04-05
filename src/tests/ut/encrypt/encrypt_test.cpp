#include "encrypt_test.hpp"

namespace
{
TEST_F(EncryptTestFixture, EmptyStringTest)
{
    std::string input = "";
    std::string expectedOutput = "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff831"
                                 "8d2877eec2f63b931bd47417a81a538327af927da3e";
    EXPECT_EQ(expectedOutput, encrypt.hashSHA512(input));
}

TEST_F(EncryptTestFixture, NonEmptyStringTest)
{
    std::string input = "Hello, World!";
    std::string expectedOutput = "374d794a95cdcfd8b35993185fef9ba368f160d8daf432d08ba9f1ed1e5abe6cc69291e0fa2fe0006a525"
                                 "70ef18c19def4e617c33ce52ef0a6e5fbe318cb0387";
    EXPECT_EQ(expectedOutput, encrypt.hashSHA512(input));
}
} // namespace
