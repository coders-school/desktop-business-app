#include "VisitCollection.hpp"
// TODO: VERIFY
#include "visit/iVisit.hpp"

namespace visit
{

void VisitCollection::appendVisit(std::unique_ptr<iVisit> visit)
{
    visits_.emplace_back(std::move(visit));
}

const std::vector<std::unique_ptr<iVisit>>& VisitCollection::getVisits() const
{
    return visits_;
}

} // namespace visit
