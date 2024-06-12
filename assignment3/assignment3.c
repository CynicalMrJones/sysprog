
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
    //for (int i = 0; i < n; i++) {
    //    printf("%c, ", *(ptr + i + 1));
    //}
    
    sort(ptr,n);

    free(ptr);

}

void sort(char *a, int size){
    for (int i = 0; i < size; i++) {
        //Leaving off here need to sort by ascii table codes
        printf("%c, ", *(a + i + 1));
    }
}
