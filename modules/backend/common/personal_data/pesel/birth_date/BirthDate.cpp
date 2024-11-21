#include "BirthDate.hpp"

namespace common 
{

namespace birth_date 
{
    BirthDate::BirthDate(const std::string& pesel) 
        : pesel_{pesel}, day_{}, month_{}, year_{} 
    {
        parsePesel();
    }

    void BirthDate::parsePesel()
    {
        int month = std::stoi(pesel_.substr(2, 2));
        int year = std::stoi(pesel_.substr(0, 2));

        if (month > 80) 
        {
            year += 1800;
            month -= 80;
        }
        else if (month > 60) 
        {
            year += 2200;
            month -= 60;
        }
        else if (month > 40) 
        {
            year += 2100;
            month -= 40;
        } 
        else if (month > 20) 
        {
            year += 2000;
            month -= 20;
        } 
        else 
        {
            year += 1900;
        }

        day_ = pesel_.substr(4, 2);
        month_ = (month < 10 ? "0" : "") + std::to_string(month);
        year_ = std::to_string(year);
    }

    std::string BirthDate::getDay() const
    {
        return day_;
    }

    std::string BirthDate::getMonth() const
    {
        return month_;
    }

    std::string BirthDate::getYear() const
    {
        return year_;
    }

    std::string BirthDate::getCompleteDate() const
    {
        return day_ + "-" + month_ + "-" + year_;
    }


}  // namespace birth_date

}  // namespace common
