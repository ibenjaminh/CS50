//
// Created by ibenj on 4/30/2024.
//
#include <stdio.h>
#include <stdbool.h>
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
for (int i = 0; i < 4; i++) {
     int randomIndex = rand() % 4;
     int temp = myArray[i];

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
    int userArray[3];

    int choice;

    while (1) {
        printf("Choose an option: \n");
        printf("1. Bet Exacta\n");
        printf("2. Bet Exacta Box\n");
        printf("3. Bet Trifecta\n");
        printf("4. Bet Trifecta Box\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("Selected Exacta\nEnter 2 numbers: ");
            scanf("%d %d", &userArray[0], &userArray[1]);

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


        else if (choice == 2) {
            printf("Selected Exacta Box\nEnter 2 numbers: ");
            scanf("%d %d", &userArray[0], &userArray[1]);

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


        else if (choice == 3) {
            printf("Selected Trifecta\nEnter 3 numbers: ");
            scanf("%d %d %d", &userArray[0], &userArray[1], &userArray[2]);

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



        else if (choice == 4) {
            printf("Selected Trifecta Box\nEnter 3 numbers: ");
            scanf("%d %d %d", &userArray[0], &userArray[1], &userArray[2]);

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



        else if (choice == 5) {
            printf("Exiting\n");
            break;
        }

        else {
            printf("Invalid choice\n");
        }
    }

}