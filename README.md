Rebecca Hom & Jorge Gonzalez
#README
<h1>CS100 - Homework 1: rshell - Writing a Basic Command Shell</h1>
<p>In this project, we built a basic command shell using C++ source code. It takes in a string of commands and connectors from the user that will be executed in the shell.</p> 

<h2>The Rshell Process</h2>
<p>The commands are parsed so that they are separated into their command and argument lists. In addition, the connectors are also parsed while anything after a comment is excluded from the parsing process.</p>

<p>Once the commands are successfully parsed, then the commands will be executed. If the command is successfully executed, then the command will behave as intended. However, if it does not succeed, then the command will result in an error message.</p>

<p>This shell also allows for the use of the connectors <strong><em>;</em></strong>, <strong><em>&&</em></strong>, and <strong><em>||</em></strong>.</p> 
<ul>
    <li><strong><em>;</em></strong> - the following command is executed regardless of the status of the previous command.</li>
    <li><strong><em>&&</em></strong> - the following command is executed only if the previous command succeeds.</li>
    <li><strong><em>||</em></strong> - the following command is executed only if the previous command fails.</li>
</ul>

<h2>Known Bugs</h2>
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
