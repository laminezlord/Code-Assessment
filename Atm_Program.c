#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USERNAME_LEN 50
#define PASSWORD_LEN 50
#define FILENAME "users.txt"

typedef  struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    int account_number;
    int balance;
} User;

// read a line and strip newline
static void read_line(char *buf, int size) {
    if (!fgets(buf, size, stdin)) { buf[0] = '\0'; return; }
    size_t len = strlen(buf);
    if (len && buf[len-1] == '\n') buf[len-1] = '\0';
}

// find next account number (simple incremental)
static int next_account_number(void) {
    FILE *f = fopen(FILENAME, "r");
    if (!f) return 1000000001;
    int acc, bal; char u[USERNAME_LEN], p[PASSWORD_LEN];
    int max = 1000000000;
    while (fscanf(f, "%s %s %d %d", u, p, &acc, &bal) == 4) if (acc > max) max = acc;
    fclose(f);
    return max + 1;
}

void signup(void) {
    User new_user;
    printf("\n-- Create account --\n");
    printf("Username: "); read_line(new_user.username, USERNAME_LEN);
    printf("Password: "); read_line(new_user.password, PASSWORD_LEN);
    new_user.account_number = next_account_number();
    new_user.balance = 1000;

    FILE *f = fopen(FILENAME, "a");
    if (!f) { printf("Unable to save account.\n"); return; }
    fprintf(f, "%s %s %d %d\n", new_user.username, new_user.password, new_user.account_number, new_user.balance);
    fclose(f);
    printf("Account created. Your account #: %d\n", new_user.account_number);
}

int login(User *current_user) {
    char username[USERNAME_LEN], password[PASSWORD_LEN];
    printf("\n-- Login --\nUsername: "); read_line(username, USERNAME_LEN);
    printf("Password: "); read_line(password, PASSWORD_LEN);
    FILE *f = fopen(FILENAME, "r");
    if (!f) { printf("No accounts yet.\n"); return 0; }
    User temp;
    while (fscanf(f, "%s %s %d %d", temp.username, temp.password, &temp.account_number, &temp.balance) == 4) {
        if (strcmp(temp.username, username) == 0 && strcmp(temp.password, password) == 0) { *current_user = temp; fclose(f); printf("Welcome %s!\n", current_user->username); return 1; }
    }
    fclose(f);
    printf("Login failed.\n");
    return 0;
}

static void rewrite_user_in_file(User *current_user) {
    FILE *f = fopen(FILENAME, "r");
    FILE *t = fopen("temp.txt", "w");
    if (!f || !t) { if (f) fclose(f); if (t) fclose(t); printf("File error.\n"); return; }
    User temp;
    while (fscanf(f, "%s %s %d %d", temp.username, temp.password, &temp.account_number, &temp.balance) == 4) {
        if (temp.account_number == current_user->account_number) fprintf(t, "%s %s %d %d\n", current_user->username, current_user->password, current_user->account_number, current_user->balance);
        else fprintf(t, "%s %s %d %d\n", temp.username, temp.password, temp.account_number, temp.balance);
    }
    fclose(f); fclose(t); remove(FILENAME); rename("temp.txt", FILENAME);
}

void show_balance(User *current_user) { printf("\nAccount: %d\nBalance: %d\n", current_user->account_number, current_user->balance); }

void withdraw(User *current_user) {
    char b[32]; printf("Amount to withdraw: "); read_line(b, sizeof(b)); int amount = atoi(b);
    if (amount <= 0) { printf("Invalid amount.\n"); return; }
    if (amount > current_user->balance) { printf("Insufficient funds.\n"); return; }
    current_user->balance -= amount; rewrite_user_in_file(current_user); printf("Withdrawn %d. New balance: %d\n", amount, current_user->balance);
}

void deposit(User *current_user) {
    char b[32]; printf("Amount to deposit: "); read_line(b, sizeof(b)); int amount = atoi(b);
    if (amount <= 0) { printf("Invalid amount.\n"); return; }
    current_user->balance += amount; rewrite_user_in_file(current_user); printf("Deposited %d. New balance: %d\n", amount, current_user->balance);
}

void transfer(User *current_user) {
    char b[32]; printf("Target account #: "); read_line(b, sizeof(b)); int target = atoi(b);
    if (target <= 0) { printf("Invalid account.\n"); return; }
    printf("Amount to send: "); read_line(b, sizeof(b)); int amount = atoi(b);
    if (amount <= 0 || amount > current_user->balance) { printf("Invalid amount.\n"); return; }
    FILE *f = fopen(FILENAME, "r"); if (!f) { printf("No users file.\n"); return; }
    FILE *t = fopen("temp.txt", "w"); if (!t) { fclose(f); printf("File error.\n"); return; }
    User temp; int found = 0;
    while (fscanf(f, "%s %s %d %d", temp.username, temp.password, &temp.account_number, &temp.balance) == 4) {
        if (temp.account_number == current_user->account_number) { current_user->balance -= amount; fprintf(t, "%s %s %d %d\n", current_user->username, current_user->password, current_user->account_number, current_user->balance); }
        else if (temp.account_number == target) { temp.balance += amount; fprintf(t, "%s %s %d %d\n", temp.username, temp.password, temp.account_number, temp.balance); found = 1; }
        else fprintf(t, "%s %s %d %d\n", temp.username, temp.password, temp.account_number, temp.balance);
    }
    fclose(f); fclose(t);
    if (!found) { remove("temp.txt"); printf("Target not found.\n"); return; }
    remove(FILENAME); rename("temp.txt", FILENAME); printf("Sent %d. New balance: %d\n", amount, current_user->balance);
}

void menu(User *current_user) {
    while (1) {
        printf("\n1) Balance  2) Withdraw  3) Deposit  4) Transfer  5) Logout\n");
        printf("Choice: "); char c[8]; read_line(c, sizeof(c)); int ch = atoi(c);
        if (ch == 1) show_balance(current_user);
        else if (ch == 2) withdraw(current_user);
        else if (ch == 3) deposit(current_user);
        else if (ch == 4) transfer(current_user);
        else if (ch == 5) break;
        else printf("Enter 1-5.\n");
    }
}

int main(void) {
    while (1) {
        printf("\nSimple ATM\n1) Sign Up\n2) Login\n3) Exit\n"); printf("Enter: "); char b[8]; read_line(b, sizeof(b)); int cmd = atoi(b);
        if (cmd == 1) signup();
        else if (cmd == 2) { User current; if (login(&current)) menu(&current); }
        else if (cmd == 3) break;
        else printf("Choose 1-3.\n");
    }
    printf("Goodbye\n"); return 0;
}
