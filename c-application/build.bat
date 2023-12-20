set files=src\engine\*.c src\*.c
set libs=C:\Users\mscul\Documents\Projects\C-Application\c-windows-application\lib\*.lib

CL /Zi /I C:\Users\mscul\Documents\Projects\C-Application\c-windows-application\include %files% /link %libs% /OUT:game.exe