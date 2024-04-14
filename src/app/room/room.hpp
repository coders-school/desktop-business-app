#pragma once
#include "treatment.hpp"
#include "warehouse.hpp"
<<<<<<< HEAD
#include <memory>
    == == ==
    =
#include <utility>
        >>>>>>> d349a39(Update README.md(#66))
#include <vector>

                    class Room
{
    uint roomNumber_;
    std::vector<Treatment> treatments_;
<<<<<<< HEAD
    bool avalaible_{true};
    std::shared_ptr<Warehouse> ptrToWarehouse_;

  public:
    Room() = delete;
    Room(const uint roomNumber, const std::vector<Treatment>& treatments, std::shared_ptr<Warehouse>& ptrToWarehouse);

    // bool isRoomFree(timeInterval); TODO: write this function
    uint getRoomNumber() const;
    std::vector<Treatment> getTreatments() const;
    std::shared_ptr<Warehouse> getWarehouse() const;
    void setRoomAvalaibility(bool avalaible);
    void setWarehouse(std::shared_ptr<Warehouse>& ptrToWarehouse);
=======
    bool avalaibility_{true};
    Warehouse& refToWarehouse_;

  public:
    Room() = delete;
    Room(const uint roomNumber, const std::vector<Treatment> treatments, Warehouse& refToWarehouse);

    uint getRoomNumber();
    // bool isRoomFree(timeInterval); TODO: write this function
    void setRoomAvalaibility(bool avalaibility);
    std::vector<Treatment> getTreatments();
>>>>>>> d349a39 (Update README.md (#66))
};
