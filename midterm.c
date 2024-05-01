//
// Created by ibenj on 4/30/2024.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// horse array


// exacta function (2 numbers matching the exact order of first 2)
bool exacta(int *myArray, int *userArray) {
    if (myArray[0] == userArray[0] && myArray[1] == userArray[1])
    {
        return true;
    }
    else
        return false;
}


// exacta box function (2 numbers matching the first 2 in any order)
bool exactaBox(int *myArray, int *userArray) {
    if (myArray[0] == userArray[0] && myArray[1] == userArray[1] || myArray[0] == userArray[1] && myArray[1] == userArray[0])
    {
        return true;
    }
    else
        return false;
}



// trifecta function (3 numbers matching the exact order of first 3)
bool trifecta(int *myArray, int *userArray) {
    if (myArray[0] == userArray[0] && myArray[1] == userArray[1] && myArray[2] == userArray[2])
    {
        return true;
    }
    else
        return false;
}


// trifecta box function (3 numbers matching the first 3 in any order)
bool trifectaBox(int *myArray, int *userArray) {
    if (myArray[0] == userArray[0] && myArray[1] == userArray[1] && myArray[2] == userArray[2] ||
    myArray[0] == userArray[1] && myArray[1] == userArray[2] && myArray[2] == userArray[0] ||
    myArray[0] == userArray[2] && myArray[1] == userArray[1] && myArray[2] == userArray[0] ||
    myArray[0] == userArray[0] && myArray[1] == userArray[2] && myArray[2] == userArray[1] ||
    myArray[0] == userArray[1] && myArray[1] == userArray[0] && myArray[2] == userArray[2] ||
    myArray[0] == userArray[2] && myArray[1] == userArray[0] && myArray[2] == userArray[1])
    {
        return true;
    }
    else
        return false;
}


// shuffle array function
void readysetgo(int *myArray, int n) {
     static int init=0;
     time_t t;
     if (!init) {
          srand((unsigned) time(&t));
          init = 1;
     }

     // Loop over array.
     for (int i = 0; i < n; i++) {
          // Get a random index of the array past the current index.
          // ... The argument is an exclusive bound.
          //     It will not go past the array's end.
          int randomValue = i + (rand() % (n - i) );
          // Swap the random element with the present element.
          int randomElement = myArray[randomValue];
          myArray[randomValue] = myArray[i];
          myArray[i] = randomElement;
     }
}


// display shuffled array



int main(void) {

    int balance = 200;

    int exactaBet = 15;
    int exactaBetWin = 150;

    int exactaBoxBet = 10;
    int exactaBoxBetWin = 100;

    int trifectaBet = 20;
    int trifectaBetWin = 250;

    int trifectaBetBox = 18;
    int trifectaBetBoxWin = 180;

    int myArray[] = {1, 2, 3, 4};




    while (1) {

        readysetgo(myArray, 4);
        printf("\n\nTHE WINNING ORDER IS: %d %d %d %d\n\n", myArray[0], myArray[1], myArray[2], myArray[3]);

        printf("Choose an option (Type of bet # #: \n");
        printf("Exacta # #\n");
        printf("Exactabox # #\n");
        printf("Trifecta # # #\n");
        printf("Trifectabox # # #\n");
        printf("Balance \n");
        printf("Exit\n");



        char choice[50];
        char *typeBets;
        int userArray[3];


        fgets(choice, 50, stdin);

        sscanf(choice, "%s %d %d %d", typeBets, &userArray[0], &userArray[1], &userArray[2]);
        printf("Selected Option: %s\n", typeBets);




        if (strcmp(typeBets, "Exacta") == 0) {

            printf("Selected 2 racers: %d %d\n", userArray[0], userArray[1]);
            printf("The winning order is: %d %d %d %d\n", myArray[0], myArray[1], myArray[2], myArray[3]);
            printf("This bet costs $%d\n", exactaBet);
            // if user has enough money to place the bet
            if (balance >= exactaBet) {
                 balance -= exactaBet;
                 // call exacta function
                 if (exacta(myArray, userArray)) {
                      printf("You won the exacta bet! Here is your $%d!\n", exactaBetWin);
                      balance += exactaBetWin;
                 }
                 else {
                      printf("You lost the exacta bet\n");
                 }
            }
            else
            {
                 printf("Not enough money\n");
            }

        }


        else if (strcmp(typeBets, "Exactabox") == 0) {
            printf("Selected 2 racers: %d %d\n", userArray[0], userArray[1]);
            printf("The winning order is: %d %d %d %d\n", myArray[0], myArray[1], myArray[2], myArray[3]);
            printf("This bet costs $%d\n", exactaBoxBet);
            // if user has enough money to place the bet
            if (balance >= exactaBoxBet) {
                 balance -= exactaBoxBet;
                 // call exacta box function
                 if (exactaBox(myArray, userArray)) { // if function is returns TRUE
                      printf("You won the exacta box bet! Here is your $%d!\n", exactaBoxBetWin);
                      balance += exactaBoxBetWin;
                 }
                 else { // If it returns FALSE
                      printf("You lost the exacta box bet\n");
                 }
            }
            else {
                 printf("Not enough money\n");
            }
        }


        else if (strcmp(typeBets, "Trifecta") == 0) {
            printf("Selected 3 racers: %d %d %d\n", userArray[0], userArray[1], userArray[2]);
            printf("The winning order is: %d %d %d %d\n", myArray[0], myArray[1], myArray[2], myArray[3]);
            printf("This bet costs $%d\n", trifectaBet);
            // if user has enough money to place the bet
            if (balance >= trifectaBet) {
                 balance -= trifectaBet; // subtract the bet amount from the balance

                 // call trifecta function
                 if (trifecta(myArray, userArray)) {
                      printf("You won the trifecta bet! Here is your $%d!\n", trifectaBetWin);
                      balance += trifectaBetWin;
                 }
                 else
                      printf("You lost the trifecta bet.\n");
            }
            else
                 printf("Not enough money!\n");
        }



        else if (strcmp(typeBets, "Trifectabox") == 0) {
            printf("Selected 3 racers: %d %d %d\n", userArray[0], userArray[1], userArray[2]);
            printf("The winning order is: %d %d %d %d\n", myArray[0], myArray[1], myArray[2], myArray[3]);
            printf("This bet costs $%d\n", trifectaBetBox);
            if (balance >= trifectaBet) {
                 balance -= trifectaBet;

                 // call trifecta box func
                 if (trifectaBox(myArray, userArray))
                 {
                      printf("You won the trifecta box bet! Here is your $%d!\n", trifectaBetBoxWin);
                      balance += trifectaBetBoxWin;
                 }
                 else
                      printf("You lost the trifecta box bet.\n");
            }
            else
                 printf("Not enough money!");
        }

        else if (strcmp(typeBets, "Balance") == 0) {
            printf("Your balance is: $%d\n", balance);
        }


        else if (strcmp(typeBets, "Exit") == 0) {
            printf("Exiting\n");
            break;
        }

        else {
            printf("Invalid choice\n");
        }
    }

}