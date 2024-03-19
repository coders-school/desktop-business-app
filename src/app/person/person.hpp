#pragma once

#include <memory>
#include <string>

class Person
{
    std::string first_name_;
    std::string last_name_;
    std::string pesel_;

  public:
    explicit Person(std::string first_name, std::string last_name, std::string pesel);
    virtual ~Person();
    void setFirstName(const std::string& first_name);
    std::string getFirstName() const;
    void setLastName(const std::string& last_name);
    std::string getLastName() const;
    void setPesel(const std::string& pesel);
    std::string getPesel() const;
};
