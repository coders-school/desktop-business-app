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
    std::string getDay() const;
    std::string getMonth() const;
    std::string getYear() const;
    std::string getCompleteDate() const;

  private:
    std::string pesel_;
    std::string day_;
    std::string month_;
    std::string year_;

    void parsePesel();
};

} // namespace birth_date

} // namespace common
