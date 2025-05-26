#include<iostream>

using namespace std;

class DatabasePersistant{
    public:
        virtual void save(string data) = 0;
};

class MySQLDatabase: public DatabasePersistant{
    public:
        void save(string data) override {
            cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
        }
};

class MongoDbDatabase : public DatabasePersistant{
    public:
        void save(string data) override {
            cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
        }
};

class UserService{
    private:
        DatabasePersistant* db;
    public:
        UserService(DatabasePersistant* database){
            this->db = database;
        }

        void storeUser(string user){
            db->save(user);
        }
};

int main(){
    MySQLDatabase mysql;
    MongoDbDatabase mongodb;

    UserService service1(&mysql);
    service1.storeUser("Aditya");

    UserService service2(&mongodb);
    service2.storeUser("ROhit");

    return 0;
}