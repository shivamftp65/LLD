#include<iostream>

using namespace std;

// A precondition must be satistfied before a method can execute
// Sub classes can waeken the precondition but cannot strengthen it.

class User{
public:
    // Precondition: Password must be atleast 8 characters long
    virtual void setPassword(string password){
        if(password.length() < 8){
            throw invalid_argument("Password must be at least 8 characters long!");
        }
        cout<< "Password set successfully"<<endl;
    }
};

class AdminUser : public User{
    //Precondition : Password must be at least 6 characters
    void setPassword(string password) override {
        if(password.length() < 6){
            throw invalid_argument("Password must be at least 6 characters long!");
        }
        cout<< "Password set successfully"<<endl;
    }
};

int main(){
    User* user = new AdminUser();
    user->setPassword("Admin"); // Works fine : Admin allows shorter password
    
    return 0;
}