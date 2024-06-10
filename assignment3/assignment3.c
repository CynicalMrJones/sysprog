
#include <stdlib.h>
#include <stdio.h>

void sort(char *a, int size);
void swap(char *x, char *y);

int main(){
    char* ptr;
    int n;
    char ch = '\0';

    printf("How many chars is the string: ");
    scanf("%d", &n);
    ptr = (char*)calloc(n, sizeof(char));

    printf("Please give the string: ");
    for (int i = 0; i < n+1; i++) {
            scanf("%c", ptr + i);
    }
    //I don't know whats happening here. For some reason its printing a 
    //null or empty char before it prints the rest.
    //I might have to reach out to the professor.
    for (int i = 0; i < n+1; i++) {
        printf("%c, ", *(ptr + i));
    }

    free(ptr);

}
