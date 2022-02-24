#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

void push(node** head, int data);
void printList(node** head);

int main()
{
    // system("clear");


    node n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, *head;

    head = &n1;

    n1.value = 10;
    n1.next = &n2;

    n2.value = 20;
    n2.next = &n3;

    n3.value = 30;
    n3.next = &n11;

    n11.value = 110;
    n11.next = &n4;

    n4.value = 40;
    n4.next = &n5;

    n5.value = 50;
    n5.next = &n6;

    n6.value = 60;
    n6.next = &n7;

    n7.value = 70;
    n7.next = &n8;

    n8.value = 80;
    n8.next = &n9;

    n9.value = 90;
    n9.next = &n10;

    n10.value = 100;
    n10.next = NULL;

    // printf("\n\nNodes: \n");
    // printf("\n=============================================\n");
    // printf(" Value    | Current        | Next \n");
    // printf("----------|----------------|-----------------\n");
    // printf(" %d       | %p | %p\n", n1.value, &n1, n1.next);
    // printf(" %d       | %p | %p\n", n2.value, &n2, n2.next);
    // printf(" %d       | %p | %p\n", n3.value, &n3, n3.next);
    // printf(" %d      | %p | %p\n", n11.value, &n11, n11.next);
    // printf(" %d       | %p | %p\n", n4.value, &n4, n4.next);
    // printf(" %d       | %p | %p\n", n5.value, &n5, n5.next);
    // printf(" %d       | %p | %p\n", n6.value, &n6, n6.next);
    // printf(" %d       | %p | %p\n", n7.value, &n7, n7.next);
    // printf(" %d       | %p | %p\n", n8.value, &n8, n8.next);
    // printf(" %d       | %p | %p\n", n9.value, &n9, n9.next);
    // printf(" %d      | %p | %p\n", n10.value, &n10, n10.next);

    printList(&head);

    push(&head, 511);

    printList(&head);

    return 0;
}

void push(node** head, int data)
{
    //pointer because is also new head
    node *newNode = (node*) malloc(sizeof(node)); //is also new head

    //set new node data to the data parameter
    newNode->value = data;

    //set new node next node to the previous head
    newNode->next = *head;
    
    //set current head to the new node
    *head = newNode;
}

void printList(node** head)
{
    node *ptr = *head;
    int i = 0;

    printf("[\n");

    while(ptr != NULL)
    {
        printf("  Item %d: %d, %p\n", i, ptr->value, ptr->next);
        ptr = ptr->next;
        i++;
    }

    printf("]\n");
}