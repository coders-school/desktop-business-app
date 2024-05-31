#pragma once

#include "modules/backend/visits/visit/iVisit.hpp"
#include <vector>

namespace visit
{

class VisitCollection
{
    std::vector<iVisit> visits_;

  public:
    void AppendVisit(const iVisit& visit)
    {
        visits_.emplace_back(visit);
    }

    const std::vector<iVisit>& GetVisits()
    {
        return visits_;
    }
};

} // namespace visit
