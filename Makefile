#Makefile

#Variables
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic
OBJS = src/rshell.o

#Targets
all: src/main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o bin/rshell src/main.cpp $(OBJS)
rshell.o: src/rshell.cpp src/rshell.h
	$(COMPILE) $(FLAGS) -c src/rshell.cpp

clean:
	rm ~rf *~o *.o a.out
