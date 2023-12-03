#include <span>
#include <iostream>
#include <assert.h>

struct DynamicArray
{
	int* addres;
	size_t capacity;
	size_t count;

};

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

int main()
{
	DynamicArray array = createarray(10);
	assert(array.capacity == 10);
	return 0;


}
