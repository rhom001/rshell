Script started on Fri 06 Nov 2015 08:41:44 PM PST
[rhom001@hammer rshell]$ make
mkdir bin
g++ -Wall -Werror -ansi -pedantic -o bin/rshell src/main.cpp src/rshell.cpp
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ echo "Hello world" && echo "And all those who inhabit it"
"Hello world"
"And all those who inhabit it"
rhom001@hammer$ git status || date
# On branch master
# Changes not staged for commit:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   README.md
#	modified:   tests/multi_command.sh
#	modified:   tests/single_command.sh
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	bin/
#	magic/
#	rhom001
no changes added to commit (use "git add" and/or "git commit -a")
rhom001@hammer$ git log;&ls;-a; mkdir kit
commit dfdbf0b97dbfa1d599a9d8b1d9fb24aa90b57a06
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 20:33:11 2015 -0800

    modified username/hostname prompt to match example

commit 2bfd6bb24917f5ed47286c121e68e7d608e6dcd5
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 20:32:16 2015 -0800

    modified multi_command.sh

commit 0a5306061d39aae269473eb07b4611dd4f281489
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 20:17:31 2015 -0800

    modified single command test script

commit bb1ef1889706a1962517ea44268743f8a28f22c3
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 19:43:58 2015 -0800

    updated main to clear arrays at end of the program
.  ..  bin  .git  LICENSE  magic  Makefile  README.md  rhom001	src  tests
rhom001@hammer$ ls; rmdir magic&&&mrmdir kit; vim magic/test.txt
bin  kit  LICENSE  magic  Makefile  README.md  rhom001	src  tests
rmdir: failed to remove `magic': Directory not empty
"magic/test.txt"x1L,06C written															    ~															      ~																~															  ~															    ~															      ~																~															  ~															    ~															      ~																~															  ~															    ~															      ~																~															  ~															    ~															      ~																~															  ~															    ~															      0,0-1All-- INSERT --0,1AllH1,2e3l4l5o61,5All:wq
rhom001@hammer$ mv magic/test.txt test.txt
rhom001@hammer$ ls -a
.  ..  bin  .git  LICENSE  magic  Makefile  README.md  rhom001	src  tests  test.txt
rhom001@hammer$ echo "Now the magic directory is empty"
"Now the magic directory is empty"
rhom001@hammer$ rmdir magic && rm test.txt
rhom001@hammer$ ls || date && cal || whoami
bin  LICENSE  Makefile	README.md  rhom001  src	 tests
    November 2015
Su Mo Tu We Th Fr Sa
 1  2  3  4  5	6  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30

rhom001@hammer$ whoami && hostname
rhom001
hammer.cs.ucr.edu
rhom001@hammer$ who || echo "Goodbye"
rhom001	 pts/0	      2015-11-06 20:41
tprye001 pts/1	      2015-11-06 18:07 (71-84-75-198.dhcp.rvsd.ca.charter.com)
rhom001	 pts/2	      2015-11-06 19:39 (ucrwpa2-4-183-2.bulk.ucr.edu)
jflor053 pts/3	      2015-11-06 14:02 (169.235.73.116)
jphan016 pts/4	      2015-11-06 20:45 (97-93-103-140.static.mtpk.ca.charter.com)
jreim001 pts/5	      2015-11-06 20:33 (cpe-76-95-0-184.socal.res.rr.com)
jchan107 pts/7	      2015-11-06 18:17 (71-95-61-210.dhcp.rvsd.ca.charter.com)
anguy112 pts/8	      2015-11-06 20:33 (99-186-17-163.lightspeed.irvnca.sbcglobal.net)
spica001 pts/9	      2015-11-06 19:24 (kilo-20.cs.ucr.edu)
ady002	 pts/10	      2015-11-06 15:46 (99-37-187-118.lightspeed.cornca.sbcglobal.net)
ychen133 pts/13	      2015-11-06 18:33 (lancetreo.dyn.ucr.edu)
emull005 pts/15	      2015-11-06 17:26 (99-179-30-234.lightspeed.irvnca.sbcglobal.net)
qluu001	 pts/16	      2015-11-06 19:00 (63.138.45.36)
ddiep003 pts/17	      2015-11-06 17:52 (kilo-27.cs.ucr.edu)
dzhu006	 pts/18	      2015-11-06 18:35 (71-95-49-90.dhcp.rvsd.ca.charter.com)
smagn001 pts/19	      2015-11-06 12:51 (71-95-39-117.dhcp.rvsd.ca.charter.com)
jalca011 pts/20	      2015-11-06 17:54 (71-84-75-198.dhcp.rvsd.ca.charter.com)
apuh001	 pts/21	      2015-11-06 17:52 (104.241.36.27)
mcast052 pts/22	      2015-11-06 18:38 (169.235.57.203)
fyang016 pts/23	      2015-11-06 20:24 (96-40-173-200.dhcp.mtpk.ca.charter.com)
bpara001 pts/24	      2015-11-06 18:42 (68-119-155-221.dhcp.ahvl.nc.charter.com)
lzhan021 pts/25	      2015-11-06 19:12 (99-109-89-176.lightspeed.irvnca.sbcglobal.net)
mcast052 pts/26	      2015-11-06 18:58 (169.235.57.203)
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
wrand001 pts/39	      2015-11-06 20:16 (66-215-152-208.dhcp.rvsd.ca.charter.com)
rhom001@hammer$ echo Goodbye && exit
Goodbye
logout
[rhom001@hammer rshell]$ exit
exit

Script done on Fri 06 Nov 2015 08:46:52 PM PST
