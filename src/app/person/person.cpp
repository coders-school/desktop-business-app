#include "person.hpp"

Person::Person(std::string first_name, std::string last_name, std::string pesel)
    : first_name_{first_name}, last_name_{last_name}
{
    setPesel(pesel);
}

Person::~Person()
{
}

void Person::setFirstName(const std::string& first_name)
{
    first_name_ = first_name;
}

std::string Person::getFirstName() const
{
    return first_name_;
}

void Person::setLastName(const std::string& last_name)
{
    last_name_ = last_name;
}

std::string Person::getLastName() const
{
    return last_name_;
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
