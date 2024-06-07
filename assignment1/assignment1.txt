
//Jacob Jones
//CIS 340
//Results: This program lets the user input every array element and then prints out 
//every element in it.
//
//It then finds the smallest value and the largest value and prints them out.
//Finally it finds the average and prints that out

#include <stdio.h>
#define ARRAYSIZE 10

void makeArray(int[]);
void printArray(int[]);
int findSmall(int[]);
int findLarge(int[]);
float findAverage(int[]);


int main(){
    int array[ARRAYSIZE];
    makeArray(array);
    printArray(array);
    printf("Smallest element is %d\n", findSmall(array));
    printf("Largest element is %d\n", findLarge(array));
    printf("Average of array is %5.2f\n", findAverage(array));
}

void makeArray(int arr[]){
    printf("Create the arrray\n");
    for (int i = 0; i < ARRAYSIZE; i++) {
        printf("Enter element %d: ", (i+1));
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[]){
    printf("\nPrint the array\n");
    for (int j = 0; j < ARRAYSIZE; j++) {
        printf("Element %d value %d\n",(j+1), arr[j]);
    }
}

int findSmall(int arr[]){
    int smallest = arr[0];
    for (int i = 0; i < ARRAYSIZE; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

int findLarge(int arr[]){
    int largest = arr[0];
    for (int i = 0; i < ARRAYSIZE; i++) {
        if (arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}

float findAverage(int arr[]){
    float total = 0;
    for (int k = 0; k < ARRAYSIZE; k++) {
        total = total + arr[k];
    }
    total = total / ARRAYSIZE;
    return total;
}
