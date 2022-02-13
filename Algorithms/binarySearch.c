
//DO NOT ATTEMPT AN ARRAY SIZE OF MORE THAN 1000000 ON LOW MEMORY PC, IT WILL PROBABLY CRASH DUE TO INSUFFICIENT MEMORY :)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int64_t N = 0; //variable to store the size of the array
int64_t l = 0; //variable used to count the number of operations done to sort the array

void bubbleSort(int64_t arr[]); //bubble sort function
void printArr(int64_t arr[]); //print array function
void swap(int64_t *x, int64_t *y); //swap two values function
void fillRandom(int64_t arr[], int64_t max); //fill array with random numbers from 0 to max
void quickSort(int64_t arr[], int64_t low, int64_t high); //quick sort function

int main() {
    system("clear"); //clear previous console output

    srand(time(NULL)); //set random seed to current(?) time

    printf("Enter number of elements to be generated: ");
    scanf("%lld", &N);

    int64_t *arr = NULL;
    
    int64_t Nlow = 0;
    int64_t Nhigh = 0;

    int64_t target = 0;
    int found = 0;

    int64_t i = 0;
    int64_t k = 0;

    struct timespec fillBegin, fillEnd; 
    struct timespec sortBegin, sortEnd; 
    struct timespec searchBegin, searchEnd; 

    long fillSeconds;
    long fillNanoseconds;
    long double fillElapsed;

    long sortSeconds;
    long sortNanoseconds;
    long double sortElapsed;

    long searchSeconds;
    long searchNanoseconds;
    long double searchElapsed;

    long double totalTime = 0.0;

    printf("Enter number of elements to be generated: ");
    scanf("%lld", &N);

    arr = calloc(N, sizeof(int64_t));

    Nhigh = N - 1;

    clock_gettime(CLOCK_REALTIME, &fillBegin);

        fillRandom(arr, (N * 2));

    clock_gettime(CLOCK_REALTIME, &fillEnd);

    //printf("Elements before sorting: \n");
    //printArr(arr);

    clock_gettime(CLOCK_REALTIME, &sortBegin);
    
        quickSort(arr, 0, N - 1);

    clock_gettime(CLOCK_REALTIME, &sortEnd);

    printf("\n\n\nElements after sorting: \n");
    printArr(arr);

    printf("\n\nEnter number to search: ");
    scanf("%lld", &target);

    clock_gettime(CLOCK_REALTIME, &searchBegin);

        while (Nlow <= Nhigh) {
            k++;
            int Nmid = (Nlow + Nhigh) / 2;

            if (target == arr[Nmid]) {
                target = arr[Nmid];
                i = Nmid;
                found = 1; 
                break;
            }
            else if (target < arr[Nmid]) {
                Nhigh = Nmid - 1;
            } 
            else if (target > arr[Nmid]) {
                Nlow = Nmid + 1;
            }
            else {
                found = 0;
            }
        }

    clock_gettime(CLOCK_REALTIME, &searchEnd);

    if (found == 1) {
        printf("\nTarget element %lld found at index %lld with %lld operations.\n", target, i, k);
    } 
    else {
        printf("\nTarget element %lld not found with %lld operations.\n", target, k);
    }

    fillSeconds = fillEnd.tv_sec - fillBegin.tv_sec;
    fillNanoseconds = fillEnd.tv_nsec - fillBegin.tv_nsec;
    fillElapsed = fillSeconds + fillNanoseconds*1e-9;

    sortSeconds = sortEnd.tv_sec - sortBegin.tv_sec;
    sortNanoseconds = sortEnd.tv_nsec - sortBegin.tv_nsec;
    sortElapsed = sortSeconds + sortNanoseconds*1e-9;

    searchSeconds = searchEnd.tv_sec - searchBegin.tv_sec;
    searchNanoseconds = searchEnd.tv_nsec - searchBegin.tv_nsec;
    searchElapsed = searchSeconds + searchNanoseconds*1e-9;

    totalTime = fillElapsed + sortElapsed + searchElapsed;

    printf("\n\nElements sorted with %lld operations.", l);
    printf("\n\nRandom array fill took: %Lf seconds", fillElapsed);
    printf("\nArray sort took: %Lf seconds", sortElapsed);
    printf("\nArray search took: %Lf seconds", searchElapsed);
    printf("\nTotal operations took: %Lf seconds", totalTime);

    printf("\n\n");
    return 0;
}

void swap(int64_t *x, int64_t *y) { 
    int64_t temp = *x; 
    *x = *y; 
    *y = temp; 
}

void sort(int64_t arr[]) {
    for (int64_t i = 0; i < N; i++) {
        for (int64_t j = 0; j < N; j++) {
            l++;
            if (arr[i] < arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void printArr(int64_t arr[]) {
    for (int64_t i = 0; i < N; i++) {
        printf("%lld", arr[i]);
        if (i != N - 1) {
            printf(", ");
        }
    }
}

void fillRandom(int64_t arr[], int64_t max) {
    for (int64_t i = 0; i < N; i++) {
        arr[i] = (rand() % max) + 1;
    }
}

void quickSort(int64_t arr[], int64_t low, int64_t high) {
    if (low < high) {
        int64_t pivotIndex = 0;

        int64_t pivot = arr[high];

        int64_t i = (low - 1);

        for (int64_t j = low; j < high; j++) {
            l++;
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i + 1], &arr[high]);

        pivotIndex = i + 1;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
