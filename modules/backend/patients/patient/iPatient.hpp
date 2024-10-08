#pragma once

namespace patient
{

/*
 * is a general interface to keep Patietns in collection, other objects shall
 * use interfaces with API corresponding to their responsibility.
 */
class iPatient
{
  public:
    virtual ~iPatient() = default;
};

} // namespace patient
