#include "SerializerHelperFixture.hpp"
#include <gtest/gtest.h>

namespace
{

TEST_F(SerialzierHelperFixture, GivenSpecializationStateWhenSerializeCalledExpectProtoSpecialization)
{
    auto specialization = PrepareSpecialization();
    auto proto_specialization = ::serde::serializeSpecialization(specialization);
    EXPECT_EQ(proto_specialization, ::proto_common::Specialization::DENTIST);
}

TEST_F(SerialzierHelperFixture, GivenProtoSpecializationWhenDeserializeCalledExpectSpecializationState)
{
    auto proto_specialization = ::proto_common::Specialization::DENTIST;
    auto specialization = ::serde::deserializeSpecialization(proto_specialization);
    EXPECT_EQ(specialization, PrepareSpecialization());
}

TEST_F(SerialzierHelperFixture, GivenAddressWhenSerializeCalledExpectProtoAddress)
{
    auto address = PrepareAddress();
    ProtoAddress proto_address{};
    ::serde::serializeAddress(&proto_address, address);
    EXPECT_EQ(proto_address.city(), "city");
    EXPECT_EQ(proto_address.country(), "country");
    EXPECT_EQ(proto_address.province(), "province");
    EXPECT_EQ(proto_address.street(), "street");
    EXPECT_EQ(proto_address.zip_code(), "zip_code");
}

TEST_F(SerialzierHelperFixture, GivenProtoAddressWhenDeserializeCalledExpectAddress)
{
    auto proto_address = PrepareProtoAddress();
    auto address = ::serde::deserializeAddress(proto_address);
    EXPECT_EQ(address.city_, "city");
    EXPECT_EQ(address.country_, "country");
    EXPECT_EQ(address.province_, "province");
    EXPECT_EQ(address.street_, "street");
    EXPECT_EQ(address.zip_code_, "zip_code");
}

TEST_F(SerialzierHelperFixture, GivenPhoneNumberWhenSerializeCalledExpectProtoPhoneNumber)
{
    auto phone_number = PreparePhoneNumber();
    ProtoPhoneNumber proto_phone_number{};
    ::serde::serializePhoneNumber(&proto_phone_number, phone_number);
    EXPECT_EQ(proto_phone_number.cellphone_code_(), "cellphone_code");
    EXPECT_EQ(proto_phone_number.cellphone_number_(), "cellphone_number");
    EXPECT_EQ(proto_phone_number.home_number_code_(), "home_number_code");
    EXPECT_EQ(proto_phone_number.home_number_(), "home_number");
}

TEST_F(SerialzierHelperFixture, GivenProtoPhoneNumberWhenDeserializeCalledExpectPhoneNumber)
{
    auto proto_phone_number = PrepareProtoPhoneNumber();
    auto phone_number = ::serde::deserializePhoneNumber(proto_phone_number);
    EXPECT_EQ(phone_number.cellphone_code_, "cellphone_code");
    EXPECT_EQ(phone_number.cellphone_number_, "cellphone_number");
    EXPECT_EQ(phone_number.home_number_code_, "home_number_code");
    EXPECT_EQ(phone_number.home_number_, "home_number");
}

TEST_F(SerialzierHelperFixture, GivenNameWhenSerializeCalledExpectProtoName)
{
    auto name = PrepareName();
    ProtoName proto_name{};
    ::serde::serializeName(&proto_name, name);
    EXPECT_EQ(proto_name.first_name(), "first_name");
    EXPECT_EQ(proto_name.second_name(), "second_name");
    EXPECT_EQ(proto_name.last_name(), "last_name");
}

TEST_F(SerialzierHelperFixture, GivenProtoNameWhenDeserializeCalledExpectName)
{
    auto proto_name = PrepareProtoName();
    auto name = ::serde::deserializeName(proto_name);
    EXPECT_EQ(name.first_name_, "first_name");
    EXPECT_EQ(name.second_name_, "second_name");
    EXPECT_EQ(name.last_name_, "last_name");
}

TEST_F(SerialzierHelperFixture, GivenPersonalDataWhenSerializeCalledExpectProtoPersonalData)
{
    auto personal_data = PreparePersonalData();
    auto proto_personal_data = ::proto_common::PersonalData{};
    ::serde::serializePersonalData(&proto_personal_data, personal_data);
    EXPECT_EQ(proto_personal_data.name().first_name(), "first_name");
    EXPECT_EQ(proto_personal_data.name().second_name(), "second_name");
    EXPECT_EQ(proto_personal_data.name().last_name(), "last_name");
    EXPECT_EQ(proto_personal_data.address().city(), "city");
    EXPECT_EQ(proto_personal_data.address().country(), "country");
    EXPECT_EQ(proto_personal_data.address().province(), "province");
    EXPECT_EQ(proto_personal_data.address().street(), "street");
    EXPECT_EQ(proto_personal_data.address().zip_code(), "zip_code");
    EXPECT_EQ(proto_personal_data.pesel().pesel(), "80062378532");
    EXPECT_EQ(proto_personal_data.phone_numbers().cellphone_code_(), "cellphone_code");
    EXPECT_EQ(proto_personal_data.phone_numbers().cellphone_number_(), "cellphone_number");
    EXPECT_EQ(proto_personal_data.phone_numbers().home_number_code_(), "home_number_code");
    EXPECT_EQ(proto_personal_data.phone_numbers().home_number_(), "home_number");
}

TEST_F(SerialzierHelperFixture, GivenProtoPersonalDataWhenDeserializeCalledExpectPersonalData)
{
    auto proto_personal_data = PrepareProtoPersonalData();
    auto personal_data = ::serde::deserializePersonalData(proto_personal_data);
    EXPECT_EQ(personal_data.getName().first_name_, "first_name");
    EXPECT_EQ(personal_data.getName().second_name_, "second_name");
    EXPECT_EQ(personal_data.getName().last_name_, "last_name");
    EXPECT_EQ(personal_data.getAddress().city_, "city");
    EXPECT_EQ(personal_data.getAddress().country_, "country");
    EXPECT_EQ(personal_data.getAddress().province_, "province");
    EXPECT_EQ(personal_data.getAddress().street_, "street");
    EXPECT_EQ(personal_data.getAddress().zip_code_, "zip_code");
    EXPECT_EQ(personal_data.getPesel(), "80062378532");
    EXPECT_EQ(personal_data.getPhoneNumber().cellphone_code_, "cellphone_code");
    EXPECT_EQ(personal_data.getPhoneNumber().cellphone_number_, "cellphone_number");
    EXPECT_EQ(personal_data.getPhoneNumber().home_number_code_, "home_number_code");
    EXPECT_EQ(personal_data.getPhoneNumber().home_number_, "home_number");
}

} // namespace
