#include <iostream>
using namespace std;

int main()
{
	int i;
	i = 69;
	cout << "  " << endl;

	int number = 72;
	i = 69 + 72;
	int arr[3] = {};
	int* iPointer = &i;
	number = *iPointer;
	*iPointer = 15;
	iPointer = &arr[0];
	iPointer = iPointer + 2;
	arr[0] = 5;
	*iPointer = 6;
	cout << "Hello!";
}