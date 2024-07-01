
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

char *concad(char *str1, char *str2){
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *result = (char *)malloc(len1 + len2 + 1);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

char *getStats(const char *filename){
    const char *tmp = filename;
    if (filename == NULL) {
        return NULL;
    }
    struct stat buf;
    struct group *gw;
    struct passwd *pw;
    char arr[10];
    arr[0] = '\0';
    static char full[50];
    full[0] = '\0';
    stat(tmp, &buf);

    arr[0] = (buf.st_mode & S_IRUSR) ? 'r' : '-';
    arr[1] = (buf.st_mode & S_IWUSR) ? 'w' : '-';
    arr[2] = (buf.st_mode & S_IXUSR) ? 'x' : '-';

    arr[3] = (buf.st_mode & S_IRGRP) ? 'r' : '-';
    arr[4] = (buf.st_mode & S_IWGRP) ? 'w' : '-';
    arr[5] = (buf.st_mode & S_IXGRP) ? 'x' : '-';

    arr[6] = (buf.st_mode & S_IROTH) ? 'r' : '-';
    arr[7] = (buf.st_mode & S_IWOTH) ? 'w' : '-';
    arr[8] = (buf.st_mode & S_IXOTH) ? 'x' : '-';

    arr[9] = '\0';

    gw = getgrgid(buf.st_gid);
    pw = getpwuid(buf.st_gid);
    char *test = gw->gr_name;
    char *test2 = pw->pw_name;

    strcat(full, arr);
    strcat(full, " ");
    strcat(full, test);
    strcat(full, " ");
    strcat(full, test2);
    return full;
}

void printBS(struct dirent **entries,int count){
    int test = count;
    for (int i=0; i<test; i++) {
        if (((entries[i]->d_name[0]) != '.')) {
            printf("%-10s ", entries[i]->d_name);
        }
    }
}

void ls (char dirname[], int aFlag, int lFlag){
    int count = 0;
    DIR *dir_ptr;
    char *tempDirname = dirname; 
    struct dirent *direntp;
    struct dirent **entries;
    //This checks to see if the directory exsists
    if((dir_ptr=opendir(dirname)) == NULL){
        fprintf(stderr,"cannot open %s\n",dirname);
    }
    else{
        //Long if else chain. Its very ugly and doesn't allow for expandability but it works 
        //for the extents of this program
        int altcount = 0;
        while ((direntp=readdir(dir_ptr))!= NULL){
            if (direntp->d_name[0] == '.') {
                count++;
            }
            else {
                count++;
                altcount++;
            }
        }

        entries = (struct dirent **)malloc(count * sizeof(struct dirent *));
        rewinddir(dir_ptr);


        int k = 0;
        while ((direntp=readdir(dir_ptr))!= NULL){
            entries[k++] = direntp;
        }

        //I have NO idea why this needs to be here for the A flag to work but it does and its stupid.
        printf(" ");
        closedir(dir_ptr);
        qsort(entries, count, sizeof(struct dirent *), compare);

        if ((aFlag == 1) & (lFlag == 1)){
            char *temp;
            for (int j = 0; j<count; j++) {
                temp = concad(tempDirname, entries[j]->d_name);
                printf("%s %s\n",getStats(temp) , entries[j]->d_name);
                free(temp);
            }
        }
        else if (aFlag == 1){
            for (int j = 0; j<count; j++) {
                fprintf(stdout, "%-10s ",(entries[j])->d_name);
            }
        }
        else if (lFlag == 1){
            char *temp;
            for (int j = 0; j<count; j++) {
                if ((entries[j]->d_name[0] != '.')) {
                    temp = concad(tempDirname, entries[j]->d_name);
                    printf("%s %s\n",getStats(temp) , entries[j]->d_name);
                    free(temp);
                }
            }
        }
        else {
            printBS(entries, count);
        }
    }
}

int main(int argc, char *argv[]){
    int aFlag=0;
    int lFlag=0;
    int opt=0;
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
