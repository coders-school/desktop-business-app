#include "PeselValidator.hpp"

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>

namespace common
{

namespace
{
constexpr int cPeselSize = 11;
}

namespace validators
{

std::string PeselValidator::Validate(const std::string& pesel) const
{
    if (!(IsSizeValid(pesel) && IsDateValid(pesel) && IsControlNumberValid(pesel)))
    {
        throw std::invalid_argument("Invalid PESEL number");
    }
    return pesel;
}

/**
 * @brief Checks if the size of the given PESEL is valid.
 *
 * @param pesel The PESEL to be checked.
 * @return true if the size is valid, false otherwise.
 */
bool PeselValidator::IsSizeValid(const std::string& pesel) const
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
bool PeselValidator::IsDateValid(const std::string& pesel) const
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
bool PeselValidator::IsControlNumberValid(const std::string& pesel) const
{
    std::vector<int> weights{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

    std::transform(begin(weights), end(weights), begin(pesel), begin(weights),
                   [](auto weight, const auto pesel_number) { return weight * (pesel_number - '0'); });

    const int control_number = 10 - (std::accumulate(begin(weights), end(weights), 0) % 10);

    return control_number != (pesel.back() - '0') ? false : true;
}

bool PeselValidator::IsMonthInRange(const std::string& month) const
{
    return (std::stoi(month) >= 1 && std::stoi(month) <= 12) ? true : false;
}

bool PeselValidator::IsDayInFebruaryValid(const std::string& month, const std::string& day) const
{
    return IsFebruary(month) && IsDayInRangeInFebruary(day);
}

bool PeselValidator::IsFebruary(const std::string& month) const
{
    return std::stoi(month) == 2 ? true : false;
}

bool PeselValidator::IsDayInRangeInFebruary(const std::string& day) const
{
    return (std::stoi(day) >= 1 && std::stoi(day) <= 29) ? true : false;
}

bool PeselValidator::IsDayInThirtyDaysMonthValid(const std::string& month, const std::string& day) const
{
    return IsThirtyDaysMonth(month) && IsDayInRangeInThirtyDaysMonth(day);
}

bool PeselValidator::IsThirtyDaysMonth(const std::string& month) const
{
    return (std::stoi(month) == 4 or std::stoi(month) == 6 or std::stoi(month) == 9 or std::stoi(month) == 11) ? true
                                                                                                               : false;
}

bool PeselValidator::IsDayInRangeInThirtyDaysMonth(const std::string& day) const
{
    return (std::stoi(day) >= 1 && std::stoi(day) <= 30) ? true : false;
}

bool PeselValidator::IsThirtyOneDaysMonthValid(const std::string& month, const std::string& day) const
{
    return IsThirtyOneDaysMonth(month) && IsDayInRangeInThirtyOneDaysMonth(day);
}

bool PeselValidator::IsThirtyOneDaysMonth(const std::string& month) const
{
    return (std::stoi(month) == 1 or std::stoi(month) == 3 or std::stoi(month) == 5 or std::stoi(month) == 7 or
            std::stoi(month) == 8 or std::stoi(month) == 10 or std::stoi(month) == 12)
               ? true
               : false;
}

bool PeselValidator::IsDayInRangeInThirtyOneDaysMonth(const std::string& day) const
{
    return (std::stoi(day) >= 1 && std::stoi(day) <= 31) ? true : false;
}

} // namespace validators
} // namespace common
