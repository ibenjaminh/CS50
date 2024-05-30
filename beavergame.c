//
// Created by Izaac Haro on 5/29/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void printArray(char* arr[3][3], int row, int col) {
     for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
               if (i == row && j == col) {
                    printf("%s\t", arr[i][j]);
               } else {
                    printf("#\t");
               }
          }
          printf("\n");
     }
}

void cheatArray (char* arr[3][3]) {
     printf("Here is the beaver's location:\n");
     for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
               printf("%s\t", arr[i][j]);
          }
          printf("\n");
     }
}



int main() {
     int row, col;
     int wins = 0;
     int losses = 0;
     char* beaver[3][3] = {
             {"NOT HERE!", "NOT HERE!", "NOT HERE!"},
             {"NOT HERE!", "FOUND HIM! x_x", "NOT HERE!"},
             {"NOT HERE!", "NOT HERE!", "NOT HERE!"}
     };


     while (1) {


          printf("Welcome to beaver smasher!\n");
          printf("Here in one of these boxes is a beaver. Choose wisely.\n Enter the corresponding row and column # to reveal the beaver's fate (e.g. 2 3)\n");
          printf("#\t#\t#\n#\t#\t#\n#\t#\t#\n");

          printf("Would you like to cheat? (y/n)\n");
          char cheat;
          scanf("%c", &cheat);
          if (cheat == 'y') {
               cheatArray(beaver);
          } else {
               printf("Choose a row and column:\n");

          }

          scanf("%d %d", &row, &col);


          printArray(beaver, row, col);
          if (strcmp(beaver[row][col], "FOUND HIM! x_x") == 0) {
               wins++;
               printf("\n\nCongratulations! You now have %d beaver(s).\n", wins);
          } else {
               losses++;
               printf("\n\nSorry! You now have %d failed opportunitie(s) to catch a beaver.\n", losses);
          }

          printf("Would you like to play again? (y/n)\n");
          char playAgain = 'y';
          scanf("%c", &playAgain);
          if (playAgain == 'n') {
               printf("Thanks for playing! You caught %d beaver(s) and missed %d beaver(s).\n", wins, losses);
               return 0;

          }




     }
}
