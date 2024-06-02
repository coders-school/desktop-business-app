#pragma once

#include "enumerations/treatment/Treatment.hpp"
#include "enumerations/treatment_state/TreatmentState.hpp"

#include <chrono>
#include <unordered_map>

namespace patient
{

/*
 *  represents the treatment that is planned for the patient or has been provided to the patient.
 */
class Treatments
{
  public:
    // Treatments should contain logic
    // planned -> set once visit is made
    // done -> set once visit state switches
    // Treatmends done in future should also collect date when
    // treatment was completed

    void updateTreatment(const common::TreatmentState treatment_state);

  private:
    // map or different object containing treatment and date
    // and then kept in vector?
    std::unordered_map<common::Treatment, std::chrono::year_month_day> treatments_done_;
    std::unordered_map<common::Treatment, std::chrono::year_month_day> treatments_planned_;
    std::unordered_map<common::Treatment, std::chrono::year_month_day> treatments_declined_;
    // vector<treatment> done
    // vector<treatment> declined
    // vector<treatment> planned
};

} // namespace patient
