#include "PersonalData.hpp"

namespace common
{

PersonalData::PersonalData(const Name& name, const Address& address, const Pesel& pesel,
                           const PhoneNumber& phone_number)
    : name_{name}, address_{address}, pesel_{pesel}, phone_number_{phone_number}, sex_{pesel_.getSex()}
{
}

Name PersonalData::getName() const
{
    return name_;
}

Address PersonalData::getAddress() const
{
    return address_;
}

std::string PersonalData::getPesel() const
{
    return pesel_.getPesel();
}

PhoneNumber PersonalData::getPhoneNumber() const
{
    return phone_number_;
}

Sex PersonalData::getSex() const
{
    return sex_;
}

} // namespace common
