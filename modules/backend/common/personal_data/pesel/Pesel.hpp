#pragma once

#include "enumerations/sex/Sex.hpp"
#include "validators/PeselValidator.hpp"

#include <string>

namespace common
{

class Pesel
{
  public:
    Pesel(const std::string& pesel);

    std::string getPesel() const;
    Sex getSex() const;

  private:
    validators::PeselValidator pesel_validator_;
    std::string pesel_;
};

} // namespace common
