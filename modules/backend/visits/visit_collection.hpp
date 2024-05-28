#pragma once

#include "modules/backend/visits/visit/i_visit.hpp"
#include <vector>

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