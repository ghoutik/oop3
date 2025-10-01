#include <iostream>
#include <string>
using namespace std;

class Tovar {
private:
    string name;
    int quantity;
    double price;

public:
    Tovar(const string& n = "", int q = 0, double p = 0.0) {
        setName(n);
        setQuantity(q);
        setPrice(p);
    }

    void setName(const string& n) { name = n; }

    void setQuantity(int q) {
        if (q < 0) throw "ʳ������ �� ���� ���� ��'�����!";
        quantity = q;
    }

    void setPrice(double p) {
        if (p < 0) throw "ֳ�� �� ���� ���� ��'�����!";
        price = p;
    }

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    Tovar& operator++() { ++quantity; return *this; }

    Tovar& operator--() {
        if (quantity > 0) --quantity;
        else throw "ʳ������ ��� 0";
        return *this;
    }

    Tovar& operator=(const Tovar& other) {
        if (this != &other) {
            name = other.name;
            quantity = other.quantity;
            price = other.price;
        }
        return *this;
    }

    void print() const {
        cout << name << " | " << quantity << " �� | " << price << " ���\n";
    }
};
