
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char firstName[25];
    char lastName[25];
    int age;
    struct node *next;
} node_t;

int main(){
    //Gonna try to understand file I/O in c
    FILE* file_ptr = fopen("Homework5_Data.txt", "r"); 
    node_t *nodePtr;
    int count;
    int ch;

    //Get the line count
    while(!feof(file_ptr))
    {
        ch = fgetc(file_ptr);
        if(ch == '\n')
        {
            count++;
        }
    }
    rewind(file_ptr);

    //Set up the number of nodes
    nodePtr = (node_t *) calloc(count,sizeof (node_t)); 
    for (int i = 0; i < count; i++) {
        fscanf(file_ptr, "%s %s %d", (nodePtr+i)->lastName, (nodePtr+i)->firstName, &(nodePtr+i)->age); 
        (nodePtr+i)->next = (nodePtr+i+1);
        printf("%s %s %d\n", (nodePtr+i)->lastName, (nodePtr+i)->firstName, (nodePtr+i)->age);
    }

    rewind(file_ptr);

    fclose(file_ptr);
}

