#include <stdio.h>

int sum(int a, int b, int c) 
       { return a + b + c; }
int product(int a, int b, int c) 
           { return a * b * c; }

int smallest(int a, int b, int c) {
    int s = a;
    if (b < s) s = b;
    if (c < s) s = c;
    return s;
}

int largest(int a, int b, int c) {
    int l = a;
    if (b > l) l = b;
    if (c > l) l = c;
    return l;
}

int main() {
    int a, b, c;

    printf("Enter three different integers: ");
    scanf("%d,%d and %d", &a, &b, &c);

    printf("Sum is %d\n", sum(a, b, c));
    printf("Average is %d\n", sum(a, b, c) / 3);
    printf("Product is %d\n", product(a, b, c));
    printf("Smallest is %d\n", smallest(a, b, c));
    printf("Largest is %d\n", largest(a, b, c));

    return 0;
}
