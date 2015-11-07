Script started on Fri 06 Nov 2015 09:40:40 PM PST
[rhom001@hammer rshell]$ make
mkdir bin
g++ -Wall -Werror -ansi -pedantic -o bin/rshell src/main.cpp src/rshell.cpp
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ echo		Hello		world
Hello world
rhom001@hammer$ git status
# On branch master
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	bin/
#	rhom001
#	single.sh
nothing added to commit but untracked files present (use "git add" to track)
rhom001@hammer$ git log
commit 5c4970a33555993ba015a8cd188ddba869398fd0
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 21:37:04 2015 -0800

    updated README.md to include known bugs

commit 0d9b757abe87d42237e539ac6856692c2f26f97e
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 21:34:44 2015 -0800

    cleaned up exit test script

commit ca414a315c0926f2b20c76822dcfc6ae668aac44
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 21:33:38 2015 -0800

    cleaned up commented_command.sh

commit a11da07861b60401ddec0f63bb979550ab621eca
Author: Rebecca Hom <rhom001@hammer.cs.ucr.edu>
Date:	Fri Nov 6 21:29:29 2015 -0800

    cleaned up multiple command script

commit 1066401a5839ba0638113a33a512272f143fc4f2
rhom001@hammer$ calt
    November 2015
Su Mo Tu We Th Fr Sa
 1  2  3  4  5	6  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30

rhom001@hammer$ who
dphan015 pts/0	      2015-11-06 21:24 (97-93-103-140.static.mtpk.ca.charter.com)
tprye001 pts/1	      2015-11-06 18:07 (71-84-75-198.dhcp.rvsd.ca.charter.com)
rhom001	 pts/2	      2015-11-06 19:39 (ucrwpa2-4-183-2.bulk.ucr.edu)
jflor053 pts/3	      2015-11-06 14:02 (169.235.73.116)
jphan016 pts/4	      2015-11-06 20:45 (97-93-103-140.static.mtpk.ca.charter.com)
jreim001 pts/5	      2015-11-06 20:33 (cpe-76-95-0-184.socal.res.rr.com)
lzhan021 pts/6	      2015-11-06 20:55 (99-109-89-176.lightspeed.irvnca.sbcglobal.net)
jchan107 pts/7	      2015-11-06 18:17 (71-95-61-210.dhcp.rvsd.ca.charter.com)
anguy112 pts/8	      2015-11-06 20:33 (99-186-17-163.lightspeed.irvnca.sbcglobal.net)
jflor053 pts/9	      2015-11-06 21:25
ady002	 pts/10	      2015-11-06 15:46 (99-37-187-118.lightspeed.cornca.sbcglobal.net)
ddiep003 pts/11	      2015-11-06 21:05 (ucrwpa1-5-146-253.bulk.ucr.edu)
spica001 pts/12	      2015-11-06 21:06 (ucrwpa1-2-135-11.bulk.ucr.edu)
fyang016 pts/13	      2015-11-06 21:10 (96-40-173-200.dhcp.mtpk.ca.charter.com)
cwong043 pts/14	      2015-11-06 21:21 (71-95-45-183.dhcp.rvsd.ca.charter.com)
emull005 pts/15	      2015-11-06 17:26 (99-179-30-234.lightspeed.irvnca.sbcglobal.net)
qluu001	 pts/16	      2015-11-06 19:00 (63.138.45.36)
ddiep003 pts/17	      2015-11-06 17:52 (kilo-27.cs.ucr.edu)
jflor053 pts/18	      2015-11-06 21:26
smagn001 pts/19	      2015-11-06 12:51 (71-95-39-117.dhcp.rvsd.ca.charter.com)
jalca011 pts/20	      2015-11-06 17:54 (71-84-75-198.dhcp.rvsd.ca.charter.com)
apuh001	 pts/21	      2015-11-06 17:52 (104.241.36.27)
cfalz002 pts/22	      2015-11-06 21:29 (71-84-66-161.dhcp.rvsd.ca.charter.com)
mcast052 pts/23	      2015-11-06 21:38
bpara001 pts/24	      2015-11-06 18:42 (68-119-155-221.dhcp.ahvl.nc.charter.com)
mcast052 pts/25	      2015-11-06 21:37
lhern031 pts/27	      2015-11-06 19:05 (75-141-121-119.dhcp.mtpk.ca.charter.com)
tlars001 pts/28	      2015-11-06 19:06 (138.229.143.23)
mcast052 pts/29	      2015-11-06 19:47 (169.235.57.203)
cwong043 pts/30	      2015-11-06 19:13 (71-95-45-183.dhcp.rvsd.ca.charter.com)
rhom001	 pts/31	      2015-11-06 21:40
bgutz001 pts/32	      2015-11-06 19:50 (107-193-230-2.lightspeed.irvnca.sbcglobal.net)
jphan016 pts/33	      2015-11-06 21:38
oli001	 pts/34	      2015-11-06 13:12 (104.241.36.27)
mlauh001 pts/35	      2015-11-06 20:16 (71-95-191-2.static.mtpk.ca.charter.com)
cbent002 pts/36	      2015-11-06 14:20 (63.138.45.36)
bito001	 pts/37	      2015-11-06 20:07 (75-141-121-119.dhcp.mtpk.ca.charter.com)
mcast052 pts/38	      2015-11-06 20:11 (169.235.57.203)
rhom001@hammer$ exit
logout
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ mkdir kit
mkdir: cannot create directory `kit': File exists
rhom001@hammer$ mkdir magic
rhom001@hammer$ ls
bin  kit  LICENSE  magic  Makefile  README.md  rhom001	single.sh  src	tests
rhom001@hammer$ rmdirrmagic
rhom001@hammer$ touch kit/test.txt
rhom001@hammer$ ls
bin  kit  LICENSE  Makefile  README.md	rhom001	 single.sh  src	 tests
rhom001@hammer$ rmdir kit
rmdir: failed to remove `kit': Directory not empty
rhom001@hammer$ exit
logout
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ echo "This		is	a test!"
"This		is	a test!"
rhom001@hammer$ echo "\"This is another		test\""
"\"This is another test\""
rhom001@hammer$ ls
bin  kit  LICENSE  Makefile  README.md	rhom001	 single.sh  src	 tests
rhom001@hammer$ mv kit/test.txt test.txt
rhom001@hammer$ exit
logout
[rhom001@hammer rshell]$ exit
exit

Script done on Fri 06 Nov 2015 09:43:22 PM PST
