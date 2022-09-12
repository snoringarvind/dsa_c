#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};

struct Node *first = NULL;
struct Node *second = NULL;

struct Node *CreateLinkedList(int A[], int n)
{
    struct Node *last, *p, *first;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->Data = A[0];
    first->Next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->Data = A[i];
        p->Next = NULL;

        last->Next = p;
        last = p;
    }

    return first;
}

void DisplayLinkedList(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
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
    return max;
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

void InsertInSortedList(struct Node *p, int element)
{
    struct Node *q = NULL;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node *));
    t->Data = element;
    t->Next = NULL;

    if (p == NULL)
        first = t;
    else
    {
        while (p != NULL && p->Data < element)
        {
            q = p;
            p = p->Next;
        }
        if (first == p)
        {
            t->Next = first;
            first = t;
        }
        else
        {
            t->Next = q->Next;
            q->Next = t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;

    if (index < 0 || index > CountingNodes(p))
    {
        return x;
    }

    if (index == 0)
    {
        first = p->Next;
        x = p->Data;
        free(p);
    }
    else
    {
        int i = 0;
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->Next;
        }

        x = p->Data;
        q->Next = p->Next;

        free(p);
    }
    return x;
}

int isSorted(struct Node *p)
{
    int min = INT_MIN;

    while (p != NULL)
    {
        if (p->Data < min)
        {
            return 0;
        }
        min = p->Data;
        p = p->Next;
    }
    return 1;
}

void RemoveDuplicatedFromSortedLinkedList(struct Node *p)
{
    struct Node *q = p->Next;
    while (q != NULL)
    {
        if (p->Data == q->Data)
        {
            p->Next = q->Next;
            free(q);
            q = p->Next;
        }
        else
        {
            p = q;
            q = q->Next;
        }
    }
}

// using array
void ReverseLinkedList_1(struct Node *p)
{
    int *A = (int *)malloc(CountingNodes(p) * sizeof(int));
    int i = 0;

    while (p != NULL)
    {
        A[i] = p->Data;
        i++;
        p = p->Next;
    }

    i--;

    p = first;

    for (; i >= 0; i--)
    {
        p->Data = A[i];
        p = p->Next;
    }
}

// using pointers
void ReverseLinkedList_2(struct Node *p)
{
    struct Node *q = NULL;
    struct Node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->Next;

        q->Next = r;
    }
    first = q;
}

// using recursion
struct Node *ReverseLinkedList_3(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        ReverseLinkedList_3(p, p->Next);
        p->Next = q;
    }
    else
    {
        first = q;
    }
}

void Concatenate(struct Node *A, struct Node *B)
{
    while (A->Next != NULL)
    {
        A = A->Next;
    }

    A->Next = B;
}

struct Node *Merge(struct Node *first, struct Node *second)
{
    struct Node *third, *last;

    if (first->Data < second->Data)
    {
        third = last = first;
        first = first->Next;
        last->Next = NULL;
    }
    else
    {
        third = last = second;
        second = second->Next;
        last->Next = NULL;
    }

    while (first != NULL && second != NULL)
    {
        if (first->Data > second->Data)
        {
            last->Next = second;
            last = second;
            second = second->Next;
            last->Next = NULL;
        }
        else
        {
            last->Next = first;
            last = first;
            first = first->Next;
            last->Next = NULL;
        }
    }

    if (first != NULL)
        last->Next = first;
    else
        last->Next = second;
    return third;
}

int CheckLoop(struct Node *p)
{
    struct Node *q = p;

    do
    {
        p = p->Next;
        q = q->Next;
        q = q != NULL ? q->Next : NULL;
    } while (p && q && p != q);

    if (p == q)
        return 1;
    else
        return 0;
}

void FindMiddleElement_1(struct Node *p)
{
    int c = 0;
    struct Node *q = p;
    while (p != NULL)
    {
        c++;
        if (c % 2 == 0)
        {
            q = q->Next;
        }
        p = p->Next;
    }

    printf("%d\n", q->Data);
}

void FindMiddleElement_2(struct Node *p)
{
    struct Node *q = p;
    while (q->Next != NULL)
    {
        p = p->Next;
        q = q->Next;
        if (q)
            q = q->Next;
    }

    printf("%d\n", p->Data);
}

int main()
{
    int A[] = {2, 8, 15, 14, 17, 19, 20, 23, 24};
    first = CreateLinkedList(A, 9);

    FindMiddleElement_2(first);
    return 0;
}