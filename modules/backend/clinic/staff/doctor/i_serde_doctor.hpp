#pragma once

class iSerdeDoctor
{
  public:
    virtual ~iSerdeDoctor() = 0;
    virtual void serialize() const = 0;
    virtual void deserialize() = 0;
};
