#include <stdio.h>

int main() {

     double money;
     double salesTax = 0.08;
     double iPhone = (500 * salesTax) + 500;
     printf("How much money do you have? $");
     scanf("%lf", &money);

     if (money < iPhone)
     {
          printf("Im sorry, you don't have enough money to purchase this iPhone.");

     }
     else
     {
          printf("Congratulations on your new iPhone purchase!\n");
          money -= iPhone;
          printf("You have $%.2lf left", money);
     }


     return 0;
}
