#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hotel {
private :
    string name;
    string addres;
    string number;
    int stars;

    // конструктор без примеров
public:
    Hotel() {
        name = "";
        addres = "";
        number = "";
        stars = 0;
    }
    // конструктор c примерами 
    Hotel(string name, string addres, string number, int stars) {
        this->name = name;
        this->addres = addres;
        this->number = number;
        this->stars = stars;
    }

    void showInfo() {
        cout << "name: "<< name << endl;
        cout << "addres: " << addres << endl;
        cout << "number: " << number << endl;
        cout << "stars: " << stars << endl;
    }

    void input() {
        cout << "enter name: ";
        cin >> name;
        cout << "enter addres: ";
        cin >> addres;
        cout << "enter number: ";
        cin >> number;
        cout << "enter stars: ";
        cin >> stars;
    }


  
};

int main(){

    Hotel Hotel1("Paradise", "Shtefan cel Mare", "264684684", 5);
    Hotel hotel2;
    hotel2.input(); 

    cout << "info about hotel" << endl;

    Hotel1.showInfo();
    hotel2.showInfo();

    vector<Hotel> hotels;
    int choise;

    do {
        cout << "Menu: " << endl;
        cout << "1. hotel rating: " << endl;
        cout << "0. create a new hotel: " << endl;
        cout << "2. create a new review:  " << endl;
        cout << "3. busy hotel: " << endl;
        cin >> choise;


        switch (choise) {
        case 1:
            cout << "hotel rating: " << endl;
            for (int i = 0; i < hotels.size(); i++)
        }
    }


}






