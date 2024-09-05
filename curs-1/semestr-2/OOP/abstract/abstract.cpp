//
//#include <iostream>
//using namespace std;
//enum class Day {
//    Monday = 1,
//    Tuesday,
//    Wednesday,
//    Thursday,
//    Friday,
//    Saturday,
//    Sunday
//};
//
//class Shape {
//public : 
//
//
//    virtual double getSquare() const = 0;
//    virtual double getPerimeter() const = 0;
//
//
//};
//
//class Rectangle: public Shape {
//public: 
//    Rectangle(double width, double height)
//    {
//        this->width = width;
//        this->height = height; 
//
//    }
//    double getSquare() const override {
//        return  width * height;
//            
//    }
//    double getPerimeter() const override {
//        return  (width + height) * 2;
//    }
//private:
//    double width;
//    double height;
//
//};
//
//class Circle : public Shape {
//public:
//    Circle (double radius)
//    {
//        this->radius = radius;
//        this->day = Day::Saturday;
//    }
//    double getSquare() const override {
//        return  radius * radius * 3.14;
//
//    }
//    double getPerimeter() const override {
//        return  radius * 3.14 * 2;
//    }
//
//    void getDayNum() {
//        cout << static_cast<int>(day);
//    }
//
//    static void getCount() {
//        cout << count << endl;
//    }
//
//private:
//    double radius;
//    Day day;
//    static inline int count = 0;
//};
//
//int main()
//{
//
//    Circle b(5);
//    Circle::getCount();
//    Circle b1(58);
//    Circle b2(36);
//    Circle b3(12);
//    Circle::getCount();
//
//    
//}
//

#include <iostream>
//
//class Person;
//
//class Auto
//{
//    friend Person;
//    friend void drive(const Auto&);
//    friend void setPrice(Auto&, unsigned);
//public:
//    Auto(std::string autoName, unsigned autoPrice)
//    {
//        name = autoName;
//        price = autoPrice;
//    }
//    void print()
//    {
//        std::cout << name << " : " << price << std::endl;
//    }
//
//private:
//    std::string name;   // название автомобиля
//    unsigned price;  // цена автомобиля
//};
//
//void drive(const Auto& car)
//{
//    std::cout << car.name << " is driven" << std::endl;
//}
//
//void setPrice(Auto& car, unsigned price)
//{
//    car.price = price;
//}
//
//class Person {
//    void someMethod(Auto& car) {
//        car.price = 9999;
//    }
//};
//
//int main()
//{
//    Auto tesla("Tesla", 5000);
//    tesla.print();  //
//    drive(tesla);
//    setPrice(tesla, 8000);
//    tesla.print();  //
//}

class Counter
{
public:
    Counter(int val)
    {
        value = val;
    }
    void print()
    {
        std::cout << "Value: " << value << std::endl;
    }
    //Counter operator + (const Counter& counter) const
    //{
    //    return Counter{ value + counter.value };
    //}
    int value;
};

bool operator < (const Counter& c1, const Counter& c2)
{
    return Counter{ c1.value + c2.value };
}   

int main()
{
    Counter c1{ 20 };
    Counter c2{ 10 };
    Counter c3 = c1 + c2;
    c3.print();   // Value: 30
}
