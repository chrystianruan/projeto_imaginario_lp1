#author: Chrystian
#project: Projeto Complexo

PROG=complexo
CC=g++
CPPFLAGS=-O0 -g -Wall -pedantic

OBJS=main.o complexo.o

$(PROG):$(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o: complexo.h
	$(CC) $(CPPFLAGS) -c main.cpp

complexo.o: complexo.h
	$(CC) $(CPPFLAGS) -c complexo.cpp

clean: 
	rm -rf $(PROG) $(OBJS)