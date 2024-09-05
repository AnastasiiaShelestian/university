@echo off
echo hello!
goto mylabel
echo This is text will not be visible.
:mylabel
echo This text will be output after use "goto".
