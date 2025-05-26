#include<iostream>

using namespace std;

class MySQLDatabase{
    public:
        void saveTOSQL(string data){
            cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
        }
};

class MongoDbDatabase{
    public:
        void saveTOMongo(string data){
            cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
        }
};

class UserService{
    private:
        MySQLDatabase sqlDb;
        MongoDbDatabase mongoDb;
    public:
        void storeUserToSql(string user){
            sqlDb.saveTOSQL(user);
        }

        void storeUserToMongo(string user){
            mongoDb.saveTOMongo(user);
        }
};

int main(){
    UserService service;
    service.storeUserToSql("Aditya");
    service.storeUserToMongo("Rohit");

    return 0;
}