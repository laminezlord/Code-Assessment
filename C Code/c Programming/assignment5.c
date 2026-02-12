#include <stdio.h>
#include <string.h>

int main() {
    char code[10];
    int mainChoice, subChoice;

    printf("Enter USSD Code: ");
    scanf("%s", code);

    if(strcmp(code, "*123#") == 0) {

        printf("\nWelcome to XYZ Network\n");
        printf("1. Airtime Services\n");
        printf("2. Data Services\n");
        printf("3. Account Information\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &mainChoice);

        switch(mainChoice) {

            case 1:
                printf("\nAirtime Services\n");
                printf("1. Recharge Airtime\n");
                printf("2. Borrow Airtime\n");
                printf("3. Transfer Airtime\n");
                printf("4. Back to Main Menu\n");
                printf("Enter option: ");
                scanf("%d", &subChoice);

                switch(subChoice) {
                    case 1: printf("You selected Recharge Airtime"); break;
                    case 2: printf("You selected Borrow Airtime"); break;
                    case 3: printf("You selected Transfer Airtime"); break;
                    case 4: printf("Back to Main Menu"); break;
                    default: printf("Invalid Airtime option");
                }
                break;

            case 2:
                printf("\nData Services\n");
                printf("1. Buy Data Plan\n");
                printf("2. Check Data Balance\n");
                printf("3. Get Data Bonus\n");
                printf("4. Back to Main Menu\n");
                printf("Enter option: ");
                scanf("%d", &subChoice);

                switch(subChoice) {
                    case 1: printf("You selected Buy Data Plan"); break;
                    case 2: printf("You selected Check Data Balance"); break;
                    case 3: printf("You selected Get Data Bonus"); break;
                    case 4: printf("Back to Main Menu"); break;
                    default: printf("Invalid Data option");
                }
                break;

            case 3:
                printf("\nAccount Information\n");
                printf("1. Check Airtime Balance\n");
                printf("2. Check Bonus Balance\n");
                printf("3. SIM Registration Status\n");
                printf("4. Back to Main Menu\n");
                printf("Enter option: ");
                scanf("%d", &subChoice);

                switch(subChoice) {
                    case 1: printf("You selected Check Airtime Balance"); break;
                    case 2: printf("You selected Check Bonus Balance"); break;
                    case 3: printf("You selected SIM Registration Status"); break;
                    case 4: printf("Back to Main Menu"); break;
                    default: printf("Invalid Account option");
                }
                break;

            case 4:
                printf("Exiting...");
                break;

            default:
                printf("Invalid Main Menu option");
        }

    } else {
        printf("Invalid USSD Code");
    }

    return 0;
}