#include <stdio.h>

int main() {
    char code[10];
    int menu, option;

    printf("Enter USSD code: ");
    scanf("%s", code);

    if (code[0] == '*' && code[1] == '3' && code[2] == '1' && code[3] == '2' && code[4] == '#' ) {

        printf(
            "\nWelcome\n"
            "1. Data Plans\n"
            "2. Enjoy 4.5GB for 1000\n"
            "3. Enjoy 7GB for 1500\n"
            "4. Voice Offer\n" 
            "5. XtraValue\n"
            "6. Roaming\n"
            "7. Borrowing Credit\n"
            "8. Next\n"
        );
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            printf(
                "\nBuy Data Plans\n"
                "1. Daily\n"
                "2. 2-3 days\n"
                "3. Weekly\n"
                "4. Monthly\n"
                "5. 2months +\n"
                "6. Social Bundles\n"
                "7. BroadBand\n"
                "8. Binge Bundles\n"
                "9. Family Share\n"
                "10. Hot Deals\n"
                "99. Next\n"
                "0. Back\n"
            );
            scanf("%d", &option);
            switch (option) {
                case 1: printf(
                    "1. N75 = 75MB\n"
                    "2. N100 = 110MB\n"
                    "3. N200 = 230MB\n"
                    "4. N350 = 500MB\n"
                    "5. N500 = 1GB\n"
                    "6. N750 = 2.5GB\n"
                    "7. N50 Betamix Mini = 40MB & 1 Min\n"
                    "99. Next\n"
                    "0. Back\n"
                ); break;
                case 2: printf(
                    "1. N600 = 1.5GB\n"
                    "2. N750 = 2GB\n"
                    "3. N900 = 2.5GB\n"
                    "4. N1000 = 3.2GB\n"
                    "5. N1800 = 7GB\n"
                    "6. N100 Jolly Combo Offer\n"
                    "0. Back\n"
                ); break;
                case 3: printf(
                    "1. N500 = 500MB\n"
                    "2. N800 = 1GB\n"
                    "3. N1500 = 3.5GB\n"
                    "4. N2500 = 6GB\n"
                    "5. N5000 = 20GB\n"
                    "6. N3500 = 11GB\n"
                    "11. N50 = 40MB Whatsapp\n"
                    "0. Back\n"
                ); break;
                case 4:printf(
                    "1. N1500 = 2GB+2GB\n"
                    "2. N1500 = 1.8GB+6mins\n"
                    "3. N2000 = 2.7GB+2GB\n"
                    "4. N2500 = 3.5GB+2GB\n"
                    "5. N3000 = 5.5GB+8mins\n"
                    "6. N3500 = 7GB+2GB\n"
                    "99. Next\n"
                    "0. Back\n"
                ); break;
                case 5: printf(
                    "2Months +"
                    "1. N40,000 = 150GB/60Days\n"
                    "2. N90,000 = 480GB/90DAYS\n"
                    "3. N125,000 = 800GB/365DAYS\n"
                    "0. Back\n"
                ); break;
                case 6 : printf(
                    "1. Whatsapp\n"
                    "2. Facebook\n"
                    "3. Instagram\n"
                    "4. Tiktok\n"
                    "5. Ayoba\n"
                    "6. All Social Bundles\n"
                    "0. Back\n"
                );break;
                case 7 : printf(
                    "1. Link Device\n"
                    "2. Recharge Device\n"
                    "3. Check Device Balance\n"
                    "4. View & Unlink Device\n"
                ); break;
                case 8 : printf(
                    "1. N500 for 1GB\n"
                    "2. N600 for 1.5GB\n"
                    "3. N900 for 2.5GB\n"
                    "4. N1,000 for 3.2GB\n"
                    "5. N2,500 for 6GB\n"
                    "6. N3,500 for 11GB\n"
                    "0. Back\n"
                ); break;
                case 9 : printf(
                    "1. Add New Beneficiary/Sponsor\n"
                    "2. Manage Beneficiary/Sponsor\n"
                    "3. Balance Enquiry\n"
                    "4. Deactivate service\n"
                    "5. Help\n"
                    "0. Back\n"
                    "00. Main Menu\n"
                );break;
                case 10 : printf(
                    "New Xtravalue Plans"
                    "1. N500 - 600MB+2mins+2 SMS. Valid 7days\n"
                    "2. N1,500 - 1.8GB+6mins+5 SMS. Valid 30days\n"
                    "3. N3,000 - 5.5GB+8mins+7 SMS. Valid 30days\n"
                    "0. Back\n"
                );break;
                case 99 : printf(
                    "11. Always ON\n"
                    "12. Manage Data\n"
                    "13. Youtube\n"
                    "14. Apple Music Flexa\n"
                    "0. Back\n"
                );break;
                case 0 : printf(
                     "\nWelcome\n"
                     "1. Data Plans\n"
                     "2. Enjoy 4.5GB for 1000\n"
                     "3. Enjoy 7GB for 1500\n"
                     "4. Voice Offer\n" 
                     "5. XtraValue\n"
                     "6. Roaming\n"
                     "7. Borrowing Credit\n"
                     "8. Next\n"
                );break;
                default: printf("Invalid\n");
            }
            break;

        case 2:
            printf(
                "\nSpecial Offer for you! Get 4.5GB for N1000\n"
                "\nData is valid for 1 day\n"
                "1. Activate\n"
                "0. Back\n"
            );
            printf("\n4.5 gb has been successfully activated\n");
            scanf("%d", &option);
        case 3:
            printf(
                "\nSpecial Offer for you! Get 7GB for N1500.\n"
                "\n Data is valid for 1 day\n"
                "1. Activate\n"
                "0. Back\n"
            );
            printf("1. Airtime Bal\n2. Bonus Bal\n3. SIM Status\n4. Back\n");
            scanf("%d", &option);
            switch (option) {
                case 1: printf("Airtime Bal selected\n"); break;
                case 2: printf("Bonus Bal selected\n"); break;
                case 3: printf("SIM Status selected\n"); break;
                case 4: printf("Back\n"); break;
                default: printf("Invalid\n");
            }
            break;

        case 4:
            printf("Exit\n");
            break;

        default:
            printf("Wrong menu\n");
        }
    }
    else {
        printf("Wrong code\n");
    }

    return 0;
}



#include <stdio.h>

int main() {
    int a, b, c, d, sum;

    printf("Enter 4 numbers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    sum = a + b + c + d;

    printf("Sum = %d\n", sum);

    return 0;
}


#include <stdio.h>

int main() {
    int arr[] = {5, 2, 8, 12, 3};
    int n = 5;
    int min = arr[0];
    int max = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    int diff = max - min;

    printf("Maximum difference: %d\n", diff);

    return 0;
}
