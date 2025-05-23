#include<iostream>
#include<string>
using namespace std;

class Car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
    public: 
        Car(string b, string m){
            this->brand = b;
            this->model = m;
            isEngineOn=false;
            currentSpeed = 0;
        }
        // Common methods
        void startEngine(){
            isEngineOn = true;
            cout<<brand<<" "<<model<<" : Engine Starts with a roar!"<<endl;
        }

        void accelerate(){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" : Engine is off! Cannot Accelerate."<<endl;
                return;
            }

            currentSpeed += 20;
            cout<<brand<<" "<<model<<" : Accelearated to "<<currentSpeed<<" km/h"<<endl;
        }

        void brake(){
            currentSpeed -= 20;
            if(currentSpeed < 0) currentSpeed=0;
            cout<<brand<<" "<<model<<" : Braking! Speed is now "<<currentSpeed<<" km/h"<<endl;
        }

        void stopEngine(){
            isEngineOn = false;
            currentSpeed = 0;
            cout<<brand<<" "<<model<<" "<<" :Engine turned off."<<endl;
        }
};

class ManualCar: public Car{       // Inherits from Car
    private:
        int currentGear;  // Specific to manual car
    
    public:
        ManualCar(string b, string m):Car(b,m){
            currentGear = 0;
        }

        //Specialized method for manual car
        void shiftGear(int gear){
            currentGear = gear;
            cout<<brand<<" "<<model<<" : Shifted to gear "<<currentGear<<endl;
        }
};

class ElectricCar: public Car{       // Inherits from Car
    private:
        int batteryLevel;  // Specific to Electrical car
    
    public:
        ElectricCar(string b, string m):Car(b,m){
            batteryLevel = 100;
        }

        //Specialized method for manual car
        void chargeBattery(){
            batteryLevel = 100;
            cout<<brand<<" "<<model<<" : Battery fully charged "<<batteryLevel<<endl;
        }
};

int main(){
    ManualCar* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1); //Specific to manual car
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout<<"-------------------------------------------"<<endl;
    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery();  // sepcific to electric Car
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;
}