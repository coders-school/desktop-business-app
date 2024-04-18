#include "person.hpp"
#include <algorithm>
#include <numeric>
#include <vector>

Person::Person(const std::string& name, const std::string& surname, const std::string& pesel)
    : name_{name}, surname_{surname}
{
    setPesel(pesel);
}

Person::~Person()
{
}

void Person::setName(const std::string& name)
{
    name_ = name;
}

std::string Person::getName() const
{
    return name_;
}

void Person::setSurname(const std::string& surname)
{
    surname_ = surname;
}

std::string Person::getSurname() const
{
    return surname_;
}

void Person::setPesel(const std::string& pesel)
{
    if (validatePESEL(pesel))
    {
        pesel_ = pesel;
    }
    // TODO: Else what?
}

std::string Person::getPesel() const
{
    return pesel_;
}

bool Person::validatePESEL(const std::string& PESEL) const
{
    if (not validatePESELSize(PESEL) or not validatePESELDate(PESEL) or not validateControlNumber(PESEL))
    {
        return false;
    }
    return true;
}

bool Person::validatePESELSize(const std::string& PESEL) const
{
    if (PESEL.size() != 11)
    {
        return false;
    }
    return true;
}

bool Person::validatePESELDate(const std::string& PESEL) const
{
    std::string Month = PESEL.substr(2, 2);
    std::string Day = PESEL.substr(4, 2);

    if (std::stoi(Month) < 1 and std::stoi(Month) > 12)
    {
        return false;
    }
    if (std::stoi(Month) == 2 and (std::stoi(Day) < 1 or std::stoi(Day) > 29))
    {
        return false;
    }
    if ((std::stoi(Month) == 4 or std::stoi(Month) == 6 or std::stoi(Month) == 9 or std::stoi(Month) == 11) and
        (std::stoi(Day) < 1 or std::stoi(Day) > 30))
    {
        return false;
    }
    if ((std::stoi(Month) == 1 or std::stoi(Month) == 3 or std::stoi(Month) == 5 or std::stoi(Month) == 7 or
         std::stoi(Month) == 8 or std::stoi(Month) == 10 or std::stoi(Month) == 12) and
        (std::stoi(Day) < 1 and std::stoi(Day) > 31))
    {
        return false;
    }
    return true;
}

bool Person::validateControlNumber(const std::string& PESEL) const
{
    std::vector<int> weights{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::transform(begin(weights), end(weights), begin(PESEL), begin(weights),
                   [](auto weight, auto PESELNumber) { return weight * (PESELNumber - '0'); });
    std::string tempStr = std::to_string(std::accumulate(begin(weights), end(weights), 0));
    int controlNumber = 10 - (tempStr.back() - '0');
    if (controlNumber == 10)
    {
        controlNumber = 0;
    }

    if (controlNumber != (PESEL.back() - '0'))
    {
        return false;
    }
    return true;
}
