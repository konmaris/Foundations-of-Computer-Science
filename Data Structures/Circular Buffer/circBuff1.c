#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

int main()
{
    // system("clear");

    node *n1 = (node *)malloc(sizeof(node));
    node *n2 = (node *)malloc(sizeof(node));
    node *n3 = (node *)malloc(sizeof(node));
    node *n4 = (node *)malloc(sizeof(node));
    node *n5 = (node *)malloc(sizeof(node));

    n1->value = 2;
    n1->next = n2;

    n2->value = 4;
    n2->next = n3;

    n3->value = 6;
    n3->next = n4;

    n4->value = 8;
    n4->next = n5;

    n5->value = 10;
    n5->next = n1;

    int i = 0;

    printf("%d: %d, %p -> %p\n", i, n1->value, n1, n1->next);
    i++;
    printf("%d: %d, %p -> %p\n", i, n2->value, n2, n2->next);
    i++;
    printf("%d: %d, %p -> %p\n", i, n3->value, n3, n3->next);
    i++;
    printf("%d: %d, %p -> %p\n", i, n4->value, n4, n4->next);
    i++;
    printf("%d: %d, %p -> %p\n", i, n5->value, n5, n5->next);
    i++;

    return 0;
}