#include <stdio.h>
int main() {
    char code[10];
    int menu, option;
    printf("Enter USSD code: ");
    scanf("%s", code);
    if (code[0] == '*' && code[1] == '3' && code[2] == '1' && code[3] == '2' && code[4] == '#') {
        printf("\nWelcome to MTN\n");
        printf("1. Data Plans\n");
        printf("2. Enjoy 4.5GB for 1000\n");
        printf("3. Enjoy 7GB for 1500\n");
        printf("4. Voice Offer\n");
        printf("5. XtraValue\n");
        printf("6. Roaming\n");
        printf("7. Borrowing Credit\n");
        printf("8. Next\n");
        printf("Choose: ");
        scanf("%d", &menu);
        switch (menu) {
        case 1:
            printf("\nBuy Data Plans\n");
            printf("1. Daily\n");
            printf("2. 2-3 days\n");
            printf("3. Weekly\n");
            printf("4. Monthly\n");
            printf("5. 2months +\n");
            printf("6. Social Bundles\n");
            printf("7. BroadBand\n");
            printf("8. Binge Bundles\n");
            printf("9. Family Share\n");
            printf("10. Hot Deals\n");
            printf("99. Next\n");
            printf("0. Back\n");
            printf("Choose: ");
            scanf("%d", &option);
            switch (option) {
            case 1:
                printf("1. N75 = 75MB\n");
                printf("2. N100 = 110MB\n");
                printf("3. N200 = 230MB\n");
                printf("4. N350 = 500MB\n");
                printf("5. N500 = 1GB\n");
                printf("6. N750 = 2.5GB\n");
                printf("7. N50 Betamix Mini = 40MB & 1 Min\n");
                printf("99. Next\n");
                printf("0. Back\n");
                break;
            case 2:
                printf("1. N600 = 1.5GB\n");
                printf("2. N750 = 2GB\n");
                printf("3. N900 = 2.5GB\n");
                printf("4. N1000 = 3.2GB\n");
                printf("5. N1800 = 7GB\n");
                printf("6. N100 Jolly Combo Offer\n");
                printf("0. Back\n");
                break;
            case 3:
                printf("1. N500 = 500MB\n");
                printf("2. N800 = 1GB\n");
                printf("3. N1500 = 3.5GB\n");
                printf("4. N2500 = 6GB\n");
                printf("5. N5000 = 20GB\n");
                printf("6. N3500 = 11GB\n");
                printf("11. N50 = 40MB Whatsapp\n");
                printf("0. Back\n");
                break;
            case 4:
                printf("1. N1500 = 2GB+2GB\n");
                printf("2. N1500 = 1.8GB+6mins\n");
                printf("3. N2000 = 2.7GB+2GB\n");
                printf("4. N2500 = 3.5GB+2GB\n");
                printf("5. N3000 = 5.5GB+8mins\n");
                printf("6. N3500 = 7GB+2GB\n");
                printf("99. Next\n");
                printf("0. Back\n");
                break;
            case 5:
                printf("2Months +\n");
                printf("1. N40,000 = 150GB/60Days\n");
                printf("2. N90,000 = 480GB/90DAYS\n");
                printf("3. N125,000 = 800GB/365DAYS\n");
                printf("0. Back\n");
                break;
            case 6:
                printf("1. Whatsapp\n");
                printf("2. Facebook\n");
                printf("3. Instagram\n");
                printf("4. Tiktok\n");
                printf("5. Ayoba\n");
                printf("6. All Social Bundles\n");
                printf("0. Back\n");
                break;
            case 7:
                printf("1. Link Device\n");
                printf("2. Recharge Device\n");
                printf("3. Check Device Balance\n");
                printf("4. View & Unlink Device\n");
                break;
            case 8:
                printf("1. N500 for 1GB\n");
                printf("2. N600 for 1.5GB\n");
                printf("3. N900 for 2.5GB\n");
                printf("4. N1,000 for 3.2GB\n");
                printf("5. N2,500 for 6GB\n");
                printf("6. N3,500 for 11GB\n");
                printf("0. Back\n");
                break;
            case 9:
                printf("1. Add New Beneficiary/Sponsor\n");
                printf("2. Manage Beneficiary/Sponsor\n");
                printf("3. Balance Enquiry\n");
                printf("4. Deactivate service\n");
                printf("5. Help\n");
                printf("0. Back\n");
                printf("00. Main Menu\n");
                break;
            case 10:
                printf("New Xtravalue Plans\n");
                printf("1. N500 - 600MB+2mins+2 SMS. Valid 7days\n");
                printf("2. N1,500 - 1.8GB+6mins+5 SMS. Valid 30days\n");
                printf("3. N3,000 - 5.5GB+8mins+7 SMS. Valid 30days\n");
                printf("0. Back\n");
                break;
            case 99:
                printf("11. Always ON\n");
                printf("12. Manage Data\n");
                printf("13. Youtube\n");
                printf("14. Apple Music Flexa\n");
                printf("0. Back\n");
                break;
            case 0:
                printf("\nWelcome\n");
                printf("1. Data Plans\n");
                printf("2. Enjoy 4.5GB for 1000\n");
                printf("3. Enjoy 7GB for 1500\n");
                printf("4. Voice Offer\n");
                printf("5. XtraValue\n");
                printf("6. Roaming\n");
                printf("7. Borrowing Credit\n");
                printf("8. Next\n");
                break;
            default:
                printf("Invalid\n");
            }
            break;
        case 2:
            printf("\nSpecial Offer for you! Get 4.5GB for N1000\n");
            printf("\nData is valid for 1 day\n");
            printf("1. Activate\n");
            printf("0. Back\n");
            printf("Choose: ");
            scanf("%d", &option);
            if (option == 1) {
                printf("\n4.5GB has been successfully activated\n");
            } else if (option == 0) {
                printf("\nBack\n");
            } else {
                printf("\nInvalid\n");
            }
            break;
        case 3:
            printf("\nSpecial Offer for you! Get 7GB for N1500.\n");
            printf("\nData is valid for 1 day\n");
            printf("1. Activate\n");
            printf("0. Back\n");
            printf("Choose: ");
            scanf("%d", &option);
            if (option == 1) {
                printf("\n7GB has been successfully activated\n");
            } else if (option == 0) {
                printf("\nBack\n");
            } else {
                printf("\nInvalid\n");
            }
            break;
        case 4:
            printf("Voice Offer Menu\n");
            printf("1. Voice Bundles\n");
            printf("2. Night Plans\n");
            printf("3. Weekend Bundles\n");
            printf("4. Back\n");
            printf("Choose: ");
            scanf("%d", &option);
            if (option == 1) {
                printf("Voice Bundles Selected\n");
            } else if (option == 2) {
                printf("Night Plans Selected\n");
            } else if (option == 3) {
                printf("Weekend Bundles Selected\n");
            } else if (option == 4) {
                printf("Back\n");
            } else {
                printf("Invalid\n");
            }
            break;
        case 5:
            printf("XtraValue Menu\n");
            printf("1. XtraValue Plans\n");
            printf("2. Manage XtraValue\n");
            printf("0. Back\n");
            printf("Choose: ");
            scanf("%d", &option);
            if (option == 1) {
                printf("XtraValue Plans Displayed\n");
            } else if (option == 2) {
                printf("Manage XtraValue Selected\n");
            } else if (option == 0) {
                printf("Back\n");
            } else {
                printf("Invalid\n");
            }
            break;
        case 6:
            printf("Roaming Menu\n");
            printf("1. Activate Roaming\n");
            printf("2. Roaming Rates\n");
            printf("0. Back\n");
            printf("Choose: ");
            scanf("%d", &option);
            if (option == 1) {
                printf("Roaming Activated\n");
            } else if (option == 2) {
                printf("Roaming Rates Displayed\n");
            } else if (option == 0) {
                printf("Back\n");
            } else {
                printf("Invalid\n");
            }
            break;
        case 7:
            printf("Borrowing Credit Menu\n");
            printf("1. Borrow Airtime\n");
            printf("2. Borrow Data\n");
            printf("3. Borrow Later\n");
            printf("0. Back\n");
            printf("Choose: ");
            scanf("%d", &option);
            if (option == 1) {
                printf("Airtime Borrowed\n");
            } else if (option == 2) {
                printf("Data Borrowed\n");
            } else if (option == 3) {
                printf("Borrow Later Selected\n");
            } else if (option == 0) {
                printf("Back\n");
            } else {
                printf("Invalid\n");
            }
            break;
        case 8:
            printf("Next Page\n");
            printf("1. Offers\n");
            printf("2. Promos\n");
            printf("3. Help\n");
            printf("0. Back\n");
            printf("Choose: ");
            scanf("%d", &option);
            if (option == 1) {
                printf("Offers Shown\n");
            } else if (option == 2) {
                printf("Promos Shown\n");
            } else if (option == 3) {
                printf("Help Menu\n");
            } else if (option == 0) {
                printf("Back\n");
            } else {
                printf("Invalid\n");
            }
            break;
        default:
            printf("Wrong menu\n");
        }
    } else {
        printf("Wrong code\n");
    }
    return 0;
}