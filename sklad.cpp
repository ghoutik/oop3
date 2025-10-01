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
    if (count >= capacity) throw "����� ������!";
    items[count++] = t;
}

void Sklad::printAll() const {
    if (count == 0) {
        cout << "����� �������.\n";
        return;
    }
    cout << "=== ���� ������ ===\n";
    for (int i = 0; i < count; i++) {
        cout << i << ". ";
        items[i].print();
    }
}

void Sklad::incrementQuantity(int index) {
    if (index < 0 || index >= count) throw "������� ������";
    ++items[index];
}

void Sklad::decrementQuantity(int index) {
    if (index < 0 || index >= count) throw "������� ������";
    --items[index];
}

void Sklad::replaceTovar(int index, const Tovar& t) {
    if (index < 0 || index >= count) throw "������� ������";
    items[index] = t;
}

void Sklad::searchByName(const string& name) const {
    cout << "����� �� ������ '" << name << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getName() == name) items[i].print();
}

void Sklad::searchByQuantity(int quantity) const {
    cout << "����� �� ������� '" << quantity << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getQuantity() == quantity) items[i].print();
}

void Sklad::searchByPrice(double price) const {
    cout << "����� �� ����� '" << price << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getPrice() == price) items[i].print();
}
