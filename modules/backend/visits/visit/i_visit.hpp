#pragma once

// visits in future might be separated by type (completed, planned, canceled)
// thus iterface could help manage different types of visits
class iVisit
{
  public:
    virtual ~iVisit() = 0;
};