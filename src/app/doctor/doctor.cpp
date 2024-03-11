#include "doctor.hpp"

void Doctor::addAssociation(std::shared_ptr<Visit> visit){
    if(visit == nullptr){
        //TODO Exception
        return;
    }
    //if() sprawdzamy czy w vectorze istnieje juz ta wizyta
    visitAssociation_.push_back(visit);
    visit->setAssociation(shared_from_this());
}