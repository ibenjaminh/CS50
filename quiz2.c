//
// Created by ibenj on 5/30/2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Horse{
    char *horseName;
    char *jockeyName;
    char *jockeyWeight;
    struct Horse *next;
} *horsePtr;

typedef struct Race {
    char name[50];
    char time[100];
    horsePtr horses;
    struct Race *next;
} *racePtr;

void printHorses(horsePtr head) {
    horsePtr current = head;
    while (current != NULL) {
        printf("Horse: %s Jockey: %s Weight: %s\n", current->horseName, current->jockeyName, current->jockeyWeight);
        current = current->next;
    }
    printf("\n");
}
void printRaces(racePtr head) {
    racePtr current = head;
    printf("The races are: \n");
    while (current != NULL) {
        printf(" %s %s\n", current->name, current->time);
        printHorses(current->horses); // Print the horses associated with the current race
        current = current->next;
    }
    printf("\n");
}



racePtr addRace(racePtr head, char *name, char *time, horsePtr horses) {
    racePtr newRace = (racePtr) malloc(sizeof(struct Race));
    strcpy(newRace->name, name);
    strcpy(newRace->time, time);
    newRace->horses = horses; // Assign the list of horses to the race
    newRace->next = head;
    return newRace;
}

horsePtr addHorse(horsePtr head, char *horseName, char *jockeyName, char *jockeyWeight) {
    horsePtr newHorse = (horsePtr) malloc(sizeof(struct Horse));
    newHorse->horseName = horseName;
    newHorse->jockeyName = jockeyName;
    newHorse->jockeyWeight = jockeyWeight;
    newHorse->next = head;
    return newHorse;
}
int main() {
    racePtr head = NULL;
    horsePtr headHorse = NULL;

    headHorse = addHorse(headHorse, "Jimmy", "John", "150");
    headHorse = addHorse(headHorse, "Bobby", "Bob", "160");
    headHorse = addHorse(headHorse, "Tommy", "Tom", "170");

int main() {
    racePtr head = NULL;
    horsePtr headHorse = NULL;

    headHorse = addHorse(headHorse, "Jimmy", "John", "150");
    headHorse = addHorse(headHorse, "Bobby", "Bob", "160");
    headHorse = addHorse(headHorse, "Tommy", "Tom", "170");

    head = addRace(head, "Race 1", "12PM May 30 2024", headHorse);
    head = addRace(head, "Race 2", "1PM May 30 2024", headHorse);
    head = addRace(head, "Race 3", "2PM May 30 2024", headHorse);

    printRaces(head);
    return 0;
}