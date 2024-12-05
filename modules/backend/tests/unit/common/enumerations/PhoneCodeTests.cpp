#include "enumerations/phone_code/PhoneCode.hpp"
#include <gtest/gtest.h>

namespace common
{

namespace phone_code
{

namespace tests
{

TEST(PhoneCodeTest, GivenPhoneCodeWhenToStringCalledThenReturnCorrectString)
{
    const auto phone_code = PhoneCode::France;
    const auto expected_output = "France";
    const auto output = toString(phone_code);

    EXPECT_EQ(output, expected_output);
}

TEST(PhoneCodeTest, GivenInvalidPhoneCodeWhenToStringCalledThenReturnUnknown)
{
    const auto phone_code = static_cast<PhoneCode>(600);
    const auto expected_output = "Unknown";
    const auto output = toString(phone_code);

    EXPECT_EQ(output, expected_output);
}

TEST(PhoneCodeTest, GivenPhoneCodeStringWhenToEnumCalledThenReturnCorrectPhoneCode)
{
    const auto phone_code = "France";
    const auto expected_output = PhoneCode::France;
    const auto output = toEnum(phone_code);

    EXPECT_EQ(output, expected_output);
}

TEST(PhoneCodeTest, GivenInvalidPhoneCodeStringWhenToEnumCalledThenReturnUnknown)
{
    const auto phone_code = "Invalid";
    const auto expected_output = PhoneCode::Unknown;
    const auto output = toEnum(phone_code);

    EXPECT_EQ(output, expected_output);
}

TEST(PhoneCodeTest, GivenPhoneCodeWhenGetPhoneCodeIndexCalledThenReturnCorrectString)
{
    const auto phone_code = PhoneCode::France;
    const auto expected_output = "+33";
    const auto output = getPhoneCodeIndex(phone_code);

    EXPECT_EQ(output, expected_output);
}

TEST(PhoneCodeTest, WhenGetPhoneCodeIndexCalledWithDefaultParameterThenReturnCorrectString)
{
    const auto expected_output = "+48";
    const auto output = getPhoneCodeIndex();

    EXPECT_EQ(output, expected_output);
}

} // namespace tests
} // namespace phone_code
} // namespace common
