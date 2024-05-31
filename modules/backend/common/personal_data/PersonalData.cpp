#include "PersonalData.hpp"

namespace common
{
namespace personal_data
{

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

} // namespace personal_data
} // namespace common
