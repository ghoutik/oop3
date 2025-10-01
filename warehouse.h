#include "product.h"

class warehouse {
private:
    product* items;
    int count;
    int capacity;

public:
    warehouse(int maxSize = 10);
    ~warehouse();

    void addTovar(const product& t);
    void printAll() const;

    void incrementQuantity(int index);
    void decrementQuantity(int index);
    void replaceProduct(int index, const product& t);

    void search(const string& name) const;
    void search(int quantity) const;
    void search(double price) const;
};