
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *createNode(int value){
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main(){
    int x = 0;
    struct node *head = NULL;
    struct node *temp= NULL;
    printf("Please start entering numbers\n");
    while (scanf("%d", &x)>0 && x>0){
        if (temp == NULL) {
            head = temp = createNode(x);
        }
        else {
            temp->next = createNode(x);
            temp->next->prev = temp;
            temp = temp->next;
        }
    }
    printf("Before sort\n");
    printList(head);
    printf("\n");
    head = bubbleSort(head);
    printf("After sort\n");
    printList(head);
    printListReverse(head);
}
