#include "SerializerHelperFixture.hpp"
#include <gtest/gtest.h>

namespace
{

TEST_F(SerialzierHelperFixture, GivenSpecializationStateWhenSerializeCalledExpectProtoSpecialization)
{
    const auto specialization = PrepareSpecialization();

    auto proto_specialization = ::serde::serializeSpecialization(specialization);

    EXPECT_EQ(proto_specialization, ::proto_common::Specialization::DENTIST);
}

TEST_F(SerialzierHelperFixture, GivenProtoSpecializationWhenDeserializeCalledExpectSpecializationState)
{
    const auto proto_specialization = ::proto_common::Specialization::DENTIST;

    auto specialization = ::serde::deserializeSpecialization(proto_specialization);

    EXPECT_EQ(specialization, PrepareSpecialization());
}

TEST_F(SerialzierHelperFixture, GivenAddressWhenSerializeCalledExpectProtoAddress)
{
    const auto address = PrepareAddress();
    ProtoAddress proto_address{};

    ::serde::serializeAddress(&proto_address, address);

    ExpectProtoAddress(proto_address);
}

TEST_F(SerialzierHelperFixture, GivenProtoAddressWhenDeserializeCalledExpectAddress)
{
    const auto proto_address = PrepareProtoAddress();

    auto address = ::serde::deserializeAddress(proto_address);

    ExpectAddress(address);
}

TEST_F(SerialzierHelperFixture, GivenPhoneNumberWhenSerializeCalledExpectProtoPhoneNumber)
{
    const auto phone_number = PreparePhoneNumber();
    ProtoPhoneNumber proto_phone_number{};

    ::serde::serializePhoneNumber(&proto_phone_number, phone_number);

    ExpectProtoPhoneNumber(proto_phone_number);
}

TEST_F(SerialzierHelperFixture, GivenProtoPhoneNumberWhenDeserializeCalledExpectPhoneNumber)
{
    const auto proto_phone_number = PrepareProtoPhoneNumber();

    auto phone_number = ::serde::deserializePhoneNumber(proto_phone_number);

    ExpectPhoneNumber(phone_number);
}

TEST_F(SerialzierHelperFixture, GivenNameWhenSerializeCalledExpectProtoName)
{
    const auto name = PrepareName();
    ProtoName proto_name{};

    ::serde::serializeName(&proto_name, name);

    ExpectProtoName(proto_name);
}

TEST_F(SerialzierHelperFixture, GivenProtoNameWhenDeserializeCalledExpectName)
{
    const auto proto_name = PrepareProtoName();

    auto name = ::serde::deserializeName(proto_name);

    ExpectName(name);
}
TEST_F(SerialzierHelperFixture, GivenPersonalDataWhenSerializeCalledExpectProtoPersonalData)
{
    const auto personal_data = PreparePersonalData();
    auto proto_personal_data = ::proto_common::PersonalData{};

    ::serde::serializePersonalData(&proto_personal_data, personal_data);

    ExpectProtoPersonalData(proto_personal_data);
}

TEST_F(SerialzierHelperFixture, GivenProtoPersonalDataWhenDeserializeCalledExpectPersonalData)
{
    const auto proto_personal_data = PrepareProtoPersonalData();

    auto personal_data = ::serde::deserializePersonalData(proto_personal_data);

    ExpectPersonalData(personal_data);
}

TEST_F(SerialzierHelperFixture, GivenDoctorWhenSerializeCalledExpectProtoDoctor)
{
    const auto doctor = PrepareDoctor();
    ProtoDoctor proto_doctor{};

    ::serde::serializeDoctor(doctor, &proto_doctor);

    ExpectProtoDoctor(proto_doctor);
}

TEST_F(SerialzierHelperFixture, GivenProtoDoctorWhenDeserializeCalledExpectDoctor)
{
    const auto proto_doctor = PrepareProtoDoctor();

    auto doctor = ::serde::deserializeDoctor(proto_doctor);

    ExpectDoctor(doctor);
}

} // namespace
