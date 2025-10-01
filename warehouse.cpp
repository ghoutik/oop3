#include "warehouse.h"
#include <iostream>
using namespace std;

warehouse::warehouse(int maxSize) {
    capacity = maxSize;
    count = 0;
    items = new Product[capacity];
}

warehouse::~warehouse() {
    delete[] items;
}

void warehouse::addProduct(const Product& t) {
    if (count >= capacity) throw "Warehouse is full!";
    items[count++] = t;
}

void warehouse::printAll() const {
    if (count == 0) {
        cout << "Warehouse is empty.\n";
        return;
    }
    cout << "=== Warehouse Contents ===\n";
    for (int i = 0; i < count; i++) {
        cout << i << ". ";
        items[i].print();
    }
}

void warehouse::incrementQuantity(int index) {
    if (index < 0 || index >= count) throw "Invalid index";
    ++items[index];
}

void warehouse::decrementQuantity(int index) {
    if (index < 0 || index >= count) throw "Invalid index";
    --items[index];
}

void warehouse::replaceProduct(int index, const Product& t) {
    if (index < 0 || index >= count) throw "Invalid index";
    items[index] = t;
}

void warehouse::search(const string& name) const {
    cout << "Search by name '" << name << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getName() == name) items[i].print();
}

void warehouse::search(int quantity) const {
    cout << "Search by quantity '" << quantity << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getQuantity() == quantity) items[i].print();
}

void warehouse::search(double price) const {
    cout << "Search by price '" << price << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getPrice() == price) items[i].print();
}
