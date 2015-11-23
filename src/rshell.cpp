#include "rshell.h"

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
#include <stack>
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
void Rshell::run(string& input)
{
    //  Parses input into a 2d char array
    char line[][256];
    parseCommand(input, line);
    
    //  Checks to make sure that parentheses are balanced
    int cntPL = 0;
    int cntPR = 0;
    char c;
    for(unsigned i = 0; line[i][0] != '\0'; ++i)
    {
        c = line[i][0];
        if(c == '(')
        {
            ++cntPL;
        }
        else if(c == ')')
        {
            ++cntPR;
        }
    }
    //  Returns error if extra parentheses and exits
    if(cntPL < cntPR)
    {
        cout << "Syntax error: extra ');" << endl;
        return;
    }
    else if(cntPL > cntPR)
    {
        cout << "Syntax error: extra '('" << endl;
        return;
    }
    //  Sets up running of commands
    bool success = true;    //  Returns true if command succeeds
    unsigned pos = 0;       //  Position at where iterator is at
    queue <unsigned> prec;  //  Keeps track of precedence (line array rows)
    //  bool par = false;   //  Keeps track if parentheses is true
    stack <bool> prev;      //  Keeps track of previous successes
    bool conAnd = false;    //  AND connector if true
    bool conOr = false;     //  OR connector if true
    bool conFlag = false;   //  AND if true, OR if false

    //  Run commands
    while(line[pos][0] != '\0')
    {
        //  If '(' then push the pos on to the queue
        if(line[pos][0] == '(')
        {
            prec.push(pos);
        }
        //  If ')' then execute commands in the queues until empty
        else if(line[pos][0] == ')')
        {
            //  Execute all commands in the precedence queue
            queue <bool> inner;
            while(!prec.empty())
            {
                //  Look at top of queue
                unsigned doThis = prec.front();
                //  Checks for connector
                if(checkCon(line, doThis))
                {
                    if(line[doThis][0] == '&')
                    {
                        conAnd = true;
                        conOr = false;
                        conFlag = true;
                    }
                    else    // if(line[i][0] == '|')
                    {
                        conOr = true;
                        conAnd = false;
                        conFlag = false;
                    }
                }
                else    //  Runs commands in queue
                {
                    success = executeCommand(line, doThis);
                    //  If the inner queue is not empty, then run commands in it
                    while(!inner.empty())
                    {
                        //  Checks success of the connector
                        bool conSuc = connect(inner.front(), conFlag, line, doThis);
                        if((line[doThis + 1][0] != '\0')
                        {
                            if(checkCon(line, doThis + 1))
                            {
                                
                            
                }
        }
        ++pos;
    }
    
    return;
}
//  These functions takes command input from the user and parses them
//  parseCommand(string& input, char line[][256], char* argv[][64]) - 
//      parses out whitespace and puts charaters from string into array of char
void Rshell::parseCommand(string& input, char line[][256], char* argv[][64])
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
            else if((input.at(i) == '(') || 
                (input.at(i) == ')'))   //  Gets precedence '(' or ')'
            {
                cout << input.at(i) << endl;
                row++;
                col = 0;
                line[row][col] = input.at(i);
                row++;
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

    //  Sets up the argv array
    row = 0;
    col = 0;
    quote = false;
    clearArrayP(argv);
/*
    //  Uses strtok to replace any ' ' with \0
    char* pch;
    for(unsigned i = 0; line[i][0] != '\0'; ++i)
    {
        col = 0;
        argv[row][col] = &line[i][0];
        pch = strtok(line[i], " ");
        while(pch != NULL)      //  Keeps going until '\0' is found
        {
            argv[row][col] = pch;
            ++col; 
            pch = strtok(NULL, " ");
        }
        ++row;
    }
*/
/* 
    //  Output array
    for(unsigned i = 0; line[i][0] != '\0'; ++i)
    {
        cout << line[i] << endl;
    }
*/    
    //  Looks through line and replaces any ' ' with \0'
    for(unsigned i = 0; line[i][0] != '\0'; ++i)
    {
        for(unsigned j = 0; line[i][j] != '\0'; ++j)
        {
            if(j == 0)  //  Gets the command
            {
                argv[row][col] = &line[i][j];
                ++col;
            }
            if(!quote && (line[i][j] == ' '))   //  Replaces space with '\0'
            {
                line[i][j] = '\0';
                argv[row][col] = &line[i][j + 1];
                ++col;
            }
            if(line[i][j] == '"')   //  Triggers quotes
            {
                quote = !quote;
            }    
        }
        ++row;      //  Goes to the next row
        col = 0;
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
    return;
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

//  void clearArrayP(char* argv[][]) - puts '\0' for all spots in the pointer
//      array
void Rshell::clearArrayP(char* argv[][64])
{
    for(unsigned row = 0; argv[row][0] != '\0'; ++row)
    {
        for(unsigned col = 0; argv[row][col] != '\0'; ++col)
        {
            argv[row][col] = '\0';
        }
    }
    return;
}

//  void executeCommand(char* argv[][]) - takes the array of commands and 
//      executes them
void Rshell::executeCommand(char line[][256], char* argv[][64], bool bye)
{
    pid_t pid;
    int status;
    bool conAnd = false;    //  '&&'
    bool conOr = false;     //  '||'
    bool success = true;    //  If previous command was successful
<<<<<<< HEAD
/*
   //   Outputs the argv array 
   for(unsigned i = 0; argv[i][0] != '\0'; ++i)
    {
        for(unsigned j = 0; argv[i][j] != '\0'; ++j)
        {
            cout << argv[i][j] << " ";
        }
        cout << endl;
    }
*/ 
=======
    stack <char> prec;      //  Checks for precedence
	bool checkedTest = false;
>>>>>>> ea265ece7c27c3ee26b41a32647b8d765e375ee4
    for(unsigned i = 0; argv[i][0] != '\0'; ++i)
    {
	checkedTest = false;
        //  Check for exit
        if((line[i][0] == 'e') && (line[i][1] == 'x') && (line[i][2] == 'i') &&
            (line[i][3] == 't'))
        {
            if(!((conAnd && !success) || (conOr && success)))
            {
                bye = true;
                cout << "logout" << endl;
                exit(0);
            }
        }       
        //  Check for connectors
        else if(line[i][0] == '&')        //  Found an AND connector
        {
            conAnd = true;
<<<<<<< HEAD
            cout << "AND" << endl;
            continue;
=======
	    continue;
>>>>>>> ea265ece7c27c3ee26b41a32647b8d765e375ee4
        }
        else if(line[i][0] == '|')    //  Found an OR connector
        {
            conOr = true;
<<<<<<< HEAD
            cout << "OR" << endl;
            continue;
=======
	    continue;
>>>>>>> ea265ece7c27c3ee26b41a32647b8d765e375ee4
        }
        else if((conAnd && !success) || (conOr && success)) //  No connect
        {
            conAnd = false;
            conOr = false;
            cout << "Connector failed!" << endl;
            continue;
        }
        else if(!checkedTest)
        {
		if(argv[i][0] == NULL)
		{
		   cout << "Error, empty array" << endl;
		   continue;
		}
                string x = argv[i][0];
		string com = "";
		//cout << x << y << endl;
		struct stat mystat;
		//for (int i = 0, j = 0; argv[i]; i++)
		//{
		//    cout << x << endl;
		//    x = *argv[i + 1];
		//}
		string end = "";
		int k = 0;
		for(k = 0; argv[i][k] != '\0'; k++)
		{
		    ;
		}
		k--;
		end = argv[i][k];
		//cout << "x: " << x << " end: " << end << endl;
		if(x == "[" && end != "]")
		{
		    cout << "Error, no terminating brace" << endl;
		   continue;

		}
		else if((x == "test" || (x == "[" && end == "]")))
		{
		    if(argv[i][1] != NULL)
		    {
                        com = argv[i][1];
			//cout << "com: " << com << endl;
		    }
		    //cout << "now we should check the array for a test" << endl;
		    if(argv[i][1] == NULL || com == "]")
		    {
		        cout << "Nothing to test" << endl;
		   continue;

		    }
		    else if (com == "-e")
		    {
			if(argv[i][2] == NULL)
			{
			    cout << "Nothing to test" << endl;
		   continue;

			}
		        else
			{   
			    string third = argv[i][2];
			    if(third == "]")
			    {
				cout << "Nothing to test" << endl;
		   continue;

			    }
			    else if(stat(argv[i][2],&mystat) == -1)
			    {
				perror("stat");
		   continue;

			    }
			    else
			    {
			        cout << "Path exists" << endl;
		   continue;

			    }
			}
		    }
		    else if (com == "-f")
		    {
			if(argv[i][2] == NULL)
			{
			    cout << "Nothing to test" << endl;
		   continue;

			}
		        else
			{
			    string third = argv[i][2];
			    if(third == "]")
			    {
				cout << "Nothing to test" << endl;
		   continue;

			    }
			    else if(stat(argv[i][2],&mystat) == -1)
			    {
				perror("stat");
		   continue;

			    }
			    else if(S_ISREG(mystat.st_mode))
			    {
				cout << "Path exists and is a file" << endl;
		   continue;

			    }
			    else
			    {
				cout << "Path exists but is not a file" << endl;
		   continue;

			    }
			    //cout << "lol" << endl;
			}
		    }
		    else if (com == "-d")
		    {
			if(argv[i][2] == NULL)
			{
			    cout << "Nothing to test" << endl;
		   continue;

			}
		        else
			{
			    string third = argv[i][2];
			    if(third == "]")
			    {
				cout << "Nothing to test" << endl;
		   continue;

			    }
			    else if(stat(argv[i][2],&mystat) == -1)
			    {
				perror("stat");
		   continue;

			    }
			    else if(S_ISDIR(mystat.st_mode))
			    {
				cout << "Path exists and is a directory" << endl;
		   continue;

			    }
			    else
			    {
				cout << "Path exists and is not a directory" << endl;
		   continue;

			    }
			    //cout << "lol" << endl;
			}
		    }
		    else
		    {
			if(stat(argv[i][1],&mystat) == -1)
			{
			    perror("stat");
		   continue;

			}
			else
			{
                            cout << "Path exists" << endl;
		   continue;

		        }
		    }

		}
		}
        if (!checkedTest)    //  Tries to execute the command
        {
            if((pid = fork()) < 0)   //  Forks a child process
            {
                perror("Forking child process failed");
                exit(1);
            }
            else if(pid == 0)
            {
                success = false;
                //  Execute the command
<<<<<<< HEAD
                if(execvp(*argv[i], argv[i]) >= 0)
                {
                   success = true;
                   cout << "Command succeeded!" << endl;
                }
                else
                {
=======
                
        	if(execvp(*argv[i], argv[i]) < 0)
		{
                    success = false;
>>>>>>> ea265ece7c27c3ee26b41a32647b8d765e375ee4
                    perror(*argv[i]);
                }
            } 
            else    //  For the parent:
            {
                while(wait(&status) != pid) //  Wait for completion
                {
                    if(wait(&status) == -1)
                    {
                        perror("Wait error");
                    }
                }
            }
            if(conAnd || conOr)
            {
                conAnd = false;
                conOr = false;
                cout << "Finished connector" << endl;
            }
        }
    }
    return;
}

