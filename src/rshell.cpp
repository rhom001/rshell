#include "rshell.h"

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <vector>

using namespace std;

//  Constructors
//  Default constructor (creates an Rshell object for commands)
Rshell::Rshell()
{}

//  Rshell functions
//  System call functions and tests
//  void myFork() - tests the use of fork()
void Rshell::myFork()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        cout << "Fork Failed" << endl;
        exit(1);
    }
    else if(pid == 0)
    {
        cout << "Child: I'm the child: " << pid << endl;
    }
    else if(pid > 0)
    {
        cout << "Parent: I'm the parent: " << pid << endl;
    }
}
