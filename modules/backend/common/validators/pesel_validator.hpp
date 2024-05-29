#pragma once

#include "modules/backend/common/enumerations/gender.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

constexpr int cPeselSize = 11;

class PeselValidator
{
  public:
    /**
     * @brief Validates a PESEL number.
     *
     * This function validates a PESEL number by checking its size, date, and control number.
     * If any of these checks fail, an exception is thrown.
     *
     * @param pesel The PESEL number to validate.
     *
     * @throws std::invalid_argument If the PESEL number is invalid.
     *
     * @return The validated PESEL number.
     */
    std::string Validate(const std::string& pesel) const
    {
        if (!(IsSizeValid(pesel) && IsDateValid(pesel) && IsControlNumberValid(pesel)))
        {
            throw std::invalid_argument("Invalid PESEL number");
        }
        return pesel;
    }

  private:
    /**
     * @brief Checks if the size of the given PESEL is valid.
     *
     * @param pesel The PESEL to be checked.
     * @return true if the size is valid, false otherwise.
     */
    bool IsSizeValid(const std::string& pesel) const
    {
        return (pesel.size() == cPeselSize) ? true : false;
    }

    /**
     * @brief Checks if the date extracted from the given PESEL number is valid.
     *
     * This function extracts the month and day from the given PESEL number and checks if the date is valid.
     * The month and day are extracted from specific positions in the PESEL number.
     *
     * @param pesel The PESEL number from which the date is extracted.
     * @return true if the date is valid, false otherwise.
     */
    bool IsDateValid(const std::string& pesel) const
    {
        std::string month = pesel.substr(2, 2);
        std::string day = pesel.substr(4, 2);

        return IsMonthInRange(month) && (IsDayInFebruaryValid(month, day) || IsDayInThirtyDaysMonthValid(month, day) ||
                                         IsThirtyOneDaysMonthValid(month, day));
    }

    /**
     * Validates the control number of the PESEL.
     *
     * @param pesel The PESEL number.
     * @return True if the control number is valid, false otherwise.
     */
    bool IsControlNumberValid(const std::string& pesel) const
    {
        std::vector<int> weights{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

        std::transform(begin(weights), end(weights), begin(pesel), begin(weights),
                       [](auto weight, const auto pesel_number) { return weight * (pesel_number - '0'); });

        const int control_number = 10 - (std::accumulate(begin(weights), end(weights), 0) % 10);

        return control_number != (pesel.back() - '0') ? false : true;
    }

    bool IsMonthInRange(const std::string& month) const
    {
        return (std::stoi(month) >= 1 && std::stoi(month) <= 12) ? true : false;
    }

    bool IsDayInFebruaryValid(const std::string& month, const std::string& day) const
    {
        IsFebruary(month) && IsDayInRangeInFebruary(day);
    }

    bool IsFebruary(const std::string& month) const
    {
        return std::stoi(month) == 2 ? true : false;
    }

    bool IsDayInRangeInFebruary(const std::string& day) const
    {
        return (std::stoi(day) >= 1 && std::stoi(day) <= 29) ? true : false;
    }

    bool IsDayInThirtyDaysMonthValid(const std::string& month, const std::string& day) const
    {
        return IsThirtyDaysMonth(month) && IsDayInRangeInThirtyDaysMonth(day);
    }

    bool IsThirtyDaysMonth(const std::string& month) const
    {
        return (std::stoi(month) == 4 or std::stoi(month) == 6 or std::stoi(month) == 9 or std::stoi(month) == 11)
                   ? true
                   : false;
    }

    bool IsDayInRangeInThirtyDaysMonth(const std::string& day) const
    {
        return (std::stoi(day) >= 1 && std::stoi(day) <= 30) ? true : false;
    }

    bool IsThirtyOneDaysMonthValid(const std::string& month, const std::string& day) const
    {
        return IsThirtyOneDaysMonth(month) && IsDayInRangeInThirtyOneDaysMonth(day);
    }

    bool IsThirtyOneDaysMonth(const std::string& month) const
    {
        return (std::stoi(month) == 1 or std::stoi(month) == 3 or std::stoi(month) == 5 or std::stoi(month) == 7 or
                std::stoi(month) == 8 or std::stoi(month) == 10 or std::stoi(month) == 12)
                   ? true
                   : false;
    }

    bool IsDayInRangeInThirtyOneDaysMonth(const std::string& day) const
    {
        return (std::stoi(day) >= 1 && std::stoi(day) <= 31) ? true : false;
    }
};
