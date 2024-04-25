#pragma once

#include <memory>
#include <string>

enum class Gender
{
    Male,
    Female
};

class Person
{
    std::string name_;
    std::string surname_;
    std::string pesel_;
    Gender gender_;

    bool validatePeselSize(const std::string& PESEL) const;
    bool validatePeselDate(const std::string& PESEL) const;
    bool validateControlNumber(const std::string& PESEL) const;
    bool validateGender() const;

  public:
    Person(const std::string& name, const std::string& surname, const std::string& pesel, const Gender& gender);
    virtual ~Person();
    void setName(const std::string& name);
    std::string getName() const;
    void setSurname(const std::string& surname);
    std::string getSurname() const;
    void setPesel(const std::string& pesel);
    std::string getPesel() const;
    bool validatePesel(const std::string& PESEL) const;
    bool validatePesel() const;
};
