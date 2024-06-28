
struct node{
    int value;
    struct node *next;
    struct node *prev;
};

struct node* bubbleSort(struct node* list);
void printList(struct node* list);
void printListReverse(struct node* head);
    
