
//Jacob Jones
//CIS 340
//Results: The user inputs an array of first names and last names and their ages
//It then sorts them and retuns them to the user
#include <stdio.h>
#include <string.h>

#define ARRAYSIZE 20

void bubbleSort(char lastName[ARRAYSIZE][50], char firstName[ARRAYSIZE][50], int age[], int numberToList);

int main(){
    char firstName[ARRAYSIZE][50];
    char lastName[ARRAYSIZE][50];
    int ages[ARRAYSIZE];
    int numberToList;
    printf("How many people would you like to list: ");
    scanf("%d", &numberToList);
    for (int i = 0; i < numberToList; i++) {
        printf("Please enter last name, first name, and age(Put spaces inbetween each): ");
        scanf("%s %s %d", lastName[i],firstName[i], &ages[i]);
    }
    bubbleSort(lastName, firstName, ages, numberToList);

    printf("These are the names and ages in order");
    for (int i = 0; i < numberToList; i++) {
        printf("%s %s %d\n", lastName[i], firstName[i], ages[i]);
    }
}


void bubbleSort(char lastName[ARRAYSIZE][50], char firstName[ARRAYSIZE][50], int ages[], int numberToList){
    int i, j, temp2;
    char temp[50];
    for (i = 0; i < numberToList - 1; i++) {
        for (j = 0; j < numberToList - i - 1; j++) {
            if(strcmp(lastName[j], lastName[j+1]) > 0){
                strcpy(temp, lastName[j]);
                strcpy(lastName[j], lastName[j+1]);
                strcpy(lastName[j+1], temp);
                strcpy(temp, firstName[j]);
                strcpy(firstName[j], firstName[j+1]);
                strcpy(firstName[j+1], temp);
                temp2 = ages[j];
                ages[j] = ages[j+1];
                ages[j+1] = temp2;
            }
        }
    }
}
