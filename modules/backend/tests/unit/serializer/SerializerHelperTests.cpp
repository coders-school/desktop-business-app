#include "SerializerHelper.hpp"
#include <gtest/gtest.h>

namespace
{

TEST(SerializerHelperTests, GivenSpecializationStateWhenSerializeCalledExpectProtoSpecialization)
{
    auto specialization = ::common::specialization::Specialization::Dentist;
    auto proto_specialization = ::serde::serializeSpecialization(specialization);
    EXPECT_EQ(proto_specialization, ::proto_common::Specialization::DENTIST);
}

TEST(SerializerHelperTests, GivenProtoSpecializationWhenDeserializeCalledExpectSpecializationState)
{
    auto proto_specialization = ::proto_common::Specialization::DENTIST;
    auto specialization = ::serde::deserializeSpecialization(proto_specialization);
    EXPECT_EQ(specialization, ::common::specialization::Specialization::Dentist);
}

TEST(SerializerHelperTests, GivenAddressWhenSerializeCalledExpectProtoAddress)
{
    auto address = ::common::Address{"city", "country", "province", "street", "zip_code"};
    auto proto_address = ::proto_common::PersonalData_Address{};
    ::serde::serializeAddress(&proto_address, address);
    EXPECT_EQ(proto_address.city(), "city");
    EXPECT_EQ(proto_address.country(), "country");
    EXPECT_EQ(proto_address.province(), "province");
    EXPECT_EQ(proto_address.street(), "street");
    EXPECT_EQ(proto_address.zip_code(), "zip_code");
}

TEST(SerializerHelperTests, GivenProtoAddressWhenDeserializeCalledExpectAddress)
{
    auto proto_address = ::proto_common::PersonalData_Address{};
    proto_address.set_city("city");
    proto_address.set_country("country");
    proto_address.set_province("province");
    proto_address.set_street("street");
    proto_address.set_zip_code("zip_code");
    auto address = ::serde::deserializeAddress(proto_address);
    EXPECT_EQ(address.city_, "city");
    EXPECT_EQ(address.country_, "country");
    EXPECT_EQ(address.province_, "province");
    EXPECT_EQ(address.street_, "street");
    EXPECT_EQ(address.zip_code_, "zip_code");
}

TEST(SerializerHelperTests, GivenPhoneNumberWhenSerializeCalledExpectProtoPhoneNumber)
{
    auto phone_number = ::common::PhoneNumber{"cellphone_code", "cellphone_number", "home_number_code", "home_number"};
    auto proto_phone_number = ::proto_common::PersonalData_PhoneNumber{};
    ::serde::serializePhoneNumber(&proto_phone_number, phone_number);
    EXPECT_EQ(proto_phone_number.cellphone_code_(), "cellphone_code");
    EXPECT_EQ(proto_phone_number.cellphone_number_(), "cellphone_number");
    EXPECT_EQ(proto_phone_number.home_number_code_(), "home_number_code");
    EXPECT_EQ(proto_phone_number.home_number_(), "home_number");
}

TEST(SerializerHelperTests, GivenProtoPhoneNumberWhenDeserializeCalledExpectPhoneNumber)
{
    auto proto_phone_number = ::proto_common::PersonalData_PhoneNumber{};
    proto_phone_number.set_cellphone_code_("cellphone_code");
    proto_phone_number.set_cellphone_number_("cellphone_number");
    proto_phone_number.set_home_number_code_("home_number_code");
    proto_phone_number.set_home_number_("home_number");
    auto phone_number = ::serde::deserializePhoneNumber(proto_phone_number);
    EXPECT_EQ(phone_number.cellphone_code_, "cellphone_code");
    EXPECT_EQ(phone_number.cellphone_number_, "cellphone_number");
    EXPECT_EQ(phone_number.home_number_code_, "home_number_code");
    EXPECT_EQ(phone_number.home_number_, "home_number");
}

TEST(SerializerHelperTests, GivenNameWhenSerializeCalledExpectProtoName)
{
    auto name = ::common::Name{"first_name", "second_name", "last_name"};
    auto proto_name = ::proto_common::PersonalData_Name{};
    ::serde::serializeName(&proto_name, name);
    EXPECT_EQ(proto_name.first_name(), "first_name");
    EXPECT_EQ(proto_name.second_name(), "second_name");
    EXPECT_EQ(proto_name.last_name(), "last_name");
}

TEST(SerializerHelperTests, GivenProtoNameWhenDeserializeCalledExpectName)
{
    auto proto_name = ::proto_common::PersonalData_Name{};
    proto_name.set_first_name("first_name");
    proto_name.set_second_name("second_name");
    proto_name.set_last_name("last_name");
    auto name = ::serde::deserializeName(proto_name);
    EXPECT_EQ(name.first_name_, "first_name");
    EXPECT_EQ(name.second_name_, "second_name");
    EXPECT_EQ(name.last_name_, "last_name");
}

} // namespace
