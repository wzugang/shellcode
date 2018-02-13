@setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
cl -c winasmhexdump.c
link winasmhexdump.obj /out:winasmhexdump.exe
@endlocal
