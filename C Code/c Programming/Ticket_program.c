#include <stdio.h>
#include <stdbool.h>


int main(){

    float price = 10.00;
    bool isStudent = true;
    bool isSenior = false;


    if(isStudent){
        printf("You get a 10% student discount! \n");
        price*= 0.9;  
    }
    if(isSenior){
        printf("You get a 15% senior citizen discount! \n");
        price*= 0.85;  
    }
    
    printf("The price of a ticket is : $%.2f\n", price);


    



    return 0;
}