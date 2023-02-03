# xv6-initial-utilities
In this exercise we implement four UNIX utilities in c

#Unix Utilities Implemented
wact
wgrep
wzip
wunzip

##wcat
This program simple show the content of file, given as argument, to the stdout.
you can compile it and test it using below commands.
'''
prompt> git clone https://github.com/remzi-arpacidusseau/ostep-projects
prompt> cd ostep-projects/initial-utilities/wcat
prompt> emacs -nw wcat.c 
prompt> gcc -o wcat wcat.c -Wall 
prompt> ./test-wcat.sh
test 1: passed
test 2: passed
test 3: passed
test 4: passed
test 5: passed
test 6: passed
test 7: passed
prompt>
'''

##wgrep
This program find the pattern in the file given in the argumen of this program.

##wzip
This program convert the file to binary file. In this proram content in the file is compressed such that if you have "aaaaaa bbb" in the file then this convert to something like this "6a1 3b".

##wunzip
This program unzip the file content of above function.

###Projects for an undergraduate OS course
https://github.com/remzi-arpacidusseau/ostep-projects
