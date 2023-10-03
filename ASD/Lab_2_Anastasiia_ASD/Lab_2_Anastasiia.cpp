#include <stdio.h>

int main()
{
	int i;
	i = 69;
	int number = 72;
	i = 69 + 72;
	int arr[3] = {};
	arr[0];
	arr[1];
	arr[2];
	int* iPointer = &i;
	number = *iPointer;
	*iPointer = 15;
	iPointer = &arr[0];
	iPointer = iPointer + 2;
	arr[0] = 5;
	*iPointer = 6;

}