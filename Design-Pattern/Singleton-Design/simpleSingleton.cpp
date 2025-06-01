#include<iostream>

using namespace std;

class Singleton{
    private:
        static Singleton* instance;
        Singleton(){
            cout<<"Singleton contructor called. New Object created"<<endl;
        }

    public:
        static Singleton* getInstance(){
            if(instance == nullptr){
                instance = new Singleton();  // critical section, multiple threads can access this line
            }
            return instance;   
        }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main(){

    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout<< (s1 == s2)<<endl;

    return 0;
}