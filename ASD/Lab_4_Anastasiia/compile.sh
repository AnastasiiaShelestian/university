g++ -std=c++20 dynamicArray.cpp -o dynamicArray.o
g++ -std=c++20 Lab_4_Anastasiia.cpp -o Lab_4_Anastasiia.o
g++ Lab_4_Anastasiia.o dynamicArray.o -o program.exe

rm Lab_4_Anastasiia.o dynamicArray.o