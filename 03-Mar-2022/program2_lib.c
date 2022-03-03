#include <stdio.h>
#include <stdlib.h>
#include "libraries/listImpl.h"

int main()
{
    system("clear");

    node *list1 = List(10);
    int temp = 0, i = 0;
    size_t n = 0;

    printf("\n\n");

    PrintList(&list1);

    printf("\n\n");

    printf("Enter amount of elements to push: ");
    scanf("%zu", &n);

    printf("\n");

    while (i < n)
    {
        printf("Enter element value to push (%d): ", i + 1);
        scanf("%d", &temp);
        Push(&list1, temp);
        i++;
    }

    printf("\n\n");

    PrintList(&list1);

    free(list1);

    system("pause");

    return 0;
}
