set files=src\glad.c src\main.c src\engine\render.c
set libs=C:\Users\mscul\Documents\Projects\C-Application\c-windows-application\lib\SDL2main.lib C:\Users\mscul\Documents\Projects\C-Application\c-windows-application\lib\SDL2.lib C:\Users\mscul\Documents\Projects\C-Application\c-windows-application\lib\SDL2_ttf.lib

CL /Zi /I C:\Users\mscul\Documents\Projects\C-Application\c-windows-application\include %files% /link %libs% /OUT:MyApplication.exe