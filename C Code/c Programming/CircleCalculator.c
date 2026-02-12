#include<stdio.h>
#include<math.h>

int main(){


    //CIRCLE CALCULATOR PROGRAM

    double radius = 0.0;
    double area = 0.0;
    double surfacArea;
    double volume;
    const double PI = 3.14159;

    printf("Enter the radius : ");
    scanf("%lf", &radius);

    area = PI * pow(radius, 2); 
    surfacArea = 4 * PI* pow(radius, 2);  
    volume = (4.0/3.0) * PI * pow(radius, 3);
     



    printf("Area : %.2lfcm\n", area);
    printf("Surface Area : %.2lfcm\n", surfacArea);
    printf("Volume : %.2lfcm\n", volume);









    return 0;
}