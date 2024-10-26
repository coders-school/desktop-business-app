#include "SerializerHelper.hpp"
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
};
