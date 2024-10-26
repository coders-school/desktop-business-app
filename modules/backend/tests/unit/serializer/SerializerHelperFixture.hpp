#pragma once
#include "SerializerHelper.hpp"
#include "SerializerHelperTestData.hpp"
#include <gtest/gtest.h>
#include <memory>

using Address = ::common::Address;
using Name = ::common::Name;
using PersonalData = ::common::PersonalData;
using Pesel = ::common::Pesel;
using PhoneNumber = ::common::PhoneNumber;
using Specialization = ::common::specialization::Specialization;

using ProtoAddress = ::proto_common::PersonalData_Address;
using ProtoName = ::proto_common::PersonalData_Name;
using ProtoPersonalData = ::proto_common::PersonalData;
using ProtoPesel = ::proto_common::PersonalData_Pesel;
using ProtoPhoneNumber = ::proto_common::PersonalData_PhoneNumber;
using ProtoSpecialization = ::proto_common::Specialization;

class SerialzierHelperFixture : public ::testing::Test
{
  protected:
    Address PrepareAddress()
    {
        return Address{"city", "country", "province", "street", "zip_code"};
    }

    Name PrepareName()
    {
        return Name{"first_name", "second_name", "last_name"};
    }

    PersonalData PreparePersonalData()
    {
        return PersonalData(PrepareName(), PrepareAddress(), PreparePesel(), PreparePhoneNumber());
    }

    Pesel PreparePesel()
    {
        return Pesel{"80062378532"};
    }

    PhoneNumber PreparePhoneNumber()
    {
        return PhoneNumber{"cellphone_code", "cellphone_number", "home_number_code", "home_number"};
    }

    Specialization PrepareSpecialization()
    {
        return Specialization::Dentist;
    }

    ProtoAddress PrepareProtoAddress()
    {
        auto proto_address = ProtoAddress{};
        proto_address.set_city("city");
        proto_address.set_country("country");
        proto_address.set_province("province");
        proto_address.set_street("street");
        proto_address.set_zip_code("zip_code");
        return proto_address;
    }

    ProtoName PrepareProtoName()
    {
        auto proto_name = ProtoName{};
        proto_name.set_first_name("first_name");
        proto_name.set_second_name("second_name");
        proto_name.set_last_name("last_name");
        return proto_name;
    }

    ProtoPhoneNumber PrepareProtoPhoneNumber()
    {
        auto proto_phone_number = ProtoPhoneNumber{};
        proto_phone_number.set_cellphone_code_("cellphone_code");
        proto_phone_number.set_cellphone_number_("cellphone_number");
        proto_phone_number.set_home_number_code_("home_number_code");
        proto_phone_number.set_home_number_("home_number");
        return proto_phone_number;
    }
    ProtoPesel PrepareProtoPesel()
    {
        auto proto_pesel = ProtoPesel{};
        proto_pesel.set_pesel("80062378532");
        return proto_pesel;
    }

    ProtoPersonalData PrepareProtoPersonalData()
    {
        auto proto_personal_data = ProtoPersonalData{};
        proto_personal_data.set_allocated_address(new ProtoAddress(PrepareProtoAddress()));
        proto_personal_data.set_allocated_name(new ProtoName(PrepareProtoName()));
        proto_personal_data.set_allocated_pesel(new ProtoPesel(PrepareProtoPesel()));
        proto_personal_data.set_allocated_phone_numbers(new ProtoPhoneNumber(PrepareProtoPhoneNumber()));
        return proto_personal_data;
    }
    void ExpectProtoAddress(const ProtoAddress& proto_address)
    {
        EXPECT_EQ(proto_address.city(), kCity);
        EXPECT_EQ(proto_address.country(), kCountry);
        EXPECT_EQ(proto_address.province(), kProvince);
        EXPECT_EQ(proto_address.street(), kStreet);
        EXPECT_EQ(proto_address.zip_code(), kZipCode);
    }

