#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void myFork()
{
	pid_t pid = fork();
	if(pid < 0)
	{
		cout << "Fork Failed" << endl;
		exit(1);
	}
	else if (pid == 0)
	{
		cout << "Child: I'm the child: " << pid << endl;
	}
	else if (pid > 0)
	{
		cout << "Parent: I'm the parent: " << pid << endl;
	}
}


int main()
{
	string input = "";
	//myFork();
	while(input != "exit")
	{
		//myFork();
		cout << "$ ";
		cin >> input;
	}
	return 0;
}
