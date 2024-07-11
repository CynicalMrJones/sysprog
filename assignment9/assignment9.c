
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>



pid_t a,b,c,d; 

void processA(int logPip[], int ABpip[]){
    close(logPip[0]);
    close(ABpip[0]);
    srand(time(0));
    int upperBound = 1;
    int lowerBound = 0;
    char letter,answer[4];
    for (int i = 0; i<10; i++) {
        int value = rand() % (upperBound- lowerBound+ 1) + lowerBound;
        if (value == 0) {
            letter = 'C';
        }
        else {
            letter = 'D';
        }
        answer[0] = 'A';
        answer[1] = letter;
        answer[2] = i + '0';
        answer[3] = '\0';
        write(ABpip[1], &answer[1], 2);
        write(logPip[1], answer,3);
    }
    close(logPip[1]);
    close(ABpip[1]);
}
void processB(int logPip[], int ABpip[], int BCpip[], int BDpip[]){
    close(logPip[0]);
    close(BCpip[0]);
    close(BDpip[0]);
    close(ABpip[1]);
    for (int i = 0; i < 10; i++) {
        char buf[3];
        read(ABpip[0], &buf[1], 2);
        buf[0] = 'B';
        if (buf[1] == 'D') {
            write(BDpip[1], &buf[1], 2);
            write(logPip[1], buf, 3);
            sleep(1);
        }
        else {
            write(BCpip[1], &buf[1], 2);
            write(logPip[1], buf, 3);
            sleep(1);
        }

    }
    close(logPip[1]);
    close(BCpip[1]);
    close(BDpip[1]);
    close(ABpip[0]);
}
void processC(int logPip[], int BCpip[]){
    close(logPip[0]);
    close(BCpip[1]);
    ssize_t nbytes;
    char buf[3];
    while ((nbytes = read(BCpip[0], &buf[1], 2)) != 0) {
        buf[0] = 'C';
        write(logPip[1], buf, 3);
    }
    close(logPip[1]);
    close(BCpip[0]);
}
void processD(int logPip[], int BDpip[]){
    close(logPip[0]);
    close(BDpip[1]);
    ssize_t nbytes;
    char buf[3];
    while ((nbytes = read(BDpip[0], &buf[1], 2)) != 0) {
        buf[0] = 'D';
        write(logPip[1], buf, 2);
        sleep(5);
    }
    close(logPip[1]);
    close(BDpip[0]);
}
int main(){
    int logPip[2];
    int ABpip[2];
    int BCpip[2];
    int BDpip[2];
    pipe(logPip);
    pipe(ABpip);
    pipe(BCpip);
    pipe(BDpip);

    a = fork();
    if (a == 0) {
        // Child process 1 code
        processA(logPip, ABpip);
        printf("Child 1: PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(0);
    } else if (a < 0) {
        perror("fork");
        exit(1);
    }

    // Create second child process
    b = fork();
    if (b == 0) {
        // Child process 2 code
        processB(logPip, ABpip,BCpip,BDpip);
        printf("Child 2: PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(0);
    } else if (b < 0) {
        perror("fork");
        exit(1);
    }

    // Create third child process
    c = fork();
    if (c == 0) {
        //Child process 3 code
        close(logPip[0]);
        close(BDpip[1]);
        close(ABpip[0]);
        close(ABpip[1]);
        processC(logPip, BCpip);
        printf("Child 3: PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(0);
    } else if (c < 0) {
        perror("fork");
        exit(1);
    }

    // Create fourth child process
    d = fork();
    if (d == 0) {
        // Child process 4 code
        close(logPip[0]);
        close(BDpip[1]);
        close(ABpip[0]);
        close(ABpip[1]);
        processD(logPip, BDpip);
        printf("Child 4: PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(0);
    } else if (d < 0) {
        perror("fork");
        exit(1);
    }
    close(logPip[1]);
    close(ABpip[0]);
    close(ABpip[1]);
    close(BCpip[0]);
    close(BCpip[1]);
    close(BDpip[0]);
    close(BDpip[1]);
    char buf[3];
    while (read(logPip[0], buf, 3) > 0) {
        printf("Logging received from process %c: %c%c\n", buf[0], buf[1], buf[2]);
    }
    close(logPip[0]);
    waitpid(a, NULL, 0);
    waitpid(b, NULL, 0);
    waitpid(c, NULL, 0);
    waitpid(d, NULL, 0);

    printf("Logging process: All child processes have terminated.\n");

    return 0;

}
