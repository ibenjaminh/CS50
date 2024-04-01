#include <stdio.h>
#include <stdlib.h>

int main() {

     int winner = 21;
     int programmer = 43;
     int player;
     int playerWins = 0;
     int rounds = 0;
     int dealerWins = 0;
     do {

          printf("Player please pick a number: ");
          scanf("%d", &player);

          int diff1 = abs(winner - programmer);
          int diff2 = abs(winner - player);

          if (diff1 < diff2) {
               printf("Dealer has %d. Dealer wins\n", programmer);
               dealerWins++;

          } else if (diff2 < diff1) {
               printf("PLayer has %d. Player wins\n", player);
               playerWins++;
          } else {
               printf("Player and Dealer are equally distant\n");
          }

          rounds++;
     } while (player != 21);

     printf("\n\n\nNumber of hands played: %d", rounds);
     printf("\nDealer won: %d Player won: %d", dealerWins, playerWins);
     printf("\nYou're %d for %d", playerWins, rounds);
     printf("\nCome back to the Bear Fork soon.");


     return 0;
}
