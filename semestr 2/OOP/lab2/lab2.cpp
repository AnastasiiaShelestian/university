#include <iostream>
#include <string>

using namespace std;

class Side {
private:
	double length;

public:
	Side(double length)
	{
		this->length = length;
	}
	double getLength() {
		return length;
	}
};

class Hexagon: public Side {
public:
	Hexagon(double length) : Side(length) {}
};

class Pencil : public Hexagon {
private:
	Pencil()
};





int main()
{
    std::cout << "Hello World!\n";
}

