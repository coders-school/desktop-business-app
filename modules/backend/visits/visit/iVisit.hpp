#pragma once

namespace visit
{

// visits in future might be separated by type (completed, planned, canceled)
// thus iterface could help manage different types of visits
class iVisit
{
  public:
    virtual ~iVisit() = 0;
};

} // namespace visit
