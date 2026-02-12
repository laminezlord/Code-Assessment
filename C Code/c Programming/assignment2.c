// #include <stdio.h>

// int main() {
//     char name[20], dept[20];
//     int age;

//     printf("Name: ");
//     scanf("%s", name);

//     printf("Age: ");
//     scanf("%d", &age);

//     printf("Department: ");
//     scanf("%s", dept);

//     printf("\nYou entered: %s, %d, %s", name, age, dept);
//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int a, b;

//     printf("Enter two numbers: ");
//     scanf("%d %d", &a, &b);

//     printf("Sum = %d\n", a + b);
//     printf("Difference = %d\n", a - b);
//     printf("Product = %d\n", a * b);
//     printf("Quotient = %d\n", a / b);
//     printf("Remainder = %d\n", a % b);

//     return 0;
// }



// #include <stdio.h>

// int main() {
//     float r, area, circ;
//     printf("Enter radius: ");
//     scanf("%f", &r);

//     area = 3.14 * r * r;
//     circ = 2 * 3.14 * r;

//     printf("Area = %.2f\n", area);
//     printf("Circumference = %.2f", circ);

//     return 0;
// }


// #include <stdio.h>

// int main() {
//     float c, f;
//     printf("Enter Celsius: ");
//     scanf("%f", &c);

//     f = (c * 9/5) + 32;
//     printf("Fahrenheit = %.2f", f);

//     return 0;
// }





#include<stdio.h>
#include<stdbool.h>

int main(){
    char name[] ="John Doe\n";
    char department[] = "computer science\n";
    int age = 21;
    bool isOnline = 0;


    printf("Enter your name\n");
    scanf(" %s", &name);
     printf("Your name is %s\n", name);

    printf("\nWhich department are you from?\n");
    scanf(" %s", &department);
    printf("You are from %s", department);

    printf("How old are you?\n");
    scanf(" %d", &age);
     printf("You are %d years old\n", age);

    printf("Are you online currently? (1 for yes, 0 for no)\n");
    scanf(" %d", &isOnline);

    
    if(isOnline){
        printf("i am online\n");
    }
        else{
            printf("i am offline\n");
        }



    return 0;
}