    void ExpectAddress(const Address& address)
    {
        EXPECT_EQ(address.city_, kCity);
        EXPECT_EQ(address.country_, kCountry);
        EXPECT_EQ(address.province_, kProvince);
        EXPECT_EQ(address.street_, kStreet);
        EXPECT_EQ(address.zip_code_, kZipCode);
    }

    void ExpectProtoPhoneNumber(const ProtoPhoneNumber& proto_phone_number)
    {
        EXPECT_EQ(proto_phone_number.cellphone_code_(), kCellphoneCode);
        EXPECT_EQ(proto_phone_number.cellphone_number_(), kCellphoneNumber);
        EXPECT_EQ(proto_phone_number.home_number_code_(), kHomeNumberCode);
        EXPECT_EQ(proto_phone_number.home_number_(), kHomeNumber);
    }

    void ExpectPhoneNumber(const PhoneNumber& phone_number)
    {
        EXPECT_EQ(phone_number.cellphone_code_, kCellphoneCode);
        EXPECT_EQ(phone_number.cellphone_number_, kCellphoneNumber);
        EXPECT_EQ(phone_number.home_number_code_, kHomeNumberCode);
        EXPECT_EQ(phone_number.home_number_, kHomeNumber);
    }

    void ExpectProtoName(const ProtoName& proto_name)
    {
        EXPECT_EQ(proto_name.first_name(), kFirstName);
        EXPECT_EQ(proto_name.second_name(), kSecondName);
        EXPECT_EQ(proto_name.last_name(), kLastName);
    }

    void ExpectName(const Name& name)
    {
        EXPECT_EQ(name.first_name_, kFirstName);
        EXPECT_EQ(name.second_name_, kSecondName);
        EXPECT_EQ(name.last_name_, kLastName);
    }

    void ExpectProtoPersonalData(const ::proto_common::PersonalData& proto_personal_data)
    {
        EXPECT_EQ(proto_personal_data.name().first_name(), kFirstName);
        EXPECT_EQ(proto_personal_data.name().second_name(), kSecondName);
        EXPECT_EQ(proto_personal_data.name().last_name(), kLastName);
        EXPECT_EQ(proto_personal_data.address().city(), kCity);
        EXPECT_EQ(proto_personal_data.address().country(), kCountry);
        EXPECT_EQ(proto_personal_data.address().province(), kProvince);
        EXPECT_EQ(proto_personal_data.address().street(), kStreet);
        EXPECT_EQ(proto_personal_data.address().zip_code(), kZipCode);
        EXPECT_EQ(proto_personal_data.pesel().pesel(), kPesel);
        EXPECT_EQ(proto_personal_data.phone_numbers().cellphone_code_(), kCellphoneCode);
        EXPECT_EQ(proto_personal_data.phone_numbers().cellphone_number_(), kCellphoneNumber);
        EXPECT_EQ(proto_personal_data.phone_numbers().home_number_code_(), kHomeNumberCode);
        EXPECT_EQ(proto_personal_data.phone_numbers().home_number_(), kHomeNumber);
    }

    void ExpectPersonalData(const PersonalData& personal_data)
    {
        EXPECT_EQ(personal_data.getName().first_name_, kFirstName);
        EXPECT_EQ(personal_data.getName().second_name_, kSecondName);
        EXPECT_EQ(personal_data.getName().last_name_, kLastName);
        EXPECT_EQ(personal_data.getAddress().city_, kCity);
        EXPECT_EQ(personal_data.getAddress().country_, kCountry);
        EXPECT_EQ(personal_data.getAddress().province_, kProvince);
        EXPECT_EQ(personal_data.getAddress().street_, kStreet);
        EXPECT_EQ(personal_data.getAddress().zip_code_, kZipCode);
        EXPECT_EQ(personal_data.getPesel(), kPesel);
        EXPECT_EQ(personal_data.getPhoneNumber().cellphone_code_, kCellphoneCode);
        EXPECT_EQ(personal_data.getPhoneNumber().cellphone_number_, kCellphoneNumber);
        EXPECT_EQ(personal_data.getPhoneNumber().home_number_code_, kHomeNumberCode);
        EXPECT_EQ(personal_data.getPhoneNumber().home_number_, kHomeNumber);
    }
};
