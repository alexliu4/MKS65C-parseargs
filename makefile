all: strep.o
	gcc strep.o

run: all
	./a.out

file.o: strep.c
	gcc -c strep.c

clean:
	rm *.o
	rm *.out
