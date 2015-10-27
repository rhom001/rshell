#README
CS100
<h1>rshell - Writing a Basic Command Shell</h1>
<p>In this project, we will try to build a basic command shell using C++ source code.</p> 
<p>This command shell is will allow print a command prommpt ($) that will then read in a command on one line. The command will take in an <strong>exectuable</strong> program in the <strong>PATH</strong> as well as an <strong>argumentList</strong>.</p>
<p>In addition we will have a few connectors to run multiple commands.</p>
<ul>
    <li>If a command is followed by <strong>,</strong> then the next command will always be executed.</li>
    <li>If a command is followed by <strong>&&</strong>, then the next command will only be executed if the first one succeeds.</li>
    <li>If the command is followed by <strong>||</strong>, then the next command will only be executed if the first one fails.</li>
</ul>

<h2>Source Files</h2>
<h3>main.cpp</h3>
<p>Acts as a testing area for various functions as well as the main bash. The exit has already been dealt well.</p>
<p>For each syscall, <em>fork</em>, <em>execvp</em>, <em>waitpd</em>, we will have their own functions that will execute their behavior.</p>

<h3>rshell.cpp/rshell.h</h3>
<p>The rshell class contains the the syscalls <em>fork</em> (void myFork()), <em>execvp</em> (void myExec()), and  <em>waitpid</em> (void myWait()).</p>

<p>We also have the following functions in order for our shell to work:</p>
<ul>
    <li><em>void removeSpace(string input)</em> - removes extraneous whitespace from <em>input</em>.</li>
    <li><em>void convertCommands(string &input, vector<string> &inputs)</em> - takes in the commands from the <em>input</em> and parses them into a vector of <em>inputs</em></li>
</ul>
