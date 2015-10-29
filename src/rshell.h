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
        //  Parses command inputs
        void removeSpace(string&);
        void convertCommands(string&, vector<string>&);
};
#endif  //  RSHELL_H
