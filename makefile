main: main.o R3space.o vectorspace.o
	gcc -g -o main main.o R3space.o vectorspace.o

main.o: main.c R3space.h vectorspace.h
	gcc -c -g main.c

R3space.o: R3space.c R3space.h vectorspace.h
	gcc -c -g R3space.o

vectorspace.o: vectorspace.c R3space.h vectorspace.h
	gcc -c -g vectorspace.o
