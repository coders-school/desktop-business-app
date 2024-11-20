#pragma once

#include <string>

namespace common 
{

namespace birth_date 
{

class BirthDate 
{
    public:
    BirthDate(const std::string& pesel);
    void parsePesel();
    std::string getDay() const;
    std::string getMonth() const;
    std::string getYear() const;

    private:
    std::string pesel_;
    std::string day_;
    std::string month_;
    std::string year_;
};

}  // namespace birth_date

}  // namespace common
