#pragma once

#include "../person/person.hpp"
#include "../visit/visit.hpp"
#include <unordered_set>

class Doctor : public Person, std::enable_shared_from_this<Doctor>{
    private:
        std::unordered_set<std::shared_ptr<Visit>> visitAssociation_;
    public:
        Doctor();

        void addAssociation(std::shared_ptr<Visit> visit);
        std::unordered_set<std::shared_ptr<Visit>> getVisitAssociation();
};