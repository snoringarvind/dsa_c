#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first;

struct Node *Create(int A[], int n)
{
    struct Node *last, *q, *p = NULL;
    p = (struct Node *)malloc(sizeof(struct Node *));
    p->data = A[0];
    p->next = NULL;
    last = p;

    for (int i = 1; i < n; i++)
    {
        q = (struct Node *)malloc(sizeof(struct Node *));
        q->data = A[i];
        q->next = NULL;
        last->next = q;
        last = q;
    }
    last->next = p;

    return p;
}

void Display(struct Node *p)
{
    do
    {
        if (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    } while (first != p);
}

void RDisplay(struct Node *p)
{
    static int flag = 1;
    if (p != first || flag == 1)
    {
        printf("%d ", p->data);
        flag = 0;
        RDisplay(p->next);
    }
}

int Count(struct Node *p)
{
    int c = 0;
    do
    {
        c++;
        p = p->next;
    } while (p != first);
    return c;
}

void Insert(struct Node *p, int element, int index)
{

    if (index < 0 || index > Count(p))
    {
        return;
    }

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = element;

    if (index == 0)
    {
        if (p == NULL)
        {
            t->next = t;
            p = t;
        }
        else
        {
            while (p->next != first)
                p = p->next;

            t->next = first;
            first = t;
            p->next = t;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = 0;

    if (index < 0 || index >= Count(p))
    {
        x = -1;
        return x;
    }

    if (index == 0)
    {
        x = p->data;
        while (p->next != first)
            p = p->next;

        if (p == first)
        {
            free(first);
            first = NULL;
        }
        else
        {
            p->next = first->next;
            free(first);
            first = p->next;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        q = p->next;
        x = q->data;
        p->next = q->next;
        free(q);
    }
    return x;
}


int main()
{
    int A[] = {2, 7, 8, 9, 10};

    first = Create(A, 5);
    int x = Delete(first, 0);
    printf("%d\n", x);
    Display(first);
    return 0;
}