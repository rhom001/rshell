Script started on Fri 06 Nov 2015 09:09:56 PM PST
[rhom001@hammer rshell]$ make
mkdir bin
g++ -Wall -Werror -ansi -pedantic -o bin/rshell src/main.cpp src/rshell.cpp
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ exit
logout
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ git status && echo "Hello world" || exit
# On branch master
# Your branch is ahead of 'origin/master' by 3 commits.
#   (use "git push" to publish your local commits)
#
# Changes not staged for commit:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   README.md
#	modified:   tests/exit.sh
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	bin/
#	rhom001
no changes added to commit (use "git add" and/or "git commit -a")
"Hello world"
rhom001@hammer$ cal && exit
    November 2015
Su Mo Tu We Th Fr Sa
 1  2  3  4  5	6  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30

logout
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ echo "Hello world" && exit; echo Goodbye || echo "Whataa bummer"
"Hello world"
logout
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ echo "Let's try a comment#ed exit" && exit
"Let's try a comment#ed exit"
logout
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ echoo"Let's try this again" #&& exit; echo "Again?!?"
"Let's try this again"
rhom001@hammer$ echo Hoorayy&&nexitork"
Hooray
logout
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ #exit; echo "That exit was commented out"
rhom001@hammer$ git status || exit; git log && exit; git sta
# On branch master
# Your branch is ahead of 'origin/master' by 3 commits.
#   (use "git push" to publish your local commits)
#
# Changes not staged for commit:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   README.md
#	modified:   tests/exit.sh
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	bin/
#	rhom001
no changes added to commit (use "git add" and/or "git commit -a")
commit 3e1d070e508f45a8df4ac4c9284d069f07218eed
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 21:02:51 2015 -0800

    modified commented_command.sh

commit 13ea3b4d3c6a51754045b57a6cb5cc9fb90531fe
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 20:47:59 2015 -0800

    updated multiple commands script test

commit 2a160cb94cc4f7aebda71bfcd872f6552a34a9b5
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 20:47:59 2015 -0800

    updated single command script test

commit dfdbf0b97dbfa1d599a9d8b1d9fb24aa90b57a06
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 20:33:11 2015 -0800

    modified username/hostname prompt to match example

commit 2bfd6bb24917f5ed47286c121e68e7d608e6dcd5
logout
[rhom001@hammer rshell]$ git status && exit
# On branch master
# Your branch is ahead of 'origin/master' by 3 commits.
#   (use "git push" to publish your local commits)
#
# Changes not staged for commit:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   README.md
#	modified:   tests/exit.sh
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	bin/
#	rhom001
no changes added to commit (use "git add" and/or "git commit -a")
exit

Script done on Fri 06 Nov 2015 09:13:02 PM PST
