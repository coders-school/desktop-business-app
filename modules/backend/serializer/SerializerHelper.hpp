#pragma once

#include <staff.pb.h>
#include "staff/Staff.hpp"

namespace serde
{
// TODO should functions be moved to separate files in targets of it's orginal type?
// TODO introduce deserialize functions

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

::common::specialization::Specialization deserializeSpecialization(const ::proto_common::Specialization specialization)
{
    ::common::specialization::Specialization specialization_{::common::specialization::Specialization::Unknown};
    switch (specialization)
    {
    case ::proto_common::Specialization::DENTIST:
        specialization_ = ::common::specialization::Specialization::Dentist;
        break;
    default:
        break;
    }
    return specialization_;
}

void serializeAddress(::proto_common::PersonalData_Address* proto_address, const ::common::Address& address)
{
    proto_address->set_city(address.city_);
    proto_address->set_country(address.country_);
    proto_address->set_province(address.province_);
    proto_address->set_street(address.street_);
    proto_address->set_zip_code(address.zip_code_);
}

::common::Address deserializeAddress(const ::proto_common::PersonalData_Address& proto_address)
{
    return {proto_address.city(), proto_address.country(), proto_address.province(), proto_address.street(),
            proto_address.zip_code()};
}

void serializePhoneNumber(::proto_common::PersonalData_PhoneNumber* phone_number,
                          const ::common::PhoneNumber& phone_number_)
{
    phone_number->set_cellphone_code_(phone_number_.cellphone_code_);
    phone_number->set_cellphone_number_(phone_number_.cellphone_number_);
    phone_number->set_home_number_code_(phone_number_.home_number_code_);
    phone_number->set_home_number_(phone_number_.home_number_);
}

::common::PhoneNumber deserializePhoneNumber(const ::proto_common::PersonalData_PhoneNumber& proto_phone_number)
{
    return {proto_phone_number.cellphone_code_(), proto_phone_number.cellphone_number_(),
            proto_phone_number.home_number_code_(), proto_phone_number.home_number_()};
}

void serializeName(::proto_common::PersonalData_Name* name, const ::common::Name& name_)
{
    name->set_first_name(name_.first_name_);
    name->set_second_name(name_.second_name_);
    name->set_last_name(name_.last_name_);
}

::common::Name deserializeName(const ::proto_common::PersonalData_Name& proto_name)
{
    return {proto_name.first_name(), proto_name.second_name(), proto_name.last_name()};
}

void serializePesel(::proto_common::PersonalData_Pesel* pesel, const ::common::Pesel& pesel_)
{
    pesel->set_pesel(pesel_.getPesel());
}

::common::Pesel deserializePesel(const ::proto_common::PersonalData_Pesel& proto_pesel)
{
    return {proto_pesel.pesel()};
}

void serializePersonalData(::proto_common::PersonalData* proto_personal_data,
                           const ::common::PersonalData& personal_data)
{
    serializeName(proto_personal_data->mutable_name(), personal_data.getName());
    serializeAddress(proto_personal_data->mutable_address(), personal_data.getAddress());
    serializePhoneNumber(proto_personal_data->mutable_phone_numbers(), personal_data.getPhoneNumber());
    serializePesel(proto_personal_data->mutable_pesel(), personal_data.getPesel());
}

::common::PersonalData deserializePersonalData(const ::proto_common::PersonalData& proto_personal_data)
{
    ::common::PersonalData personal_data{
        deserializeName(proto_personal_data.name()), deserializeAddress(proto_personal_data.address()),
        deserializePesel(proto_personal_data.pesel()), deserializePhoneNumber(proto_personal_data.phone_numbers())};
    return personal_data;
}

void serializeDoctor(const ::clinic::staff::doctor::Doctor& doctor, ::proto_staff::Doctor* proto_doctor)
{
    serializePersonalData(proto_doctor->mutable_personaldata(), doctor.GetPersonalData());
    proto_doctor->set_specialization(serializeSpecialization(doctor.GetSpecialization()));
}

::clinic::staff::doctor::Doctor deserializeDoctor(const ::proto_staff::Doctor& proto_doctor)
{
    return {deserializePersonalData(proto_doctor.personaldata()),
            deserializeSpecialization(proto_doctor.specialization())};
}

::proto_staff::Staff serializeStaff(const ::clinic::staff::Staff& staff)
{
    ::proto_staff::Staff proto_staff{};
    for (const auto& doctor : staff.getDoctors())
    {
        serializeDoctor(doctor, proto_staff.add_doctor());
    }

    return proto_staff;
}

void deserializeStaff(::clinic::staff::Staff& staff, const ::proto_staff::Staff& proto_staff)
{
    for (const auto& proto_doctor : proto_staff.doctor())
    {
        auto doctor = deserializeDoctor(proto_doctor);
        staff.addDoctor(doctor);
    }
}

} // namespace serde
