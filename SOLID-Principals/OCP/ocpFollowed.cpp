#include<iostream>
#include<vector>

using namespace std;

class Product{
public:   
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;      
    }
};

class ShopingCart{
private:
    vector<Product*> products;

public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*> & getProduct(){
        return products;
    }

    // Calculate total price in cart
    double calculateTotalPrice(){
        double total = 0;

        for(auto p : products){
            total += p->price;
        }

        return total;
    }      
};


class ShoppingCartPrinter{
    private:
        ShopingCart* cart;

    public:
        ShoppingCartPrinter(ShopingCart* cart){
            this->cart = cart;
        }

        void printInvoice(){
            cout<< "Shoping Cart Invoice:\n";
            for(auto p:cart->getProduct()){
                cout<<p->name << " - Rs "<<p->price<<endl;
            }

            cout<<"Total: Rs "<<cart->calculateTotalPrice()<< endl;
        }
};

class DBPersistant{
    private:
        ShopingCart* cart;
    public:
        virtual void save(ShopingCart* cart) = 0; //pure virtual function
};

class SQLPersistant : public DBPersistant{
    public:
        void save(ShopingCart *cart) override {
            cout<<"Saving shoping cart to SQL DB..."<<endl;
        }      
};

class MongoPersistant : public DBPersistant{
    public:
        void save(ShopingCart *cart) override {
            cout<<"Saving shoping cart to MongoDB..."<<endl;
        }      
};
class FilePersistant : public DBPersistant{
    public:
        void save(ShopingCart *cart) override {
            cout<<"Saving shoping cart to File..."<<endl;
        }      
};

int main(){
    ShopingCart * cart = new ShopingCart();
    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    DBPersistant* db = new SQLPersistant();
    DBPersistant* mongo = new MongoPersistant();
    DBPersistant* file = new FilePersistant();
    
    db->save(cart);  // Save to Sql
    mongo->save(cart); // Save to mongo
    file->save(cart); // Save to File

    return 0;
}