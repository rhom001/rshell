#include "rshell.h"

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

using namespace std;

//  Rshell class - takes in commands and executes them
//  Constructors
//  Default constructor (creates an Rshell object for commands)
Rshell::Rshell()
{}

//  Rshell functions
void Rshell::run(string& input, char line[][256],  bool bye)
{
    //  Checks if the first character is a connector
    if((input.at(0) == '&') || (input.at(0) == '|'))
    {
        cout << "Syntax error: unexpected token '" << input.at(0) 
            << input.at(1) << "'" << endl;
        return;
    }
    //  Parses input into a 2d char array
    parseCommand(input, line);
     
    //  Sets up running of commands
    bool success = true;    //  Returns true if command succeeds
    unsigned pos = 0;       //  Position at where iterator is at
    queue <unsigned> prec;  //  Keeps track of precedence (line array rows)
    stack <bool> prev;      //  Keeps track of previous successes
    bool conFlag = false;   //  AND if true, OR if false
    bool hasCon = false;     //  Checks if is a connector

    //  Pushes commands into a queue to determine size of list of commands
    for(pos = 0; line[pos][0] != '\0'; ++pos)
    {
        prec.push(pos);
    }

   //  Run commands
    while(!prec.empty())
    {
        //  Sets the position to the current front of the queue
        pos = prec.front();
        //  Checks if the current pos is a connector
        hasCon = checkCon(line, pos);
        if(!hasCon)
        {
            //  Runs the command
            //  If the previous connector is true or if the prev stack is empty
            if((prev.empty()) || (prev.top() == true))
            {
                success = executeCommand(line, pos, bye);
                //  If the prev stack is not empty, then pop the top
                if(!prev.empty())
                {
                    prev.pop();
                }
                //  Puts result of success on to the stack
                prev.push(success);
            }

        }
        else    //  if(hasCon)
        {
            //  If the prev stack is empty, then return error
            if(prev.empty())
            {
                cout << "Error: extraneous token '" << line[pos] << "'"
                    << endl;
                return;
            }
            //  Since there is a connector, it is AND or OR
            if(line[pos][0] == '&')
            {
                //  cout << "AND" << endl;
                conFlag = true;
            }
            else    //  if(line[pos][0] == '|')
            {
                //  cout << "OR" << endl;
                conFlag = false;
            }
            //  Checks the success of the connector and pushes on to stack
            success = connect(prev.top(), conFlag);
            prev.push(success);
        }
        //  Pops off the front of the precedence queue
        prec.pop();
    }
        
    //  Cleans array at end
    clearArray(line);
}
//  These functions takes command input from the user and parses them
//  parseCommand(string& input, char line[][256], char* argv[][64]) - 
//      parses out whitespace and puts charaters from string into array of char
void Rshell::parseCommand(string& input, char line[][256])
{
    unsigned row = 0;
    unsigned col = 0;
    bool quote = false;     //  Has a flag if the argument is in quotations
    clearArray(line);       //  Cleans array

    //  Parses string into the array (takes out whitespace)
    for(unsigned i = 0; i < input.size(); ++i)
    {
        if(!quote)
        {
            if(input.at(i) == '#')  //  Finishes with a comment
            {
                break;
            }
            if((input.at(i) == ' ') || (input.at(i) == '\t') || 
                (input.at(i) == '\n'))  //  Replaces whitespace with ' ' if DNE
            {
                if((col > 0) && 
                    !((input.at(i + 1) == '&') || 
                    (input.at(i + 1) == '|') ||
                    (input.at(i + 1) == ';')))  //  Makes sure !connector
                {
                    if(line[row][col-1] != ' ')
                    {
                        line[row][col] = ' ';
                        ++col;
                    }
                }
            }
            else if(input.at(i) == ';')     //  Treat ';' as a newline
            {
                row++;
                col = 0;
            }
            else if(input.at(i) == '&')     //  Checks for &&
            {
                parseConnect(input, i, line, '&', row, col);
            }
            else if(input.at(i) == '|')     //  Checks for ||
            {
                parseConnect(input, i, line, '|', row, col);
            }
            else    //  Any other character
            {
                line[row][col] = input.at(i);
                col++;
                if(input.at(i) == '"')      //  Checks for "
                {
                    quote = true;
                }
            }
        }
        else    //  Character is in quotes
        {
            line[row][col] = input.at(i);
            col++;
            if(input.at(i) == '"')
            {
                quote = false;
            }
        }
    }
    return;
}
//  void parseConnect(string&, unsigned, char [][], char, unsigned&, unsigned&)-
//      checks if an '&' or '|'  is a connector or not
void Rshell::parseConnect(string& input, unsigned pos, char line[][256], char con, unsigned& row, unsigned& col)
{
    if(col == 1)
    {
        line[row][col] = input.at(pos);
        col++;
        if(line[row][0] == con)         //  if prev char is connector
        {
            row++;
            col = 0;
        }
    }
    else 
    {
        if(input.at(pos + 1) == con)    //  if next char is connector
        {
            row++;
            col = 0;
        }
        line[row][col] = input.at(pos);
        col++;
    }
}

