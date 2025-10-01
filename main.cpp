#include "Sklad.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Sklad sklad;
    int choice;

    do {
        cout << "1. Додати товар\n";
        cout << "2. Збільшити кількість товару\n";
        cout << "3. Зменшити кількість товару\n";
        cout << "4. Замінити товар\n";
        cout << "5. Пошук товару за назвою\n";
        cout << "6. Пошук товару за кількістю\n";
        cout << "7. Пошук товару за ціною\n";
        cout << "8. Показати всі товари\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int quantity;
            double price;

            cout << "Введіть назву товару: ";
            cin >> ws;
            getline(cin, name);
            cout << "Введіть кількість: ";
            cin >> quantity;
            cout << "Введіть ціну: ";
            cin >> price;

            try {
                Tovar t(name, quantity, price);
                sklad.addTovar(t);
                cout << "Товар додано.\n";
            }
            catch (const char* msg) {
                cerr << "Помилка: " << msg << endl;
            }
            break;
        }

        case 2: {
            int index;
            cout << "Введіть номер товару для збільшення кількості: ";
            cin >> index;

            try {
                sklad.incrementQuantity(index);
                cout << "Кількість збільшено.\n";
            }
            catch (const char* msg) {
                cerr << "Помилка: " << msg << endl;
            }
            break;
        }

        case 3: {
            int index;
            cout << "Введіть номер товару для зменшення кількості: ";
            cin >> index;

            try {
                sklad.decrementQuantity(index);
                cout << "Кількість зменшено.\n";
            }
            catch (const char* msg) {
                cerr << "Помилка: " << msg << endl;
            }
            break;
        }

        case 4: {
            int index;
            cout << "Введіть номер товару для заміни: ";
            cin >> index;

            string name;
            int quantity;
            double price;

            cout << "Введіть нову назву: ";
            cin >> ws;
            getline(cin, name);
            cout << "Введіть нову кількість: ";
            cin >> quantity;
            cout << "Введіть нову ціну: ";
            cin >> price;

            try {
                Tovar t(name, quantity, price);
                sklad.replaceTovar(index, t);
                cout << "Товар замінено.\n";
            }
            catch (const char* msg) {
                cerr << "Помилка: " << msg << endl;
            }
            break;
        }

        case 5: {
            string name;
            cout << "Введіть назву для пошуку: ";
            cin >> ws;
            getline(cin, name);
            sklad.searchByName(name);
            break;
        }

        case 6: {
            int q;
            cout << "Введіть кількість для пошуку: ";
            cin >> q;
            sklad.searchByQuantity(q);
            break;
        }

        case 7: {
            double p;
            cout << "Введіть ціну для пошуку: ";
            cin >> p;
            sklad.searchByPrice(p);
            break;
        }

        case 8:
            sklad.printAll();
            break;

        case 0:
            cout << "Вихід з програми.\n";
            break;

        default:
            cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}