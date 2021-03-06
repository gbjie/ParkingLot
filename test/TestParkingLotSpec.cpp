//
// Created by twer  on 5/5/15.
//


#include "TestParkingLotSpec.h"
#include "../src/ParkingLot.h"
#include "../src/Car.h"
#include "../src/ParkingBoy.h"

void TestParkingLotSpec::TearDown() {
    Test::TearDown();
}


void TestParkingLotSpec::SetUp() {
    Test::SetUp();
}


TEST_F(TestParkingLotSpec, should_park_car_when_parkinglot_exist_pariking_space)
{
    ParkingLot parkingLot(1, 0);
    ASSERT_TRUE(parkingLot.Park(std::make_shared<Car>("1")));
}

TEST_F(TestParkingLotSpec, should_not_park_car_when_the_parkinginglot_is_full)
{
    ParkingLot parkingLot(0, 0);
    ASSERT_FALSE(parkingLot.Park(std::make_shared<Car>("1")));
}

TEST_F(TestParkingLotSpec, should_release_parking_space_when_unpark_carr)
{
    //given
    ParkingLot parkingLot(2, 0);

    parkingLot.Park(std::make_shared<Car>("1"));
    int nParkingSpaceCountBefore = parkingLot.getAvailableParkingSpaceCount();

    //when
    parkingLot.UnPark(std::make_shared<Car>("1"));

    //then
    ASSERT_EQ(1, parkingLot.getAvailableParkingSpaceCount() - nParkingSpaceCountBefore);
}