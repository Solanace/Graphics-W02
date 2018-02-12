run: main.c draw.c display.c
	gcc -c main.c
	gcc -c draw.c
	gcc -c display.c
	gcc -o main main.o draw.o display.o