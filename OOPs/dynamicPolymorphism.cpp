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

        void stopEngine(){
            isEngineOn = false;
            currentSpeed = 0;
            cout<<brand<<" "<<model<<" "<<" :Engine turned off."<<endl;
        }

        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual ~Car() {}
};

class ManualCar: public Car{       // Inherits from Car
    private:
        int currentGear;  // Specific to manual car
    
    public:
        ManualCar(string b, string m):Car(b,m){
            this->currentGear = 0;
        }

        //Specialized method for manual car
        void shiftGear(int gear){
            currentGear = gear;
            cout<<brand<<" "<<model<<" : Shifted to gear "<<currentGear<<endl;
        }

        // Overriding accelerate - Dynamic Polymorphism
        void accelerate(){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" : Engine is off! Cannot Accelerate."<<endl;
                return;
            }

            currentSpeed += 20;
            cout<<brand<<" "<<model<<" : Accelearated to "<<currentSpeed<<" km/h"<<endl;
        }

        // override brake - dynamic polimorphism
        void brake(){
            currentSpeed -= 20;
            if(currentSpeed < 0) currentSpeed=0;
            cout<<brand<<" "<<model<<" : Braking! Speed is now "<<currentSpeed<<" km/h"<<endl;
        }
};

class ElectricCar: public Car{       // Inherits from Car
    private:
        int batteryLevel;  // Specific to Electrical car
    
    public:
        ElectricCar(string b, string m):Car(b,m){
            this->batteryLevel = 100;
        }

        //Specialized method for manual car
        void chargeBattery(){
            batteryLevel = 100;
            cout<<brand<<" "<<model<<" : Battery fully charged "<<batteryLevel<<endl;
        }

        void accelerate(){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" : Engine is off! Cannot Accelerate."<<endl;
                return;
            }
            if(batteryLevel<=0){
                cout<<brand<<" " <<model<< " : Battery Dead! Cannot Accelerate."<<endl;
                return;
            }
            batteryLevel -= 10;
            currentSpeed += 15;
            cout<<brand<<" "<<model<<" : Accelearated to "<<currentSpeed<<" km/h. Batter at "<<batteryLevel<<"%."<<endl;
        }

        void brake(){
            currentSpeed -= 15;
            if(currentSpeed < 0) currentSpeed=0;
            cout<<brand<<" "<<model<<" : Regenerative breaking! speed is now "<<currentSpeed<<" km/h.Batter at "<<batteryLevel<<"%."<<endl;
        }
};

int main(){
    ManualCar* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1); //Specific to manual car
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();

    cout<<"-------------------------------------------"<<endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery();  // sepcific to electric Car
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    // cleanup
    delete myElectricCar;
    delete myManualCar;

    return 0;
}