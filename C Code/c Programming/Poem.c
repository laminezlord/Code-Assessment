#include <stdio.h>

int main(){

    // READ FILE
    FILE* pFILE = fopen("poem.txt", "r");
    char buffer[1024] = {0};

    if(pFILE == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    while(fgets(buffer, sizeof(buffer), pFILE) != NULL){
        printf("%s", buffer);
    }

    fclose(pFILE);
    return 0;
}