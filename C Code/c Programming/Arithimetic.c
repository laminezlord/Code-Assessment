#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d and %d", &a, &b);


    printf("Sum = %d\n", a + b);
    printf("Product = %d\n", a * b);
    printf("Difference = %d\n", a - b);

    if (b != 0) {
        printf("Quotient = %d\n", a / b);
        printf("Remainder = %d\n", a % b);
    } else {
        printf("Quotient and Remainder: Division by zero not allowed\n");
    }

    return 0;
}
