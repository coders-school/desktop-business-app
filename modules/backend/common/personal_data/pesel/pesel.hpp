#pragma once

#include <string>
#include "modules/backend/common/enumerations/gender.hpp"

class Pesel
{
    std::string pesel_;
    std::string ValidatePesel(const std::string& pesel)
    {
        // move validation
        return pesel;
    }

  public:
    Pesel(const std::string& pesel) : pesel_{ValidatePesel(pesel)}
    {
    }

    std::string GetPesel()
    {
        return pesel_;
    }
    

};