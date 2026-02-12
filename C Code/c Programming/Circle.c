#include <stdio.h>

#define PI 3.14159

// Function prototypes
float diameter(float r);
float circumference(float r);
float area(float r);

int main() {
    float radius = 2.0;

    printf("Diameter: %f\n", diameter(radius));
    printf("Circumference: %f\n", circumference(radius));
    printf("Area: %f\n", area(radius));

    return 0;
}

// Function definitions
float diameter(float r) {
    return 2 * r;
}

float circumference(float r) {
    return 2 * PI * r;
}

float area(float r) {
    return PI * r * r;
}
