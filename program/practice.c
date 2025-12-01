#include <stdio.h>

int main() {
    char name[50];
    char item[50];
    float price;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the item you want to buy: ");
    scanf("%s", item);

    printf("Enter the price: ");
    scanf("%f", &price); 

    printf("\nHey %s! You picked \"%s\" and it costs ₦%.2f — happy shopping!\n", name, item, price);

    return 0;
}

 
  