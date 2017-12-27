all: program5

clean:
	rm program5

run: program5 
	./program5

program5: program5.c vector.c vector.h list.c list.h profile.c profile.h data.h
	gcc program5.c vector.c list.c profile.c -o program5

checkmem:
	valgrind ./program5

	
