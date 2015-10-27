#Makefile

#Variables
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic
OBJS = src/Rshell.o

#Targets
all: src/main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out src/main.cpp $(OBJS)
Rshell.o: src/Rshell.cpp src/Rshell.h
	$(COMPIlE) $(FLAGS) -c src/Rshell.cpp

clean:
	rm ~rf *~o *.o a.out
