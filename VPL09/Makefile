CC=g++
CFLAGS=-std=c++03 -Wall
OBJDIR=build

CFLAGS=-std=c++03 -Wall -I./include

all:vpl_execution

pessoa.o: include/pessoa.h src/pessoa.cpp
	${CC} ${CFLAGS} -c src/pessoa.cpp -o ${OBJDIR}/pessoa.o

funcionario.o: include/funcionario.h src/funcionario.cpp
	${CC} ${CFLAGS} -c src/funcionario.cpp -o ${OBJDIR}/funcionario.o

professor.o: include/professor.h src/professor.cpp
	${CC} ${CFLAGS} -c src/professor.cpp -o ${OBJDIR}/professor.o

main.o: src/main.cpp
	${CC} ${CFLAGS} -c src/main.cpp -o ${OBJDIR}/main.o

vpl_execution: pessoa.o funcionario.o professor.o main.o
	${CC} ${CFLAGS} -o vpl_execution ${OBJDIR}/pessoa.o ${OBJDIR}/funcionario.o ${OBJDIR}/professor.o ${OBJDIR}/main.o

clean:
	rm -f vpl_execution ${OBJDIR}/*.o