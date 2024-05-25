#pragma once

// find better name for the interface
class iSerdePatient : public virtual iPatient
{
  public:
    virtual void SerializeData() = 0;
    virtual ~iSerdePatient() = 0;
};