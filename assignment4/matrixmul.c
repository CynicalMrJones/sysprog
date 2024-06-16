
#include <stdlib.h>
#include <stdio.h>


int main(){

    //Getting input from the user
    int n,k,m,v;
    printf("Please input the size of Matrix A (seperated by spaces): ");
    scanf("%d %d",&n, &k);

    //Dynamically allocating Matrix A
    int** matrix = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++){
        matrix[i] = (int*)calloc(k, sizeof(int));
    }

    //Ok so this works for loading in the Matrix. somehow
    printf("Please input numbers: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n");

    //input for second matrix
    printf("Please input the size of Matrix B (seperated by spaces): ");
    scanf("%d %d",&v, &m);
    //Small bit of logic to verify matrix sizes are compatible
    if (v != k) {
        printf("Invalid matrix size for multiplication");
        free(matrix);
        return(1);
    }

    //Dynamically allocating Matrix B
    int** matrix2 = (int**)calloc(k, sizeof(int*));
    for (int i = 0; i < k; i++){
        matrix2[i] = (int*)calloc(m, sizeof(int));
    }

    printf("Please input numbers: \n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }


    //Dynamically allocating Matrix C
    int** matrix3 = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++){
        matrix3[i] = (int*)calloc(m, sizeof(int));
    }

    //This is what does the multiplication of the Matrix
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            for (int x = 0; x<k; x++) {
                matrix3[i][j] += (matrix[i][x] * matrix2[x][j]);
            }
        }
    }

    //Printing out the resulting Matrix
    printf("\n");
    printf("Here is the resulting matrix");
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    //Freeing memory 
    free(matrix);
    free(matrix2);
    free(matrix3);

}
