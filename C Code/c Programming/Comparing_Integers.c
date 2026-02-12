#include <stdio.h>

int compare_integers(int a, int b) {
    if (a > b)
        printf("%d is larger.\n", a);

    if (b > a)
        printf("%d is larger.\n", b);

    if (a == b)
        printf("These numbers are equal.\n");

    return 0;
}

int main() {
    int x, y;

    printf("Enter two integers: ");
    scanf("%d and %d", &x, &y);

    compare_integers(x,y);

    return 0;
}
