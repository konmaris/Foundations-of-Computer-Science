#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

node *List(size_t node_count);
void Print(node **head);
node *Push(node **head, int val);
node *Insert(node **head, int index, int val);
node *Delete(node **head, int index);
void DeleteList(node **head);

void emptyLine(size_t count);

int main()
{
    // system("clear");
    node *list = NULL;
    node *temp = NULL;
    size_t listSize = 0;
    size_t n = 0;
    int value = 0;
    int index = 0;

    // ask for list size
    printf("Enter list size: ");
    scanf("%ld", &listSize);

    // create list
    list = List(listSize);

    emptyLine(1); // print 1 empty line

    // print created list
    Print(&list);

    emptyLine(1); // print 1 empty line

    // push element
    printf("Enter value to push: ");
    scanf("%d", &value);

    list = Push(&list, value);

    emptyLine(1); // print 1 empty line

    printf("New head element has value %d and is at position: %p", value, list);

    emptyLine(2); // print 2 empty lines

    // print list after push
    Print(&list);

    emptyLine(1); // print 1 empty line

    // insert n elements
    printf("Enter number of elements to insert: ");
    scanf("%ld", &n);

    emptyLine(1); // print 1 empty line

    for (size_t i = 0; i < n; i++)
    {
        printf("Enter index of new element: ");
        scanf("%d", &index);
        printf("Enter value of new element (%d): ", index);
        scanf("%d", &value);

        emptyLine(1); // print 1 empty line

        temp = Insert(&list, index, value);
        printf("Element with value %d was inserted in position %p", value, temp);
    }

    emptyLine(2); // print 1 empty line

    // print list after insert
    Print(&list);

    emptyLine(1); // print 1 empty line

    // delete specific index element

    printf("Enter index of element to delete: ");
    scanf("%d", &index);

    temp = Delete(&list, index);

    emptyLine(1); // print 1 empty line

    printf("Element at position %p was deleted!", temp);

    emptyLine(2); // print 2 empty lines

    // print list after deletion
    Print(&list);

    // DeleteList(&list);

    free(list);

    emptyLine(1UL);

    if (list != NULL)
    {
        Print(&list);
        printf("List is not NULL!");
    }
    else
    {
        printf("Can't print empty list!");
    }

    if (list != NULL)
    {
        Print(&list);
        printf("List is not NULL!");
    }
    else
    {
        printf("Can't print empty list!");
    }

    return 0;
}

void Print(node **head)
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

node *List(size_t node_count)
{
    node *head = (node *)malloc(node_count * sizeof(node));
    node *current = head;

    for (size_t i = 0; i < node_count && current != NULL; i++)
    {
        printf("Enter element value (%ld): ", i);
        scanf("%d", &(current->value));

        if (i == node_count - 1)
        {
            current->next = NULL;
        }
        else
        {
            current->next = current + sizeof(node);
        }

        current = current->next;
    }

    return head;
}

node *Push(node **head, int val)
{
    node *new = (node *)malloc(sizeof(node));

    new->next = *head;
    new->value = val;

    *head = new;

    return new;
}

node *Insert(node **head, int index, int val)
{
    if (index == 0)
    {
        printf("\nElement cannot be inserted in the first position using the Insert method.\nTry using the push method!\n");
        return NULL;
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
    // node *tail = NULL;
    // node *current = head;
    // node **temp = NULL;

    // for (size_t i = 0; current != NULL; i++)
    // {
    //     if (current->next == NULL)
    //     {
    //         tail = current;
    //     }

    //     current = current->next;
    // }

    // current = head;

    // for (size_t i = 0; current != NULL; i++)
    // {
    //     temp = &current;
    //     current = current->next;
    //     free(temp);
    // }
    free(*head);
}

void emptyLine(size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        printf("\n");
    }
}