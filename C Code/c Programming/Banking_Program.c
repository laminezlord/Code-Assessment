#include <stdio.h>

void CheckBalance(float balance);
float Deposit();
float Withdraw(float balance);

int main(){
    //Banking Program

    int choice = 0;
    float balance = 0.0f;

    printf("*** Welcome to Credly Bank ***\n");

    do{
        printf("\nSelect an option:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            CheckBalance(balance);
            break;
        case 2:
            balance += Deposit();
            break;
        case 3:
            balance -= Withdraw(balance);
            break;
        case 4:
            printf("Transfer feature coming soon!\n");
            break;
        case 5:
            printf("Thank you for using Credly Bank. Goodbye!\n");    
            break;
        default:
            printf("Invalid choice. Please select (1-5).\n");
        }
    }while(choice != 5);
    return 0;
}

void CheckBalance(float balance){
    printf("Your current balance is: $%.2f\n", balance);

}
float Deposit(){
    float amount = 0.0f;
    printf("Enter amount to deposit: $");
    scanf("%f", &amount);

    if(amount <= 0){
        printf("Invalid amount. Deposit must be greater than $0.\n");
        return 0.0f;
    }else{
        printf("Successfully deposited $%.2f\n", amount);
    return amount;
    }

}
float Withdraw(float balance){
    float amount = 0.0f;

    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);

    if(amount <= 0){
        printf("Invalid amount. Withdrawal must be greater than $0.\n");
        return 0.0f;
    }else if(amount > balance){
        printf("Insufficient funds. Your balance is $%.2f\n", balance);
    return 0.0f;
    }else{
        printf("Successfully withdrew $%.2f\n", amount);
        return amount;
    }

}