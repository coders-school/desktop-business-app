#include "visit.hpp"

Visit::Visit(std::shared_ptr<Doctor> doc) : doc_{doc}{
    visitExtent.push_back(this);
}

void Visit::createVisit(std::shared_ptr<Doctor> doc){
    auto visit{std::make_shared<Visit>(doc)};
    doc->addAssociation(visit);
};

void Visit::setAssociation(std::shared_ptr<Doctor> doc){
    if(!doc_){
        doc_={doc};
        doc->addAssociation(shared_from_this());
    }
}

