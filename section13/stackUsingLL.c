#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Top = NULL;

void Push(int x)
{

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));

    if (p == NULL)
    {
        printf("stack overflow\n");
    }
    else
    {
        p->data = x;
        p->next = Top == NULL ? NULL : Top;
        Top = p;
    }
}

void Pop()
{
    struct Node *q = Top;

    if (Top == NULL)
        printf("stack underflow\n");
    else
    {
        Top = q->next;
        free(q);
        q = NULL;
    }
}

int isEmpty()
{
    if (Top == NULL)
        return 1;
    else
        return 0;
}

int isFull()
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    if (q == NULL)
        return 1;
    else
        return 0;
}

int peek(int pos)
{
    struct Node *p = Top;
    for (int i = 0; i < pos - 1 && p != NULL; i++)
    {
        p->next = p;
    }

    if (p == NULL)
        return -1;
    else
        return p->data;
}

int stackTop()
{
    struct Node *p = Top;

    if (p == NULL)
        return -1;
    else
        return p->data;
}

int main()
{

    Push(1);
    Push(2);
    Push(3);
    Push(4);
    printf("%d", stackTop());
    Pop();
    printf("%d", stackTop());
    return 0;
}