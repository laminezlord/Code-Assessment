#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "users.txt"

typedef struct {
    char username[50];
    char password[50];
    long acc;
    int balance;
} User;

/* VALID POSITIVE INTEGER */
int getInt() {
    char buf[100], *end;
    long v;
    while (1) {
        fgets(buf, 100, stdin);
        if (buf[0] == '\n') { printf("Empty. Try again: "); continue; }
        v = strtol(buf, &end, 10);
        if (*end != '\n' || v <= 0) { printf("Invalid. Try again: "); continue; }
        return (int)v;
    }
}

/* GENERATE UNIQUE 10-DIGIT ACCOUNT NUMBER */
long nextAccount() {
    FILE *fp = fopen(FILE_NAME, "r");
    User u;
    long max = 1000000000;   /* 10 digits start */

    if (fp) {
        while (fscanf(fp, "%s %s %ld %d", u.username, u.password, &u.acc, &u.balance) != EOF)
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

    u.acc = nextAccount();
    u.balance = 1000;

    fprintf(fp, "%s %s %ld %d\n", u.username, u.password, u.acc, u.balance);
    fclose(fp);

    printf("Account created successfully!\nAccount Number: %ld\n", u.acc);
}

/* LOGIN */
int login(User *current) {
    FILE *fp = fopen(FILE_NAME, "r");
    User u;
    char name[50], pass[50];

    printf("Username: ");
    scanf("%s", name);
    printf("Password: ");
    scanf("%s", pass);

    while (fp && fscanf(fp, "%s %s %ld %d", u.username, u.password, &u.acc, &u.balance) != EOF) {
        if (!strcmp(name, u.username) && !strcmp(pass, u.password)) {
            *current = u;
            fclose(fp);
            return 1;
        }
    }
    if (fp) fclose(fp);
    return 0;
}

/* UPDATE USER */
void updateUser(User updated) {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *tmp = fopen("temp.txt", "w");
    User u;

    while (fscanf(fp, "%s %s %ld %d", u.username, u.password, &u.acc, &u.balance) != EOF) {
        if (u.acc == updated.acc)
            fprintf(tmp, "%s %s %ld %d\n", updated.username, updated.password, updated.acc, updated.balance);
        else
            fprintf(tmp, "%s %s %ld %d\n", u.username, u.password, u.acc, u.balance);
    }

    fclose(fp); fclose(tmp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
}

/* TRANSFER */
void transfer(User *sender) {
    long target;
    int amt, found = 0;
    User u;

    printf("Target account number: ");
    scanf("%ld", &target);
    printf("Amount: ");
    amt = getInt();

    if (amt > sender->balance) {
        printf("Insufficient balance.\n");
        return;
    }

    FILE *fp = fopen(FILE_NAME, "r");
    FILE *tmp = fopen("temp.txt", "w");

    while (fscanf(fp, "%s %s %ld %d", u.username, u.password, &u.acc, &u.balance) != EOF) {
        if (u.acc == target) {
            u.balance += amt;
            found = 1;
        }
        if (u.acc == sender->acc)
            u.balance -= amt;

        fprintf(tmp, "%s %s %ld %d\n", u.username, u.password, u.acc, u.balance);
    }

    fclose(fp); fclose(tmp);

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
        printf("\n1.Check Balance\n2.Withdraw\n3.Deposit\n4.Transfer\n5.Exit\nChoice: ");
        choice = getInt();

        if (choice == 1)
            printf("Balance: %d\n", current.balance);

        else if (choice == 2) {
            printf("Amount: ");
            int a = getInt();
            if (a > current.balance) printf("Insufficient balance.\n");
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
