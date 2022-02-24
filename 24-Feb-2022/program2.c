#include <stdio.h>
#include <stdlib.h>

int main()
{
    //system("clear");

    int arr[10] = {5, 8, 23, 76, 43, 87, 21, 4, 8, 22};
    int* pArr[10];

    for(int i = 0; i < sizeof(*pArr)/sizeof(*(pArr + i)); i++)
    {
        *(pArr + i) = &arr[i];
    }

    printf("Memory address of first array element: %p\n\n", arr);
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("Integer at index %d has a value of %d and is at position %p\n", i, *(arr + i), pArr + i);
    }

    return 0;
}