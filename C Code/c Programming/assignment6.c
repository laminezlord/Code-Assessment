#include <stdio.h>

int main() {
    int i = 1, sum = 0;

    while(i <= 50) {
        if(i % 2 == 0)
            sum += i;
        i++;
    }

    printf("Sum of even numbers = %d", sum);
    return 0;
}

    #include <stdio.h>

int main() {
    int num, count = 1, largest;
    
    printf("Enter number 1: ");
    while(scanf("%d", &largest) != 1) {
        printf("Invalid! Enter an integer: ");
        while(getchar() != '\n'); // clear input
    }

    count = 2;

    while(count <= 10) {
        printf("Enter number %d: ", count);

        while(scanf("%d", &num) != 1) {
            printf("Invalid! Enter an integer: ");
            while(getchar() != '\n');
        }

        if(num > largest)
            largest = num;

        count++;
    }

    printf("Largest number = %d", largest);
    return 0;
}

#include <stdio.h>

int main() {
    int pin;
    int choice;
    float balance = 1000, amount;

    // PIN validation loop
    printf("Enter PIN: ");
    while(scanf("%d", &pin) != 1 || pin != 1234) {
        printf("Invalid PIN or non-numeric input. Try again: ");
        while(getchar() != '\n');
    }

    printf("\nLogin Successful!\n");

    while(1) {
        printf("\n--- ATM MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Money\n");
        printf("3. Deposit Money\n");
        printf("4. Exit\n");
        printf("Enter option: ");

        while(scanf("%d", &choice) != 1) {
            printf("Invalid! Enter a number: ");
            while(getchar() != '\n');
        }

        if(choice == 1) {
            printf("Current Balance: $%.2f\n", balance);
        }

        else if(choice == 2) {
            printf("Enter amount to withdraw: ");
            while(scanf("%f", &amount) != 1 || amount <= 0) {
                printf("Invalid amount! Enter again: ");
                while(getchar() != '\n');
            }

            if(amount > balance)
                printf("Insufficient funds!\n");
            else {
                balance -= amount;
                printf("Withdraw Successful. New Balance: $%.2f\n", balance);
            }
        }

        else if(choice == 3) {
            printf("Enter amount to deposit: ");
            while(scanf("%f", &amount) != 1 || amount <= 0) {
                printf("Invalid amount! Enter again: ");
                while(getchar() != '\n');
            }

            balance += amount;
            printf("Deposit Successful. New Balance: $%.2f\n", balance);
        }

        else if(choice == 4) {
            printf("Thank you for using our ATM!\n");
            break;
        }

        else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}

