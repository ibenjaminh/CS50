#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


void printit(int data[5][5]) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void myclear(int data[5][5]) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            data[i][j] = 0;
        }
    }
}


int main() {
    char sentence[50];
    char firstword[50];
    int x;
    int row, col;
    int args;
    int arr[5][5];

    printf("u # will move the one up # times\n");
    printf("d # will move the one down # times\n");
    printf("l # will move the one left # times\n");
    printf("r # will move the one right # times\n");
    printf("exit will leave\n\n");

    myclear(arr);
    arr[2][2] = 1;
    printit(arr);
    row = 2;
    col = 2;

    for (;;) {

        printf("enter your command> ");

        // empty out the string just to be safe
        strcpy(firstword, "");
        strcpy(sentence, "");

        // suck in a sentence from the user into memory
        fgets(sentence, sizeof(sentence), stdin);

        // suck from our sentence a word followed by two doubles
        args = sscanf(sentence, "%s %d", firstword,  &x);

        // compare the first word to quit
        if (strcmp(firstword, "exit") == 0) {
            printf("goodbye");
            break;
        }
        else if (strcmp(firstword, "u") == 0) {
            if (args < 2) x = 1;
            printf("row is %d col is %d\n", row, col);
            for (int i = 0; i < x; i++) {
                row = abs((row -1) % 5);
                myclear(arr);
                arr[row][col] = 1;
                printit(arr);
            }
        }
        else if (strcmp(firstword, "d") == 0) {
            if (args < 2) x = 1;
            printf("row is %d col is %d\n", row, col);
            for (int i = 0; i < x; i++) {
                row = abs((row + 1) % 5);
                myclear(arr);
                arr[row][col] = 1;
                printit(arr);
            }

        }
        else if (strcmp(firstword, "l") == 0) {
            if (args < 2) x = 1;
            printf("row is %d col is %d\n", row, col);
            for (int i = 0; i < x; i++) {
                col = abs((col + 4) % 5);
                myclear(arr);
                arr[row][col] = 1;
                printit(arr);
            }
        }
        else if (strcmp(firstword, "r") == 0) {
            if (args < 2) x = 1;
            printf("row is %d col is %d\n", row, col);
            for (int i = 0; i < x; i++) {
                col = abs((col + 1) % 5);
                myclear(arr);
                arr[row][col] = 1;
                printit(arr);
            }
        }
        else {
            printf("don't understand that");
        }
    }
    return(0);
}
