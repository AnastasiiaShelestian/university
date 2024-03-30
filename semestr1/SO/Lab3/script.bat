@echo off
rem Скопировать имена всех текстовых файлов, которые начинаются на букву,
rem заданную в качестве параметра, в файл rez.txt. Создать из этого списка
rem "папки" и "файлы" в рабочем каталоге.

rem "%~1" представляет %1 в виде строки. Если в %1 содержались кавычки, они убираются.
rem Если %1 равен пустой строке, значит аргумент не был предоставлен.
if "%~1"=="" (
  rem Вывести сообщение об ошибке
  echo "No letter provided. Please, provide a letter that files start with."
  rem Перейти к концу программы
  goto endprogram
) else (
  rem Иначе, выполняем программу из корневого каталога university (там содержится много файлов .txt для примеров)
  cd c:/university/university/so

  rem Удаляем файл rez.txt, если он уже существует, пересоздаем папку lab3\newfolder для копирования файлов
  if exist rez.txt (
    del rez.txt
    rmdir /s /q lab3\newfolder
    mkdir lab3\newfolder
  )

  rem Перебираем текстовые файлы, начинающиеся на букву из переменной letter, и копируем их имена в rez.txt
  for /r %%F in (%1*.txt) do (
    echo %%F >> rez.txt
  )

  rem Для всех файлов из файла rez.txt копируем их в lab3\newfolder\ используя их имя
  for /f %%f in (rez.txt) do (
    copy %%f lab3\newfolder\%%~nxf
  )

  echo Program complete.
)
cd c:/university/university/so/lab3
:endprogram