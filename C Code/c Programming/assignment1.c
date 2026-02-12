#include <stdio.h>

int main() {
    printf("Name: Laminez\n");
    printf("Age: 16\n");
    printf("Hobby: Coding\n");
    return 0;
}


#include <stdio.h>

int main() {
    int a = 5, b = 7, sum;
    sum = a + b;
    printf("Sum = %d", sum);
    return 0;
}

#include <stdio.h>

int main() {
    int length, width, area;
    length = 10;
    width = 5;
    area = length * width;
    printf("Area = %d", area);
    return 0;
}


#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(n % 2 == 0)
        printf("Even");
    else
        printf("Odd");

    return 0;
}