
//
// Created by ibenj on 5/30/2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct horseEntry {
    char horseName[50];
    char jockeyName[50];
    int jockeyWeight;
    struct horseEntry *next;
} *horseEntryPtr;

typedef struct races {
    char raceName[50];
    char time[50];
    horseEntryPtr horses;
} races;

void printHorseEntry(horseEntryPtr entry) {
     horseEntryPtr current = entry;
     while (current != NULL) {
               printf("\tHorse Name: %s\n", current->horseName);
               printf("\tJockey Name: %s\n", current->jockeyName);
               printf("\tJockey Weight: %d\n", current->jockeyWeight);
               printf("\n");
               current = current->next;
     }
     printf("\n");
}

void printRaces (races s[], int num) { // passing in the race struct and num to pass in size of arr
     printf("\nRACES:\n\n");
     for (int i = 0; i < num; i++) {
          printf("%s %s\n", s[i].raceName, s[i].time);
            printHorseEntry(s[i].horses); //this passes the horses entry in the race struct which points to the horse struct
     }
     printf("\n");
}

horseEntryPtr addHorseEntry(horseEntryPtr head, const char* name, const char* jockey, int weight) {
     // create new horse entry
     horseEntryPtr newEntry = (horseEntryPtr)malloc(sizeof(struct horseEntry));
     strcpy(newEntry->horseName, name);
     strcpy(newEntry->jockeyName, jockey);
     newEntry->jockeyWeight = weight;
     newEntry->next = NULL;

     // if head is null, return new entry
     if (head == NULL) { // if the list is empty, make this the head
          head = newEntry;
            return head;
     }

     horseEntryPtr current = head; // use current to move through the list while keeping head the same
        while (current->next != NULL) {
            current = current->next;
        }
        // when it reaches NULL (end of list), add the new entry
        current->next = newEntry;
        return head; // head remains the same but the list is updated


}
// classe are the horse entries and students are the races
int main() {
     races racesArr[3];

     // initialize horse entries to null
     for (int i = 0; i < 3; i++) {
          racesArr[i].horses = NULL;
     }

     strcpy(racesArr[0].raceName, "RACE 1");
     strcpy(racesArr[0].time, "10AM May 30 2024");
     racesArr[0].horses = addHorseEntry(racesArr[0].horses, "Jimmy", "John", 150);
     racesArr[0].horses = addHorseEntry(racesArr[0].horses, "Billy", "Bob", 160);

     strcpy(racesArr[1].raceName, "RACE 2");
     strcpy(racesArr[1].time, "11AM May 30 2024");
     racesArr[1].horses = addHorseEntry(racesArr[1].horses, "Sally", "Sue", 140);
     racesArr[1].horses = addHorseEntry(racesArr[1].horses, "Tommy", "Tim", 130);

     strcpy(racesArr[2].raceName, "RACE 3");
     strcpy(racesArr[2].time, "12PM May 30 2024");
     racesArr[2].horses = addHorseEntry(racesArr[2].horses, "Jerry", "Jim", 120);
     racesArr[2].horses = addHorseEntry(racesArr[2].horses, "Garfield", "Garry", 110);

     printRaces(racesArr, 3);


}
