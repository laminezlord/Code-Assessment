#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void signup();
int login(User *current_user);
void menu(User *current_user);
void balance(User *current_user);
void withdraw(User *current_user);
void deposit(User *current_user);
void transfer(User *current_user);

int main() {
    int choice;
    User current_user;
    while (1) {
        printf("\nATM\n1. Sign Up\n2. Login\n3. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input!\n");
            continue;
        }
        if (choice == 1) signup();
        else if (choice == 2) {
            if (login(&current_user)) menu(&current_user);
        }
        else if (choice == 3) break;
        else printf("Invalid choice!\n");
    }
    return 0;
}

void signup() {
    FILE *file = fopen(FILENAME, "a+");
    User new_user;
    printf("Username: ");
    scanf("%s", new_user.username);
    printf("Password: ");
    scanf("%s", new_user.password);
    srand(time(NULL));
    new_user.account_number = 1000000000 + (rand() % 9000000000);
    new_user.balance = 1000;
    fprintf(file, "%s %s %d %d\n", new_user.username, new_user.password, new_user.account_number, new_user.balance);
    fclose(file);
    printf("Account %d created!\n", new_user.account_number);
}

int login(User *current_user) {
    char username[USERNAME_LEN], password[PASSWORD_LEN];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No accounts exist yet!\n");
        return 0;
    }
    User temp_user;
    while (fscanf(file, "%s %s %d %d", temp_user.username, temp_user.password, &temp_user.account_number, &temp_user.balance) != EOF) {
        if (strcmp(temp_user.username, username) == 0 && strcmp(temp_user.password, password) == 0) {
            *current_user = temp_user;
            fclose(file);
            printf("Login success!\n");
            return 1;
        }
    }
    fclose(file);
    printf("Wrong username/password!\n");
    return 0;
}

void menu(User *current_user) {
    int choice;
    while (1) {
        printf("\n1. Balance  2. Withdraw  3. Deposit  4. Transfer  5. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input!\n");
            continue;
        }
        if (choice == 1) balance(current_user);
        else if (choice == 2) withdraw(current_user);
        else if (choice == 3) deposit(current_user);
        else if (choice == 4) transfer(current_user);
        else if (choice == 5) break;
        else printf("Invalid choice!\n");
    }
}

void balance(User *current_user) {
    printf("\nAccount: %d\nBalance: %d\n", current_user->account_number, current_user->balance);
}

void withdraw(User *current_user) {
    int amount;
    printf("Amount: ");
    scanf("%d", &amount);
    if (amount <= 0 || amount > current_user->balance) {
        printf("Invalid!\n");
        return;
    }
    current_user->balance -= amount;
    FILE *file = fopen(FILENAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    User temp_user;
    while (fscanf(file, "%s %s %d %d", temp_user.username, temp_user.password, &temp_user.account_number, &temp_user.balance) != EOF) {
        if (temp_user.account_number == current_user->account_number) 
            fprintf(temp_file, "%s %s %d %d\n", current_user->username, current_user->password, current_user->account_number, current_user->balance);
        else 
            fprintf(temp_file, "%s %s %d %d\n", temp_user.username, temp_user.password, temp_user.account_number, temp_user.balance);
    }
    fclose(file);
    fclose(temp_file);
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    printf("Withdrawn! Balance: $%d\n", current_user->balance);
}

void deposit(User *current_user) {
    int amount;
    printf("Amount: ");
    scanf("%d", &amount);
    if (amount <= 0) {
        printf("Invalid!\n");
        return;
    }
    current_user->balance += amount;
    FILE *file = fopen(FILENAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    User temp_user;
    while (fscanf(file, "%s %s %d %d", temp_user.username, temp_user.password, &temp_user.account_number, &temp_user.balance) != EOF) {
        if (temp_user.account_number == current_user->account_number) 
            fprintf(temp_file, "%s %s %d %d\n", current_user->username, current_user->password, current_user->account_number, current_user->balance);
        else 
            fprintf(temp_file, "%s %s %d %d\n", temp_user.username, temp_user.password, temp_user.account_number, temp_user.balance);
    }
    fclose(file);
    fclose(temp_file);
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    printf("Deposited! Balance: $%d\n", current_user->balance);
}

void transfer(User *current_user) {
    int target_account, amount;
    printf("Target acc: ");
    scanf("%d", &target_account);
    printf("Amount: ");
    scanf("%d", &amount);
    if (amount <= 0 || amount > current_user->balance) {
        printf("Invalid!\n");
        return;
    }
    FILE *file = fopen(FILENAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    User temp_user;
    int found_target = 0;
    while (fscanf(file, "%s %s %d %d", temp_user.username, temp_user.password, &temp_user.account_number, &temp_user.balance) != EOF) {
        if (temp_user.account_number == current_user->account_number) {
            current_user->balance -= amount;
            fprintf(temp_file, "%s %s %d %d\n", current_user->username, current_user->password, current_user->account_number, current_user->balance);
        } else if (temp_user.account_number == target_account) {
            temp_user.balance += amount;
            fprintf(temp_file, "%s %s %d %d\n", temp_user.username, temp_user.password, temp_user.account_number, temp_user.balance);
            found_target = 1;
        } else {
            fprintf(temp_file, "%s %s %d %d\n", temp_user.username, temp_user.password, temp_user.account_number, temp_user.balance);
        }
    }
    fclose(file);
    fclose(temp_file);
    if (!found_target) {
        printf("Account not found!\n");
        remove("temp.txt");
        return;
    }
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    printf("Transferred! Balance: $%d\n", current_user->balance);
}
