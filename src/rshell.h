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
        void run(string& input);
        //  Parses command inputs
        void parseCommand(string& input, char line[][256], char* argv[][64]);
        void parseConnect(string&, unsigned, char line[][256], char, unsigned&, unsigned&);
        //  Clears the array
        void clearArray(char line[][256]);
        void clearArrayP(char* argv[][64]);
        //  Executes command inputs
        void executeCommand(char line[][256], char* argv[][64], bool);
        //  Checks for a connector and compares
        bool checkCon(char line[][256], unsigned);
        bool connect(bool, bool, char line[][256], unsigned);
};
#endif  //  RSHELL_H
