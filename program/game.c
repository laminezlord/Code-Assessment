#include <stdio.h>

int  main () {
    char matrix [3][3];
    char input;
    int slot;
    int round = 0;

    for (int i = 0;i < 3; i++){
        for (int j = 0; j < 3; j++){
            matrix[i][j] = ' ';

         }
     
   }
    printf("Welcome to  ABIOLA'S X and O game\n");
    printf("Slots are numbered 1-9 as follows:\n");
    printf(" 1 | 2 | 3\n");
    printf("-----------\n");
    printf(" 4 | 5 | 6\n");
    printf("-----------\n");
    printf(" 7 | 8 | 9\n\n");  


    while (round < 9){
        printf("Round %d: Enter slot number (1-9): ", round + 1);
        scanf(" %d", &slot);
        if (slot < 1 || slot > 9) {
            printf("Invalid slot number. Please pick between (1-9)\n"); b
            continue;
        }
    }

}
