#pragma once

#include "birth_date/BirthDate.hpp"
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
    sex::Sex getSex() const;
    birth_date::BirthDate getBirthDate() const;

  private:
    validators::PeselValidator pesel_validator_;
    std::string pesel_;
    birth_date::BirthDate birth_date_;
};

} // namespace common
