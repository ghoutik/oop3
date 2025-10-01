#include "warehouse.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    warehouse warehouse;
    int choice;

    do {
        cout << "1. Add product\n";
        cout << "2. Increase product quantity\n";
        cout << "3. Decrease product quantity\n";
        cout << "4. Replace product\n";
        cout << "5. Search product by name\n";
        cout << "6. Search product by quantity\n";
        cout << "7. Search product by price\n";
        cout << "8. Show all products\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int quantity;
            double price;

            cout << "Enter product name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;

            try {
                Product t(name, quantity, price);
                warehouse.addProduct(t);
                cout << "Product added.\n";
            }
            catch (const char* msg) {
                cerr << "Error: " << msg << endl;
            }
            break;
        }

        case 2: {
            int index;
            cout << "Enter product number to increase quantity: ";
            cin >> index;

            try {
                warehouse.incrementQuantity(index);
                cout << "Quantity increased.\n";
            }
            catch (const char* msg) {
                cerr << "Error: " << msg << endl;
            }
            break;
        }

        case 3: {
            int index;
            cout << "Enter product number to decrease quantity: ";
            cin >> index;

            try {
                warehouse.decrementQuantity(index);
                cout << "Quantity decreased.\n";
            }
            catch (const char* msg) {
                cerr << "Error: " << msg << endl;
            }
            break;
        }

        case 4: {
            int index;
            cout << "Enter product number to replace: ";
            cin >> index;

            string name;
            int quantity;
            double price;

            cout << "Enter new name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter new quantity: ";
            cin >> quantity;
            cout << "Enter new price: ";
            cin >> price;

            try {
                Product t(name, quantity, price);
                warehouse.replaceProduct(index, t);
                cout << "Product replaced.\n";
            }
            catch (const char* msg) {
                cerr << "Error: " << msg << endl;
            }
            break;
        }

        case 5: {
            string name;
            cout << "Enter name to search: ";
            cin >> ws;
            getline(cin, name);
            warehouse.search(name);
            break;
        }

        case 6: {
            int q;
            cout << "Enter quantity to search: ";
            cin >> q;
            warehouse.search(q);
            break;
        }

        case 7: {
            double p;
            cout << "Enter price to search: ";
            cin >> p;
            warehouse.search(p);
            break;
        }

        case 8:
            warehouse.printAll();
            break;

        case 0:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}