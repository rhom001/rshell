#ifndef RSHELL_H
#define RSHELL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Rshell
{
    public:
        //  Class constructor
        Rshell();
        //  Runs commands
        void metaRun(string& input, char line[][256], bool);
        bool run(string& input, char line[][256], bool);
        //  Parses command inputs
        void parseCommand(string& input, char line[][256]); 
        void parseConnect(string&, unsigned, char line[][256], char, unsigned&, unsigned&);
        //  Clears the array
        void clearArray(char line[][256]);
        void clearCommand(char* command[64]);
        //  Executes command inputs
        bool executeCommand(char line[][256], unsigned, bool);
        //  Checks for a connector and compares
        bool checkCon(char line[][256], unsigned);
        bool connect(bool, bool);
        //  Executes the test command
        bool executeTest(bool, unsigned, char* com[64]);
};
#endif  //  RSHELL_H
