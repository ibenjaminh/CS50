//
// Created by ibenj on 4/30/2024.
//
#include <stdio.h>

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
bool trifecta(int *myArray, int *userArray) {
    if (myArray[0] == userArray[0] && myArray[1] == userArray[1] && myArray[2] == userArray[2] || myArray[0] == userArray[1] && myArray[1] == userArray[2] && myArray[2] == userArray[0] || myArray[0] == userArray[2] && myArray[1] == userArray[0] && myArray[2] == userArray[1] ||)
}


// shuffle array function



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
        printf("5. Exit\n")

        scanf("%d", &choice);

        if (choice == 1) {
            printf("Selected Exacta\nEnter 2 numbers: ");
            scanf("%d %d", &userArray[0], &userArray[1]);
            exacta();
        }
        else if (choice == 2) {
            printf("Selected Exacta Box\nEnter 2 numbers: ");
            scanf("%d %d", &userArray[0], &userArray[1]);
            exactaBox();
        }
        else if (choice == 3) {
            printf("Selected Trifecta\nEnter 3 numbers: ");
            scanf("%d %d %d", &userArray[0], &userArray[1], &userArray[2]);
            trifecta();
        }
        else if (choice == 4) {
            printf("Selected Trifecta Box\nEnter 3 numbers: ");
            scanf("%d %d %d", &userArray[0], &userArray[1], &userArray[2]);
            trifectaBox();
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