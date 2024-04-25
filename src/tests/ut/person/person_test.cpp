#include "person.hpp"
#include "gtest/gtest.h"

TEST(PeselTest, PersonHasCorrectPesel)
{
    Person person{"Jan", "Kowalski", "95082910213", Gender::Male};

    EXPECT_EQ(person.validatePesel(), true);
}
TEST(PeselTest, PersonHasIncorrectPeselSize)
{
    Person person{"Jan", "Kowalski", "950829102130", Gender::Male};

    EXPECT_EQ(person.validatePesel(), false);
}

TEST(PeselTest, PersonHasIncorrectPeselDate)
{
    Person person{"Jan", "Kowalski", "95132910213", Gender::Male};

    EXPECT_EQ(person.validatePesel(), false);
}

TEST(PeselTest, PersonHasIncorrectPeselControlNumber)
{
    Person person{"Jan", "Kowalski", "95132910210", Gender::Male};

    EXPECT_EQ(person.validatePesel(), false);
}

TEST(PeselTest, PersonHasIncorrectPeselGender)
{
    Person person{"Jan", "Kowalski", "95082910213", Gender::Female};

    EXPECT_EQ(person.validatePesel(), false);
}
