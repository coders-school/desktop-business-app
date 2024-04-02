#include "visit.hpp"
#include "../clinic/clinic_facade.hpp"
#include "../doctor/doctor.hpp"

Visit::Visit(const std::shared_ptr<Doctor>& doctor, const std::vector<Treatment>& treatments)
    : doctor_{doctor}, treatments_{std::move(treatments)}, visit_information_{}
{
}

std::shared_ptr<Doctor> Visit::getDoctor() const
{
    return doctor_;
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

void Visit::updateTreatments(const std::vector<Treatment>& treatments)
{
    treatments_ = treatments;
}

void Visit::createVisit(const std::shared_ptr<Doctor>& doctor)
{
    Visit visit(doctor);
    auto visit_ptr = std::make_shared<Visit>(visit);
    visit.doctor_->appendVisit(visit_ptr);
    Clinic::appendVisit(visit_ptr);
}
