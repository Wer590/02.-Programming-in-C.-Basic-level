all: prog

prog: main.o temp_api.o
	gcc -std=c99 -o prog main.o temp_api.o

main.o: main.c temp_api.h
	gcc -std=c99 -c -o main.o main.c

temp_api.o: temp_api.c
	gcc -std=c99 -c -o temp_api.o temp_api.c

clean:
	del *.o prog.exe  
