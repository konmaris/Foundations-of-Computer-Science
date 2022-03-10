#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

node *createNodes(int size);
void printCircBuff(node **head);

int main()
{
    // system("clear");

    node *cList = createNodes(10);

    printCircBuff(&cList);

    return 0;
}

node *createNodes(int size)
{
    node *head = NULL;
    node *current = NULL;

    head = (node *)malloc(sizeof(node) * size);

    current = head;

    int i = 0;

    while (i < size)
    {
        current->value = 2 * i;

        if (i == size - 1)
        {
            current->next = head;
            // printf("%d: %d, %p, %p\n", i, current->value, current, current->next);
            break;
        }

        current->next = current + sizeof(node);

        // printf("%d: %d, %p, %p\n", i, current->value, current, current->next);

        current = current->next;

        i++;
    }

    return head;
}

void printCircBuff(node **head)
{
    node *current = *head;
    int i = 0;

    while (current != NULL)
    {
        printf("%d: %d, %p, %p\n", i, current->value, current, current->next);
        current = current->next;
        i++;
    }
}