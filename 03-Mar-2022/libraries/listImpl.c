#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

void PrintList(node **head)
{
    node *current = *head;
    int i = 1;

    printf(" #\t| Value\t\t| Position\t\t| Next Position\n");
    printf("--------|---------------|-----------------------|----------------\n");

    while (current != NULL)
    {
        printf(" %d\t| %d\t\t| %p\t| %p\n", i, current->value, current, current->next);
        current = current->next;
        i++;
    }
}

node *List(size_t node_count)
{
    node *head = NULL, *current = NULL;
    head = (node *)malloc(node_count * sizeof(node));

    current = head;

    int i = 0;

    while (i < node_count)
    {
        printf("Enter element value (%d): ", i + 1);
        scanf("%d", &(current->value));

        if (i == node_count - 1)
        {
            current->next = NULL;
            break;
        }
        else
        {
            current->next = current + sizeof(node);
        }

        current = current + sizeof(node);
        i++;
    }

    return head;
}

void Push(node **head, int val)
{
    node *new = (node *)malloc(sizeof(node));

    new->next = *head;
    new->value = val;

    *head = new;
}