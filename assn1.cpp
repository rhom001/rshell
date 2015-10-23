#include <iostream>
#include <string>
using namespace std;
int main()
{
	string input = "";
	while(input != "exit")
	{
		cout << "$ ";
		cin >> input;
	}
	return 0;
}
