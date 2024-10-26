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

} // namespace
