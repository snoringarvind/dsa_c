#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *first = NULL;

struct Node *Create(int A[], int n)
{
    struct Node *p, *q, *last;

    p = (struct Node *)malloc(sizeof(struct Node));
    p->prev = NULL;
    p->data = A[0];
    p->next = NULL;

    last = p;

    for (int i = 1; i < n; i++)
    {
        q = (struct Node *)malloc(sizeof(struct Node));
        q->prev = last;
        q->data = A[i];
        q->next = NULL;

        last->next = q;
        last = q;
    }

    return p;
};

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        p = p->next;
        c++;
    }

    return c;
}

int Insert(struct Node *p, int index, int element)
{

    if (index < 0 || index > Count(first))
    {
        return 0;
    }
    else if (index == 0)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        if (p != NULL)
        {
            t->prev = NULL;
            t->data = element;
            t->next = p;
            p->prev = t;

            first = t;
        }
        else
        {
            t->prev = NULL;
            t->data = element;
            t->next = NULL;

            first = t;
        }
        return 1;
    }
    else
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));

        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        t->prev = p;
        t->data = element;

        if (p->next)
            p->next->prev = t;
        p->next = t;
        return 1;
    }
}

int Delete(struct Node *p, int index)
{
    int x = 0;

    if (index < 0 || index >= Count(p))
    {
        return -1;
    }
    else if (index == 0)
    {
        x = p->data;
        if (p->next)
        {
            first = p->next;
            p->next->prev = NULL;
            free(p);
        }
        else
        {
            free(first);
            first = NULL;
        }
        return x;
    }
    else
    {
        struct Node *q, *t;
        for (int i = 0; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        x = p->data;

        q->next = p->next;

        if (p->next)
        {
            t = p->next;
            t->prev = q;
        }

        free(p);
        return x;
    }
}

// swaping pointers
void Reverse_1(struct Node *p)
{
    struct Node *t = NULL;
    while (p != NULL)
    {
        t = p;
        p = p->next;
        t->next = t->prev;
        t->prev = p;
    }

    first = t;
}

// using sliding pointers
void Reverse_2(struct Node *p)
{
    struct Node *q = NULL;
    struct Node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;

        p = p->next;
        q->next = r;
        q->prev = p;
    }

    first = q;
}

// using recursion;
void Reverse_3(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        Reverse_3(p, p->next);
        p->prev = p->next;
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    int A[] = {2, 4, 6, 8, 10};

    first = Create(A, 5);

    Reverse_4(first);
    // printf("%d\n", x);
    Display(first);

    return 0;
}