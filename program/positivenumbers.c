// #include <stdio.h>

// int main(){
//     for(char c = 'A'; c <= 'Z'; c++) {
//         printf("%c\n", c);
//     }
//     return 0;
// }

#include <stdio.h>

int main() {
    char matrix[3][3];
    char input;
    int round = 1;

    printf("Welcome to  ABIOLA'S X and O game\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            while (1) {
                printf("Round %d: Enter X or O: ", round);
                scanf(" %c", &input);

                if (input == 'X' || input == 'x' || input == 'O' || input == 'o') {
                    matrix[i][j] = input;
                    break;
                } else {
                    printf("Invalid! Please enter only X or O.\n");
                }
            }

            round++;
        }
    }

    printf("\nFinal Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}