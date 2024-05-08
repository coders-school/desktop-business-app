#include "person.hpp"
#include "gtest/gtest.h"
#include <stdexcept>

TEST(PeselTest, PersonHasCorrectPesel)
{
    Person person{"Jan", "Kowalski", "80062378532", Gender::Male};

    EXPECT_NO_THROW(person.setPesel("80062378532", Gender::Male));
}
TEST(PeselTest, PersonHasIncorrectPeselSize)
{
    Person person{"Jan", "Kowalski", "80062378532", Gender::Male};

    EXPECT_THROW(person.setPesel("800623785320", Gender::Male), std::invalid_argument);
}

TEST(PeselTest, PersonHasIncorrectPeselDate)
{
    Person person{"Jan", "Kowalski", "80062378532", Gender::Male};

    EXPECT_THROW(person.setPesel("95132910213", Gender::Male), std::invalid_argument);
}

TEST(PeselTest, PersonHasIncorrectPeselControlNumber)
{
    Person person{"Jan", "Kowalski", "96032931571", Gender::Male};

    EXPECT_THROW(person.setPesel("96032931572", Gender::Male), std::invalid_argument);
}

TEST(PeselTest, PersonHasIncorrectPeselGender)
{
    Person person{"Jan", "Kowalski", "86110274229", Gender::Female};

    EXPECT_THROW(person.setPesel("87071989652", Gender::Female), std::invalid_argument);
}
