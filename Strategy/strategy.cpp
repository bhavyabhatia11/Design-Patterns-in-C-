#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
 
class DriveStrategy {
    public: 
        virtual void drive() = 0;
};

class SimpleDriveStrategy : public DriveStrategy {
    public:
        void drive(){
            cout << "Implements a simple driving strategy" << endl;
            return;
        }
};

class AdvanceDriveStrategy : public DriveStrategy {
    public:
        void drive(){
            cout << "Implements an advanced driving strategy" << endl;
            return;
        }
};





class Vehicle{
    public:
        DriveStrategy* driveStrategy;

        Vehicle(DriveStrategy* driveStrategy){
            //this vehicle class does not know which driving strategy it is getting.
            // It just updates the drivingStrategy obj and exectues
            this->driveStrategy = driveStrategy;
        }

        void drive(){
            driveStrategy->drive();
            return;
        }
};

class OffRoadVehicle : public Vehicle {
    public:
        OffRoadVehicle(DriveStrategy* driveStrategy) : Vehicle(driveStrategy){
            this->driveStrategy = driveStrategy;
        }
};

class CityVehicle : public Vehicle {
     public:
        CityVehicle(DriveStrategy* driveStrategy) : Vehicle(driveStrategy){
            this->driveStrategy = driveStrategy;
        }
};


int main() {
    
    DriveStrategy* advDrive = new AdvanceDriveStrategy();
    DriveStrategy* simpleDrive = new SimpleDriveStrategy();


    Vehicle* offRoadVehicle = new OffRoadVehicle(advDrive);
    Vehicle* cityVehicle = new CityVehicle(simpleDrive);

    offRoadVehicle->drive();
    cityVehicle->drive();

    delete advDrive;
    delete simpleDrive;
    delete offRoadVehicle;
    delete cityVehicle;



    return 0;
};