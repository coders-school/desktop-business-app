#pragma once

#include "clinic/staff/Staff.hpp"
#include <staff.pb.h>

namespace serde
{

void serializeStaff(const ::clinic::staff::Staff& staff, ::proto_staff::Staff* proto_staff)
{
    for (const auto& doctor : staff.getDoctors())
    {
        serializeDoctor(doctor, proto_staff->add_doctor());
    }
}

::proto_common::Specialization serializeSpecialization(const ::common::specialization::Specialization specialization)
{
    ::proto_common::Specialization proto_specialization{::proto_common::Specialization::UNKNOWN};
    switch (specialization)
    {
    case ::common::specialization::Specialization::Dentist:
        proto_specialization = ::proto_common::Specialization::DENTIST;
        break;
    default:
        break;
    }
    return proto_specialization;
}

void serializeAddress(::proto_common::PersonalData_Address* address, const ::common::PersonalData& personal_data)
{
    address->set_city(personal_data.getAddress().city_);
    address->set_country(personal_data.getAddress().country_);
    address->set_province(personal_data.getAddress().province_);
    address->set_street(personal_data.getAddress().street_);
    address->set_zip_code(personal_data.getAddress().zip_code_);
}

void serializePhoneNumber(::proto_common::PersonalData_PhoneNumber* phone_number,
                          const ::common::PhoneNumber& phone_number_)
{
    phone_number->set_cellphone_code_(phone_number_.cellphone_code_);
    phone_number->set_cellphone_number_(phone_number_.cellphone_number_);
    phone_number->set_home_number_code_(phone_number_.home_number_code_);
    phone_number->set_home_number_(phone_number_.home_number_);
}

void serializeName(::proto_common::PersonalData_Name* name, const ::common::Name& name_)
{
    name->set_first_name(name_.first_name_);
    name->set_second_name(name_.second_name_);
    name->set_last_name(name_.last_name_);
}

void serializePesel(::proto_common::PersonalData_Pesel* pesel, const ::common::Pesel& pesel_)
{
    pesel->set_pesel(pesel_.getPesel());
}

void serializePersonalData(::proto_common::PersonalData* proto_personal_data,
                           const ::common::PersonalData& personal_data)
{
    serializeName(proto_personal_data->mutable_name(), personal_data.getName());
    serializeAddress(proto_personal_data->mutable_address(), personal_data);
    serializePhoneNumber(proto_personal_data->mutable_phone_numbers(), personal_data.getPhoneNumber());
    serializePesel(proto_personal_data->mutable_pesel(), personal_data.getPesel());
}

void serializeDoctor(const ::clinic::staff::doctor::Doctor& doctor, ::proto_staff::Doctor* proto_doctor)
{
    serializePersonalData(proto_doctor->mutable_personaldata(), doctor.GetPersonalData());
    proto_doctor->set_specialization(serializeSpecialization(doctor.GetSpecialization()));
}


} // namespace serde
