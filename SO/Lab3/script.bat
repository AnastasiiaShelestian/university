@ECHO OFF

choice /m "What do  you want to do with the file?" /c ctd /cs /d t /t 15 /n
echo %ERRORLEVEL%
if ERRORLEVEL 3 (
  if NOT EXIST %1 (
    echo File doesn't exist!
    goto exitprogram
  )
  del %1
)
if ERRORLEVEL 2 (
  if NOT EXIST %1 (
    echo File doesn't exist!
    goto exitprogram
  )
  type %1
)
if ERRORLEVEL 1 (
  if EXIST %1 (
    echo File already exists!
    goto exitprogram
  )
  copy con %1
) 

:exitprogram