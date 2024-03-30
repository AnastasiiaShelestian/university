#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string productName;
    float price;
    int quantity;


public:
    Product(string name, float cost, int qty) {
        this->productName = name;
        this->price = cost;
        this->quantity = qty;
    }

    float calculateTotalCost(int qty) {
        return price * qty;
    }

    void displayProductDetails() {
        cout << "Product: " << productName << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity available: " << quantity << endl;
    }
};

class Electronics : public Product {
private:
    int warrantyPeriod;
    string manufacturer;

public:
    Electronics(string name, float cost, int qty, int warranty, string manu)
        : Product(name, cost, qty) {
        this->warrantyPeriod = warranty; this->manufacturer = manu;
    }

    void extendWarranty(int months) {
        warrantyPeriod += months;
    }

    void updateManufacturer(string newManufacturer) {
        manufacturer = newManufacturer;
    }
};

class Clothing : public Product {
private:
    string size;

public:
    Clothing(string name, float cost, int qty, string sz)
        : Product(name, cost, qty) {
        this->size = sz;
    }

    void changeSize(string newSize) {
        size = newSize;
    }

    bool isSizeAvailable(string newSize) {
        return size == newSize;
    }
};

int main() {
    Clothing aaaa("bbb", 5, 5, "S");
    aaaa.changeSize("M");
    cout << aaaa.isSizeAvailable("M");

    return 0;
}