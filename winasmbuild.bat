@setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
cl -c winasmhex.c
link winasmhex.obj /out:winasmhex.exe
@endlocal
