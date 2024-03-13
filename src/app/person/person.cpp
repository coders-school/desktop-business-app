#include "person.hpp"

Person::Person(std::string firstName, std::string lastName, std::string pesel)
{
    setFirstName(firstName);
    setLastName(lastName);
    setPesel(pesel);
}

Person::~Person()
{
}

void Person::setFirstName(std::string firstName)
{
    firstName_ = firstName;
}

std::string Person::getFirstName()
{
    return firstName_;
}

void Person::setLastName(std::string lastName)
{
    lastName_ = lastName;
}

std::string Person::getLastName()
{
    return lastName_;
}

void Person::setPesel(std::string pesel)
{
    // TODO Validation
    pesel_ = pesel;
}

std::string Person::getPesel()
{
    return pesel_;
}
