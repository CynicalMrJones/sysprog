
#include <stdlib.h>
#include <stdio.h>
//Given an n x k matrix A and an k x m matrix B, with 1 ≤ n, m,k ≤ 300, write a C program
//that computes the matrix product C=AB. All entries in matrices A and B are integers
//with absolute value less than 1000, so you don't need to worry about overflow. If
//matrices A and B do not have the right dimensions to be multiplied, the product
//matrix C should have its number of rows and columns both set to zero.
int main(){
    //First things first i need to get input the way written in the assignment
    int n,k;
    printf("Please input the size of matrix A (seperated by spaces): ");
    scanf("%d %d",&n, &k);
    //Now i need to create a matrix...trying to decide if i should use pointers or an array
    int **ptr;
    ptr = (int **)calloc(n,sizeof(int *));
    ptr[0] = (int *)calloc(k,sizeof(int));
    ptr[1] = (int *)calloc(n,sizeof(int));

    //now i need to prompt the user to input n+1 entries
    //Ok so this works for loading in the matrix. somehow
    printf("Please input numbers: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &ptr[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }

    free(ptr);

}
