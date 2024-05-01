#include "calendar.hpp"
#include "../clinic/clinic_facade.hpp"
#include <iostream>

void Calendar::createCalendar(){
    if(!Clinic::getCalendar()){
        Clinic::appendCalendar(std::make_shared<Calendar>());
    }else{
        throw std::length_error("There cannot be more than one calendar");
    }
}
std::shared_ptr<Connector> Calendar::addConnector(std::chrono::year_month_day ymd, std::shared_ptr<Room>, std::shared_ptr<Doctor>){
    return nullptr;
}
