#pragma once

#include <memory>
#include <vector>

namespace visit
{

class iVisit;

class VisitCollection
{
  public:
    void appendVisit(std::unique_ptr<iVisit> visit);
    const std::vector<std::unique_ptr<iVisit>>& getVisits() const;

  private:
    //  Functions require this consideration too then
    std::vector<std::unique_ptr<iVisit>> visits_;
};

} // namespace visit
