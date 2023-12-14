set files=src\glad.c src\main.c
set libs=C:\Users\mscul\Documents\Projects\C-Application\c-windows-application\lib\SDL2main.lib C:\Users\mscul\Documents\Projects\C-Application\c-windows-application\lib\SDL2.lib

CL /Zi /I C:\Users\mscul\Documents\Projects\C-Application\c-windows-application\include %files% /link %libs% /OUT:MyApplication.exe