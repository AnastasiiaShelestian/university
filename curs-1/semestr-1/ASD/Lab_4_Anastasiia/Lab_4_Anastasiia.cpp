#include "dynamicArray.h"
#include <iostream>
#include <assert.h>

static void test1()
{
	DynamicArray arr = createarray(10);
	assert(arr.capacity == 10);
}

static void test2()
{
	DynamicArray arr = createarray();
	assert(arr.count == 0);
	addElementToArray(&arr, 5);
	assert(arr.count == 1);
}

static void test3()
{
	DynamicArray arr = createarray(1);
	addElementToArray(&arr, 5);
	assert(arr.capacity == 1);
	addElementToArray(&arr, 10);
	assert(arr.capacity == 2);
	addElementToArray(&arr, 20);
	assert(arr.capacity == 4);
}

static void test4()
{
	DynamicArray arr = createarray();
	addElementToArray(&arr, 5);
	int el = getElementAtIndex(&arr, 0);
	assert(el == 5);
}

static void test5()
{
	DynamicArray arr{};
	addElementToArray(&arr, 5);
	addElementToArray(&arr, 6);
	addElementToArray(&arr, 7);

	std::span<int> span = getCurrentSpan(&arr);

	assert(span.size() == 3);
	assert(span[0] == 5);
	assert(span[1] == 6);
	assert(span[2] == 7);
}

static void test6()
{
	DynamicArray arr{};
	addElementToArray(&arr, 5);
	addElementToArray(&arr, 6);
	addElementToArray(&arr, 7);

	assert(arr.capacity == 4);
	assert(arr.count == 3);

	deleteArray(&arr);
	assert(arr.capacity == 0);
	assert(arr.count == 0);
	assert(arr.addres == nullptr);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return 0;
}
