#include "Patient.hpp"

namespace patient
{

Patient::Patient()
    : personal_data_{common::PersonalData{common::Name{}, common::Address{}, common::Pesel{""}, common::PhoneNumber{}}},
      payments_{Payments{}}, allergens_{Allergens{}}, treatments_{Treatments{}}
{
}

common::Pesel Patient::getPesel()
{
    return personal_data_.getPesel();
}
} // namespace patient
