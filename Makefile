#Makefile

#Variables
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic
OBJS = rshell.o

#Targets
all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)
rshell.o: Rshell.cpp Rshell.h
	$(COMPIlE) $(FLAGS) -c Rshell.cpp
