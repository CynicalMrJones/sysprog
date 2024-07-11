
Questions: 
1) Process A generates all the messages to send to B. B then starts to distribute the message to process C and D.
2) There is evidence of independent process and that can be seen when c responds with what b is sending it.

Project Description: 
This project was kinda fun even though I didn't quite get it. The program creates 4 child processes and a logging parent
Process A sends signals to Process B and B sends to C and D.
D has a 5 second delay after sending a logging message.

Compilation instructions:
gcc -o assignment9 assignment9.c

Existing bugs:
The program works for the most part. The issue is when process D sleeps for 5 seconds. If Process B sends another message
to D then will try and take that new request without logging the old one. 
