#include <stdio.h>

int main ()
{
     double kiloPerMile = 1.60934;
     int miles = 60;
     double KilometersConv;
     KilometersConv = miles / kiloPerMile;
     printf("%d miles is %lf in kilometers\n", miles, KilometersConv);
     printf("Enter the amount of miles you want to convert to kilometers: \n");
     scanf("%d", &miles);
     KilometersConv = miles / kiloPerMile;

     printf("%d miles is %lf in kilometers", miles, KilometersConv);
     return 0;
}
