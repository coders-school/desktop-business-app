#pragma once

#include <memory>
#include <string>
#include <unordered_set>

class Doctor;

class Visit : public std::enable_shared_from_this<Visit>
{
    Visit();
    static std::unordered_set<Visit *> visitExtent;
    std::shared_ptr<Doctor> docAssociation_;

    std::string visitInfo_;

  public:
    ~Visit();
    static std::shared_ptr<Visit> createVisit(std::shared_ptr<Doctor> doc);
    static std::unordered_set<Visit *> getExtent();
    static void removeFromExtent(Visit *visit);

    void setAssociation(std::shared_ptr<Doctor> doc);
    std::shared_ptr<Doctor> getDocAssociation();
    void setVisitInfo(std::string info);
    std::string getVisitInfo();
};