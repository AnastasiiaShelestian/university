#pragma once
#include <span>
using namespace std;

struct DynamicArray
{
	int* addres;
	size_t capacity;
	size_t count;
};

void addElementToArray(DynamicArray* arr, int n);
DynamicArray createarray(size_t capacity);
DynamicArray createarray();
span<int> getCurrentSpan(DynamicArray* arr); 
void deleteArray(DynamicArray* arr);
int getElementAtIndex(DynamicArray* arr, size_t index);