Script started on Sun 22 Nov 2015 10:48:32 PM PST
[rhom001@hammer rshell]$ make
mkdir bin
g++ -Wall -Werror -ansi -pedantic -o bin/rshell src/main.cpp src/rshell.cpp
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ ls
a.out  LICENSE	 parenthesis.cpp  rhom001  tests
bin    Makefile	 README.md	  src	   test.sh
rhom001@hammer$ test -e parenthesis.cpp && echo Pathnfor parenthesis.cpp
Path for parenthesis.cpp
rhom001@hammer$ test -dcsrce&&oecho src is a directory
src is a directory
rhom001@hammer$ test -f test.cpp || test.cpp does not exists as file
stat: No such file or directory
test.cpp: No such file or directory
rhom001@hammer$ test bin && echohbin has a path
bin has a path
rhom001@hammer$ [ -e src/main.cpp ] && echo We have a main.cpp!
We have a main.cpp!
rhom001@hammer$ [ -f src/test.cpp ] || echo We don't have test.cpp!cp
stat: No such file or directory
We don't have test.cpp!
rhom001@hammer$ [ -d tester ] || echo We don't have a tester directory!
stat: No such file or directory
We don't have a tester directory!
rhom001@hammer$ [ README.md]] && echolReally short bracket README.md
Really short bracket README.md
rhom001@hammer$ [ ] || echo Notfileuincluded
Error: Please provide a file or directory to check.
No file included
rhom001@hammer$ test || echo Have something to test!
Error: Please provide a file or directory to check.
Have something to test!
rhom001@hammer$ test -f test.cpp test.h
Error: too many arguments.
rhom001@hammer$ [c-e test.cpp test.h ] || echo Overkill
Error: too many arguments.
Overkill
rhom001@hammer$ exit
logout
rhom001@hammer$ exit
logout
[rhom001@hammer rshell]$ exit
exit

Script done on Sun 22 Nov 2015 10:59:53 PM PST
