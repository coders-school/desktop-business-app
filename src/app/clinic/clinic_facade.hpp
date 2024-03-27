#pragma once
#include "../doctor/doctor.hpp"
#include "../receptionist/receptionist.hpp"
#include "../visit/visit.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

class Clinic
{
    static std::vector<Doctor> doctors_;
    static std::vector<Visit> visits_;
    static std::vector<Receptionist> receptionists_;

    template <typename T> static std::vector<T>& getObjectVector()
    {
        if constexpr (std::is_same_v<T, Doctor>)
        {
            return doctors_;
        }
        else if constexpr (std::is_same_v<T, Visit>)
        {
            return visits_;
        }
        else if constexpr (std::is_same_v<T, Receptionist>)
        {
            return receptionists_;
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }

    template <typename T> static void addObjectHelper(const T& obj, std::vector<T>& vec)
    {
        vec.emplace_back(obj);
    }

    template <typename T> static void removeObjectHelper(const T& obj, std::vector<T>& vec)
    {
        auto it = std::remove_if(vec.begin(), vec.end(),
                                 [&](const T& item) { return std::addressof(item) == std::addressof(obj); });
        vec.erase(it, vec.end());
    }

  public:
    template <typename T> static std::vector<T>& getObjects()
    {
        return getObjectVector<T>();
    }

    template <typename T> static void addObject(const T& obj)
    {
        addObjectHelper(obj, getObjectVector<T>());
    }

    template <typename T> static void removeObject(const T& obj)
    {
        removeObjectHelper(obj, getObjectVector<T>());
    }
};
