#include "person.hpp"

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
    // TODO Validation
    pesel_ = pesel;
}

std::string Person::getPesel() const
{
    return pesel_;
}
