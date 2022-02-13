#include <stdio.h>
#include <stdlib.h>

#define N 10

void swap(int *x, int *y);
void sort(int arr[]);
void printArr(int arr[]);

int main() {
    //system("clear");

    int arr[N] = {7,3,8,34,87,90,342,53,75,32};

    printf("Elements before sorting: ");
    printArr(arr);

    printf("\n\nSorting....\n");

    sort(arr);

    printf("\nElements after sorting: ");
    printArr(arr);
    
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