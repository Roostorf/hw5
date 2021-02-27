homework5: driver.o iofunctions.o
	gcc -o homework5 driver.o iofunctions.o

iofunctions.o: iofunctions.c pokemon.h iofunctions.h
	gcc -ansi -pedantic-errors -Wall -c iofunctions.c

driver.o: driver.c pokemon.h iofunctions.h
	gcc -ansi -pedantic-errors -Wall -c driver.c