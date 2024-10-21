#pragma once

#include "iReceptionist.hpp"
#include "personal_data/PersonalData.hpp"

namespace clinic
{
namespace staff
{
namespace receptionist
{

class Receptionist : public iReceptionist
{
  private:
    common::PersonalData personal_data_;

  public:
    explicit Receptionist(const common::PersonalData& personal_data);

    common::PersonalData GetPersonalData() const override;
};

} // namespace receptionist
} // namespace staff
} // namespace clinic