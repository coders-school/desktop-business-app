#pragma once

class iSerdeDoctor
{
  public:
    virtual ~iSerdeDoctor() = 0;
    virtual void Serialize() const = 0;
    virtual void Deserialize() = 0;
};
