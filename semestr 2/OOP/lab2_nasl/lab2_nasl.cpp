#include <iostream>
using namespace std;


class Side {
protected:
    double length;

public:
    Side(double len) : length(len) {}

    virtual double getArea() const = 0;
};

class Hexagon : public Side {
public:
    Hexagon(double len) : Side(len) {}

    double getArea() const override {
        return 3 * sqrt(3) * length * length / 2;
    }
};

class Pencil : public Hexagon {
protected:
    bool soft;

public:
    Pencil(double len, bool isSoft) : Hexagon(len), soft(isSoft) {}

    double getVolume() const {
        return getArea() * length;
    }

    double getRateOfUsage() const {
        return soft ? 3 : 2; 
    }

    void printCharacteristics() const {
        cout << "Pencil Characteristics:" << endl;
        cout << "Length: " << length << " mm" << endl;
        cout << "Area: " << getArea() << " mm^2" << endl;
        cout << "Volume: " << getVolume() << " mm^3" << endl;
        cout << "Rate of Usage: " << getRateOfUsage() << " mm/day" << endl;
        cout << "Softness: " << (soft ? "Soft" : "Hard") << endl;
    }
};

int main() {
    Pencil pencil1(10, true); 
    Pencil pencil2(25, true); 
    Pencil pencil3(33, false);

    pencil1.printCharacteristics();
    cout << endl;
    pencil2.printCharacteristics();
    cout << endl;
    pencil3.printCharacteristics();
    cout << endl;

    double days1 = 100 / pencil1.getRateOfUsage(); 
    double days2 = 100 / pencil2.getRateOfUsage(); 
    double days3 = 100 / pencil3.getRateOfUsage(); 

    cout << "Days for pencil1 to wear out: " << days1 << " days" << endl;
    cout << "Days for pencil2 to wear out: " << days2 << " days" << endl;
    cout << "Days for pencil3 to wear out: " << days3 << " days" << endl;

    return 0;
}
