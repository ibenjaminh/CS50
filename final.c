//
// Created by ibenj on 6/1/2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*void missing (int arr[], int n) {
    int last = arr[n - 1];

    for (int i = 0; i < last; i++) {
        if (arr[i] != i) {
            printf("%d\n", i);
        }
    }
}*/

void missing(int arr[], int n) {
    int expected = 1;

    for (int i = 0; i < n; i++) {
        while (arr[i] > expected) {
            printf("%d\n", expected);
            expected++;
        }
        expected++;
    }
}
int main() {

    int arr[] = {1, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]); // we have to divide because sizeof gives the size of the array in bytes
    missing(arr, n);

    return 0;

}