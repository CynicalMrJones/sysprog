#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

void ls (char dirname[], int aFlag, int lFlag){
    DIR *dir_ptr;
    struct dirent *direntp;
    //This checks to see if the directory exsists
    if((dir_ptr=opendir(dirname)) == NULL){
        fprintf(stderr,"cannot open %s\n",dirname);
    }
    else{
        //Long if else chain. Its very ugly and doesn't allow for expandability but it works 
        //for the extents of this program
        //TODO: Need to organize and parse the additional information provided by the flags 
        if ((aFlag == 1) & (lFlag == 1)){
            //TODO: Do both the l and the a flag 
            printf("The a and l flag is set\n");
            while ((direntp=readdir(dir_ptr))!= NULL){
                printf("%s\n",direntp->d_name);
            }
        }
        else if (aFlag == 1){
            printf("The a flag is set\n");
            //TODO: Parse the data and show all of them in order
            while ((direntp=readdir(dir_ptr))!= NULL){
                printf("%s\n",direntp->d_name);
            }
        }
        else if (lFlag == 1){
            printf("The l flag is set\n");
            //TODO: show them in a list and show the additional information 
            while ((direntp=readdir(dir_ptr))!= NULL){
                printf("%s\n",direntp->d_name);
            }
        }
        else if ((lFlag == 0) & (aFlag == 0)){
            printf("Neither flag is set\n");
            while ((direntp=readdir(dir_ptr))!= NULL){
                printf("%s\n",direntp->d_name);
            }
        }
    }
    closedir(dir_ptr);
}

int main(int argc, char *argv[]){
    int aFlag;
    int lFlag;
    int opt;
    while ((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt){
            case 'a':
                aFlag = 1;
                break;
            case 'l':
                lFlag = 1;
                break;
        }
    }
    ls(argv[argc-1],aFlag,lFlag);
    return 0;
}
