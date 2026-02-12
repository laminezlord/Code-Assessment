#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 100
#define USERNAME_LEN 50
#define PASSWORD_LEN 50
#define FILENAME "users.txt"
typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    int account_number;
    int balance;
} User;
void sign_up();
int login(User *current_user);
void atm_menu(User *current_user);
void check_balance(User *current_user);
void withdraw(User *current_user);
void deposit(User *current_user);
void transfer(User *current_user);
int main() {
    int choice;
    User current_user;
    while (1) {
        printf("Welcome to the ATM System\n");
        printf("1. Sign Up\n");
        printf("2. Login\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            sign_up();
        } else if (choice == 2) {
            if (login(&current_user)) {
                atm_menu(&current_user);
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
void sign_up() {
    FILE *file = fopen(FILENAME, "a+");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    User new_user;
    printf("Enter username: ");
    scanf("%s", new_user.username);
    printf("Enter password: ");
    scanf("%s", new_user.password);
    int max_account_number = 0;
    User temp_user;
    while (fscanf(file, "%s %s %d %d", temp_user.username, temp_user.password, &temp_user.account_number, &temp_user.balance) != EOF) {
        if (temp_user.account_number > max_account_number) {
            max_account_number = temp_user.account_number;
        }
    }
    new_user.account_number = max_account_number + 1;
    new_user.balance = 1000;
    fprintf(file, "%s %s %d %d\n", new_user.username, new_user.password, new_user.account_number, new_user.balance);
    fclose(file);
    printf("Account created successfully! Your account number is %d\n", new_user.account_number);
}
int login(User *current_user) {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error opening file.\n");
        return 0;
    }
    User temp_user;
    while (fscanf(file, "%s %s %d %d", temp_user.username, temp_user.password, &temp_user.account_number, &temp_user.balance) != EOF) {
        if (strcmp(temp_user.username, username) == 0 && strcmp(temp_user.password, password) == 0) {
            *current_user = temp_user;
            fclose(file);
            printf("Login successful!\n");
            return 1;
        }
    }
    fclose(file);
    printf("Invalid username or password.\n");
    return 0;
}
void atm_menu(User *current_user) {
    int choice;
    while (1) {
        printf("\nATM Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Transfer\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                check_balance(current_user);
                break;
            case 2:
                withdraw(current_user);
                break;
            case 3:
                deposit(current_user);
                break;
            case 4:
                transfer(current_user);
                break;
            case 5:
                printf("Thank you for using the ATM.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
void check_balance(User *current_user) {
    printf("Your current balance is: %d\n", current_user->balance);
}
void withdraw(User *current_user) {
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }
    if (amount > current_user->balance) {
        printf("Insufficient balance.\n");
        return;
    }
    current_user->balance -= amount;
    FILE *file = fopen(FILENAME, "r+");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    User temp_user;
    long pos;
    while (fscanf(file, "%s %s %d %d", temp_user.username, temp_user.password, &temp_user.account_number, &temp_user.balance) != EOF) {
        if (temp_user.account_number == current_user->account_number) {
            pos = ftell(file) - sizeof(temp_user);
            fseek(file, pos, SEEK_SET);
            fprintf(file, "%s %s %d %d\n", current_user->username, current_user->password, current_user->account_number, current_user->balance);
            break;
        }
    }
    fclose(file);
    printf("Withdrawal successful. New balance: %d\n", current_user->balance);
}
void deposit(User *current_user) {
    int amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }
    current_user->balance += amount;
    FILE *file = fopen(FILENAME, "r+");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    User temp_user;
    long pos;
    while (fscanf(file, "%s %s %d %d", temp_user.username, temp_user.password, &temp_user.account_number, &temp_user.balance) != EOF) {
        if (temp_user.account_number == current_user->account_number) {
            pos = ftell(file) - sizeof(temp_user);
            fseek(file, pos, SEEK_SET);
            fprintf(file, "%s %s %d %d\n", current_user->username, current_user->password, current_user->account_number, current_user->balance);
            break;
        }
    }
    fclose(file);
    printf("Deposit successful. New balance: %d\n", current_user->balance);
}
void transfer(User *current_user) {
    int target_account, amount;
    printf("Enter target account number: ");
    scanf("%d", &target_account);
    printf("Enter amount to transfer: ");
    scanf("%d", &amount);
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }
    if (amount > current_user->balance) {
        printf("Insufficient balance.\n");
        return;
    }
    FILE *file = fopen(FILENAME, "r+");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    User temp_user;
    long pos_sender, pos_receiver;
    int found_receiver = 0;
    while (fscanf(file, "%s %s %d %d", temp_user.username, temp_user.password, &temp_user.account_number, &temp_user.balance) != EOF) {
        if (temp_user.account_number == current_user->account_number) {
            pos_sender = ftell(file) - sizeof(temp_user);
        }
        if (temp_user.account_number == target_account) {
            pos_receiver = ftell(file) - sizeof(temp_user);
            found_receiver = 1;
        }
    }
    if (!found_receiver) {
        printf("Target account not found.\n");
        fclose(file);
        return;
    }
    current_user->balance -= amount;
    fseek(file, pos_sender, SEEK_SET);
    fprintf(file, "%s %s %d %d\n", current_user->username, current_user->password, current_user->account_number, current_user->balance);
    fseek(file, pos_receiver, SEEK_SET);
    fscanf(file, "%s %s %d %d", temp_user.username, temp_user.password, &temp_user.account_number, &temp_user.balance);
    temp_user.balance += amount;
    fseek(file, pos_receiver, SEEK_SET);
    fprintf(file, "%s %s %d %d\n", temp_user.username, temp_user.password, temp_user.account_number, temp_user.balance);
    fclose(file);
    printf("Transfer successful. New balance: %d\n", current_user->balance);
}
