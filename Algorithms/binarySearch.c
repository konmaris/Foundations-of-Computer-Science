#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

void sort(int arr[]);
void printArr(int arr[]);
void swap(int *x, int *y);

int main() {
    system("clear");

    int arr[N] = {7,3,8,34,87,90,342,53,75,32};
    int Nmid = N/2;
    int target = 0;
    int i = 0;
    int found = 0;
    int k = 0;

    //printf("Nmid is: %d\n", Nmid);

    printf("Elements before sorting: ");
    printArr(arr);

    sort(arr);

    printf("\nElements after sorting: ");
    printArr(arr);

    printf("\n\nEnter number to search: ");
    scanf("%d", &target);

    if (target == arr[Nmid]) {
        target = arr[Nmid];
        i = Nmid;
        found = 1;
        k++;
    } 
    else if (target > arr[Nmid]) {
        for (i = Nmid + 1; i < N; i++) {
            if (target == arr[i]) {
                target = arr[i];
                found = 1;
                k++;
                break;
            }
            k++;
        }
    }
    else if (target < arr[Nmid]) {
        for (i = 0; i < Nmid - 1; i++) {
            if (target == arr[i]) {
                target = arr[i];
                found = 1;
                k++;
                break;
            }
            k++;
        }
    }
    else {
        found = 0;
        k++;
    }

    if (found == 1) {
        printf("\nTarget element %d found at index %d with %d operations.\n", target, i, k);
    } 
    else {
        printf("\nTarget element %d not found with %d operations.\n", target, k);
    }

    printf("\n");
    return 0;
}

void swap(int *x, int *y) { 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

void sort(int arr[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i] < arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void printArr(int arr[]) {
    for (int i = 0; i < N; i++) {
        printf("%d", arr[i]);
        if (i != N - 1) {
            printf(", ");
        }
    }
}