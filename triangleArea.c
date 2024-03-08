#include <stdio.h>

int main() {


     double BaseValue = 0;
     double HeightValue = 0;

     printf("Triangle Area Calculator\n");
     printf("Enter Base Value: ");
     scanf("%lf", &BaseValue);
     printf("Enter Height Value: ");
     scanf("%lf", &HeightValue);

     double formula = 0.5 * BaseValue * HeightValue;

     printf("Area: %lf", formula);

     return 0;
}
