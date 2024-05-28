#pragma once

#include "../name/name.hpp"
#include "../address/address.hpp"
#include "../pesel/pesel.hpp"
#include "../phone_number/phone_number.hpp"
#include "../enumerations/gender.hpp"

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
    Name getName() const
    {
      return name_;
    }

    Address getAddress() const
    {
      return address_;
    }

    Pesel getPesel() const
    {
      return pesel_;
    }

    PhoneNumber getPhoneNumber() const
    {
      return phone_number_;
    }

    Gender getGender() const
    {
      return gender_;
    }
};

