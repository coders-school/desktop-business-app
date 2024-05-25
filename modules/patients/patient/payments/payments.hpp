#pragma once

struct Payments
{
    std::uint8_t paid_;
    std::uint8_t planned_;
    std::uint8_t overdue_;
    // paid -> total received from patient
    // planned -> informative value for planned treatment
    // overdue -> if patient did not have enough money,
    // patient may pay in installments
};

