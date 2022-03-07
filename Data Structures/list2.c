#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CLEAR "clear"

typedef struct Node
{
    int value;
    struct Node *next;
} node;

void Print(node **head);                       // print list
node *Push(node **head, int val);              // insert at first position
node *Tail(node **head, int val);              // insert at tail
node *Insert(node **head, int index, int val); // insert a specific position
node *Delete(node **head, int index);          // delete at specific position
void DeleteList(node **head);                  // delete the entire list

void emptyLine(size_t count);

int main()
{
    system(CLEAR);

    node *list = NULL;
    node *temp = NULL;

    int option = 0;
    char delOption = ' ';

    int index = 0;
    int value = 0;

    while (0 != 1)
    {
        printf("1.\tPush node\n");
        printf("2.\tTail node\n");
        printf("3.\tInsert node \n");
        printf("4.\tPrint list\n");
        printf("5.\tDelete node\n");
        printf("6.\tDelete list\n");
        printf("7.\tQuit\n");

        printf("\nChoose an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system(CLEAR);
            printf("Enter value to push: ");
            scanf("%d", &value);
            temp = Push(&list, value);
            emptyLine(1);
            printf("Element with value \"%d\" was pushed at position [%p].", value, temp);
            emptyLine(2);
            break;
        case 2:
            system(CLEAR);
            printf("Enter value to tail: ");
            scanf("%d", &value);
            temp = Tail(&list, value);
            emptyLine(1);
            printf("Element with value \"%d\" was tailed at position [%p].", value, temp);
            emptyLine(2);
            break;
        case 3:
            system(CLEAR);
            printf("Enter index to insert to: ");
            scanf("%d", &index);
            printf("Enter value to insert at index (%d): ", index);
            scanf("%d", &value);
            temp = Insert(&list, index, value);
            emptyLine(1);
            printf("Element with value \"%d\" was inserted at position [%p] and index %d.", value, temp, index);
            emptyLine(2);
            break;
        case 4:
            system(CLEAR);
            Print(&list);
            emptyLine(2);
            break;
        case 5:
            system(CLEAR);
            printf("Enter index of element to delete: ");
            scanf("%d", &index);
            temp = Delete(&list, index);
            emptyLine(1);
            printf("Element at index %d and position [%p] was deleted.", index, temp);
            emptyLine(2);
            break;
        case 6:
            system(CLEAR);
            while (1 != 0)
            {
                printf("Are you sure you want to delete the entire list? (y/n): ");
                scanf(" %c", &delOption);
                delOption = tolower(delOption);
                if (delOption == 'y')
                {
                    emptyLine(1);
                    DeleteList(&list);
                    emptyLine(2);
                    break;
                }
                else if (delOption == 'n')
                {
                    emptyLine(1);
                    break;
                }
                else
                {
                    printf("Choose either yes (y/Y) or no (n/N)!");
                    emptyLine(2);
                }
            }
            break;
        case 7:
            emptyLine(1);
            printf("Goodbye!");
            emptyLine(2);
            return 0;
            break;

        default:
            system(CLEAR);
            printf("Please choose an option from 1-7!");
            emptyLine(2);
            break;
        }
    }

    return -1;
}

void Print(node **head)
{
    if (*head != NULL)
    {
        node *current = *head;

        printf(" #\t| Value\t\t| Position\t\t| Next Position\n");
        printf("--------|---------------|-----------------------|----------------\n");

        for (size_t i = 0; current != NULL; i++)
        {
            printf(" %ld\t| %d\t\t| %p\t| %p\n", i, current->value, current, current->next);
            current = current->next;
        }
    }
    else
    {
        printf("Cannot print empty list!");
    }
}

node *Push(node **head, int val)
{
    node *new = (node *)malloc(sizeof(node));

    new->next = *head;
    new->value = val;

    *head = new;

    return new;
}

node *Tail(node **head, int val)
{
    if (*head == NULL)
    {
        return NULL;
    }

    node *new = (node *)malloc(sizeof(node));
    node *current = *head;

    while (current != NULL)
    {
        if (current->next == NULL)
        {
            current->next = new;
            new->value = val;
            new->next = NULL;
            break;
        }
        current = current->next;
    }

    return new;
}

node *Insert(node **head, int index, int val)
{
    if (index == 0)
    {
        node *new = Push(&(*head), val);
        return new;
    }

    node *new = (node *)malloc(sizeof(node));

    node *prevPos = *head;

    for (int i = 0; i < index - 1; i++)
    {
        prevPos = prevPos->next;
    }

    new->next = prevPos->next;
    new->value = val;

    prevPos->next = new;

    return new;
}

node *Delete(node **head, int index)
{
    node *prevPos = *head;
    node *currPos = *head;

    for (int i = 0; i < index - 1; i++)
    {
        prevPos = prevPos->next;
    }

    for (int i = 0; i < index; i++)
    {
        currPos = currPos->next;
    }

    prevPos->next = currPos->next;

    free(currPos);

    return currPos;
}

void DeleteList(node **head)
{
    node *current = *head;
    node *next = NULL;

    if (*head == NULL)
    {
        printf("Cannot delete empty list!");
        return;
    }

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
    printf("List deleted successfully!");
}

void emptyLine(size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        printf("\n");
    }
}