prog:main.o image.o source.o
	gcc main.o image.o text.o source.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer 
main.o:main.c
	gcc -c main.c -g
image.o:image.c
	gcc -c image.c -g
source.o:source.c
	gcc -c source.c -g


