#pragma once

#include "modules/backend/common/enumerations/Sex.hpp"
#include "modules/backend/common/personal_data/address/Address.hpp"
#include "modules/backend/common/personal_data/name/Name.hpp"
#include "modules/backend/common/personal_data/pesel/Pesel.hpp"
#include "modules/backend/common/personal_data/phone_number/PhoneNumber.hpp"

class PersonalData
{
    Name name_;
    Address address_;
    Pesel pesel_;
    PhoneNumber phone_number_;
    Gender gender_;

  public:
    PersonalData(const Name& name, const Address& address, const Pesel& pesel, const PhoneNumber& phone_number)
        : name_{name}, address_{address}, pesel_{pesel}, phone_number_{phone_number}, gender_{pesel_.GetGender()}
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

    std::string GetPesel() const
    {
        return pesel_.GetPesel();
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
