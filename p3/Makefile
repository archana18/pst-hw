all: defuseTheBomb checkmem clean
defuseTheBomb:
	gcc -c -g defuseMe.c -o defuseMe.o
	gcc -c -g bomb.c -o bomb.o
	gcc defuseMe.o bomb.o hidden.o -o defuseTheBomb
checkmem: program3B.c
	gcc program3B.c -o program3.o
	valgrind --leak-check=full -v ./program3.o
clean:
	./trash.sh *.o defuseTheBomb

