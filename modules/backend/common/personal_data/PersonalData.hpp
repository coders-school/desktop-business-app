#pragma once

#include "modules/backend/common/enumerations/Sex.hpp"
#include "modules/backend/common/personal_data/address/Address.hpp"
#include "modules/backend/common/personal_data/name/Name.hpp"
#include "modules/backend/common/personal_data/pesel/Pesel.hpp"
#include "modules/backend/common/personal_data/phone_number/PhoneNumber.hpp"

namespace common
{
namespace personal_data
{

class PersonalData
{
    Name name_;
    Address address_;
    Pesel pesel_;
    PhoneNumber phone_number_;
    Sex sex_;

  public:
    PersonalData(const Name& name, const Address& address, const Pesel& pesel, const PhoneNumber& phone_number)
        : name_{name}, address_{address}, pesel_{pesel}, phone_number_{phone_number}, sex_{pesel_.GetSex()}
    {
    }

    Address GetAddress() const;
    Name GetName() const;
    std::string GetPesel() const;
    PhoneNumber GetPhoneNumber() const;
    Sex GetSex() const;
};

} // namespace personal_data
} // namespace common
