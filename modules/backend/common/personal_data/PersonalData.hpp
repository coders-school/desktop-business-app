#pragma once

#include "address/Address.hpp"
#include "enumerations/sex/Sex.hpp"
#include "name/Name.hpp"
#include "pesel/Pesel.hpp"
#include "phone_number/PhoneNumber.hpp"

namespace common
{

class PersonalData
{
    using Sex = sex::Sex;

  public:
    PersonalData(const Name& name, const Address& address, const Pesel& pesel, const PhoneNumber& phone_number);

    Address getAddress() const;
    Name getName() const;
    std::string getPesel() const;
    PhoneNumber getPhoneNumber() const;
    Sex getSex() const;

  private:
    Name name_;
    Address address_;
    Pesel pesel_;
    PhoneNumber phone_number_;
    Sex sex_;
};

} // namespace common
