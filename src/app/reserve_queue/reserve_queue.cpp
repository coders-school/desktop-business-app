#include "reserve_queue.hpp"
#include <algorithm>

namespace
{
bool addPatientIfNotPresent(ReserveQueue::PatientQueueType& patients_queued, const std::shared_ptr<Patient>& patient)
{
    auto patient_iterator = std::ranges::find(patients_queued, patient);

    if (patient_iterator == patients_queued.end())
    {
        patients_queued.emplace_back(patient);

        return true;
    }

    return false;
}

void removePatientFromQueue(ReserveQueue::PatientQueueType& patients_queued, const std::shared_ptr<Patient>& patient)
{
    if (auto patientSearched = std::ranges::find(patients_queued, patient); patientSearched != patients_queued.end())
    {
        patients_queued.erase(patientSearched);
    }
}
} // namespace

bool ReserveQueue::addAwaitingPatient(Treatment treatment, const std::shared_ptr<Patient>& patient)
{
    return addPatientIfNotPresent(treatment_queue_[treatment], patient);
}

bool ReserveQueue::addAwaitingPatient(const std::shared_ptr<Doctor>& doctor, const std::shared_ptr<Patient>& patient)
{
    return addPatientIfNotPresent(doctor_queue_[doctor], patient);
}

void ReserveQueue::removeAwaitingPatient(Treatment treatment, const std::shared_ptr<Patient>& patient)
{
    auto& patients_queued = treatment_queue_[treatment];

    removePatientFromQueue(patients_queued, patient);

    if (patients_queued.empty())
    {
        treatment_queue_.erase(treatment);
    }
}

void ReserveQueue::removeAwaitingPatient(const std::shared_ptr<Doctor>& doctor, const std::shared_ptr<Patient>& patient)
{
    auto& patients_queued = doctor_queue_[doctor];

    removePatientFromQueue(patients_queued, patient);

    if (patients_queued.empty())
    {
        doctor_queue_.erase(doctor);
    }
}

ReserveQueue::PatientQueueType ReserveQueue::awaitingPatients(Treatment treatment) const
{
    auto queued_patients = treatment_queue_.find(treatment);

    return queued_patients != treatment_queue_.end() ? queued_patients->second : PatientQueueType{};
}

ReserveQueue::PatientQueueType ReserveQueue::awaitingPatients(const std::shared_ptr<Doctor>& doctor) const
{
    auto queued_patients = doctor_queue_.find(doctor);

    return queued_patients != doctor_queue_.end() ? queued_patients->second : PatientQueueType{};
}

std::vector<Treatment> ReserveQueue::treatmentsHavingQueue() const
{
    std::vector<Treatment> awaiting_treatments;
    awaiting_treatments.reserve(treatment_queue_.size());
    std::ranges::transform(treatment_queue_, std::back_inserter(awaiting_treatments),
                           [](const auto& key_val_pair) { return key_val_pair.first; });

    return awaiting_treatments;
}

std::vector<std::shared_ptr<Doctor>> ReserveQueue::doctorsHavingQueue() const
{
    std::vector<std::shared_ptr<Doctor>> awaited_doctors;
    awaited_doctors.reserve(doctor_queue_.size());
    std::ranges::transform(doctor_queue_, std::back_inserter(awaited_doctors),
                           [](const auto& key_val_pair) { return key_val_pair.first; });

    return awaited_doctors;
}
