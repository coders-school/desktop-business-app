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

    PatientQueueType getQueuedPatients(Treatment treatment) const;
    PatientQueueType getQueuedPatients(const std::shared_ptr<Doctor>& doctor) const;
    std::unordered_map<Treatment, PatientQueueType> getTreatmentQueues() const;
    std::unordered_map<std::shared_ptr<Doctor>, PatientQueueType> getDoctorQueues() const;

    bool addPatientToQueue(Treatment treatment, const std::shared_ptr<Patient>& patient);
    bool addPatientToQueue(const std::shared_ptr<Doctor>& doctor, const std::shared_ptr<Patient>& patient);
    void removePatientFromQueue(Treatment treatment, const std::shared_ptr<Patient>& patient);
    void removePatientFromQueue(const std::shared_ptr<Doctor>& doctor, const std::shared_ptr<Patient>& patient);

  private:
    bool addPatientIfNotPresent(ReserveQueue::PatientQueueType& patients_queued,
                                const std::shared_ptr<Patient>& patient);
    void removePatientFromQueue(ReserveQueue::PatientQueueType& patients_queued,
                                const std::shared_ptr<Patient>& patient);

    std::unordered_map<Treatment, PatientQueueType> treatment_queues_;
    std::unordered_map<std::shared_ptr<Doctor>, PatientQueueType> doctor_queues_;
};
