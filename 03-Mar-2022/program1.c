#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

void printList(node **head);
node *makeList(node **head, size_t node_count);

int main()
{
    system("clear");

    node *n0 = NULL,
         *n1 = NULL,
         *n2 = NULL,
         *n3 = NULL,
         *n4 = NULL,
         *n5 = NULL;

    n0 = (node *)malloc(sizeof(node));
    n1 = (node *)malloc(sizeof(node));
    n2 = (node *)malloc(sizeof(node));
    n3 = (node *)malloc(sizeof(node));
    n4 = (node *)malloc(sizeof(node));

    n0->value = 5;
    n0->next = n1;

    n1->value = 10;
    n1->next = n2;

    n2->value = 15;
    n2->next = n3;

    n3->value = 20;
    n3->next = n4;

    n4->value = 25;
    n4->next = NULL;

    // printf("Node 0\n");
    // printf("=============\n");
    // printf("Position:\t%p\n", &n0);
    // printf("Value:\t\t%d\n", n0->value);
    // printf("Next:\t\t%p\n", n0->next);

    // printf("\n---------------------------------\n\n");

    printList(&n0);

    return 0;
}

void printList(node **head)
{
    node *current = *head;
    int i = 0;

    while (current != NULL)
    {
        printf("Node %d\n", i);
        printf("=============\n");
        printf("Position:\t%p\n", &current);
        printf("Value:\t\t%d\n", current->value);
        printf("Next:\t\t%p\n", current->next);
        printf("\n---------------------------------\n\n");

        current = current->next;
        i++;
    }
}

node *makeList(node **head, size_t node_count)
{
}