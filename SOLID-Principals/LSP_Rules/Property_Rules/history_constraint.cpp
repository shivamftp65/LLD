#include<iostream>

using namespace std;

// sub class methods should not be allowed state changes what base class never allowed.


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

        // History Constraint : Withdrawal should be allowed
        virtual void withdraw(double amount){
            if(balance-amount < 0) throw runtime_error("Insufficient funds");
            balance -= amount;
            cout<<"Amount withdrawn. Remaining balance is "<<balance<<endl;
        }
};

class FixedDepositAccount : public BankAccount{
    public: 
        FixedDepositAccount(double b): BankAccount(b) {}

        //LSP break! History constraint break!
        //Parent class behavior change : Now withdrawal is not allowed.
        // This class will  break client code that relies on withdrawal
        void withdraw(double amount) override{
            throw runtime_error("Withdrawal not allowed in Fixed Deposit");
        }
};

int main(){
    BankAccount* bankAccount = new BankAccount(100);
    // BankAccount* bankAccount = new FixedDepositAccount(100);

    bankAccount->withdraw(100);
}