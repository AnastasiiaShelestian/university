#include <span>
#include <iostream>
#include <assert.h>

struct DynamicArray
{
	int* addres;
	size_t capacity;
	size_t count;

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
