
#include <stdlib.h>
#include <stdio.h>

void sort(char *a, int size);
void swap(char *x, char *y);

int main(){
    char* ptr;
    int n, i;

    printf("How many chars is the string: ");
    scanf("%d", &n);
    ptr = (char*)malloc(n * sizeof(char));

    printf("Please give the string: ");
    scanf("%c", ptr);

    for (int i = 0; i < n; i++) {
        printf("%c ", ptr[i]);
    }

}
