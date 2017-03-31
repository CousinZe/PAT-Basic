CC = clang
CFLAGS = -std=c99 -g

all : main.exe

main.exe : accommodiation.o main.o
	$(CC) $(CFLAGS) accommodiation.o main.o -o main.exe

accommodiation.o : accommodiation.h accommodiation.c
	$(CC) $(CFLAGS) -c accommodiation.c -o accommodiation.o

main.o : accommodiation.h main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

clean :
	rm -rf *.o
	rm -rf *.exe
