#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(n % 2 == 0)
        printf("The number you entered is even.");
    else
        printf("The number you entered is odd.");
    return 0;
}


#include <stdio.h>

int main() {
    int age;
    printf("Enter age: ");
    scanf("%d", &age);

    if(age < 13)
        printf("You are a child");
    else if(age <= 19)
        printf("You are a teenager");
    else
        printf("You are an adult");
    return 0;
}

#include <stdio.h>

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if(a > b)
        printf("Greater number = %d", a);
    else
        printf("Greater number = %d", b);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char u[20], p[20];

    // Attempt 1
    printf("Enter username: ");
    scanf("%s", u);
    printf("Enter password: ");
    scanf("%s", p);

    if(strcmp(u, "admin") == 0 && strcmp(p, "1234") == 0) {
        printf("Login Successful");
    }

    else {
        printf("Incorrect username or password. Try again.\n\n");

        // Attempt 2
        printf("Enter username: ");
        scanf("%s", u);
        printf("Enter password: ");
        scanf("%s", p);

        if(strcmp(u, "admin") == 0 && strcmp(p, "1234") == 0) {
            printf("Login Successful");
        }

        else {
            printf("Incorrect username or password. Try again.\n\n");

            // Attempt 3
            printf("Enter username: ");
            scanf("%s", u);
            printf("Enter password: ");
            scanf("%s", p);

            if(strcmp(u, "admin") == 0 && strcmp(p, "1234") == 0)
                printf("Login Successful");
            else
                printf("Account Locked. Too many failed attempts.");
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

    printf("\nAverage Score = %.1f\n", avg);

    if(avg >= 70)
        printf("Final Grade = A\n");
    else if(avg >= 60)
        printf("Final Grade = B\n");
    else if(avg >= 50)
        printf("Final Grade = C\n");
    else
        printf("Final Grade = F\n");

    if(m >= 50 && e >= 50 && p >= 50 && c >= 50 && cs >= 50)
        printf("Status: Passed all subjects");
    else
        printf("Status: Failed at least one subject");

    return 0;
}