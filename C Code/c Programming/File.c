#include <stdio.h>

int main(){
    //WRITE A FILE
    FILE *pFILE = fopen("C:\\Users\\You\\OneDrive\\Desktop\\sample.txt", "w");
  if(pFILE == NULL){
        printf("Error opening file!\n");
        return 1;
    }
    char text[] = "This is a sample text file.\nWelcome to file handling in C.";

    fprintf(pFILE, "%s", text);


    printf("File written successfully.\n"); 
   
    fclose(pFILE);
    return 0;
}