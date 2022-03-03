#ifndef _LISTIMPL_H
#define _LISTIMPL_H

struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node node;

extern void PrintList(node **head);

extern node *List(size_t node_count);

extern void Push(node **head, int val);

#endif