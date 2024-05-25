#pragma once

#include <memory>
#include <vector>

class Serializer // find better name
{
    std::vector<std::unique_ptr<iSerdePatient>> patients_;

  public:
    void SerializeData()
    {
    }
};