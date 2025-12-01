// #include <stdio.h>

// int main() {
//     int a[5], i, j, temp;

//     for(i = 0; i < 5; i++) {
//         printf("Enter number %d: ", i+1);
//         scanf("%d", &a[i]);
//     }

//     for(i = 0; i < 5; i++) {
//         for(j = i+1; j < 5; j++) {
//             if(a[i] > a[j]) {
//                 temp = a[i];
//                 a[i] = a[j];
//                 a[j] = temp;
//             }
//         }
//     }

//     printf("Ascending: ");
//     for(i = 0; i < 5; i++) {
//         printf("%d ", a[i]);
//     }
// }

// #include <stdio.h>

// int main() {
//     int a[6], i, j, temp;

//     for(i = 0; i < 6; i++) {
//         printf("Enter number %d: ", i+1);
//         scanf("%d", &a[i]);
//     }

//     for(i = 0; i < 6; i++) {
//         for(j = i+1; j < 6; j++) {
//             if(a[i] < a[j]) {
//                 temp = a[i];
//                 a[i] = a[j];
//                 a[j] = temp;
//             }
//         }
//     }

//     printf("Descending: ");
//     for(i = 0; i < 6; i++) {
//         printf("%d ", a[i]);
//     }
// }

// #include <stdio.h>

// int main() {
//     int a[5], i, temp;

//     for(i = 0; i < 5; i++) {
//         printf("Enter number %d: ", i+1);
//         scanf("%d", &a[i]);
//     }

//     printf("Before: ");
//     for(i = 0; i < 5; i++) {
//         printf("%d ", a[i]);
//     }

//     temp = a[0];
//     a[0] = a[4];
//     a[4] = temp;

//     printf("\nAfter: ");
//     for(i = 0; i < 5; i++) {
//         printf("%d ", a[i]);
//     }
// }
