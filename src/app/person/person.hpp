#pragma once

#include <memory>
#include <string>

class Person
{
    std::string firstName_;
    std::string lastName_;
    std::string pesel_;
    
  public:
    Person(std::string firstName, std::string lastName, std::string pesel);
    virtual ~Person();

    void setFirstName(std::string firstName);
    std::string getFirstName();
    void setLastName(std::string lastName);
    std::string getLastName();
    void setPesel(std::string pesel);
    std::string getPesel();
};