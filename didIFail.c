
#include<stdio.h>

int main()
{
     int score;

     printf("Enter your score (1-100): ");
     scanf("%d", &score);

     if (score <= 59)
          printf("\nYeah you did fail, I'm sorry. \n");
     else if (score <= 69)
     {
          printf("It's a D\n");
     }
     else if (score <= 79)
          printf("It's a C\n");
     else if (score <= 89)
          printf("No you got a B!\n");
     else if (score <= 100)
          printf("No you got an A!");
     else
          printf("Please enter a number from 1-100");


     return 0;

}
