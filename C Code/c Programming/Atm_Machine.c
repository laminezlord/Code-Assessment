#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "users.txt"

typedef struct {
    char username[50];
    char password[50];
    int acc;
    int balance;
} User;

/* VALID INTEGER INPUT */
int getInt() {
    char buf[100];
    char *end;
    long val;
    while (1) {
        fgets(buf, 100, stdin);
        if (buf[0] == '\n') { printf("Empty. Try again: "); continue; }
        val = strtol(buf, &end, 10);
        if (*end != '\n' || val <= 0) { printf("Invalid. Try again: "); continue; }
        return (int)val;
    }
}

/* GET NEXT ACCOUNT NUMBER */
int nextAccountNumber() {
    FILE *fp = fopen(FILE_NAME, "r");
    int max = 1000;
    User u;
    if (fp) {
        while (fscanf(fp, "%s %s %d %d", u.username, u.password, &u.acc, &u.balance) != EOF)
            if (u.acc > max) max = u.acc;
        fclose(fp);
    }
    return max + 1;
}

/* SIGN UP */
void signUp() {
    FILE *fp = fopen(FILE_NAME, "a");
    User u;
    printf("Username: ");
    scanf("%s", u.username);
    printf("Password: ");
    scanf("%s", u.password);

    u.acc = nextAccountNumber();
    u.balance = 1000;

    fprintf(fp, "%s %s %d %d\n", u.username, u.password, u.acc, u.balance);
    fclose(fp);

    printf("Account created! Account Number: %d\n", u.acc);
}

/* LOGIN */
int login(User *logged) {
    FILE *fp = fopen(FILE_NAME, "r");
    char u[50], p[50];
    User temp;

    printf("Username: ");
    scanf("%s", u);
    printf("Password: ");
    scanf("%s", p);

    while (fp && fscanf(fp, "%s %s %d %d", temp.username, temp.password, &temp.acc, &temp.balance) != EOF) {
        if (!strcmp(u, temp.username) && !strcmp(p, temp.password)) {
            *logged = temp;
            fclose(fp);
            return 1;
        }
    }
    if (fp) fclose(fp);
    return 0;
}

/* UPDATE USER FILE */
void updateUser(User updated) {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    User u;

    while (fscanf(fp, "%s %s %d %d", u.username, u.password, &u.acc, &u.balance) != EOF) {
        if (u.acc == updated.acc)
            fprintf(temp, "%s %s %d %d\n", updated.username, updated.password, updated.acc, updated.balance);
        else
            fprintf(temp, "%s %s %d %d\n", u.username, u.password, u.acc, u.balance);
    }
    fclose(fp); fclose(temp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
}

/* TRANSFER */
void transfer(User *sender) {
    int target, amt, found = 0;
    User u;
    printf("Target account: ");
    target = getInt();
    printf("Amount: ");
    amt = getInt();

    if (amt > sender->balance) {
        printf("Insufficient balance.\n");
        return;
    }

    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(fp, "%s %s %d %d", u.username, u.password, &u.acc, &u.balance) != EOF) {
        if (u.acc == target) {
            u.balance += amt;
            found = 1;
        }
        if (u.acc == sender->acc)
            u.balance -= amt;

        fprintf(temp, "%s %s %d %d\n", u.username, u.password, u.acc, u.balance);
    }

    fclose(fp); fclose(temp);

    if (!found) {
        remove("temp.txt");
        printf("Account not found.\n");
        return;
    }

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    sender->balance -= amt;
    printf("Transfer successful.\n");
}

/* MAIN */
int main() {
    User current;
    int choice;

    printf("1. Sign Up\n2. Login\nChoice: ");
    choice = getInt();

    if (choice == 1) signUp();

    while (!login(&current))
        printf("Login failed. Try again.\n");

    while (1) {
        printf("\n1.Balance\n2.Withdraw\n3.Deposit\n4.Transfer\n5.Exit\nChoice: ");
        choice = getInt();

        if (choice == 1)
            printf("Balance: %d\n", current.balance);

        else if (choice == 2) {
            printf("Amount: ");
            int a = getInt();
            if (a > current.balance) printf("Insufficient.\n");
            else { current.balance -= a; updateUser(current); }
        }
        else if (choice == 3) {
            printf("Amount: ");
            int a = getInt();
            current.balance += a;
            updateUser(current);
        }
        else if (choice == 4)
            transfer(&current);

        else if (choice == 5) {
            printf("Thank you for using the ATM.\n");
            break;
        }
    }
    return 0;
}

// Algorithm: Multi-User ATM System

// Start

// Display Main Menu

// Show options:

// Sign Up

// Login

// Read and validate choice (must be integer 1 or 2).

// If Sign Up selected

// Prompt user to enter username.

// Prompt user to enter password.

// Open users.txt in read mode.

// Scan all existing users to find the highest account number.

// Generate a new account number = highest account number + 1.

// Set initial balance = 1000.

// Open users.txt in append mode.

// Save: username, password, account number, balance.

// Display account number and success message.

// Login Phase

// Prompt for username and password.

// Open users.txt in read mode.

// Compare input with each stored user record.

// If match found, store user details in memory and proceed.

// If no match, display error and repeat login.

// Do not allow access without correct login.

// ATM Menu (Loop until Exit)

// Display:

// Check Balance

// Withdraw

// Deposit

// Transfer

// Exit

// Read and validate menu option.

// Option 1: Check Balance

// Display current user’s balance.

// Option 2: Withdraw

// Ask for withdrawal amount.

// Validate amount (positive integer).

// If amount > balance, display error.

// Else subtract amount from balance.

// Update user record in file.

// Option 3: Deposit

// Ask for deposit amount.

// Validate amount.

// Add amount to balance.

// Update user record in file.

// Option 4: Transfer

// Ask for target account number.

// Ask for transfer amount.

// Validate amount and ensure sufficient balance.

// Open users.txt and copy data to a temporary file.

// Deduct amount from sender’s balance.

// Add amount to receiver’s balance.

// If target account not found, cancel transfer.

// Replace original file with updated file.

// Option 5: Exit

// Display “Thank you for using the ATM.”

// Terminate program.

// End