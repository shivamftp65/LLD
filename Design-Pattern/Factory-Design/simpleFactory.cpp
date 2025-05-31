#include<iostream>

using namespace std;

class Burger{
    public:
        virtual void prepare() = 0;  //pure virtual function
        virtual ~Burger() {}  // virtual destructure
};

class BasicBurger : public Burger{
    public:
        void prepare() override {
            cout<<"Preparing Basic Burger With Bun, Patty, and Ketchup!"<<endl;
        }
};

class StandardBurger : public Burger{
    public:
        void prepare() override {
            cout<<"Preparing Standard Burger With Bun, Patty, Cheese, and lettuce!"<<endl;
        }
};

class PremiumBurger : public Burger{
    public:
        void prepare() override {
            cout<<"Preparing Basic Burger With gourmet bun, premium Patty, Cheese, lettuce, and secret sauce!"<<endl;
        }
};

class BurgerFactory{
    public:
        Burger* createBurger(string &type){
            if(type == "basic"){
                return new BasicBurger();
            }else if(type == "standard"){
                return new StandardBurger();
            }else if(type == "premium"){
                return new PremiumBurger();
            }else{
                cout<<"Invalid burger type"<<endl;
                return nullptr;
            }
        }
};

int main(){
    string type = "standard";

    BurgerFactory* myBurgerFactory = new BurgerFactory();
    Burger* burger = myBurgerFactory->createBurger(type);

    burger->prepare();

    return 0;
}