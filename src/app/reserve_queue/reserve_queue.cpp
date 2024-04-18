#include "reserve_queue.hpp"
#include <algorithm>

bool ReserveQueue::addPatientToQueue(Treatment treatment, const std::shared_ptr<Patient>& patient)
{
    return addPatientIfNotPresent(treatment_queues_[treatment], patient);
}

bool ReserveQueue::addPatientToQueue(const std::shared_ptr<Doctor>& doctor, const std::shared_ptr<Patient>& patient)
{
    return addPatientIfNotPresent(doctor_queues_[doctor], patient);
}

void ReserveQueue::removePatientFromQueue(Treatment treatment, const std::shared_ptr<Patient>& patient)
{
    auto& patients_queued = treatment_queues_[treatment];

    removePatientFromQueue(patients_queued, patient);

    if (patients_queued.empty())
    {
        treatment_queues_.erase(treatment);
    }
}

void ReserveQueue::removePatientFromQueue(const std::shared_ptr<Doctor>& doctor,
                                          const std::shared_ptr<Patient>& patient)
{
    auto& patients_queued = doctor_queues_[doctor];

    removePatientFromQueue(patients_queued, patient);

    if (patients_queued.empty())
    {
        doctor_queues_.erase(doctor);
    }
}

ReserveQueue::PatientQueueType ReserveQueue::getQueuedPatients(Treatment treatment) const
{
    auto queued_patients = treatment_queues_.find(treatment);

    return queued_patients != treatment_queues_.end() ? queued_patients->second : PatientQueueType{};
}

ReserveQueue::PatientQueueType ReserveQueue::getQueuedPatients(const std::shared_ptr<Doctor>& doctor) const
{
    auto queued_patients = doctor_queues_.find(doctor);

    return queued_patients != doctor_queues_.end() ? queued_patients->second : PatientQueueType{};
}

std::unordered_map<Treatment, ReserveQueue::PatientQueueType> ReserveQueue::getTreatmentQueues() const
{
    return treatment_queues_;
}

std::unordered_map<std::shared_ptr<Doctor>, ReserveQueue::PatientQueueType> ReserveQueue::getDoctorQueues() const
{
    return doctor_queues_;
}

bool ReserveQueue::addPatientIfNotPresent(ReserveQueue::PatientQueueType& patients_queued,
                                          const std::shared_ptr<Patient>& patient)
{
    auto patient_iterator = std::ranges::find(patients_queued, patient);

    if (patient_iterator == patients_queued.end())
    {
        patients_queued.emplace_back(patient);

        return true;
    }

    return false;
}

void ReserveQueue::removePatientFromQueue(ReserveQueue::PatientQueueType& patients_queued,
                                          const std::shared_ptr<Patient>& patient)
{
    if (auto patientSearched = std::ranges::find(patients_queued, patient); patientSearched != patients_queued.end())
    {
        patients_queued.erase(patientSearched);
    }
}
