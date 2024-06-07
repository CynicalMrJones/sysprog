#include <stdio.h>

//Jacob Jones
//2081078 Systems programming
//This program asks the user for an initial payment and intrest rate and provides the payments
//for the first 6 months

int main(){
    //Might not be the most effecient but it was created in about 20 mins

    //Grab the user input for initial payment 
    printf("What is your initial payment: ");
    float initial_payment;
    scanf("%f",&initial_payment);

    //Grab user input for intrest rate
    printf("What is the intrest rate 'percent format': ");
    float intrest;
    scanf("%f", &intrest);

    float new_total;
    float answer;
    //Create final monthly intrest rate for future calculations
    const float final_intrest = (intrest/100) / 12;
    //loop to give the payments for the first 6 months
    for (int i = 0; i < 6; i++) {
        answer = (initial_payment + new_total) * (1 + final_intrest);
        new_total = answer;
        printf("You account growth for month %d is %.3f\n",(i+1), new_total);
    }
}
