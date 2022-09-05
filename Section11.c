#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
} *first = NULL;

void CreateLinkedList(int A[])
{
    struct Node *last, *p;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->Data = A[0];
    first->Next = NULL;
    last = first;

    for (int i = 1; i < 5; i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->Data = A[i];
        p->Next = NULL;

        last->Next = p;
        last = p;
    }
}

void DisplayLinkedList(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
}

void RDisplayLinkedList(struct Node *p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%d ", p->Data);
    RDisplayLinkedList(p->Next);
}

// using loops
int CountingNodes(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->Next;
    }

    return c;
}

// using recursion
int CountingNodesUsingR(struct Node *p)
{
    if (p == NULL)
        return 0;
    return 1 + CountingNodesUsingR(p->Next);
}

// using loop
void SumOfNodes(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->Data;
        p = p->Next;
    }

    printf("sum = %d\n", sum);
}

// using recursion
int SumOfNodesUsingR(struct Node *p)
{
    if (p == NULL)
        return 0;
    return p->Data + SumOfNodesUsingR(p->Next);
}

// using loop
int Max(struct Node *p)
{
    int max = INT_MIN;
    while (p != NULL)
    {
        if (p->Data > max)
            max = p->Data;
        p = p->Next;
    }
    printf("%d", max);
}
// using recursion
int MaxUsingR(struct Node *p)
{
    int x = 0;
    if (p == NULL)
        return INT_MIN;
    else
    {
        x = MaxUsingR(p->Next);
        if (x > p->Data)
            return x;
        else
            return p->Data;
    }
}

// using loop
struct Node *Search(struct Node *p, int element)
{
    while (p != NULL)
    {
        if (p->Data == element)
            return p;
        p = p->Next;
    }
    return NULL;
}

// using recursion
struct Node *SearchUsingR(struct Node *p, int element)
{
    if (p == NULL)
        return NULL;
    if (p->Data == element)
        return p;
    SearchUsingR(p->Next, element);
}

struct Node *SearchMoveToHead(struct Node *p, int element)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (p->Data == element)
        {
            q->Next = p->Next;
            p->Next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->Next;
    }
    return NULL;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > CountingNodes(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->Data = x;

    if (index == 0)
    {
        t->Next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->Next;
        t->Next = p->Next;
        p->Next = t;
    }
}

int main()
{
    int A[5] = {8, 3, 7, 12, 9};
    CreateLinkedList(A);

    Insert2(first, 3, 69);
    DisplayLinkedList(first);
    return 0;
}