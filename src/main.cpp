/** 
 * This is the main file that will be used to run the rshell.
**/
#include "rshell.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    Rshell rshell = Rshell();
    string input = "";
    while(input != "exit")
    {
        rshell.myFork();
        cout << "$ ";
        getline(cin, input);
    }		    
    return 0;
}
