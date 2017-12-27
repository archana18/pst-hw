all: program4
program4:	tournament.o program4.o
	gcc -g program4.o tournament.o -o program4

program4.o:	program4.c
	gcc -g program4.c -o program4.o

tournament.o:	tournament.c
	gcc -g tournament.c tournament.h -o tournament.o
	

checkmem:	program4
	valgrind -v program4
run:	program4
	
clean:
	rm -rf program4
