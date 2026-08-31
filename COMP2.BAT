
set TCCFLAGS=-IC:\TC3\INCLUDE -IC:\ -LC:\TC3\LIB -LC:\

tcc %TCCFLAGS% -c terceira.c
tlib 3d+terceira
tcc %TCCFLAGS% ex3d2.c graphics.lib 3d.lib
tcc %TCCFLAGS% ex3d1.c graphics.lib 3d.lib

