#include "room_test.hpp"

namespace
{

TEST_F(RoomTestFixture, GivenVisitCheckIfRoomHasCorrectAmountOfVisits)
{
    Room::createRoom(1, Clinic::getWarehouse());
    std::shared_ptr<Room> room = Clinic::getRooms().front();
    room->addVisit(Clinic::getVisits().at(1));
    const size_t expected_output{1};
    EXPECT_EQ(Clinic::getRooms().front()->getVisits().size(), expected_output);
}

TEST_F(RoomTestFixture, GivenVisitCheckIfRoomHasCorrectAmountOfVisits2)
{
    Room::createRoom(2, Clinic::getWarehouse());
    std::shared_ptr<Room> room = Clinic::getRooms().front();
    room->addVisit(Clinic::getVisits().at(0));
    room->addVisit(Clinic::getVisits().at(1));
    const size_t expected_output{2};
    EXPECT_EQ(Clinic::getRooms().front()->getVisits().size(), expected_output);
}

} // namespace
