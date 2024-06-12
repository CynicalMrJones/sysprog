
// Jacob Jones
// CIS 340
// Results: 
// 1)The program asks the user for a number of chars to enter,
// 2)The program then allocates just the right amount of memory needed,
// 3)We ask the user to input the string of chars
// 4)We load them into memory and sort them. 
// 5)We print out the sorted chars and only print out the alphabetical letters

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void sort(char *a, int size);
void swap(char *x, char *y);

int main(){
    char* ptr;
    int n;

    //Asks the user for how many chars the input will take
    printf("How many chars are going to be input: ");
    scanf("%d", &n);
    ptr = (char*)calloc(n+1, sizeof(char));

    //Have the user input the string of chars
    printf("Please give the string: ");
    for (int i = 0; i < n+1; i++) {
            scanf("%c", ptr + i);
    }
    
    //sorts the array
    sort(ptr,n);
    //Prints the array
    printf("Here are the sorted letters\n");
    int i = 0;
    while (i<n) {
        //This logic looks dumb but it works well. 
        //It iterated through the array and only prints chars that are in the alphabet
        //and ignores all other ascii codes
        if ((*(ptr + i + 1) < 65) || ((*(ptr + i + 1) <= 96) && ((*(ptr + i + 1)) >= 91)) || *(ptr+i+1) > 122) {
            i++;
        }
        else {
            printf("%c", *(ptr + i + 1));
            i++;
        }
    }
    //frees memory
    free(ptr);
}

//Just used a bubble sort from the last assignment but modified it to fit pointers 
void sort(char *a, int size){
    bool swapped;
    for (int i = 0; i < size; i++) {
        swapped = false;
        for (int j = 0; j < size - i; j++) {
            if (*(a+j) > *(a+j+1)) {
                swap((a+j), (a+j+1));
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}

void swap(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y; 
    *y = temp;
}
