#pragma once

#include "personal_data/PersonalData.hpp"
#include <memory>

namespace clinic
{
namespace staff
{
namespace receptionist
{

class iReceptionist
{
  public:
    virtual ~iReceptionist() = default;
    virtual common::PersonalData GetPersonalData() const = 0;
};
using ReceptionistPtr = std::unique_ptr<iReceptionist>;

} // namespace receptionist
} // namespace staff
} // namespace clinic