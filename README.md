Rebecca Hom & Jorge Gonzalez
#README
<h1>CS100: rshell - A Basic Command Shell</h1>
<p>
In this project, we built a basic command shell using C++ source code. 
It takes in a string of commands and connectors from the user that will be executed in the shell.
In addition, it can take in precedence for commands that allow for it to run commands in parentheses first. </p> 

<h2>Design</h2>
<p>
For the original version of our rshell, we had two main functions to run commands: parseCommand and executeCommand.
From the main, the user would input a string, which would be parsed into a 2d char array by the parseCommand.
Then the array would be tokenized further in parseCommand before being passed into executeCommand, which would carry out the commands.
</p>
<p>
However, when we began working on precedence, we realized that we needed to break up parseCommand.
We also changed parseCommand and executeCommand from void functions into boolean functions.
In addition, we added a metaRun and run functions.
The metaRun function handles parsing the user input into substrings if there is precedence involved.
Meanwhile the run function takes the command block from the substring, parses it, and executes it.
The result of the block is then used in the metaRun for any precedence operations.
</p>
<p>
In addition, a couple of helper functions were made to look for connectors as well as connector operations.
This in turn made it easier for us to control for different commands.
Particularly for the test command, after determining that it was the command we created a special function to carry out error handling for it.
</p>

<h2>Known Bugs</h2>
<p>
Some known bugs. Unless noted as fixed, expect the bugs to still be there.
</p>
<h3>Assignment 2 Bugs</h3>
<ul>
    <li>Due to time constraints, we were unable to properly implement the parentheses precedence operators.</li>
    <li>For commands run through <em> execvp()</em> in executeCommand, executeCommand will return false for explicity wrong commands, but not flags.</li>
</ul>
<h3>Assignment 1 Bugs</h3>
<ul>
    <li>When <em>exit</em> is input in a multiple command, there were problems with the following commands in multiple commands:</li>
    <ul>
        <li><em>cd</em></li>
        <li><em>who</em></li>
        <li><em>git status</em></li>
        <li><em>git log</em></li>
    </ul>
    <li>For the above commands, extra <em>exit</em> commands.</li>
    <li>For an improper <em>exit</em> command, an <em>ls</em> might be run.</li>
    <li>The command <em>cd</em> does not run in the shell.</li>
    <li>When <em>script</em> is run in rshell, it brings the user to the bash.</li>
    <li>When <em>echo</em> with an argument in quotes, it does not take out the quotes.</li>
    <li>The '\"' is in <em>echo</em> is also not accepted.</li>
</ul>
