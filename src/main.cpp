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

int main()
{
    Rshell rshell = Rshell();
    //  System call functions test
    //  rshell.myFork();    
    //  rshell.myWait();
    //  rshell.myExec();

    string input = "";
    while(input != "exit")
    {
        //  Gets command from user input
        cout << "$ ";
        getline(cin, input);

        //  Removes whitespace and puts into vector
        rshell.removeSpace(input);
        cout << input << endl;
    }		    
    return 0;
}
