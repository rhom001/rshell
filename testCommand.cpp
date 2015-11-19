#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;
int main()
{
    /*string x;
    console:
    cout << "input a command" << endl;
    cin >> x;
    cout << endl;
    cout << system(x.c_str()) << endl;
    if (system(x.c_str()))
    {
	cout << "It worked!" << endl;
    }
    else
    {
        cout << "sorry no work" << endl;
    }*/


    /*char *x[4];
    x[0] = "/bin/bash";
    x[1] = "-c";
    x[2] = "test -e 'testCommand.cpp'";
    x[3] = NULL;
    execvp(x[0],x);*/

    string x = "test -e testCommand.cpp";
    int status = system(x.c_str());
    cout << status << endl;
    x = "[ -e testCommand.cpp ]";
    status = system(x.c_str());
    cout << status << endl;
    x = "test -e boo";
    status = system(x.c_str());
    cout << status << endl;
    x = "[ -e boo ]";
    status = system(x.c_str());
    cout << status << endl;
    cout << "Now input any test you want to check using \"test\" or []:" << endl;
    while(x != "exit")
    {
        getline(cin,x);
        status = system(x.c_str());
        cout << status << endl;
    }


    return 0;
}
