#include "Pesel.hpp"

namespace common
{

Pesel::Pesel(const std::string& pesel) : pesel_validator_{}, pesel_{pesel_validator_.Validate(pesel)}
{
}

std::string Pesel::getPesel() const
{
    return pesel_;
}

Sex Pesel::getSex() const
{
    return (((pesel_[9] - '0') % 2) == 0) ? Sex::Female : Sex::Male;
}

} // namespace common
