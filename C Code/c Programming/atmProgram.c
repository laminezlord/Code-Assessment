#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int balance = 0;

// Sign-up Page
int main() {
    printf("Enter username: \n");
    scanf("%s");
    printf("Enter password: \n");
    scanf("%s");    
    printf("Account created successfully!\n");    
    

// Login Page
    char username[50];
    char password[50];
    printf("Login Page\n");
    printf("Enter username: \n");
    scanf("%s", username);
    printf("Enter password: \n");
    scanf("%s", password);

//Reading from file
    FILE *fp;
    fp = fopen("user_Info.txt", "r");
    char file_username[50];
    char file_password[50];
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fgets(file_username, sizeof(file_username), fp);
        fgets(file_password, sizeof(file_password), fp);
        fscanf(fp, "%d", &balance);
        fclose(fp);


// Comparing saved information with entered data.
    if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
        printf("Login successful!\n");
    } else {
        printf("Incorrect username or password. Try again.\n\n");
    }
}