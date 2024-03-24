#include "visit.hpp"
#include "doctor.hpp"

std::set<Visit*> Visit::visit_extent_;

Visit::Visit(std::vector<Treatment> predictedTreatments) : treatments_(std::move(predictedTreatments))
{
    visit_extent_.insert(this);
}

Visit::~Visit()
{
    removeFromExtent(this);
}

std::shared_ptr<Visit> Visit::createVisit(std::shared_ptr<Doctor> doctor, std::vector<Treatment> predictedTreatments)
{
    auto visit = std::shared_ptr<Visit>(new Visit(std::move(predictedTreatments)));
    doctor->addVisitAssociation(visit);

    return visit;
}

std::set<Visit*> Visit::getExtent()
{
    return visit_extent_;
}

void Visit::removeFromExtent(Visit* visit)
{
    auto it = visit_extent_.find(visit);
    if (it != visit_extent_.end())
    {
        visit_extent_.erase(it);
    }
}

void Visit::setDoctorAssociation(const std::shared_ptr<Doctor>& doctor)
{
    if (!doctor_association_)
    {
        doctor_association_ = {doctor};
        doctor_association_->addVisitAssociation(shared_from_this());
    }
}

std::shared_ptr<Doctor> Visit::getDoctorAssociation() const
{
    return doctor_association_;
}

std::vector<Treatment> Visit::getTreatments() const
{
    return treatments_;
}

void Visit::setVisitInformation(const std::string& visit_information)
{
    visit_information_ = visit_information;
}

std::string Visit::getVisitInformation() const
{
    return visit_information_;
}

void Visit::updateTreatments(std::vector<Treatment> newTreatments)
{
    treatments_ = std::move(newTreatments);
}