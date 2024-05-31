#pragma once

#include "modules/backend/common/enumerations/Sex.hpp"
#include "modules/backend/common/validators/PeselValidator.hpp"
#include <string>

class Pesel
{
    PeselValidator pesel_validator_;
    std::string pesel_;

  public:
    Pesel(const std::string& pesel) : pesel_validator_{}, pesel_{pesel_validator_.Validate(pesel)}
    {
    }

    std::string GetPesel() const
    {
        return pesel_;
    }

    Sex GetGender() const
    {
        return (((pesel_[9] - '0') % 2) == 0) ? Sex::Female : Sex::Male;
    }
};
