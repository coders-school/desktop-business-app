#include "PersonalData.hpp"

Name PersonalData::GetName() const
{
    return name_;
}

Address PersonalData::GetAddress() const
{
    return address_;
}

std::string PersonalData::GetPesel() const
{
    return pesel_.GetPesel();
}

PhoneNumber PersonalData::GetPhoneNumber() const
{
    return phone_number_;
}

Sex PersonalData::GetSex() const
{
    return sex_;
}
