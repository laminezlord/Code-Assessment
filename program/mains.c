#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 2 == 0)
        printf("The number you entered is even.\n");
    else
        printf("The number you entered is odd.\n");

    return 0;
}


int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    if (age < 13)
        printf("You are a child\n");
    else if (age >= 13 && age <= 19)
        printf("You are a teenager\n");
    else
        printf("You are an adult\n");

    return 0;
}


#include <stdio.h>

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a > b)
        printf("The greater number is %d\n", a);
    else
        printf("The greater number is %d\n", b);

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    char username[20], password[20];
    int attempts = 0;

    while(attempts < 3) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if(strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0) {
            printf("Login Successful\n");
            break;
        } else {
            attempts++;
            if(attempts < 3)
                printf("Incorrect username or password. Try again.\n\n");
            else
                printf("Account Locked. Too many failed attempts.\n");
        }
    }

    return 0;
}


#include <stdio.h>

int main() {
    float m, e, p, c, cs, avg;

    printf("Enter Math score: ");
    scanf("%f", &m);

    printf("Enter English score: ");
    scanf("%f", &e);

    printf("Enter Physics score: ");
    scanf("%f", &p);

    printf("Enter Chemistry score: ");
    scanf("%f", &c);

    printf("Enter Computer Science score: ");
    scanf("%f", &cs);

    avg = (m + e + p + c + cs) / 5;

    printf("Average Score = %.2f\n", avg);

    if (avg >= 70)
        printf("Final Grade = A\n");
    else if (avg >= 60)
        printf("Final Grade = B\n");
    else if (avg >= 50)
        printf("Final Grade = C\n");
    else
        printf("Final Grade = F\n");

    if (m >= 50 && e >= 50 && p >= 50 && c >= 50 && cs >= 50)
        printf("Status: Passed all subjects\n");
    else
        printf("Status: Failed at least one subject\n");

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    char username[20], password[20];

    while(1) {   
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        if(strcmp(username, "abiola") == 0 && strcmp(password, "1000") == 0) {
            printf("Login Successful\n");
            break;  
        } else {
            printf("Incorrect username or password. Try again.\n\n");
        } 
    }

    return 0;
}