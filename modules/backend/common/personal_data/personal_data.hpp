#pragma once

#include "modules/backend/common/enumerations/gender.hpp"
#include "modules/backend/common/personal_data/address/address.hpp"
#include "modules/backend/common/personal_data/name/name.hpp"
#include "modules/backend/common/personal_data/pesel/pesel.hpp"
#include "modules/backend/common/personal_data/phone_number/phone_number.hpp"

class PersonalData
{
    Name name_;
    Address address_;
    Pesel pesel_;
    PhoneNumber phone_number_;
    Gender gender_;

  public:
    PersonalData(const Name& name, const Address& address, const Pesel& pesel, const PhoneNumber& phone_number)
        : name_{name}, address_{address}, pesel_{pesel}, phone_number_{phone_number}, gender_{Gender::Unknown}
    {
    }
    Name GetName() const
    {
        return name_;
    }

    Address GetAddress() const
    {
        return address_;
    }

    Pesel GetPesel() const
    {
        return pesel_;
    }

    PhoneNumber GetPhoneNumber() const
    {
        return phone_number_;
    }

    Gender GetGender() const
    {
        return gender_;
    }
};
