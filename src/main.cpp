/** 
 * Name: Rebecca Hom
 * This is the main file that will be used to run the rshell.
 * Tests the system calls
 *
* */
#include "rshell.h"

#include <iostream>
#include <string>

using namespace std;

int main(int arc, char* argv[])
{
    Rshell rshell = Rshell();
    //  System call functions test
    //  rshell.myFork();    
    //  rshell.myWait();
    //  rshell.myExec();
    
    // Initial variables for taking in commands
    string input = "";
    vector<string> inputs;

    //  Gets the command(s) from user input until exit
    while(input != "exit")
    {
        cout << "$ ";
        getline(cin, input);

        rshell.removeSpace(input);  //  Removes whitespace from input string
        rshell.convertCommands(input, inputs);
        //  inputs.clear();
    } 
    return 0;
}
