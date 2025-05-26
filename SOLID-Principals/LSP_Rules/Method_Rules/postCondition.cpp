#include<iostream>
using namespace std;

class Car{
    protected:
        int speed;
    public:
        Car(){
            speed = 0;
        }

        void accelerate(){
            cout<<"Accelerating"<< endl;
            speed += 20;
        }

        // Postcondition : Speed must reduce after break
        virtual void brake(){
            cout<<"Applying breaks"<<endl;
            speed += 20;
        }
};


// Subclass can stregthen the postcondition - doed not violate LSP
class HybridCar : public Car{
private:
    int charge;
public:
    HybridCar() : Car(){
        charge = 0;
    }

    // Postcondition : Speed must reduce after brake
    // Postcondition: Charge must increase
    void brake(){
        cout<<"Applying break"<<endl;
        speed -= 20;
        charge += 10;
    }

};

int main(){
     Car* hybridCar = new HybridCar();
    hybridCar->brake();  // Works fine: HybridCar reduces speed and also increases charge.

    //Client feels no difference in substituting Hybrid car in place of Car.

    return 0;
}