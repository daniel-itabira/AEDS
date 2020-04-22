all: tp
tp: hash.o main.o
	gcc -o tp hashlp.o main.o
hash.o: hashlp.c hashlp.h
	gcc -o hashlp.o -c hashlp.c
main.o: main.c hashlp.h
	gcc -o main.o -c main.c

clean:
	rm -rf *.o
