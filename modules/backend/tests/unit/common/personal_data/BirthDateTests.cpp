#include "personal_data/pesel/birth_date/BirthDate.hpp"
#include <gtest/gtest.h>

namespace common
{

namespace birth_date
{

namespace tests
{

constexpr const char* kPesel{"96042982349"};
BirthDate birth_date{kPesel};

TEST(BirthDateTests, GivenBirthDateWithPeselThenReturnBirthDay)
{
    const std::string expected_day{"29"};

    EXPECT_EQ(expected_day, birth_date.getDay());
}

TEST(BirthDateTests, GivenBirthDateWithPeselThenReturnBirthMonth)
{
    const std::string expected_month{"04"};

    EXPECT_EQ(expected_month, birth_date.getMonth());
}

TEST(BirthDateTests, GivenBirthDateWithPeselThenReturnBirthYear)
{
    const std::string expected_year{"1996"};

    EXPECT_EQ(expected_year, birth_date.getYear());
}

TEST(BirthDateTests, GivenBirthDateWithPeselThenReturnCompleteBirthDate)
{
    const std::string expected_date{"29-04-1996"};

    EXPECT_EQ(expected_date, birth_date.getCompleteDate());
}

} // namespace tests
} // namespace birth_date
} // namespace common