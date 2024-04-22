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
    pesel_ = pesel;
}

std::string Person::getPesel() const
{
    return pesel_;
}

bool Person::validatePesel(const std::string& pesel) const
{
    if (not validatePeselSize(pesel) or not validatePeselDate(pesel) or not validateControlNumber(pesel))
    {
        return false;
    }
    return true;
}

bool Person::validatePeselSize(const std::string& pesel) const
{
    if (pesel.size() != 11)
    {
        return false;
    }
    return true;
}

bool Person::validatePeselDate(const std::string& pesel) const
{
    std::string Month = pesel.substr(2, 2);
    std::string Day = pesel.substr(4, 2);

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

bool Person::validateControlNumber(const std::string& pesel) const
{
    std::vector<int> weights{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::transform(begin(weights), end(weights), begin(pesel), begin(weights),
                   [](auto weight, auto peselNumber) { return weight * (peselNumber - '0'); });
    std::string tempStr = std::to_string(std::accumulate(begin(weights), end(weights), 0));
    int controlNumber = 10 - (tempStr.back() - '0');
    if (controlNumber == 10)
    {
        controlNumber = 0;
    }

    if (controlNumber != (pesel.back() - '0'))
    {
        return false;
    }
    return true;
}
