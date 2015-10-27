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
//  System call test functions
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

//  void myWait() - tests the use of wait()
void Rshell::myWait()
{
    pid_t c_pid, pid;
    int status;
    c_pid = fork();
    
    if(pid < 0)
    {
        cout << "Fork failed" << endl;
        exit(1);
    }
    else if(c_pid == 0)
    {
        pid = getpid();
       
        cout << "Child: " << pid << ": I'm the child\n" << endl;
        cout << "Child: sleeping for 3 seconds \n" << endl;
 
        sleep(3);
        exit(12);
    }
    else if(c_pid > 0)
    {
        pid = wait(&status);
        if(WIFEXITED(status))
        {
            cout << "Parent: Child exited with status: ";
            cout << WEXITSTATUS(status) << endl;
        }
    }
}
