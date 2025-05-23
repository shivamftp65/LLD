#include <iostream>
#include <string>
using namespace std;

class SportsCar{
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
        string tyres;
    public:
        SportsCar(string b, string m){
            this->brand = b;
            this->model = m;
            isEngineOn=false;
            currentSpeed = 0;
            currentGear = 0; //Neutral
            tyres = "MRF";
        }

        // getters and setters
        int getCurrentspeed(){
            return this->currentSpeed;
        }

        string getTyre(){
            return this->tyres;
        }

        void setTyre(string tyre){
            // before setting this variable 
            // apply validation
            this->tyres = tyre;
        }

        // Behaviors --> Methods
        void startEgine(){
            isEngineOn = true;
            cout<<brand<<" "<<model<<" : Engine Starts with a roar!"<<endl;
        }

        void shiftGear(int gear){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" : Engine is off! Cannot Shift Gear."<<endl;
                return;
            }

            currentGear = gear;
            cout<<brand<<" "<<model<<" : Shifted to gear "<<currentGear<<endl;
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
            currentGear = 0;
            cout<<brand<<" "<<model<<" "<<" :Engine turned off."<<endl;
        }
};



int main(){
    SportsCar* mySportCar = new SportsCar("ford", "Mustang");

    mySportCar->startEgine();
    mySportCar->shiftGear(1);
    mySportCar->accelerate();
    mySportCar->shiftGear(2);
    mySportCar->accelerate();
    mySportCar->brake();
    mySportCar->stopEngine();

    cout<<mySportCar->getCurrentspeed();

    delete mySportCar;

    return 0;
}
