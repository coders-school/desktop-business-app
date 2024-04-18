#pragma once

#include <memory>
#include <string>

class Person
{
    std::string name_;
    std::string surname_;
    std::string pesel_;

    bool validatePESELSize(const std::string& PESEL) const;
    bool validatePESELDate(const std::string& PESEL) const;
    bool validateControlNumber(const std::string& PESEL) const;

  public:
    Person(const std::string& name, const std::string& surname, const std::string& pesel);
    virtual ~Person();
    void setName(const std::string& name);
    std::string getName() const;
    void setSurname(const std::string& surname);
    std::string getSurname() const;
    void setPesel(const std::string& pesel);
    std::string getPesel() const;
    bool validatePESEL(const std::string& PESEL) const;
};
