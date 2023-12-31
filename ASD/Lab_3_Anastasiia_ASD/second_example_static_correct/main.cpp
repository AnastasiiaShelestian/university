static int hello(int somevalue) {
  return somevalue;
}

int main() 
{
  hello(3);
}

/*
  Если компилировать при помощи gcc -o program main.cpp f.cpp, программа скомпилируется успешно,
  так как статическая функция hello объявлена в main.cpp. Она используется внутри области видимости,
  поэтому линкер успешно определяет связь.

  Скорее всего, после компиляции в финальной версии будет две копии функции hello с разной областью видимости.
  Функция hello из f.cpp может быть успешно использована внутри данного файла в других функциях, но будет недоступна
  для main.cpp. То же самое и с функцией hello из файла main.cpp. Учитывая, что я компилировала два файла, 
  скорее всего, обе копии останутся в финальной executable. 
*/