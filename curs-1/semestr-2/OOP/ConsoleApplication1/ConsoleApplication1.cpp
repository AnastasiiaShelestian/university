#include <iostream>
#include <cmath> // для математических операций

using namespace std;

// Базовый класс для стороны с заданной длиной
class Side {
protected:
    double length; // длина стороны

public:
    Side(double len) : length(len) {} // конструктор

    double getLength() const { return length; } // получить длину
};

// Класс для шестиугольника, расширяющий Side
class Hexagon : public Side {
public:
    Hexagon(double len) : Side(len) {} // конструктор
};

// Класс карандаша, расширяющий Hexagon
class Pencil : public Hexagon {
private:
    bool isHard; // определяет, твердый или мягкий карандаш

public:
    Pencil(bool hard, double len) : Hexagon(len), isHard(hard) {} // конструктор

   

    double getWearSpeed() const {
        // скорость износа (мягкий 3 мм/день, твердый 2 мм/день)
        return isHard ? 2 : 3;
    }

    bool isHardness() const { return isHard; } // проверить твердость
};

int main() {
    // Создание карандашей
    Pencil pencil1(true, 150); // твердый карандаш, длина 150 мм
    Pencil pencil2(false, 120); // мягкий карандаш, длина 120 мм
    Pencil pencil3(false, 100); // мягкий карандаш, длина 100 мм

    // Вывод характеристик
    cout << "Карандаш 1:\n";
    cout << "Твердость: " << (pencil1.isHardness() ? "твердый" : "мягкий") << endl;
    cout << "Длина: " << pencil1.getLength() << " мм" << endl;
    cout << "Объем: " << pencil1.getVolume() << " куб. мм" << endl;
    cout << "Скорость износа: " << pencil1.getWearSpeed() << " мм/день\n\n";

    cout << "Карандаш 2:\n";
    cout << "Твердость: " << (pencil2.isHardness() ? "твердый" : "мягкий") << endl;
    cout << "Длина: " << pencil2.getLength() << " мм" << endl;
    cout << "Объем: " << pencil2.getVolume() << " куб. мм" << endl;
    cout << "Скорость износа: " << pencil2.getWearSpeed() << " мм/день\n\n";

    cout << "Карандаш 3:\n";
    cout << "Твердость: " << (pencil3.isHardness() ? "твердый" : "мягкий") << endl;
    cout << "Длина: " << pencil3.getLength() << " мм" << endl;
    cout << "Объем: " << pencil3.getVolume() << " куб. мм" << endl;
    cout << "Скорость износа: " << pencil3.getWearSpeed() << " мм/день\n\n";

    // Определение, какой карандаш спишется быстрее
    double wearSpeed1 = pencil1.getWearSpeed();
    double wearSpeed2 = pencil2.getWearSpeed();
    double wearSpeed3 = pencil3.getWearSpeed();

    if (wearSpeed1 < wearSpeed2 && wearSpeed1 < wearSpeed3) {
        cout << "Карандаш 1 спишется быстрее\n";
    }
    else if (wearSpeed2 < wearSpeed1 && wearSpeed2 < wearSpeed3) {
        cout << "Карандаш 2 спишется быстрее\n";
    }
    else {
        cout << "Карандаш 3 спишется быстрее\n";
    }

    return 0;
}
