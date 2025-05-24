#include<iostream>
#include<vector>

using namespace std;

class DepositOnlyAccount{
    public:
        virtual void deposit(double amount) = 0;
};

class WithdrwableAccount:public DepositOnlyAccount{
    public:
        virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrwableAccount{
    private:
        double balance;
    public:
        SavingAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance += amount;
            cout<<"Deposited: "<<amount <<" in saving account. New Balance: "<< balance<<endl;
        }

        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
                cout<<"Withdrawn: "<<amount <<" from saving account. New Balance: "<< balance<<endl;
            }else{
                cout<<"Insufficient funds in Saving Account!\n";
            }
        }
};

class CurrentAccount: public WithdrwableAccount{
    private:
        double balance;
    public:
        CurrentAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance += amount;
            cout<<"Deposited: "<<amount <<" in Current Account. New Balance: "<< balance<<endl;
        }

        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
                cout<<"Withdrawn: "<<amount <<" from Current Account. New Balance: "<< balance<<endl;
            }else{
                cout<<"Insufficient funds in Current Account!\n";
            }
        }
};

class FixedTermAccount:public DepositOnlyAccount{
    private:
        double balance;
    public:
        FixedTermAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance += amount;
            cout<<"Deposited: "<<amount <<" in saving account. New Balance: "<< balance<<endl;
        }
};

class BanKClient{
    private:
        vector<WithdrwableAccount*> withdrwableaccounts;
        vector<DepositOnlyAccount*> depositOnlyaccounts;
    public:
        BanKClient(vector<WithdrwableAccount*> withdrwableaccounts, vector<DepositOnlyAccount*> depositOnlyaccounts){
            this->withdrwableaccounts = withdrwableaccounts;
            this->depositOnlyaccounts = depositOnlyaccounts;
        }

        void processTransaction(){
            for(WithdrwableAccount* acc : withdrwableaccounts){
                acc->deposit(1000);
                acc->withdraw(500);
            }

            for(DepositOnlyAccount* acc : depositOnlyaccounts){
                acc->deposit(5000);
            }
        }
};

int main(){
    vector<WithdrwableAccount*>withdrawableAccouns;
    withdrawableAccouns.push_back(new SavingAccount());
    withdrawableAccouns.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*>depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BanKClient* client = new BanKClient(withdrawableAccouns,depositOnlyAccounts);
    client->processTransaction(); 
    
    return 0;
}