//  void clearArray(char line[100][256]) - puts '\0' for all spots in the array
void Rshell::clearArray(char line[][256])
{
    for(unsigned row = 0; line[row][0] != '\0'; ++row)
    {
        for(unsigned col = 0; col < 256; ++col)
        {
            line[row][col] = '\0';
        }
    }
    return;
}

//  void clearCommand(char* command[64]) - clears the command array
void Rshell::clearCommand(char* command[64])
{
    for(unsigned i = 0; i < 64; ++i)
    {
        command[i] = '\0';
    }
    return; 
}

//  void executeCommand(char line[][256], unsigned row) - takes a command from a row,
//      tokenizes it and executes it
bool Rshell::executeCommand(char line[][256], unsigned row, bool bye)
{
    pid_t pid;
    int status;

    //  Check for exit
    if((line[row][0] == 'e') && (line[row][1] == 'x') && (line[row][2] == 'i')
        && (line[row][3] == 't'))
    {
        bye = true;
        cout << "logout" << endl;
        exit(0);
    }

    // Declares a char pointer array called command 
    char* command[64];
    clearCommand(command);

    //  Tokenizes the command
    unsigned col = 0;
    bool quote = false;
    for(unsigned i = 0; line[row][i] != '\0'; ++i)
    {
        if(i == 0)  //  Gets the command
        {
            command[col] = &line[row][i];
            ++col;
        }
        else if(!quote && (line[row][i] == ' '))
        {
            //  Replaces space with a null terminating character
            line[row][i] = '\0';
            command[col] = &line[row][i + 1];
            ++col;
        }
        else if(line[row][i] == '"')
        {
            quote = !quote;
        }
    }

    //  Checks if it is a test command
    string x = command[0];
    if(x == "test" || x == "[")
    {
        //  Checks if it is brackets or test
        bool bracket = false;
        if(x == "[")
        {
            bracket = true;
            //  Returns error for unbalanced brackets
            string y = command[col - 1];
            if(y != "]")
            {
                cout << "Error: No terminating bracket. " << endl;
                return false;
            }
        }
        //  Returns result of test
        return executeTest(bracket, col, command);
    }

    //  Runs the token
    if((pid = fork()) < 0)   //  Forks a child process
    {
        perror("Forking child process failed");
        exit(1);
    }
    else if(pid == 0)
    {
        //  Execute the command
        if(execvp(*command, command) >= 0)
        {
            cout << "Command succeeded!" << endl;
            return true;
        }
        else
        {
            perror(*command);
            return false;
        }
    } 
    else    //  For the parent:
    {
        while(wait(&status) != pid) //  Wait for completion
        {
            if(wait(&status) == -1)
            {
                perror("Wait error");
                return false;
            }
        }
    }
    return true;
}

//  bool checkCon(char line[][256], unsigned pos) - checks if the character at pos in
//      line is either '&' (AND) or '|' (OR), otherwise returns false
bool Rshell::checkCon(char line[][256], unsigned pos)
{
    if((line[pos][0] == '&') || (line[pos][0] == '|'))
    {
        return true;
    }
    return false;
}

//  bool connect(bool prev, bool con) - checks if successful AND (the previous command 
//      succeeded) or if successful OR (the previous command failed), otherwise returns
//      false
bool Rshell::connect(bool prev, bool con)
{
    if((con && prev) || (!con && !prev))
    {
        return true;
    }
    return false;       
}

//  bool executeTest(bool bracket, unsigned col, char* com[64]) - executes the
//      test command and returns true or false depending on the flag
bool Rshell::executeTest(bool bracket, unsigned col, char* com[64])
{
    //  Checks the number of arguments
    if((bracket && (col < 3)) || (!bracket < (col < 2)))
    {
        cout << "Error: Please provide a file or directory to check." << endl;
        return false;
    }
    else if((bracket && (col > 4)) || (!bracket && (col > 3)))
    {
        cout << "Error: too many arguments." << endl;
        return false;
    }

    //  Gets a stat struct and identify the flag
    struct stat myStat;
    string flag = "";
    
    //  Looks at flagged commands
    if((bracket && (col == 4)) || (!bracket && (col == 3)))
    {
        //  Set flag to com[1]
        flag = com[1];
        //  Check if path exists
        if(stat(com[2], &myStat) == -1)
        {
            perror("stat");
            return false;
        }
        else if(flag == "-e")
        {
            cout << "Path exists for " << com[2] << endl;
            return true;
        }
        else if((flag == "-d") && (S_ISDIR(myStat.st_mode)))
        {
            cout << com[2] << " is a directory." << endl;
            return true;
        }
        else if((flag == "-f") && (S_ISREG(myStat.st_mode)))
        {
            cout << com[2] << " is a file." << endl;
            return true;
        }
        cout << flag << " is not a proper flag for " << com[2] << endl;
        return false;
    }
    else if((bracket && (col == 3)) || (!bracket && (col == 2)))
    {
        //  Don't set a flag ;)
        //  Check if path exists
        if(stat(com[1], &myStat) == -1)
        {
            perror("stat");
            return false;
        }
        cout << "Path exists for " << com[1] << endl;
        return true;
    }
    return false;
}
