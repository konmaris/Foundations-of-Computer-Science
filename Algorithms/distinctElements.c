/*-----------------------------------------*/
/*              Instructions               */
/*         ----------------------          */
/*  1. If you want to test the algorithm   */
/*     with the sample data, don't change  */
/*     anything.                           */
/*                                         */
/*  2. If you want to use your own array   */
/*     length and input your own elements, */
/*     just uncomment anything that says   */
/*     "UNCOMMENT..."                      */
/*-----------------------------------------*/

//Written by Maris Konstantinos

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y); //declare swap function, used to swap values inside of the bubble sort function
void bubbleSort(int arr[], int n); //declare bubble sort function, used to sort the elements of an array
void printArr(int arr[], int n); //declare print array function, used to print the elements of an array
int countDistinct(int arr[], int n); //declare count distinct function, used to count the distinct elements of an array
void printDistinct(int arr[], int count, int positions[]); //declare print distinct function, used to print the distinct elements of an array
void printTimesAppearedTable(int arr[], int times[], int positions[], int count); //used to print a table that shows us each distinct element and how many times did it appear on the array

int main() {
    system("clear"); //clear previous console output

    int n = 0; //used to store the length of the array
    int *arr; //pointer to dynamically store the array
    int *distinctPositions; //pointer to dynamically store the indices of distinct elements later
    int *timesAppeared; //pointer to dynamically store how many times has each distinct element appeared on the list
    int k = 0; //used as an index for storing distinct elements' positions to distinctPositions pointer array later 
    int count = 0; //used to store distinct elements count
    double distinctPercentage = 0; //used to store the percentage of distinct elements on the list

    //SAMPLE ARRAY LENGTH, COMMENT OUT TO USE CUSTOM LENGTH AND INPUT BELOW
    n = 12;

    // UNCOMMENT BOTH TO INPUT YOUR OWN VALUES
    //printf("\n Enter number of items to be tested: ");
    //scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));

    //SAMPLE ARRAY ELEMENTS, COMMENT OUT TO USE THE INPUT BELOW
    arr[0] = 5;
    arr[1] = 8;
    arr[2] = 6;
    arr[3] = 8;
    arr[4] = 5;
    arr[5] = 4;
    arr[6] = 8;
    arr[7] = 5;
    arr[8] = 5;
    arr[9] = 8;
    arr[10] = 4;
    arr[11] = 5;

    // UNCOMMENT TO INPUT YOUR OWN VALUES
    //printf("\n");

    /* UNCOMMENT TO INPUT YOUR OWN VALUES
    for (int i = 0; i < n; i++) {
        printf(" Enter value for element no. %d: ", i);
        scanf("%d", &arr[i]);
    }
    */
    
    //print element count
    printf("\n Number of elements: %d\n", n);

    //print elements before sort
    printf("\n Elements before sort:\t");
    printArr(arr, n);

    //sort elements
    bubbleSort(arr, n);

    //print elements after sort
    printf("\n Elements after sort:\t");
    printArr(arr, n);

    //count distinct elements
    count = countDistinct(arr, n);

    //calculate distinct elements percentage
    distinctPercentage = (double)count / n * 100;

    /*
        allocate enough memory to dynamically create two arrays, 
        one to store the positions of the distinct elements on the 
        initial array and another one to store how many times has 
        each distinct element appeared on the initial array.
    */
   
    distinctPositions = (int*) malloc(count * sizeof(int));
    timesAppeared = (int*) malloc(count * sizeof(int));
    
    //find and store the positions of the distinct elements on the distinctPositions array
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[i + 1]) {
            distinctPositions[k] = i;
            k++;
        } 
    }

    //find and store how many times each distinct element has appeared on the array on the timesAppeared array
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[distinctPositions[i]]) {
                timesAppeared[i]++;
            }
        }
    }

    //print final results if the distinct count is not zero, else prompt user that no distinct item exists
    if (count != 0) {
        printf("\n\n Number of distinct elements: \t%d", count);
        printDistinct(arr, count, distinctPositions);
        printf("\n Distinct percentage: \t\t%.2lf%%", distinctPercentage);
        printTimesAppearedTable(arr, timesAppeared, distinctPositions, count);
    } else {
        printf("\n\n No distinct element exists on the array!");
    }

    printf("\n\n");

    return 0;
}

//used to swap two values, takes *x and *y, pointers to the 2 values, as arguments 
void swap(int *x, int *y) { 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

//used to bubble sort an array of integer elements
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

//used to print the elements of an array
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
}

//used to count the distinct elements of an array
int countDistinct(int arr[], int n) {
    int count = 0; //variable to store the count of distinct elements
    int k = 0; //variable used to check the total 

    //for loop to find the count of distinct items
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[i + 1]) {
            count++;
        }    
    }

    /* 
        for loop used to find a value named "k" that if we divide it by the array's
        length and it returns its square root (e.g. 25/5 = 5 or sqrt(25) = 5), 
        it means that all the elements inside of the array are the same, 
        though no distinct element exists .
    */

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                k++;
            }
        }
    }

    k /= n; //divide by the array's length
    
    //if k is equal to the array length return that 0 distinct elements exist, else return the count calculated above
    if (k == n) {
        return 0;
    } else {
        return count;
    }
}

//used to print the distinct elements only
void printDistinct(int arr[], int count, int positions[]) {
    printf("\n Distinct elements: \t\t");
    for (int i = 0; i < count; i++) {
        printf("%d", arr[positions[i]]);
        if (i != count - 1) {
            printf(", ");
        }
    }
}

//used to print a table that shows us each distinct element and how many times did it appear on the array
void printTimesAppearedTable(int arr[], int times[], int positions[], int count) {
    printf("\n\n┌———————————————┰————————————————┐");
    printf("\n| Element\t| Times appeared |");
    printf("\n|———————————————┿————————————————|");
    for (int i = 0; i < count; i++) {
        printf("\n| %d\t\t| %d times\t |", arr[positions[i]], times[i]);
    }
    printf("\n└———————————————┸————————————————┘");
}