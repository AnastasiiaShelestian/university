#include <iostream>
#include <stdlib.h>

// This is the same example, but with the malloc() function,
// it uses the C heap instead of the C++ heap.

/*
  Данный пример делает то же самое, что и stack2, только использует для этого динамическое
  выделение памяти в heap при помощи функции malloc. Благодаря этому переменная а будет получать
  новый адрес в куче при каждом вызове функции. Из-за этого указатели, содержащие в себе адреса
  переменных, всегда будут содержать разные адреса и сохранять значения переменных.
*/

int* heapMemory()
{
    void* memory = malloc(sizeof(int));
    int* a = (int*) memory;
    *a = 0;
    std::cout << "a: " << *a << std::endl;
    *a = *a + 1;
    return a;
}

int main()
{
    int* a = heapMemory(); // prints 0
    int* b = heapMemory(); // prints 0

    // no
    bool areAddressesEqual = ((size_t) a == (size_t) b);
    std::cout << "are addresses equal: " << (areAddressesEqual ? "yes" : "no") << std::endl;

    // yes
    bool areValuesEqual = (*a == *b);
    std::cout << "are values equal: " << (areValuesEqual ? "yes" : "no") << std::endl;

    *a = 5;
    *b = 10;
    // Prints -5.
    std::cout << (*a - *b) << std::endl;

    free(a);
    free(b);

    return 0;
}