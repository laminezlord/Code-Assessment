#include <stdio.h>
#include<stdbool.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>


int main(){
    //DIGITAL CLOCK
    time_t rawtime = 0;
    struct tm *pTime = NULL;
    bool isRunning = true;

    printf("DIGITAL CLOCK\n");

    while(isRunning){
        time(&rawtime);
        printf("%ld\n", rawtime);
        pTime = localtime(&rawtime);
        printf("\r%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
        sleep(1000);

    }


    return 0;
}