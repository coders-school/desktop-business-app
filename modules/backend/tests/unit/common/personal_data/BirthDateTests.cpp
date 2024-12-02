#include "personal_data/pesel/birth_date/BirthDate.hpp"
#include <gtest/gtest.h>

namespace common
{

namespace birth_date
{

namespace tests
{

TEST(BirthDateTests, GivenBirthDateWithPeselThenReturnBirthDate)
{
    const std::string pesel{"96042982349"};
    BirthDate birth_date{pesel};

    EXPECT_EQ("29", birth_date.getDay());
}

TEST(BirthDateTests, GivenBirthDateWithPeselThenReturnBirthMonth)
{
    const std::string pesel{"06280935775"};
    BirthDate birth_date{pesel};

    EXPECT_EQ("08", birth_date.getMonth());
}

TEST(BirthDateTests, GivenBirthDateWithPeselThenReturnBirthYear)
{
    const std::string pesel{"92042692725"};
    BirthDate birth_date{pesel};

    EXPECT_EQ("1992", birth_date.getYear());
}

TEST(BirthDateTests, GivenBirthDateWithPeselThenReturnCompleteBirthDate)
{
    const std::string pesel{"68072753774"};
    BirthDate birth_date{pesel};

    EXPECT_EQ("27-07-1968", birth_date.getCompleteDate());
}

} // namespace tests
} // namespace birth_date
} // namespace common