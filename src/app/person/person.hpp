#pragma once

#include "gender.hpp"
#include <memory>
#include <string>

struct Address
{
    std::string city_;
    std::string country_;
    std::string province_;
    std::string street_;
    std::string zip_code_;
};

class Person
{
    std::string name_;
    std::string surname_;
    std::string pesel_;
    Gender gender_;
    std::string phone_number_;
    Address address_;

    bool hasValidSize(const std::string& PESEL) const;
    bool hasValidDate(const std::string& PESEL) const;
    bool hasValidControlNumber(const std::string& PESEL) const;
    bool hasValidGender(const std::string& pesel, const Gender gender) const;
    bool validatePesel(const std::string& PESEL, const Gender gender) const;

  public:
    Person(const std::string& name, const std::string& surname, const std::string& pesel, const Gender& gender);
    virtual ~Person();
    void setName(const std::string& name);
    std::string getName() const;
    void setSurname(const std::string& surname);
    std::string getSurname() const;
    void setPesel(const std::string& pesel, const Gender gender);
    std::string getPesel() const;
    bool validatePesel(const std::string& PESEL) const;
    void setAddress(const Address& address);
    Address getAddress() const;
    void setPhoneNumber(const std::string& phone_number);
    std::string getPhoneNumber() const;
};
