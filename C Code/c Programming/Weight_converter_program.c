#include <stdio.h>

int main(){
    // WEIGHT CONVERTER PROGRAM

    int choice = 0;
    float pounds = 0.0f;
    float kilograms = 0.0f;

    printf("Weight Converter calculator\n");
    printf("1. kilograms to pounds\n");
    printf("2. pounds to kilograms\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1){
        // kilograms to pounds
        printf("Enter weight in kilograms: ");
        scanf("%f", &kilograms);
        pounds = kilograms * 2.20462;
        printf("Weight in pounds: %.2f\n", pounds);


    }
    else if(choice){
        // pounds to kilograms
        printf("Enter weight in pounds: ");
        scanf("%f", &pounds);
        kilograms = pounds / 2.20462;
        printf("Weight in kilograms: %.2f\n", kilograms);
    }
    else{
        printf("Invalid choice. Please select 1 or 2.\n");

    }






    return 0;

}
