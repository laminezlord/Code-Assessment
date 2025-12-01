// #include <stdio.h>

// int main() {
//     int pin, choice;
//     float balance = 1000, amount;

//     // ---- PIN LOGIN ----
//     printf("Enter PIN: ");
//     while (1) {
//         if (scanf("%d", &pin) == 1 && pin == 1234) {
//             break; // correct PIN
//         }

//         printf("Invalid PIN! Try again: ");

//         // clear input buffer
//         int c;
//         while ((c = getchar()) != '\n' && c != EOF);
//     }

//     // ---- MAIN ATM MENU ----
//     while (1) {
//         printf("\n--- ATM MENU ---\n");
//         printf("1. Check Balance\n");
//         printf("2. Withdraw\n");
//         printf("3. Deposit\n");
//         printf("4. Exit\n");
//         printf("Enter choice: ");

//         while (scanf("%d", &choice) != 1) {
//             printf("Invalid! Enter a number: ");
//             int c;
//             while ((c = getchar()) != '\n' && c != EOF);
//         }

//         if (choice == 1) {
//             printf("Current Balance: $%.2f\n", balance);
//         }

//         else if (choice == 2) {
//             printf("Enter amount: ");
//             while (scanf("%f", &amount) != 1 || amount <= 0) {
//                 printf("Invalid! Enter a valid amount: ");
//                 int c;
//                 while ((c = getchar()) != '\n' && c != EOF);
//             }
//             if (amount > balance)
//                 printf("Insufficient funds!\n");
//             else {
//                 balance -= amount;
//                 printf("Withdraw successful! New balance: $%.2f\n", balance);
//             }
//         }

//         else if (choice == 3) {
//             printf("Enter amount: ");
//             while (scanf("%f", &amount) != 1 || amount <= 0) {
//                 printf("Invalid! Enter a valid amount: ");
//                 int c;
//                 while ((c = getchar()) != '\n' && c != EOF);
//             }
//             balance += amount;
//             printf("Deposit successful! New balance: $%.2f\n", balance);
//         }

//         else if (choice == 4) {
//             printf("Thank you for using the ATM.\n");
//             break;
//         }

//         else {
//             printf("Invalid menu option!\n");
//         }
//     }

//     return 0;
// }

// #include <stdio.h>

// int clearBuffer() {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF);
//     return 0;
// }

// int main() {
//     int pin, choice;
//     float balance = 1000, amount;

//     // ---- PIN LOGIN (infinite retry) ----
//     printf("Enter PIN: ");
//     while (1) {
//         if (scanf("%d", &pin) == 1 && pin == 1234) {
//             break;   // correct PIN
//         }
//         clearBuffer(); 
//         printf("Wrong PIN! Enter PIN again: ");
//     }

//     // ---- MAIN ATM MENU ----
//     while (1) {
//         printf("\n--- ATM MENU ---\n");
//         printf("1. Check Balance\n");
//         printf("2. Withdraw\n");
//         printf("3. Deposit\n");
//         printf("4. Exit\n");
//         printf("Enter choice: ");

//         while (scanf("%d", &choice) != 1) {
//             clearBuffer();
//             printf("Invalid! Enter a number: ");
//         }

//         if (choice == 1) {
//             printf("Current Balance: $%.2f\n", balance);
//         }

//         else if (choice == 2) {
//             printf("Enter amount: ");
//             while (scanf("%f", &amount) != 1 || amount <= 0) {
//                 clearBuffer();
//                 printf("Invalid! Enter a valid amount: ");
//             }

//             if (amount > balance) {
//                 printf("Insufficient funds!\n");
//             } else {
//                 balance -= amount;
//                 printf("Withdraw successful! New balance: $%.2f\n", balance);
//             }
//         }

//         else if (choice == 3) {
//             printf("Enter amount: ");
//             while (scanf("%f", &amount) != 1 || amount <= 0) {
//                 clearBuffer();
//                 printf("Invalid! Enter a valid amount: ");
//             }

//             balance += amount;
//             printf("Deposit successful! New balance: $%.2f\n", balance);
//         }

