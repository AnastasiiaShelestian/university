int hello(int somevalue);

int main() 
{
  hello(3);
}

/*
  Если компилировать при помощи gcc -o program main.cpp f.cpp, линкер не находит связь между
  объявлением функции hello в main.cpp и ее определением в файле f.cpp. Это происходит из-за того,
  что статические функции имеют ограниченную область видимости и не могут быть доступны за пределами файла, 
  в котором они определены. Это приводит к ошибке линковки, так как линкер не может найти определение функции 
  hello в другом файле.

  C:\Users\Xiaomi\AppData\Local\Temp\cc6GYOJD.o:main.cpp:(.text+0x13): undefined reference to `hello(int)'
  collect2.exe: error: ld returned 1 exit status
*/