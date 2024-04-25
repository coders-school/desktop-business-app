#include "calendar.hpp"
#include "../clinic/clinic_facade.hpp"
#include "year.hpp"

void Calendar::createCalendar(){
    Calendar calendar{};
    Clinic::addCalendar(std::make_shared<Calendar>(calendar));
}

void Calendar::createYear(const int& year_number,const DayName& first_day_name_of_first_month){
    auto year_ptr = std::make_shared<Year>(std::chrono::year{year_number});
    year_ptr->generateMonths(first_day_name_of_first_month);
    years_.push_back(year_ptr);
}

std::vector<std::shared_ptr<Year>>& Calendar::getYears(){
    return years_;
}
