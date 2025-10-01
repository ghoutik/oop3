#include <iostream>
#include <string>
using namespace std;

class product {
private:
    string name;
    int quantity;
    double price;

public:
    product(const string& n = "", int q = 0, double p = 0.0) {
        setName(n);
        setQuantity(q);
        setPrice(p);
    }

    void setName(const string& n) { name = n; }

    void setQuantity(int q) {
        if (q < 0) throw "Кількість не може бути від'ємною!";
        quantity = q;
    }

    void setPrice(double p) {
        if (p < 0) throw "Ціна не може бути від'ємною!";
        price = p;
    }

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    product& operator++() { ++quantity; return *this; }

    product& operator--() {
        if (quantity > 0) --quantity;
        else throw "Кількість вже 0";
        return *this;
    }

    product& operator=(const product& other) {
        if (this != &other) {
            name = other.name;
            quantity = other.quantity;
            price = other.price;
        }
        return *this;
    }

    void print() const {
        cout << name << " | " << quantity << " шт | " << price << " грн\n";
    }
};
