#include <stdio.h>

int main ()
{
     int input;
     printf("Enter a number: \n");
     scanf("%d", &input);

     int upIt = input * 2;
     int upItFour = input * 4;
     printf("\\~Double up is %d~\\-----/~Quadruple up is %d~/", upIt, upItFour);

     return 0;
}
