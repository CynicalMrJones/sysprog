
#include <stdio.h>
#include <stdbool.h>

struct node{
    int value;
    struct node *next;
    struct node *prev;
};


struct node* bubbleSort(struct node* list){

    struct node *listcopy = list;
    struct node *temp = list;
    int size;
    int x;

    //Get the size of the linked list
    if (temp != NULL){
        while (temp != NULL){
            size++;
            temp = temp->next;
        }
    }

    for (int i = size - 1; i >= 0; i--){
        temp = listcopy;
        for (int j = 0; j <= i - 1; j++){
            if (temp->value > temp->next->value){
                x = temp->value;
                temp->value = temp->next->value;
                temp->next->value = x;
            }
            temp = temp->next;
        }
    }
    return listcopy;
}

void printList(struct node *list){
    struct node *temp = list;
    if (temp != NULL){
        while (temp != NULL){
            if (temp->next!= NULL){
                printf("%d ", temp->value);
            }
            else {
                printf("%d", temp->value);
            }
            temp = temp->next;
        }
    }
}
void printListReverse(struct node* head)
{
    struct node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    // Move to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Traverse backwards
    printf("Reverse List: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}
