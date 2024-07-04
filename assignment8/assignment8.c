#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAXLINE 4096


char *change(char *path){
    char *temp;
    chdir(path);
    temp = getcwd(temp, sizeof(temp));
    return temp;
}


int main(int argc, char *argv[]) {
    char buf[MAXLINE];
    pid_t pid;
    int status = 0;
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    int args_num = 0;
    char *str1, *token;
    char *args[48];

    printf("%s%% ",cwd);  /* print prompt (printf requires %% to print %) */
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        getcwd(cwd, sizeof(cwd));
        if(buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */

        str1 = strdup(buf);
        for (int j = 0;; j++, str1 = NULL) {
            token = strtok(str1, " ");
            if (token == NULL) break;
            args[j] = token;
            args_num += 1;
        }

        free(str1);
        args[args_num] = (char *)NULL;

        if((pid = fork()) < 0) {
            exit(EXIT_SUCCESS);
        }
        else if (pid == 0) {        /* child */
            if (strcmp(args[0], "quit") == 0) {
                kill(pid, SIGKILL);
            }
            else if (strcmp(args[0], "cd") ==0) {
                chdir(args[1]);
                getcwd(cwd,sizeof(cwd));
            }
            execvp(args[0], &args[0]);
            exit(127);
        }

        /* parent */
        if((pid = waitpid(pid, &status, 0)) < 0){
            exit(EXIT_SUCCESS);
        }
        else{
            printf("%s%% ",cwd);
        };
    }
    exit(0);
}
