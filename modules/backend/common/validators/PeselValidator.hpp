#pragma once

#include <string>

namespace common
{

namespace validators
{

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
    std::string Validate(const std::string& pesel) const;

  private:
    bool IsSizeValid(const std::string& pesel) const;
    bool IsDateValid(const std::string& pesel) const;
    bool IsControlNumberValid(const std::string& pesel) const;
    bool IsMonthInRange(const std::string& month) const;
    bool IsDayInFebruaryValid(const std::string& month, const std::string& day) const;
    bool IsFebruary(const std::string& month) const;
    bool IsDayInRangeInFebruary(const std::string& day) const;
    bool IsDayInThirtyDaysMonthValid(const std::string& month, const std::string& day) const;
    bool IsThirtyDaysMonth(const std::string& month) const;
    bool IsDayInRangeInThirtyDaysMonth(const std::string& day) const;
    bool IsThirtyOneDaysMonthValid(const std::string& month, const std::string& day) const;
    bool IsThirtyOneDaysMonth(const std::string& month) const;
    bool IsDayInRangeInThirtyOneDaysMonth(const std::string& day) const;
};

} // namespace validators
} // namespace common
