#include "calendar.hpp"
#include "../clinic/clinic_facade.hpp"

void Calendar::createCalendar(){
    Calendar calendar{};
    Clinic::addCalendar(std::make_shared<Calendar>(calendar));
}