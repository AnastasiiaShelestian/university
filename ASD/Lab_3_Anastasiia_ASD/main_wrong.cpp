int hello(int somevalue);

int main() 
{
  hello(3);
}

/*
  C:\Users\Xiaomi\AppData\Local\Temp\ccmb4635.o: In function `main':
  c:/University/university/ASD/Lab_3_Anastasiia_ASD/main_wrong.cpp:5: undefined reference to `hello(int)'
  collect2.exe: error: ld returned 1 exit status

  Функция hello объявлена, но не определена. Компилятор анализирует исходный код и создает объектные файлы (.o или .obj), 
  содержащие машинный код для каждой функции в программе. В данном случае, функция main находится 
  в исходном файле main_wrong.cpp, и она не вызывает ошибок компиляции.
  После компиляции, объектные файлы должны быть связаны вместе при помощи линкера, 
  чтобы создать файл exe. Ошибка происходит на этом этапе. 
  Компилятор обнаруживает вызов функции hello(3);, но не находит определения этой функции.
*/