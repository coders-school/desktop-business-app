#include "visit.hpp"

Visit::Visit(std::shared_ptr<Doctor> doc) : docAssociation_{doc}{
    visitExtent.insert(this);
}

Visit::~Visit() {
    removeFromExtent(this);
}

void Visit::createVisit(std::shared_ptr<Doctor> doc){
    auto visit{std::make_shared<Visit>(doc)};
    doc->addAssociation(visit);
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


