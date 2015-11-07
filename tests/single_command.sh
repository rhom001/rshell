Script started on Fri 06 Nov 2015 07:58:21 PM PST
]0;rhom001@hammer:~/rshell[?1034h[rhom001@hammer rshell]$ make
mkdir bin
g++ -Wall -Werror -ansi -pedantic -o bin/rshell src/main.cpp src/rshell.cpp
]0;rhom001@hammer:~/rshell[rhom001@hammer rshell]$ bin/rshell
[rhom001@hammer] $ echo "Hello world"             Hello  		world
Hello world
[rhom001@hammer] $ ls
bin  LICENSE  Makefile	README.md  rhom001  src  tests
[rhom001@hammer] $ git status
# On branch master
# Your branch is ahead of 'origin/master' by 1 commit.
#
# Changed but not updated:
#   (use "git add/rm <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   README.md
#	deleted:    tests/multi_command.sh
#	modified:   tests/single_command.sh
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	bin/
#	rhom001
no changes added to commit (use "git add" and/or "git commit -a")
[rhom001@hammer] $ git log
[?1h=commit bb1ef1889706a1962517ea44268743f8a28f22c3[m
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>[m
Date:   Fri Nov 6 19:43:58 2015 -0800[m
[m
    updated main to clear arrays at end of the program[m
[m
commit 22286fe7d3cb3c05e02a637d550c770a9ab17ce9[m
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>[m
Date:   Thu Nov 5 20:49:55 2015 -0800[m
[m
    updated rshell[m
[m
commit ade6e097a2e7256128ad2f8e3d8ecccfdee85391[m
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>[m
Date:   Thu Nov 5 20:47:34 2015 -0800[m
[m
    "tweaked || connector execution"[m
[m
commit f49b2569054f5aa042d470a33ed6472b82215949[m
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>[m
Date:   Thu Nov 5 20:46:31 2015 -0800[m
[m
    "added current user and hostname"[m
:[K[K[?1l>[rhom001@hammer] $ cal
    November 2015   
Su Mo Tu We Th Fr Sa
 1  2  3  4  5 [7m 6[27m  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30

[rhom001@hammer] $ date
Fri Nov  6 19:59:04 PST 2015
[rhom001@hammer] $ mkdir kit
[rhom001@hammer] $ ls -v
LICENSE  Makefile  README.md  bin  kit	rhom001  src  tests
[rhom001@hammer] $ ls -    echo      touch kit/          git branch
  exec
* master
[rhom001@hammer] $ echo H      echo "This was a test for	single commands"
"This was a test for	single commands"
[rhom001@hammer] $ exit
logout
]0;rhom001@hammer:~/rshell[rhom001@hammer rshell]$ exit
exit

Script done on Fri 06 Nov 2015 08:00:05 PM PST
