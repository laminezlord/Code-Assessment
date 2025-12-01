#include <stdio.h>

int main() {
    char matrix[3][3];
    int slot;
    int round = 0;

    // Initialize matrix with numbers 1-9
    int num = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = '0' + num;
            num++;
        }
    }

    printf("Welcome to Tic Tac Toe game\n");
    printf("Numbers 1-9 are on the board. Press a number to replace it with X or O.\n\n");

    while (round < 9) {
        
        printf("Current Board:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %c", matrix[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) printf("-----------\n");
        }
        printf("\n");

        printf("Round %d - Player %c: Enter number (1-9): ", round + 1, (round % 2 == 0) ? 'X' : 'O');
        scanf(" %d", &slot);

        if (slot < 1 || slot > 9) {
            printf("Invalid slot! Please enter a number between 1 and 9.\n\n");
            continue;
        }

        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;
        
        if (matrix[row][col] < '1' || matrix[row][col] > '9') {
            printf("Slot already taken! Choose another.\n\n");
            continue;
        }

        
        matrix[row][col] = (round % 2 == 0) ? 'X' : 'O';
        round++;
        printf("\n");
    }

    
    printf("Final Board:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c", matrix[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }

    printf("\nGame Over!\n");
    return 0;
}