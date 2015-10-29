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
    unsigned loc;
    //  Takes out any commented out commands
    if(input.find("#") != string::npos)
    {
        loc = input.find("#");
        input = input.substr(0, loc);
    }  
    
    //  Stops the input at the first exit
    if(input.find("exit") != string::npos)
    {
        loc = input.find("exit");
        input = input.substr(0, loc + 4);   //  Cuts input at the end of exit
    }
    
    string cons[3] = { ";", "&&", "||" };
    //  Parses out individual commands from connectors
    while((input.find(";") != string::npos) || 
        (input.find("&&") != string::npos) ||
        (input.find("||") != string::npos))
    {
        string temp, con;
        loc = input.size();

        //  Finds the earliest connector
        for(unsigned i = 0; i < 3; ++i)
        {
            if((input.find(cons[i]) != string::npos) && 
                (input.find(cons[i]) < loc))
            {
                loc = input.find(cons[i]);
                temp = input.substr(0, loc);
                con = cons[i];   //  Saves the connector
            }
        }
        
        //  Puts the cmd into the vector of inputs
        inputs.push_back(temp);
        //  If there is a ";", then treat as newline
        if(con == ";")
        {
            input = input.substr(loc + 1);  //  Takes out the cmd from input
        }
        else    //  if "&&" or "||", then add in connectors
        {
            input = input.substr(loc + 2);
            inputs.push_back(con);
        }   
        removeSpace(input);             //  Takes out any whitespace
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
