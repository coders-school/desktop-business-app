#include "person.hpp"

Person::Person(std::string first_name, std::string last_name, std::string pesel)
    : name_{first_name}, surname_{last_name}
{
    setPesel(pesel);
}

Person::~Person()
{
}

void Person::setName(const std::string& first_name)
{
    name_ = first_name;
}

std::string Person::getName() const
{
    return name_;
}

void Person::setSurname(const std::string& last_name)
{
    surname_ = last_name;
}

std::string Person::getSurname() const
{
    return surname_;
}

void Person::setPesel(const std::string& pesel)
{
    // TODO Validation
    pesel_ = pesel;
}

std::string Person::getPesel() const
{
    return pesel_;
}
