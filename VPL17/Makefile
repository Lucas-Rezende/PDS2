CC=g++
CFLAGS=-std=c++20 -Wall -I./include

all: vpl_execution

build/fila.o: include/fila.h src/fila.cpp
	${CC} ${CFLAGS} -c src/fila.cpp -o build/fila.o

build/main.o: src/main.cpp
	${CC} ${CFLAGS} -c src/main.cpp -o build/main.o

build/doctest.o: include/doctest.h
	${CC} ${CFLAGS} -c include/doctest.cpp -o build/doctest.o

vpl_execution: build/fila.o build/main.o build/doctest.o
	${CC} ${CFLAGS} -o vpl_execution build/fila.o build/main.o build/doctest.o

clean:
	rm -f vpl_execution build/*.o