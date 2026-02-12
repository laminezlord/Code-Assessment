#include <stdio.h>

int main(){
    // SWITCH CASE PROGRAM

    int dayofweek = 0;

    printf("Enter a number (1-7) to get the corresponding day of the week: ");
    scanf("%d", &dayofweek);

    switch(dayofweek){
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day of the week. Please enter a number between 1 and 7.\n");
    }
}