
// Jacob Jones
// CIS 340
// Results: 
// 1) Ask the user to input a string
// 2) Prints out the len of the input
// 3) encrypts the string based on what was specified in the assignment
// Authors note: I don't think that the encryption method specified is a 
// transposition cipher. From what I read I think, transposition ciphers involve
// 2d arrays and encrypting based on a key.
// 4) prints out the newly encrypted string
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encrypt(char *string, int sizeOfString);

int main(){
    char input[8192];
    //Asking user for input
    printf("Please input a string: ");
    scanf("%s", input);
    printf("%ld\n", strlen(input));
    printf("%s",encrypt(input, strlen(input)));
}

char* encrypt(char *string, int sizeOfString){
    //The recusive base case
    if (sizeOfString <= 2) {
        return string; 
    }
    int k = sizeOfString/2;
    //array assignment
    char *firstPartOfArray = (char*)calloc(k+1,sizeof(char));
    char *secondPartOfArray = (char*)calloc(sizeOfString - (k+1),sizeof(char));

    //filling the first half of the array backwards
    for (int i = k-1; i >= 0; i--) {
        firstPartOfArray[k-1-i] = string[i];
    }
    //remembering the null char to strcat function
    firstPartOfArray[k] = '\0';

    //filling the second half of the array backwards
    for (int i = sizeOfString-1; i >=k; i--) {
        secondPartOfArray[sizeOfString-1-i] = string[i];
    }
    //remembering the null char to strcat function
    secondPartOfArray[sizeOfString-k] = '\0';

    //the recursive part
    char* recursive1 = encrypt(firstPartOfArray, k);
    char* recursive2 = encrypt(secondPartOfArray,sizeOfString-k);

    //I hate recursion
    string = strcat(recursive1,recursive2); 
    return string;
}
