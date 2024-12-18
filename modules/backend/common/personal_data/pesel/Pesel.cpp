#include "Pesel.hpp"

namespace common
{

Pesel::Pesel(const std::string& pesel)
    : pesel_validator_{}, pesel_{pesel_validator_.Validate(pesel)}, birth_date_{pesel}
{
}

std::string Pesel::getPesel() const
{
    return pesel_;
}

sex::Sex Pesel::getSex() const
{
    return (((pesel_[9] - '0') % 2) == 0) ? sex::Sex::Female : sex::Sex::Male;
}

birth_date::BirthDate Pesel::getBirthDate() const
{
    return birth_date_;
}

} // namespace common
