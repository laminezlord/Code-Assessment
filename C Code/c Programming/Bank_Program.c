#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "user.txt"

typedef struct {
    char username[50];
    char password[50];
    int balance;
    long long account;  // store 10-digit account numbers
} User;

/* ---------- INPUT VALIDATION ---------- */
int readInt(int *x) {
    char buf[50];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;
    buf[strcspn(buf, "\n")] = 0;// REMOVE NEWLINE
    if (strlen(buf) == 0) return 0;
    for (int i = 0; buf[i]; i++)
        if (!isdigit(buf[i])) return 0;
    *x = atoi(buf);// CONVERT TO INTEGER
    return *x >= 0;
}//AVOID ISSUES WITH SCANF

int readPhone(long long *acc) {
    char buf[20];
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = 0;

    if (strlen(buf) > 11) {
        printf("Phone number should not be more than 11 digits.\n");
        return 0;
    }
    if (strlen(buf) != 11) return 0;  // reject less than 11
    if (buf[0] != '0') return 0;

    for (int i = 0; buf[i]; i++)
        if (!isdigit(buf[i])) return 0;

    *acc = atoll(buf + 1); // remove leading zero
    return 1;//atoll ensures it fits long long
}

/* ---------- FILE HANDLING ---------- */
int loadUsers(User u[]) {
    FILE *fp = fopen(FILE_NAME, "r");
    int n = 0;
    if (!fp) return 0;
    while (fscanf(fp, "%s %s %d %lld",//Read user from users.txt
           u[n].username,
           u[n].password,
           &u[n].balance,
           &u[n].account) == 4)
        n++;
    fclose(fp);
    return n;// returns the number of users loaded
}

void saveUsers(User u[], int n) {
    FILE *fp = fopen(FILE_NAME, "w");
    for (int i = 0; i < n; i++)
        fprintf(fp, "%s\n%s\n%d\n%lld\n",// Write user to users.txt
            u[i].username,
            u[i].password,
            u[i].balance,
            u[i].account);
    fclose(fp);// close file
}
        //***CHECKER***// 
int findUser(User u[], int n, char *un, char *pw) {//login verification
    for (int i = 0; i < n; i++)
        if (!strcmp(u[i].username, un) &&//Check if username and password match
            !strcmp(u[i].password, pw))
            return i;// return index if found
    return -1;
}
        //***TRANSFER***//
int findAccount(User u[], int n, long long acc) {// find receipent account for transfer operations
    for (int i = 0; i < n; i++)
        if (u[i].account == acc)//prevent transfer to a non-existing account
            return i;
    return -1;
}

/* ---------- MAIN ---------- */
int main() {
    User users[100];
    int count = loadUsers(users);
    int option, choice, amt, index;
    char username[50], password[50];
    long long acc;
    char buf[20];

    /* ----- WELCOME PAGE ----- */
    printf("===== WELCOME TO COREX BANK =====\n");
    printf("Would you like to:\n1. Login\n2. Sign Up\nEnter choice: ");
    while (!readInt(&option) || option < 1 || option > 2)
        printf("Invalid choice. Enter 1 or 2: ");

    /* ----- SIGN UP ----- */
    if (option == 2) {
        printf("Create username: ");
        scanf("%49s", username);
        getchar(); // clear newline

        printf("Create password: ");
        scanf("%49s", password);
        getchar(); // clear newline

        printf("Enter 11-digit phone number: ");
        while (!readPhone(&acc)) {
            printf("Invalid phone number. Try again: ");
        }

        // Show account number immediately
        printf("Your account number is: %lld\n", acc);

        strcpy(users[count].username, username);
        strcpy(users[count].password, password);
        users[count].balance = 1000;
        users[count].account = acc;
        count++;

        saveUsers(users, count);
        printf("Account created successfully!\n");
    }

    /* ----- LOGIN ----- */
    while (1) {
        printf("\nUsername: ");
        scanf("%49s", username);
        printf("Password: ");
        scanf("%49s", password);
        index = findUser(users, count, username, password);
        if (index != -1) break;
        printf("Invalid login. Try again.\n");
    }

    /* ----- ATM MENU ----- */
    while (1) {
        printf("\n1. Check Balance\n2. Withdraw\n3. Deposit\n4. Transfer\n5. Exit\n");
        printf("Choose option: ");

        // read menu choice safely
        if (!fgets(buf, sizeof(buf), stdin)) continue;
        buf[strcspn(buf, "\n")] = 0;
        if (strlen(buf) == 0 || sscanf(buf, "%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid option.\n");
            continue;
        }

        if (choice == 1) {
            printf("Balance: %d\n", users[index].balance);
        } 
        else if (choice == 2) {
            printf("Withdraw amount: ");
            if (!fgets(buf, sizeof(buf), stdin)) continue;
            if (strlen(buf) == 0 || sscanf(buf, "%d", &amt) != 1 || amt <= 0 || amt > users[index].balance) {
                printf("Invalid amount.\n");
                continue;
            }
            users[index].balance -= amt;
            saveUsers(users, count);
            printf("Withdrawal successful.\n");
        } 
        else if (choice == 3) {
            printf("Deposit amount: ");
            if (!fgets(buf, sizeof(buf), stdin)) continue;
            if (strlen(buf) == 0 || sscanf(buf, "%d", &amt) != 1 || amt <= 0) {
                printf("Invalid amount.\n");
                continue;
            }
            users[index].balance += amt;
            saveUsers(users, count);
            printf("Deposit successful.\n");
        } 
        else if (choice == 4) {
            printf("Recipient account number: ");
            if (!fgets(buf, sizeof(buf), stdin)) continue;
            if (strlen(buf) == 0 || sscanf(buf, "%lld", &acc) != 1) {
                printf("Invalid account number.\n");
                continue;
            }
            int r = findAccount(users, count, acc);
            if (r == -1 || r == index) {
                printf("Invalid account.\n");
                continue;
            }
            printf("Transfer amount: ");
            if (!fgets(buf, sizeof(buf), stdin)) continue;
            if (strlen(buf) == 0 || sscanf(buf, "%d", &amt) != 1 || amt <= 0 || amt > users[index].balance) {
                printf("Invalid amount.\n");
                continue;
            }
            users[index].balance -= amt;
            users[r].balance += amt;
            saveUsers(users, count);
            printf("Transfer successful.\n");
        } 
        else if (choice == 5) {
            printf("Thank you for using Corex Bank.\n");
            break;
        }
    }

    return 0;
}