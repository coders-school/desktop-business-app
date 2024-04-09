#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

class Doctor;
class Patient;
enum class Treatment : uint32_t;

class ReserveQueue
{
  public:
    using PatientQueueType = std::vector<std::shared_ptr<Patient>>;

    PatientQueueType awaitingPatients(Treatment treatment) const;
    PatientQueueType awaitingPatients(const std::shared_ptr<Doctor>& doctor) const;
    std::vector<Treatment> treatmentsHavingQueue() const;
    std::vector<std::shared_ptr<Doctor>> doctorsHavingQueue() const;

    bool addAwaitingPatient(Treatment treatment, const std::shared_ptr<Patient>& patient);
    bool addAwaitingPatient(const std::shared_ptr<Doctor>& doctor, const std::shared_ptr<Patient>& patient);
    void removeAwaitingPatient(Treatment treatment, const std::shared_ptr<Patient>& patient);
    void removeAwaitingPatient(const std::shared_ptr<Doctor>& doctor, const std::shared_ptr<Patient>& patient);

  private:
    std::unordered_map<Treatment, PatientQueueType> treatment_queue_;
    std::unordered_map<std::shared_ptr<Doctor>, PatientQueueType> doctor_queue_;

};
