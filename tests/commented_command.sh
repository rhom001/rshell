Script started on Fri 06 Nov 2015 08:59:27 PM PST
[rhom001@hammer rshell]$ make
mkdir bin
g++ -Wall -Werror -ansi -pedantic -o bin/rshell src/main.cpp src/rshell.cpp
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ echo "Hello world"; ls
"Hello world"
rhom001@hammer$ ls #-a
ls: cannot access : No such file or directory
rhom001@hammer$ ls#-a
bin  LICENSE  Makefile	README.md  rhom001  src	 tests
rhom001@hammer$ ls -a; echo hello && #mkdir test || echo world; git status
.  ..  bin  .git  LICENSE  Makefile  README.md	rhom001	 src  tests
hello
rhom001@hammer$ #echo "Failed atmcommenting"
rhom001@hammer$ echo Goodbye #&& exit
Goodbye
rhom001@hammer$ exit
logout
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ echo #hello || echo goodbye

rhom001@hammer$ exit
logout
[rhom001@hammer rshell]$ exit
exit

Script done on Fri 06 Nov 2015 09:02:25 PM PST
