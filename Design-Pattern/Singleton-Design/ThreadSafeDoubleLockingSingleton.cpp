#include<iostream>
#include<mutex>

class Singleton {
private:
    static Singleton* instance;
    static std::mutex mtx; // Use std::mutex explicitly

    Singleton() {
        std::cout << "Singleton constructor called. New Object created" << std::endl;
    }

public:
    // Double check locking
    static Singleton* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mtx); // Also use std::mutex here
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx; // Again, std::mutex here

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    std::cout << (s1 == s2) << std::endl; // Should print 1 (true)

    return 0;
}
