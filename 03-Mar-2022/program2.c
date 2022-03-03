#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

node *List(size_t node_count);
void Push(node **head, int val);
void PrintList(node **head);

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