#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int compare(const void *a, const void *b) {
    const struct dirent *entryA = *(const struct dirent **)a;
    const struct dirent *entryB = *(const struct dirent **)b;
    return strcmp(entryA->d_name, entryB->d_name);
}

void printBS(struct dirent **entries,int count){
    for (int i=0; i<count; i++) {
        if ((entries[i]->d_name[0] != '.')) {
            printf("%s\n", entries[i]->d_name);
        }
    }
}

void ls (char dirname[], int aFlag, int lFlag){
    int i;
    int count;
    DIR *dir_ptr;
    struct dirent *direntp;
    struct dirent **entries;
    //This checks to see if the directory exsists
    if((dir_ptr=opendir(dirname)) == NULL){
        fprintf(stderr,"cannot open %s\n",dirname);
    }
    else{
        //Long if else chain. Its very ugly and doesn't allow for expandability but it works 
        //for the extents of this program
        //TODO: Need to organize and parse the additional information provided by the flags 
        struct stat buf;
        struct group *group;
        struct password *pw;
        stat(dirname, &buf);

        group = getgrgid(buf.st_gid);
        printf("%d",group->gr_gid);
        printf("Fuck oyou");
        printf("%d",group->gr_gid);
        printf("Fuck oyou");
        while ((direntp=readdir(dir_ptr))!= NULL){
            count++;
        }
        printf(" ");

        entries = (struct dirent **)calloc(count , sizeof(struct dirent *));
        rewinddir(dir_ptr);

        i = 0;
        while ((direntp=readdir(dir_ptr))!= NULL){
            entries[i++] = direntp;
        }
        closedir(dir_ptr);

        qsort(entries, count, sizeof(struct dirent *), compare);

        if ((aFlag == 1) & (lFlag == 1)){
            //TODO: Do both the l and the a flag 
            for (int j = 0; j<count; j++) {
                fprintf(stdout,"%-10s \n",entries[j]->d_name);
            }
        }
        else if (aFlag == 1){
            //TODO: Parse the data and show all of them in order
            for (int j = 0; j<count; j++) {
                fprintf(stdout,"%-10s ",(entries[j])->d_name);
            }
        }
        else if (lFlag == 1){
            //TODO: show them in a list and show the additional information 
            for (int j = 0; j<count; j++) {
                if ((entries[j]->d_name[0] != '.')) {
                    printf("%s\n", entries[j]->d_name);
                }
            }
        }
        else {
            printBS(entries, count);
        }
    }
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
}
