#include<iostream>

using namespace std;

//Class Invarient of a parent class Object should not be broken by child class Object.
// Hence child class can either maintain or strenthen the invarient but never narrows it down

//Invarients : Balance cannot be negative
class BankAccount{
    protected:
        double balance;
    public:
        BankAccount(double b){
            if(b<=0){
                throw invalid_argument("Balance can't be negative");
            }
            balance = b;
        }

        virtual void withdraw(double amount){
            if(balance-amount < 0) throw runtime_error("Insufficient funds");
            balance -= amount;
            cout<<"Amount withdrawn. Remaining balance is "<<balance<<endl;
        }
};

// Brake invarients: Should not be allowed
class CheatAccount:public BankAccount{
    public:
        CheatAccount(double b): BankAccount(b) {}

        void withdraw(double amount) override{
            balance -= amount; // lsp break! Negative balance allowed
            cout<<"Amount withdrawn. Remaining balance is "<<balance<<endl;
        }
};

int main(){
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);
}