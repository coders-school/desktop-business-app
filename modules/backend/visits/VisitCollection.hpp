#pragma once

#include <memory>
#include <vector>

namespace visit
{

class iVisit;

class VisitCollection
{
  public:
    void appendVisit(const std::shared_ptr<iVisit>& visit);
    const std::vector<std::shared_ptr<iVisit>>& getVisits() const;

  private:
    //  TODO: type of pointer to be decided here (unique/shared/raw).
    //  Functions require this consideration too then
    std::vector<std::shared_ptr<iVisit>> visits_;

};

} // namespace visit
