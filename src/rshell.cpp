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
#include <sstream>

using namespace std;

//  Constructors
//  Default constructor (creates an Rshell object for commands)
Rshell::Rshell()
{}

//  Rshell functions
//  These functions takes command input from the user and parses them
//  parseCommand(string& input, char line[][], char **argv) - 
//      parses out whitespace and puts charaters from string into array of char
void Rshell::parseCommand(string& input, char line[100][256],  char **argv)
{
    unsigned row = 0;
    unsigned col = 0;
    bool quote = false;     //  Has a flag if the argument is in quotations
    clearArray(line);       //  Cleans array

    //  Parses string into the array (takes out whitespace)
    for(unsigned i = 0; i < input.size(); ++i)
    {
        //  char con;
        if(input.at(i) == ' ')
        {
            cout << "Space" << endl;
        }
        if(input.at(i) == '\t')
        {
            cout << "Tab" << endl;
        }
        if(input.at(i) == '\n')
        {
            cout << "Newline" << endl;
        }
        /*
        if(!quote && (input.at(i) == '#'))  //  Aborts early from comments
        {
            break;
        }
        else if(!quote && ((input.at(i) != char(32)) || 
            (input.at(i) != '\t') || 
            (input.at(i) != '\n')))     //  If the pos in string !=  whitespace
        {*/
        if(!quote)
        {
            if(input.at(i) == '#')
            {
                break;
            }
            if((input.at(i) == ' ') || (input.at(i) == '\t') || 
                (input.at(i) == '\n'))
            {
                continue;
            }
            else if(input.at(i) == ';')     //  Treat ';' as a newline
            {
                line[row][col] = '\0';
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

    //  Once all cmd retrieved->end array with last row having '\0'
    row++;
    line[row][0] = '\0';

    //  Prints out 2d array
    for(unsigned i = 0; line[i][0] != '\0'; ++i)
    {
        for(unsigned j = 0; line[i][j] != '\0'; ++j)
        {
            //  cout << line[i][j];
            cout << "Pos[" << i << "][" << j << "]: " << line[i][j] << endl;
        }
        cout << endl;
    }
    return;
}

//  void parseConnect(string&, unsigned, char [][], char, unsigned&, unsigned&)-
//      checks if an '&' or '|'  is a connector or not
void Rshell::parseConnect(string& input, unsigned pos, char line[100][256], char con, unsigned& row, unsigned& col)
{
    if(col == 1)
    {
        line[row][col] = input.at(pos);
        col++;
        if(line[row][0] == con)         //  if prev char is connector
        {
            line[row][col] = '\0';
            row++;
            col = 0;
        }
    }
    else 
    {
        if(input.at(pos + 1) == con)    //  if next char is connector
        {
            line[row][col] = '\0';
            row++;
            col = 0;
        }
        line[row][col] = input.at(pos);
        col++;
    }
    return;
}

void Rshell::clearArray(char line[100][256])
{
    for(unsigned row = 0; row < 100; ++row)
    {
        for(unsigned col = 0; col < 256; ++col)
        {
            line[row][col] = '\0';
        }
    }
    return;
}

