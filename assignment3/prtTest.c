
#include <stdlib.h>
#include <stdio.h>

void sort(char *a, int size);
void swap(char *x, char *y);

int main(){
    int* ptr;
    int n;

    printf("enter a number: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));


    for (int i = 0; i < n; i++) {
        printf("%p ", ptr);
    }

    free(ptr);

}
