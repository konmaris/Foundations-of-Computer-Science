#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

void printList(node head);
node makeList(size_t node_count);

int main()
{
    system("clear");

    node n0 = makeList(10);
    printf("---------------------------------\n\n");

    printList(n0);

    printf("\n\n");

    return 0;
}

void printList(node head)
{
    node *current = &head;
    int i = 0;

    while (current != NULL)
    {
        printf("Node %d\n", i);
        printf("=============\n");
        printf("Position:\t%p\n", current);
        printf("Value:\t\t%d\n", (*current).value);
        printf("Next:\t\t%p\n", (*current).next);
        printf("\n---------------------------------\n\n");

        current = (*current).next;
        i++;
    }
}

node makeList(size_t node_count)
{
    node head, *current = NULL;

    current = &head;

    int i = 0;

    while (i < node_count)
    {
        printf("Enter value for node %d: ", i);
        scanf("%d", &(current->value));
        printf("\n");

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