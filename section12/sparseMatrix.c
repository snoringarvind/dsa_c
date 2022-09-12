#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int col;
    int val;
    struct Node *next;
};

struct Sparse
{
    int m; // number of rows;
    int n; // number of cols;
    struct Node *A;
};

void Create(struct Sparse *S1)
{
    printf("Number of rows and cols\n");
    // struct Sparse *S1;
    int a;
    // scanf("%d", &a);
    scanf("%d", &S1->m);
    scanf("%d", &S1->n);

    S1->A = (struct Node *)malloc(S1->m * sizeof(struct Node));

    for (int i = 0; i < S1->m; i++)
    {
        S1->A[i] = *(struct Node *)malloc(sizeof(struct Node));
        struct Node *p = &S1->A[i];
        struct Node *last = NULL;

        for (int j = 0; j < S1->n; j++)
        {
            printf("Enter elements for A[%d][%d]\n", i, j);
            int val = 0;
            scanf("%d", &val);
            if (val != 0)
            {
                if (last != NULL)
                {
                    p = (struct Node *)malloc(sizeof(struct Node));
                }
                p->val = val;
                p->col = j;
                p->next = NULL;
                if (last)
                    last->next = p;
                last = p;
            }
        }
    }
}

void Display(struct Sparse *S1)
{
    for (int i = 0; i < S1->m; i++)
    {
        struct Node *p;
        p = &S1->A[i];

        for (int j = 0; j < S1->n; j++)
        {
            if (p && p->col == j)
            {
                printf("%d ", p->val);
                p = p->next;
            }
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

int main()
{
    struct Sparse S1;
    Create(&S1);
    Display(&S1);
    return 0;
}