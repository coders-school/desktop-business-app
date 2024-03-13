#include "visit.hpp"

Visit::Visit(std::shared_ptr<Doctor> doc) : docAssociation_{doc}{
    visitExtent.push_back(this);
}

void Visit::createVisit(std::shared_ptr<Doctor> doc){
    auto visit{std::make_shared<Visit>(doc)};
    doc->addAssociation(visit);
};

void Visit::setAssociation(std::shared_ptr<Doctor> doc){
    if(!docAssociation_){
        docAssociation_={doc};
        docAssociation_->addAssociation(shared_from_this());
    }
}

std::shared_ptr<Doctor> Visit::getDocAssociation(){
    return docAssociation_;
}

