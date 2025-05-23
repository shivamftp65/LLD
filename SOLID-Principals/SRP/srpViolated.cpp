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

    // 2. Violated SRP - print invoice(should be in seperate class) 
    void printInvoice(){
        cout<< "Shoping Cart Invoice:\n";
        for(auto p:products){
            cout<<p->name << " - Rs "<<p->price<<endl;
        }

        cout<<"Total: Rs "<<calculateTotalPrice()<< endl;
    }

    // 3. Violated SRP - Saved to DB(should be in seperate class) 
    void saveToDatabase(){
        cout<<"Saving shoping cart to database..."<<endl;
    }        
};

int main(){
    ShopingCart * cart = new ShopingCart();
    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    cart->printInvoice();
    cart->saveToDatabase();
    
    return 0;
}