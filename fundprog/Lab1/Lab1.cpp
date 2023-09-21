#include <iostream>
using namespace std;
int main()
{
	float x, y;
	for (x = 0; x <= 40; x += 2)
	{
		if (x < 20)
		{
			y = 0.3 * x + 1 / x;
		}
		else {
			y = sqrt(x * x + 3 * x) / 0.7;
		}
		cout << x << " " << y << endl;
	}
}
	

