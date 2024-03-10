all: prog

prog: main.o temp_api.o argc.o
	gcc -std=c99 -Wall -o prog main.o temp_api.o argc.o

main.o: main.c main.h temp_api.h argc.h
	gcc -std=c99 -Wall -c -o main.o main.c

temp_api.o: temp_api.c main.h temp_api.h argc.h
	gcc -std=c99 -Wall -c -o temp_api.o temp_api.c

argc.o: argc.c main.h temp_api.h argc.h
	gcc -std=c99 -Wall -c -o argc.o argc.c

clean:
	del *.o prog.exe  
