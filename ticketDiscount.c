#include <stdio.h>

int main() {

     int age;
     printf("Hello, the tickets cost $14!\n");
     printf("Enter your age to check if you're eligible for any discounts:  ");
     scanf("%d", &age);
     if (age < 18)
     {
          printf("\n\nYou are eligible for a $10 admission ticket for being a minor!\n");
          printf("You do not have to pay full price.");
     }
     else if (age >= 65)
     {
         printf("\n\nYou are eligible for a $10 admission ticket for being a senior!\n");
         printf("You do not have to pay full price.");
     }
     else
     {
          printf("You are required to pay the full price of $14 for the admission ticket!");
     }

     return 0;
}
