#ifndef RSHELL_H
#define RSHELL_H

#include <iostream>

using namespace std;
class Rshell
{
    public:
        //  Class constructor
        Rshell();
        //  System call tests
        void myFork();
        void myWait();
        void myExec();
        //  Parses command inputs
        void removeSpace(string&);
};
#endif  //  RSHELL_H
