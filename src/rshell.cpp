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
