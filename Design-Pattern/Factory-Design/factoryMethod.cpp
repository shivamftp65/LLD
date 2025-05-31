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
            cout<<"Preparing Premium Burger With gourmet bun, premium Patty, Cheese, lettuce, and secret sauce!"<<endl;
        }
};

class BasicWheetBurger : public Burger{
    public:
        void prepare() override {
            cout<<"Preparing Basic Wheet Burger With Bun, Patty, and Ketchup!"<<endl;
        }
};

class StandardWheetBurger : public Burger{
    public:
        void prepare() override {
            cout<<"Preparing Standard Wheet Burger With Bun, Patty, Cheese, and lettuce!"<<endl;
        }
};

class PremiumWheetBurger : public Burger{
    public:
        void prepare() override {
            cout<<"Preparing premium Wheet Burger With gourmet bun, premium Patty, Cheese, lettuce, and secret sauce!"<<endl;
        }
};

class BurgerFactory{
    public:
        virtual Burger* createBurger(string &type) = 0;
};

class SinghBurger : public BurgerFactory{
    public:
        Burger* createBurger(string &type) override {
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

class KingBurger : public BurgerFactory{
    public:
        Burger* createBurger(string &type) override {
            if(type == "basic"){
                return new BasicWheetBurger();
            }else if(type == "standard"){
                return new StandardWheetBurger();
            }else if(type == "premium"){
                return new PremiumWheetBurger();
            }else{
                cout<<"Invalid burger type"<<endl;
                return nullptr;
            }
        }
};

int main(){
    string type = "premium";

    BurgerFactory* myBurgerFactory = new KingBurger();
    Burger* burger = myBurgerFactory->createBurger(type);

    burger->prepare();

    return 0;
}