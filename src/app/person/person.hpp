#pragma once

#include "gender.hpp"
#include <memory>
#include <string>

class Person
{
    std::string name_;
    std::string surname_;
    std::string pesel_;
    Gender gender_;

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
};
