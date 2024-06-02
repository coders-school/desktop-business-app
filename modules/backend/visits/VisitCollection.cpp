#include "VisitCollection.hpp"

namespace visit
{

void VisitCollection::appendVisit(const std::shared_ptr<iVisit>& visit)
{
    visits_.emplace_back(visit);
}

const std::vector<std::shared_ptr<iVisit>>& VisitCollection::getVisits() const
{
    return visits_;
}

} // namespace visit
