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
/*
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
    return;
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
    return;
}

//  void myExec() - tests the execvp() which executes a command
void Rshell::myExec()
{
    char * args[2] = {"ls", NULL};
    pid_t c_pid, pid;
    int status;

    c_pid = fork();

    if(c_pid < 0)
    {
        cout << "Fork Failed" << endl;
        exit(1);
    }
    else if(c_pid == 0)
    {
        cout << "Child execting ls" << endl;
        execvp(args[0], args);
        cout << "execve failed" << endl;
    }
    else if(c_pid > 0)
    {
        if((pid = wait(&status)) < 0)
        {
            cout << "Wait";
            exit(1);
        }
        cout << "Parent: finished" << endl;
    }
    return;
}
*/
//  These functions takes command input from the user and parses them
//  void removeSpace(string &input) - takes out extra whitespace from input
void Rshell::removeSpace(string& input)
{
    while((input[0] == ' ') || (input[0] == '\t'))
    {
        input.erase(input.begin());
    }
    return;
}

//  void convertCommands(string input, vector<string>& inputs) - parses the
//      input string into individual strings/commands/flags
void Rshell::convertCommands(string& input, vector<string>& inputs)
{
    //  Parses out individual commands from multi-line commands
    while(input.find(";") != string::npos)
    {
        unsigned loc = input.find(";");
        string temp = input.substr(0, loc); //  Gets command string
        input = input.substr(loc + 1);      //  Takes out the temp from input
        removeSpace(input);                 //  Cuts out preceding whitespace
        inputs.push_back(temp);             //  Pushes the command into inputs
    }
    //  Gets an individual command that isn't exit
    if(!input.empty() && (input != "exit"))
    {
        removeSpace(input);
        string temp = input;
        input.clear();
        inputs.push_back(temp);
    }
    //  Gets the exit command
    if(input == "exit")
    {
        inputs.push_back(input);
    }
    return;
}   
