/** 
 * Name: Rebecca Hom, Jorge Gonzalez
 * This is the main file that will be used to run the rshell.
* */
#include "rshell.h"

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    Rshell rshell = Rshell();
    // Initial variables for taking in commands
    string input = "";
    bool bye = false;
    char line[100][256];
    //  char *argv[64][64];

    //  Get username and machine name
    char* user = getlogin();
    char host[20];
    if(gethostname(host, 20))
    {
        perror("hostname too long");
    }
    //  Shortens machine name 
    char* mech = strtok(host, ".");

    //  Gets the command(s) from user input until exit
    while((input != "exit") && (!bye))
    {
        input.erase();
        cout << user << "@" << mech << "$ ";
        getline(cin, input);
        rshell.run(input, line, bye);
        rshell.clearArray(line);
        //  rshell.parseCommand(input, line, argv);
        //  rshell.executeCommand(line, argv, bye);
    } 
    
    //  Clears the arrays
    //  rshell.clearArray(line);
    //  rshell.clearArrayP(argv);
    return 0;
}
