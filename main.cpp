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
        cout << "1. ������ �����\n";
        cout << "2. �������� ������� ������\n";
        cout << "3. �������� ������� ������\n";
        cout << "4. ������� �����\n";
        cout << "5. ����� ������ �� ������\n";
        cout << "6. ����� ������ �� �������\n";
        cout << "7. ����� ������ �� �����\n";
        cout << "8. �������� �� ������\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int quantity;
            double price;

            cout << "������ ����� ������: ";
            cin >> ws;
            getline(cin, name);
            cout << "������ �������: ";
            cin >> quantity;
            cout << "������ ����: ";
            cin >> price;

            try {
                Tovar t(name, quantity, price);
                sklad.addTovar(t);
                cout << "����� ������.\n";
            }
            catch (const char* msg) {
                cerr << "�������: " << msg << endl;
            }
            break;
        }

        case 2: {
            int index;
            cout << "������ ����� ������ ��� ��������� �������: ";
            cin >> index;

            try {
                sklad.incrementQuantity(index);
                cout << "ʳ������ ��������.\n";
            }
            catch (const char* msg) {
                cerr << "�������: " << msg << endl;
            }
            break;
        }

        case 3: {
            int index;
            cout << "������ ����� ������ ��� ��������� �������: ";
            cin >> index;

            try {
                sklad.decrementQuantity(index);
                cout << "ʳ������ ��������.\n";
            }
            catch (const char* msg) {
                cerr << "�������: " << msg << endl;
            }
            break;
        }

        case 4: {
            int index;
            cout << "������ ����� ������ ��� �����: ";
            cin >> index;

            string name;
            int quantity;
            double price;

            cout << "������ ���� �����: ";
            cin >> ws;
            getline(cin, name);
            cout << "������ ���� �������: ";
            cin >> quantity;
            cout << "������ ���� ����: ";
            cin >> price;

            try {
                Tovar t(name, quantity, price);
                sklad.replaceTovar(index, t);
                cout << "����� �������.\n";
            }
            catch (const char* msg) {
                cerr << "�������: " << msg << endl;
            }
            break;
        }

        case 5: {
            string name;
            cout << "������ ����� ��� ������: ";
            cin >> ws;
            getline(cin, name);
            sklad.searchByName(name);
            break;
        }

        case 6: {
            int q;
            cout << "������ ������� ��� ������: ";
            cin >> q;
            sklad.searchByQuantity(q);
            break;
        }

        case 7: {
            double p;
            cout << "������ ���� ��� ������: ";
            cin >> p;
            sklad.searchByPrice(p);
            break;
        }

        case 8:
            sklad.printAll();
            break;

        case 0:
            cout << "����� � ��������.\n";
            break;

        default:
            cout << "������� ����!\n";
        }

    } while (choice != 0);

    return 0;
}