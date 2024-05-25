#pragma once

class Person
{
    Name name_;
    Address address_;
    Pesel pesel_;
    PhoneNumber phone_number_;
    Gender gender_;

  public:
    Person(const Name& name, const Address& address, const Pesel& pesel, const PhoneNumber& phone_number)
        : name_{name}, address_{address}, pesel_{pesel}, phone_number_{phone_number}, gender_{Gender::Unknown}
    {
    }
};

