#include "person.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>

Person::Person(const std::string& name, const std::string& surname, const std::string& pesel, const Gender gender)
    : name_{name}, surname_{surname}, gender_{gender}
{
    setPesel(pesel, gender);
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

void Person::setPesel(const std::string& pesel, const Gender gender)
{
    if (validatePesel(pesel, gender))
    {
        pesel_ = pesel;
    }
    else
        throw std::invalid_argument{"Invalid pesel"};
}

std::string Person::getPesel() const
{
    return pesel_;
}

std::string Person::getGender() const
{
    return toString(gender_);
}

bool Person::validatePesel(const std::string& pesel, const Gender gender) const
{
    if (not hasValidSize(pesel) or not hasValidDate(pesel) or not hasValidControlNumber(pesel) or
        not hasValidGender(pesel, gender))
    {
        return false;
    }
    return true;
}

bool Person::hasValidSize(const std::string& pesel) const
{
    if (pesel.size() != 11)
    {
        return false;
    }
    return true;
}

bool Person::hasValidDate(const std::string& pesel) const
{
    std::string Month = pesel.substr(2, 2);
    std::string Day = pesel.substr(4, 2);

    if (std::stoi(Month) < 1 or std::stoi(Month) > 12)
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

bool Person::hasValidControlNumber(const std::string& pesel) const
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

bool Person::hasValidGender(const std::string& pesel, const Gender gender) const
{
    std::string genderNumber = pesel.substr(9, 1);

    if (std::stoi(genderNumber) % 2 == 1 and gender == Gender::Male)
    {
        return true;
    }
    else if (std::stoi(genderNumber) % 2 == 0 and gender == Gender::Female)
    {
        return true;
    }
    return false;
}

void Person::setAddress(const Address& address)
{
    // TODO some data could be validated ex. zip-code format
    address_.city_ = address.city_;
    address_.country_ = address.country_;
    address_.province_ = address.province_;
    address_.street_ = address.street_;
    address_.zip_code_ = address.zip_code_;
}

Address Person::getAddress() const
{
    return address_;
}

void Person::setPhoneNumber(const std::string& phone_number)
{
    // TODO Validate phone number
    phone_number_ = phone_number;
}

std::string Person::getPhoneNumber() const
{
    return phone_number_;
}
