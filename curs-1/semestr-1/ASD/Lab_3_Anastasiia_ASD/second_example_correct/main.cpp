int hello(int somevalue);

int main() 
{
  hello(3);
}

/*
  Если компилировать при помощи gcc -o program main.cpp f.cpp, линкер находит связь между
  объявлением функции hello в main.cpp и ее определением в файле f.cpp. Программа компилируется успешно.

  Если компилировать только файл main.cpp командой gcc -o program main.cpp, будет та же ошибка, что и раньше,
  потому что определения функции hello снова не будет. 

  PS C:\University\university\ASD\Lab_3_Anastasiia_ASD\second_example_correct> gcc -o program main.cpp      
  C:\Users\Xiaomi\AppData\Local\Temp\cc621qyG.o:main.cpp:(.text+0x13): undefined reference to `hello(int)'
  collect2.exe: error: ld returned 1 exit status
*/