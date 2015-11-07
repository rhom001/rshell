Script started on Fri 06 Nov 2015 09:23:06 PM PST
[rhom001@hammer rshell]$ make
mkdir bin
g++ -Wall -Werror -ansi -pedantic -o bin/rshell src/main.cpp src/rshell.cpp
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ echo		Hello			world
Hello world
rhom001@hammer$ git status
# On branch master
# Changes not staged for commit:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   README.md
#	modified:   tests/single_command.sh
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	bin/
#	rhom001
#	test.txt
no changes added to commit (use "git add" and/or "git commit -a")
rhom001@hammer$ git log
commit 22018e02a7a748ed3c6e55c8138cdbe490416127
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 21:13:39 2015 -0800

    modified exit test shell script

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
rhom001@hammer$ whoami
rhom001
rhom001@hammer$ date
Fri Nov	 6 21:23:34 PST 2015
rhom001@hammer$ cal
    November 2015
Su Mo Tu We Th Fr Sa
 1  2  3  4  5	6  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30

rhom001@hammer$ who
rhom001	 pts/0	      2015-11-06 21:23
tprye001 pts/1	      2015-11-06 18:07 (71-84-75-198.dhcp.rvsd.ca.charter.com)
rhom001	 pts/2	      2015-11-06 19:39 (ucrwpa2-4-183-2.bulk.ucr.edu)
jflor053 pts/3	      2015-11-06 14:02 (169.235.73.116)
jphan016 pts/4	      2015-11-06 20:45 (97-93-103-140.static.mtpk.ca.charter.com)
jreim001 pts/5	      2015-11-06 20:33 (cpe-76-95-0-184.socal.res.rr.com)
lzhan021 pts/6	      2015-11-06 20:55 (99-109-89-176.lightspeed.irvnca.sbcglobal.net)
jchan107 pts/7	      2015-11-06 18:17 (71-95-61-210.dhcp.rvsd.ca.charter.com)
anguy112 pts/8	      2015-11-06 20:33 (99-186-17-163.lightspeed.irvnca.sbcglobal.net)
jflor053 pts/9	      2015-11-06 21:23
ady002	 pts/10	      2015-11-06 15:46 (99-37-187-118.lightspeed.cornca.sbcglobal.net)
ddiep003 pts/11	      2015-11-06 21:05 (ucrwpa1-5-146-253.bulk.ucr.edu)
spica001 pts/12	      2015-11-06 21:06 (ucrwpa1-2-135-11.bulk.ucr.edu)
fyang016 pts/13	      2015-11-06 21:10 (96-40-173-200.dhcp.mtpk.ca.charter.com)
cwong043 pts/14	      2015-11-06 21:21 (71-95-45-183.dhcp.rvsd.ca.charter.com)
emull005 pts/15	      2015-11-06 17:26 (99-179-30-234.lightspeed.irvnca.sbcglobal.net)
qluu001	 pts/16	      2015-11-06 19:00 (63.138.45.36)
ddiep003 pts/17	      2015-11-06 17:52 (kilo-27.cs.ucr.edu)
rhale002 pts/18	      2015-11-06 21:21 (112.50.148.146.bc.googleusercontent.com)
smagn001 pts/19	      2015-11-06 12:51 (71-95-39-117.dhcp.rvsd.ca.charter.com)
jalca011 pts/20	      2015-11-06 17:54 (71-84-75-198.dhcp.rvsd.ca.charter.com)
apuh001	 pts/21	      2015-11-06 17:52 (104.241.36.27)
bpara001 pts/24	      2015-11-06 18:42 (68-119-155-221.dhcp.ahvl.nc.charter.com)
lhern031 pts/27	      2015-11-06 19:05 (75-141-121-119.dhcp.mtpk.ca.charter.com)
tlars001 pts/28	      2015-11-06 19:06 (138.229.143.23)
mcast052 pts/29	      2015-11-06 19:47 (169.235.57.203)
cwong043 pts/30	      2015-11-06 19:13 (71-95-45-183.dhcp.rvsd.ca.charter.com)
bgutz001 pts/32	      2015-11-06 19:50 (107-193-230-2.lightspeed.irvnca.sbcglobal.net)
oli001	 pts/34	      2015-11-06 13:12 (104.241.36.27)
mlauh001 pts/35	      2015-11-06 20:16 (71-95-191-2.static.mtpk.ca.charter.com)
cbent002 pts/36	      2015-11-06 14:20 (63.138.45.36)
bito001	 pts/37	      2015-11-06 20:07 (75-141-121-119.dhcp.mtpk.ca.charter.com)
mcast052 pts/38	      2015-11-06 20:11 (169.235.57.203)
rhom001@hammer$ mkdir kit
rhom001@hammer$ ls
bin  kit  LICENSE  magic  Makefile  README.md  rhom001	src  tests  test.txt
rhom001@hammer$ rmdirrmagic
rhom001@hammer$ rmdtest.txt
rhom001@hammer$ touch kit/test.txt
rhom001@hammer$ ls kit/test.txt
bin  kit  LICENSE  Makefile  README.md	rhom001	 src  tests
rhom001@hammer$ mv kit/test.txt test.txt
rhom001@hammer$ exit
logout
[rhom001@hammer rshell]$ exit
exit

Script done on Fri 06 Nov 2015 09:24:50 PM PST
