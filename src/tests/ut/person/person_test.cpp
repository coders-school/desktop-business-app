#include "person.hpp"
#include "gtest/gtest.h"

TEST(PeselTest, PersonHasCorrectPesel)
{
    Person person{"Jan", "Kowalski", "95082910213"};

    EXPECT_EQ(person.validatePesel("95082910213"), true);
}
TEST(PeselTest, PersonHasIncorrectPesel)
{
    Person person{"Jan", "Kowalski", "00000000001"};

    EXPECT_EQ(person.validatePesel("00000000001"), false);
}
