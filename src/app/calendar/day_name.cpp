#include "day_name.hpp"

std::string toString(const DayName& day_name){
    std::string day_name_str{};

    switch(day_name){
        case DayName::Monday:
            day_name_str = "Monday";
            break;
        case DayName::Tuesday:
            day_name_str = "Tuesday";
            break;
        case DayName::Wednesday:
            day_name_str = "Wednesday";
            break;
        case DayName::Thursday:
            day_name_str = "Thursday";
            break;
        case DayName::Friday:
            day_name_str = "Friday";
            break;
        case DayName::Saturday:
            day_name_str = "Saturday";
            break;
        case DayName::Sunday:
            day_name_str = "Sunday";
            break;
        default:
            break;
    }
    return day_name_str;
}