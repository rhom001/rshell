Script started on Fri 06 Nov 2015 08:37:13 PM PST
]0;rhom001@hammer:~/rshell[?1034h[rhom001@hammer rshell]$ make
mkdir bin
g++ -Wall -Werror -ansi -pedantic -o bin/rshell src/main.cpp src/rshell.cpp
]0;rhom001@hammer:~/rshell[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ echo	Hello			world
Hello world
rhom001@hammer$ ls
bin  kit  LICENSE  Makefile  README.md	rhom001  src  tests
rhom001@hammer$ git stt atus
# On branch master
# Changes not staged for commit:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	[31mmodified:   README.md[m
#	[31mmodified:   tests/single_command.sh[m
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	[31mbin/[m
#	[31mrhom001[m
no changes added to commit (use "git add" and/or "git commit -a")
rhom001@hammer$ git log
[?1h=[33mcommit dfdbf0b97dbfa1d599a9d8b1d9fb24aa90b57a06[m[m
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>[m
Date:   Fri Nov 6 20:33:11 2015 -0800[m
[m
    modified username/hostname prompt to match example[m
[m
[33mcommit 2bfd6bb24917f5ed47286c121e68e7d608e6dcd5[m[m
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>[m
Date:   Fri Nov 6 20:32:16 2015 -0800[m
[m
    modified multi_command.sh[m
[m
[33mcommit 0a5306061d39aae269473eb07b4611dd4f281489[m[m
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>[m
Date:   Fri Nov 6 20:17:31 2015 -0800[m
[m
    modified single command test script[m
[m
[33mcommit bb1ef1889706a1962517ea44268743f8a28f22c3[m[m
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>[m
Date:   Fri Nov 6 19:43:58 2015 -0800[m
[m
    updated main to clear arrays at end of the program[m
:[K[K[?1l>rhom001@hammer$ cal
    November 2015   
Su Mo Tu We Th Fr Sa
 1  2  3  4  5 [7m 6[27m  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30

rhom001@hammer$ mkdir kit
mkdir: cannot create directory `kit': File exists
rhom001@hammer$ ls
bin  kit  LICENSE  Makefile  README.md	rhom001  src  tests
rhom001@hammer$ rmdir kit
rhom001@hammer$ mkdir magic
rhom001@hammer$ touch magic/test.txt
rhom001@hammer$ cd magic
cd: No such file or directory
rhom001@hammer$ exit
logout
rhom001@hammer$ exit
logout
]0;rhom001@hammer:~/rshell[rhom001@hammer rshell]$ exit
exit

Script done on Fri 06 Nov 2015 08:39:29 PM PST
