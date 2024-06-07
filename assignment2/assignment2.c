
#include <stdio.h>

#define ARRAYSIZE 20

void bubbleSort(char lastName[ARRAYSIZE][50], char firstName[ARRAYSIZE][50], int age[]);

int main(){
    char firstName[ARRAYSIZE][50];
    char lastName[ARRAYSIZE][50];
    int ages[ARRAYSIZE];
    int numberToList;
    printf("How many people would you like to list: ");
    scanf("%d", &numberToList);
    for (int i = 0; i < numberToList; i++) {
        printf("Please enter last name, first name, and age: ");
        scanf("%s %s %d", lastName[i],firstName[i], &ages[i]);
    }
    bubbleSort(lastName, firstName, ages);
}


//Leaving off here need to implement bubble sort on multiple arrays
void bubbleSort(char lastName[ARRAYSIZE][50], char firstName[ARRAYSIZE][50], int age[]){
    printf("%s", lastName[1]);
}


