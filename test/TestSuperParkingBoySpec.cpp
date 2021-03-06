//
// Created by twer  on 5/6/15.
//

#include "TestSuperParkingBoySpec.h"
#include "../src/ParkingLot.h"
#include "../src/SuperParkingBoy.h"

void TestSuperParkingBoySpec::SetUp() {
    Test::SetUp();
}

void TestSuperParkingBoySpec::TearDown() {
    Test::TearDown();
}

TEST_F(TestSuperParkingBoySpec, should_park_to_the_parkinglot_with_highest_ratio_when_super_parkingboy_manage_multiple_parkinglots)
{
    std::shared_ptr<ParkingLot> parkingLotSmall = std::make_shared<ParkingLot>(11);
    std::shared_ptr<ParkingLot> parkingLotBig = std::make_shared<ParkingLot>(10);

    std::shared_ptr<SuperParkingBoy> superParkingBoy = std::make_shared<SuperParkingBoy>("YYY");
    superParkingBoy->AddParkingLot(parkingLotSmall);
    superParkingBoy->AddParkingLot(parkingLotBig);

    superParkingBoy->Park(std::make_shared<Car>("1"));
    superParkingBoy->Park(std::make_shared<Car>("2"));

    ASSERT_TRUE(parkingLotSmall->FindCar(std::make_shared<Car>("1")));
    ASSERT_TRUE(parkingLotBig->FindCar(std::make_shared<Car>("2")));
}