//         else if (choice == 4) {
//             printf("Thank you for using the ATM.\n");
//             break;
//         }

//         else {
//             printf("Invalid menu option!\n");
//         }
//     }

//     return 0;
// }


// #include <stdio.h>

// // Function to clear invalid input from buffer
// void clearBuffer() {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF);
// }

// int main() {
//     int pin;
//     int choice;
//     float balance = 1000.0, amount;

//     // ---- PIN LOGIN ----
//     printf("Enter PIN: ");
//     while (1) {
//         if (scanf("%d", &pin) == 1 && pin == 1234) {
//             break;  // correct PIN
//         }
//         clearBuffer(); // clear invalid input
//         printf("Wrong PIN! Enter PIN again: ");
//     }

//     // ---- ATM MENU ----
//     while (1) {
//         printf("\n--- ATM MENU ---\n");
//         printf("1. Check Balance\n");
//         printf("2. Withdraw Money\n");
//         printf("3. Deposit Money\n");
//         printf("4. Exit\n");
//         printf("Enter your choice: ");

//         // Validate menu choice input
//         while (scanf("%d", &choice) != 1) {
//             clearBuffer();
//             printf("Invalid input! Enter a number (1-4): ");
//         }

//         if (choice == 1) {
//             printf("Current Balance: $%.2f\n", balance);
//         }
//         else if (choice == 2) {
//             printf("Enter amount to withdraw: ");
//             while (scanf("%f", &amount) != 1 || amount <= 0) {
//                 clearBuffer();
//                 printf("Invalid! Enter a positive number: ");
//             }
//             if (amount > balance) {
//                 printf("Insufficient funds!\n");
//             } else {
//                 balance -= amount;
//                 printf("Withdrawal successful! New Balance: $%.2f\n", balance);
//             }
//         }
//         else if (choice == 3) {
//             printf("Enter amount to deposit: ");
//             while (scanf("%f", &amount) != 1 || amount <= 0) {
//                 clearBuffer();
//                 printf("Invalid! Enter a positive number: ");
//             }
//             balance += amount;
//             printf("Deposit successful! New Balance: $%.2f\n", balance);
//         }
//         else if (choice == 4) {
//             printf("Thank you for using the ATM!\n");
//             break;
//         }
//         else {
//             printf("Invalid option! Please select 1-4.\n");
//         }
//     }

//     return 0;
// }


#include <stdio.h>

// Clear input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int pin;
    int choice;
    float balance = 1000.0, amount;

    // ---- PIN LOGIN ----
    printf("Enter PIN: ");
    while (1) {
        if (scanf("%d", &pin) == 1 && pin == 1234) {
            break;  // correct PIN
        }
        clearBuffer(); // remove invalid input
        printf("Wrong PIN! Enter PIN again: ");
    }

    // ---- ATM MENU ----
    while (1) {
        printf("\n--- ATM MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Money\n");
        printf("3. Deposit Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Keep asking until valid menu choice is entered
        while (scanf("%d", &choice) != 1) {
            clearBuffer(); // remove invalid input
        }

        if (choice == 1) {
            printf("Current Balance: $%.2f\n", balance);
        }
        else if (choice == 2) {
            printf("Enter amount to withdraw: ");
            while (scanf("%f", &amount) != 1 || amount <= 0) {
                clearBuffer();
            }
            if (amount > balance) {
                printf("Insufficient funds!\n");
            } else {
                balance -= amount;
                printf("Withdrawal successful! New Balance: $%.2f\n", balance);
            }
        }
        else if (choice == 3) {
            printf("Enter amount to deposit: ");
            while (scanf("%f", &amount) != 1 || amount <= 0) {
                clearBuffer();
            }
            balance += amount;
            printf("Deposit successful! New Balance: $%.2f\n", balance);
        }
        else if (choice == 4) {
            printf("Thank you for using the ATM!\n");
            break;
        }
        else {
            // If menu choice is invalid (number not 1-4)
            printf("Invalid option! Please select 1-4.\n");
        }
    }

    return 0;
}
