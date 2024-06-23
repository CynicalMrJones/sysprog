
// Jacob Jones
// CIS 340
// Results: 
// The program takes input from a file and sorts it into a singly linked list.
// It then prints it out before and after being sorted.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node struct
typedef struct node {
    char firstName[25];
    char lastName[25];
    int age;
    struct node *next;
} node_t;

void printEverything(node_t *head);
node_t* swap(node_t* ptr1, node_t* ptr2);
void bubbleSort(node_t** head, int count);

int main(){
    //Create a file pointer from the given txt
    FILE* file_ptr = fopen("Homework5_Data.txt", "r"); 
    node_t* nodePtr;
    int count;
    int ch;

    //Get the line count
    while(!feof(file_ptr)){
        ch = fgetc(file_ptr);
        if(ch == '\n'){
            count++;
        }
    }
    //Remember to rewind the pointer to the top of the file
    rewind(file_ptr);

    //Set up the number of nodes needed
    nodePtr = (node_t *)malloc(count*sizeof (node_t)); 
    printf("Before Sort...\n");
    for (int i = 0; i < count; i++) {
        fscanf(file_ptr, "%s %s %d", (nodePtr+i)->lastName, (nodePtr+i)->firstName, &(nodePtr+i)->age); 
        (nodePtr+i)->next = (nodePtr+i+1);
        printf("%s %s %d\n", (nodePtr+i)->lastName, (nodePtr+i)->firstName, (nodePtr+i)->age);
    }
    //Remembering to close the file
    fclose(file_ptr);

    //Sort the singly linked list
    bubbleSort(&nodePtr, count);
    printf("\n");
    printf("After Sort...\n");
    printEverything(nodePtr);
}

//swap used for the bubble sort
node_t* swap(node_t* ptr1, node_t* ptr2){
    node_t* temp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = temp;
    return ptr2;
}

//Modified the bubblesort used in previous assignment
void bubbleSort(node_t** node, int count){
    node_t** head;
    int i, j, swapped;
    for(i = 0; i <= count; i++){
        head = node;
        swapped = 0;
        for(j = 0; j < count-i-1; j++){
            node_t* ptr1 = *head;
            node_t* prt2 = ptr1->next;
            if(strcmp(ptr1->lastName, prt2->lastName)>0){
                *head = swap(ptr1, prt2);
                swapped = 1;
            }
            head = &(*head)->next;
        }
        if (swapped == 0)
            break;
    }
}

//Prints everything out of it
void printEverything(node_t *head){
    node_t* current = head;
    while (current->next != NULL) {
        printf("%s %s %d\n", current->lastName, current->firstName, current->age);
        current = current->next;
    }
}
