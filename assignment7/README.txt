
Project Description: 
This project was alot. I didn't manage to work out all the bugs but its close.
The user runs the program with a file path and it prints out the files in that directory.
It supports two flags that is -a and -l
-a provides all files including hidden files
-l provides all entries in a neat list
They can also be combined in any combination ex. -al or -la

Compilation instructions:
The program can be compiled using : gcc -o myLs myLs.c

Existing bugs:
Where do I begin. The program will sometimes not get the entry or user or group correct.
ex. It will have the user and the group be some user named 'daemon' with a file named 'mon'

On line

Compilation instructions:
The program can be compiled using : gcc -o myLs myLs.c

Existing bugs:
Where do I begin. The program will sometimes not get the entry or user or group correct.
ex. It will have the user and the group be some user named 'daemon' with a file named 'mon'.
On line 115 there is a print statement with a space in it that is REQUIRED for the -a option to work for some
reason. (My guess is something to do with a null char). When putting in no arguments or -a the spacing on each entry isnt 
consistent or even accurate. I ran out of time to figure out how to parse the time (I hope you see the irony here).
While working on this program it would compile perfectly normal one second and spit out seg faults the next.
At some point i had to run as super user just to get the file permissions correct.
I somehow understand c less because of this project. It makes me appreciate higher level languages more.
I could have made this in rust in half the time and half the headache.
