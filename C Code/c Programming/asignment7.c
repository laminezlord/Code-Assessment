#include <stdio.h>

int main() {
    int N;

    // Input validation loop
    printf("Enter a positive integer (>= 2): ");
    while(scanf("%d", &N) != 1 || N < 2) {
        printf("Invalid input! Enter a positive integer >= 2: ");
        while(getchar() != '\n'); // clear invalid input
    }

    // Print tables from 2 to N
    for(int i = 2; i <= N; i++) {
        printf("\nMultiplication Table of %d\n", i);

        for(int j = 1; j <= 12; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }

        printf("\n"); // space between tables
    }

    return 0;
}
