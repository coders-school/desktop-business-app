#include "doctor.hpp"
#include <stdexcept>

void Doctor::addAssociation(std::shared_ptr<Visit> visit){
    if(visit == nullptr){
        throw std::invalid_argument("Argument points to nullptr");
    }
    if(visitAssociation_.find(visit) == visitAssociation_.end()){
        visitAssociation_.insert(visit);
        visit->setAssociation(shared_from_this());
    }
}