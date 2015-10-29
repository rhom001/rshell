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
    // Initial variables for taking in commands
    string input = "";
    vector<string> inputs;

    //  Gets the command(s) from user input until exit
    while(input != "exit")
    {
        cout << "$ ";
        getline(cin, input);

        rshell.removeSpace(input);  //  Removes whitespace from input string
        rshell.convertCommands(input, inputs);  //  Gets all commands
        //  Shows all of the inputs
        for(unsigned i = 0; i < inputs.size(); ++i)
        {
            cout << "Command" << i + 1 << inputs.at(i) << endl;
        }
        inputs.clear(); //  Clears the commands in the vector
    } 
    return 0;
}
