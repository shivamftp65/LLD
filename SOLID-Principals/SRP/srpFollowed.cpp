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

//2. ShoppingCartStorage - Only reponsible for saving the cart to DB
class ShoppingCartStorage{
    private:
        ShopingCart* cart;

    public:
        ShoppingCartStorage(ShopingCart* cart){
            this->cart = cart;
        }

        void saveToDatabase(){
            cout<<"Saving shoping cart to database..."<<endl;
        } 
};

//2. ShoppingCartPrinter - Only reponsible for printing Invoice
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

int main(){
    ShopingCart * cart = new ShopingCart();
    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToDatabase();
    
    return 0;
}