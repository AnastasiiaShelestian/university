#include "dynamicArray.h"

void addElementToArray(DynamicArray* arr, int n)
{
	if (arr->count == arr->capacity)
	{
		size_t newSize = arr->capacity * 2;
		if (newSize == 0)
		{
			newSize = 1;
		}
		int* newArr = new int[newSize];

		for (size_t i = 0; i != arr->capacity; i++)
		{
			newArr[i] = arr->addres[i];
		}

		delete[] arr->addres;
		arr->addres = newArr;
		arr->capacity = newSize;
	}
	arr->addres[arr->count] = n;
	arr->count++;
};

DynamicArray createarray(size_t capacity)
{
	int* arr = new int[capacity];
	DynamicArray result;
	result.addres = arr;
	result.capacity = capacity;
	result.count = 0;
	return result;
}

DynamicArray createarray()
{
	size_t defaultCapacity = 4;
	return createarray(defaultCapacity);
}

span<int> getCurrentSpan(DynamicArray* arr) 
{
	if(arr->count > 0)
		return span<int>(arr->addres, arr->count);
} 

void deleteArray(DynamicArray* arr)
{
	delete[] arr->addres;
	arr->count = 0;
	arr->capacity = 0;
	arr->addres = nullptr;
}

int getElementAtIndex(DynamicArray* arr, size_t index)
{
	if (index < arr->count) {
		return arr->addres[index];
	}
}