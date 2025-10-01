#include "warehouse.h"
#include <iostream>
using namespace std;

warehouse::warehouse(int maxSize) {
    capacity = maxSize;
    count = 0;
    items = new product[capacity];
}

warehouse::~warehouse() {
    delete[] items;
}

void warehouse::addTovar(const product& t) {
    if (count >= capacity) throw "����� ������!";
    items[count++] = t;
}

void warehouse::printAll() const {
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

void warehouse::incrementQuantity(int index) {
    if (index < 0 || index >= count) throw "������� ������";
    ++items[index];
}

void warehouse::decrementQuantity(int index) {
    if (index < 0 || index >= count) throw "������� ������";
    --items[index];
}

void warehouse::replaceProduct(int index, const product& t) {
    if (index < 0 || index >= count) throw "������� ������";
    items[index] = t;
}

void warehouse::search(const string& name) const {
    cout << "����� �� ������ '" << name << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getName() == name) items[i].print();
}

void warehouse::search(int quantity) const {
    cout << "����� �� ������� '" << quantity << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getQuantity() == quantity) items[i].print();
}

void warehouse::search(double price) const {
    cout << "����� �� ����� '" << price << "':\n";
    for (int i = 0; i < count; i++)
        if (items[i].getPrice() == price) items[i].print();
}
