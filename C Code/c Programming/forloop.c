// #include <stdio.h>
// #include <windows.h>

// int main(){
//     for(int i = 10 ;i >= 0;i-- ){
//         printf("%d\n",i);
//         Sleep(1000);
//     }
//     printf("Happy New Year!\n");

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    printf("%d",RAND_MAX);
}