// #include <stdio.h>

// void largest(int a, int b, int c) {
//     if(a >= b && a >= c)
//         printf("Largest = %d", a);
//     else if(b >= a && b >= c)
//         printf("Largest = %d", b);
//     else
//         printf("Largest = %d", c);
// }

// int main() {
//     largest(10, 25, 15);
//     return 0;
// }



#include <stdio.h>

int main() {
    int n, temp, rev = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0) {
        digit = temp % 10;
        rev = rev + digit;
        temp = temp / 10;
    }

    if(rev == n)
        printf("1");
    else
        printf("0");

    return 0;
}






