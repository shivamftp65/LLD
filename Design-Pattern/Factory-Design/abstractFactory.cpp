#include<iostream>

using namespace std;

// Product : 1
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

// Product : 2

class GarlicBread{
    public:
        virtual void prepare() = 0;  //pure virtual function
        virtual ~GarlicBread() {}  // virtual destructure
};

class BasicGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout<<"Preparing Basic Garlic Bread with butter and garlic!"<<endl;
        }
};

class CheeseGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout<<"Preparing Cheese Garlic Bread with extra cheese and buttur!"<<endl;
        }
};

class BasicWheetGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout<<"Preparing Basic Wheet Garlic Bread with butter and garlic!"<<endl;
        }
};

class CheeseWheetGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout<<"Preparing Cheese Wheet Garlic Bread with extra cheese and buttur!"<<endl;
        }
};

// Factory And its concretions
class MealFactory{
    public:
        virtual Burger* createBurger(string &type) = 0;
        virtual GarlicBread* createGarlicBread(string &type) = 0;
};

class SinghBurger : public MealFactory{
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

        GarlicBread* createGarlicBread(string &type) override {
            if(type == "basic"){
                return new BasicGarlicBread();
            }else if(type == "cheese"){
                return new CheeseGarlicBread();
            }else{
                cout<<"Invalid Garlic Bread type"<<endl;
                return nullptr;
            }
        }
};

class KingBurger : public MealFactory{
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

        GarlicBread* createGarlicBread(string &type) override {
            if(type == "basic"){
                return new BasicWheetGarlicBread();
            }else if(type == "cheese"){
                return new CheeseWheetGarlicBread();
            }else{
                cout<<"Invalid Garlic Bread type"<<endl;
                return nullptr;
            }
        }
};

int main(){
    string burgerType = "basic";
    string garlicBreadType = "cheese";

    MealFactory* mealFactory = new KingBurger();
    Burger* burger = mealFactory->createBurger(burgerType);
    GarlicBread* garlicBread = mealFactory->createGarlicBread(garlicBreadType);

    burger->prepare();
    garlicBread->prepare();

    return 0;
}