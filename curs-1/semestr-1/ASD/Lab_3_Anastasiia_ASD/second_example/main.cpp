int hello(int somevalue);

int main() 
{
  hello(3);
}

/*
  C:\Users\Xiaomi\AppData\Local\Temp\cc6RtmdN.o:main.cpp:(.text+0x13): undefined reference to `hello(int)'
  collect2.exe: error: ld returned 1 exit status

  Компиляция при помощи команды: gcc -o program main.cpp f.cpp
  Линкер не может найти определение функции hello ни в одном из файлов. Из-за этого, как и в предыдущем примере,
  компиляция неудачная.
*/