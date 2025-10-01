#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int quantity;
    double price;

public:
    Product(const string& n = "", int q = 0, double p = 0.0) {
        setName(n);
        setQuantity(q);
        setPrice(p);
    }

    void setName(const string& n) { name = n; }

    void setQuantity(int q) {
        if (q < 0) throw "Quantity cannot be negative!";
        quantity = q;
    }

    void setPrice(double p) {
        if (p < 0) throw "Price cannot be negative!";
        price = p;
    }

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    Product& operator++() {
        ++quantity;
        return *this;
    }

    Product& operator--() {
        if (quantity > 0) --quantity;
        else throw "Quantity is already 0";
        return *this;
    }

    Product& operator=(const Product& other) {
        if (this != &other) {
            name = other.name;
            quantity = other.quantity;
            price = other.price;
        }
        return *this;
    }

    void print() const {
        cout << name << " | " << quantity << " pcs | " << price << " UAH\n";
    }
};
