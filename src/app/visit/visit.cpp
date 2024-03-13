#include "visit.hpp"
#include "../doctor/doctor.hpp"

std::unordered_set<Visit*> Visit::visitExtent;


Visit::Visit(){
    visitExtent.insert(this);
}

Visit::~Visit() {
    removeFromExtent(this);
}

std::shared_ptr<Visit> Visit::createVisit(std::shared_ptr<Doctor> doc) {
    auto visit = std::shared_ptr<Visit>(new Visit());
    doc->addAssociation(visit);
    return visit;
}

std::unordered_set<Visit*> Visit::getExtent(){
    return visitExtent;
}

void Visit::removeFromExtent(Visit* visit) {
    auto it = visitExtent.find(visit);
    if (it != visitExtent.end()) {
        visitExtent.erase(it);
    }
}

void Visit::setAssociation(std::shared_ptr<Doctor> doc){
    if(!docAssociation_){
        docAssociation_={doc};
        docAssociation_->addAssociation(shared_from_this());
    }
}

std::shared_ptr<Doctor> Visit::getDocAssociation(){
    return docAssociation_;
}

void Visit::setVisitInfo(std::string info){
    visitInfo_ = info;
}

std::string Visit::getVisitInfo(){
    return visitInfo_;
}
