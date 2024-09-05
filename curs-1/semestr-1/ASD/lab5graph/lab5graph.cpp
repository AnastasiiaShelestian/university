#include <iostream> 
#include <string> 

using namespace std;

class Product {
protected:
    string productName;
    double price;
    int quantity;

public:
    Product() {}
    Product(string name, double price, int quantity) {
        this->productName = name;
        this->price = price;
        this->quantity = quantity;
    }

    string getName() { return productName; }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }

    virtual double calculateTotalCost(int quantity) = 0;
    virtual void displayProductDetails() = 0;
};

class Electronics : public Product {
protected:
    int warrantyPeriod;
    string manufacturer;

public:
    Electronics() {}
    Electronics(string name, double price, int quantity, int warrantyPeriod, string manufacturer)
        : Product(name, price, quantity) {
        this->warrantyPeriod = warrantyPeriod;
        this->manufacturer = manufacturer;
    }

    double calculateTotalCost(int quantity) override { return price * quantity; }

    void displayProductDetails() override {
        cout << "\tЭлектроника:" << endl;
        cout << "Название: " << productName << endl;
        cout << "Цена: " << price << " лей." << endl;
        cout << "Количество: " << quantity << " шт." << endl;
        cout << "Гарантийный срок: " << warrantyPeriod << " месяцев" << endl;
        cout << "Производитель: " << manufacturer << endl;
    }

    void extendWarranty(int months) { warrantyPeriod += months; }
    void updateManufacturer(string newManufacturer) { manufacturer = newManufacturer; }
};

class Clothing : public Product {
protected:
    string size;

public:
    Clothing() {}
    Clothing(string name, double price, int quantity, string size) : Product(name, price, quantity) {
        this->size = size;
    }

    double calculateTotalCost(int quantity) override { return price * quantity; }

    void displayProductDetails() override {
        cout << "\tОдежда:" << endl;
        cout << "Название: " << productName << endl;
        cout << "Цена: " << price << " лей." << endl;
        cout << "Количество: " << quantity << " шт." << endl;
        cout << "Размер: " << size << endl;
    }

    void changeSize(string newSize) { size = newSize; }
    bool isSizeAvailable(string newSize) { return size == newSize; }
};

int main() {
    string productName, type;
    double price;
    int quantity;

    cout << "Введите тип продукта (электроника/одежда): ";
    cin >> type;
    cout << "Введите название продукта: ";
    cin >> productName;
    cout << "Введите цену: ";
    cin >> price;
    cout << "Введите количество: ";
    cin >> quantity;

    Product* product;
    if (type == "электроника") {
        int warrantyPeriod;
        string manufacturer;
        cout << "Введите гарантийный срок: ";
        cin >> warrantyPeriod;
        cout << "Введите производителя: ";
        cin >> manufacturer;
        product = new Electronics(productName, price, quantity, warrantyPeriod, manufacturer);
    }
    else if (type == "одежда") {
        string size;
        cout << "Введите размер: ";
        cin >> size;
        product = new Clothing(productName, price, quantity, size);
    }
    else {
        cout << "Неверный тип продукта!" << endl;
        return 1;
    }

    product->displayProductDetails();

    return 0;
}