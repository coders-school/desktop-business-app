#pragma once


class Doctor : public iDoctor
{
    Person person_;
    Specialization specialization_;

  public:
    Doctor(const Person& person, const Specialization specialization) : person_{person}, specialization_{specialization}
    {
    }
};