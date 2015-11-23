Script started on Sun 22 Nov 2015 11:49:08 PM PST
[rhom001@hammer rshell]$ make
mkdir bin
g++ -Wall -Werror -ansi -pedantic -o bin/rshell src/main.cpp src/rshell.cpp
[rhom001@hammer rshell]$ bin/rshell
rhom001@hammer$ echo hello world
hello world
rhom001@hammer$ (echo hello world)
rhom001@hammer$ echo Now that shouldn't have happened
Now that shouldn't have happened
rhom001@hammer$ echo A && echo B || echo C && echo D
A
B
D
rhom001@hammer$ echo Let's try this with some precedence && (echo A && echo B ^?) || (echo C && echo D)
rhom001@hammer$ (echo A && echo B) || (echo C && echo D)
rhom001@hammer$ echo A && (echo B || echo C) && echo D
rhom001@hammer$ echo Due to the half completed partoof the metaRun function, wenarerunableitodactuallysruncanymcommandsywithrparenthesestintthem had no clue how to go about this.^[[D
Due to the half completed part of the metaRun function, we are unable to actually run any commands with parentheses in them
rhom001@hammer$ echo And it's because of time constraints that we really could not get things working (butewe got test to run)
rhom001@hammer$ echo "Buttthey (could)oworknin quotes"
rhom001@hammer$ echo Nah, they don't
Nah, they don't
rhom001@hammer$ echo But here are some errors
But here are some errors
rhom001@hammer$ echo Toommany onrthehleft (
Syntax error: extra '('
rhom001@hammer$ echo Too many on the right )
Syntax error: extra ')'
rhom001@hammer$ echo And for some added frustration )(
Error: Reversed parentheses. You're a ****ing **** for doing that you terrible
monster. If you're a Pisces, you're not special for trying to code that in.
rhom001@hammer$ exit
logout
[rhom001@hammer rshell]$ exit
exit

Script done on Sun 22 Nov 2015 11:54:47 PM PST
