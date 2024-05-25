#pragma once

class VisitCollection
{
    std::vector<iVisit> visits_;

  public:
    void AppendVisit(const iVisit& visit)
    {
        visits_.emplace_back(visit);
    }
    std::vector<iVisit> GetVisits()
    {
        return visits_;
    }
};