#pragma once

#include <memory>
#include <string>
#include <../doctor/doctor.hpp>

class Visit : public std::enable_shared_from_this<Visit>{
    private:
        static std::vector<Visit*> visitExtent;
        Visit(std::shared_ptr<Doctor> doc);
        ~Visit();
        std::shared_ptr<Doctor> doc_;

        std::string visitInfo_;
    public:
        static void createVisit(std::shared_ptr<Doctor> doc);
        void setAssociation(std::shared_ptr<Doctor> doc);
};