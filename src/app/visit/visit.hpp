#pragma once

#include <memory>
#include <string>
#include <../doctor/doctor.hpp>

class Visit : public std::enable_shared_from_this<Visit>{
        Visit(std::shared_ptr<Doctor> doc);
        ~Visit();
        static std::unordered_set<Visit*> visitExtent;
        std::shared_ptr<Doctor> docAssociation_;

        std::string visitInfo_;
    public:
        static void createVisit(std::shared_ptr<Doctor> doc);
        static std::unordered_set<Visit*> getExtent();
        static void removeFromExtent(Visit* visit);

        void setAssociation(std::shared_ptr<Doctor> doc);
        std::shared_ptr<Doctor> getDocAssociation();
};