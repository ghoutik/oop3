#include "Sklad.h"
#include <iostream>
using namespace std;

Sklad::Sklad(int maxSize) {
    capacity = maxSize;
    count = 0;
    items = new Tovar[capacity];
}

Sklad::~Sklad() {
    delete[] items;
}

void Sklad::addTovar(const Tovar& t) {
    if (count >= capacity) throw "Склад повний!";
    items[count++] = t;
}

void Sklad::printAll() const {
    if (count == 0) {
        cout << "Склад порожній.\n";
        return;
    }
    cout << "=== Вміст складу ===\n";
    for (int i = 0; i < count; i++) {
        cout << i << ". ";
        items[i].print();
    }
}

void Sklad::incrementQuantity(int index) {
    if (index < 0 || index >= count) throw "Невірний індекс";
    ++items[index];
}

void Sklad::decrementQuantity(int index) {
    if (index < 0 || index >= count) throw "Невірний індекс";
    --items[index];
}

void Sklad::replaceTovar(int index, const Tovar& t) {
    if (index < 0 || index >= count) throw "Невірний індекс";
    items[index] = t;
}

void Sklad::searchByName(const string& name) const {
    cout << "Пошук за назвою '" << name << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getName() == name) items[i].print();
}

void Sklad::searchByQuantity(int quantity) const {
    cout << "Пошук за кількістю '" << quantity << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getQuantity() == quantity) items[i].print();
}

void Sklad::searchByPrice(double price) const {
    cout << "Пошук за ціною '" << price << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getPrice() == price) items[i].print();
}
