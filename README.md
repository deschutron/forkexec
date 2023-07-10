# Forkexec and Silent Forkexec 
A pair of utilities to launch a program in a separate process, using the fork() function from the Unix API.

forkexec does a fork and then exec.

silent forkexec (sf) does a fork, redirects stdout to /dev/null and then an exec.

silent forkexec is a useful way to launch GUI applications from a terminal window without having them echo anything to the terminal, just like if you had opened them from the start menu.
