#include "Tovar.h"

class Sklad {
private:
    Tovar* items;
    int count;
    int capacity;

public:
    Sklad(int maxSize = 10);
    ~Sklad();

    void addTovar(const Tovar& t);
    void printAll() const;

    void incrementQuantity(int index);
    void decrementQuantity(int index);
    void replaceTovar(int index, const Tovar& t);

    void searchByName(const string& name) const;
    void searchByQuantity(int quantity) const;
    void searchByPrice(double price) const;
};