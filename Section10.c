#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int numOfElements;
    struct Element *e;
};

void Create(struct Sparse *S)
{
    printf("Enter dimensions\n");
    scanf("%d %d", &S->m, &S->n);

    printf("Enter number of non zero elements\n");
    scanf("%d", &S->numOfElements);

    S->e = (struct Element *)malloc(S->numOfElements * sizeof(struct Element));

    printf("Enter i,j,x values\n");
    for (int i = 0; i < S->numOfElements; i++)
    {
        scanf("%d%d%d", &S->e[i].i, &S->e[i].j, &S->e[i].x);
        printf("\n");
    }
}

void Display(struct Sparse *S)
{
    int k = 0;
    for (int i = 0; i < S->m; i++)
    {
        for (int j = 0; j < S->n; j++)
        {
            if (i == S->e[k].i && j == S->e[k].j)
            {
                printf("%d ", S->e[k].x);
                k++;
            }
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

// order of matrices should be same to add.
struct Sparse *AddSparse(struct Sparse *A, struct Sparse *B)
{
    int i = 0;
    int j = 0;
    int k = 0;

    if (A->m != B->m || A->n != B->n)
    {
        printf("Order of A and B should be same\n");
        return 0;
    }

    struct Sparse *C = (struct Sparse *)malloc(sizeof(struct Sparse));
    C->m = A->m;
    C->n = A->n;
    C->e = (struct Element *)malloc((A->numOfElements + B->numOfElements) * sizeof(struct Element));

    while (i < A->numOfElements && j < B->numOfElements)
    {
        if (A->e[i].i == B->e[j].i && A->e[i].j == B->e[j].j)
        {
            C->e[k] = A->e[i++];
            C->e[k++].x += B->e[j++].x;
        }
        else if (A->e[i].i == B->e[j].i && A->e[i].j > B->e[j].j)
            C->e[k++] = B->e[j++];
        else if (A->e[i].i == B->e[j].i && A->e[i].j < B->e[j].j)
            C->e[k++] = A->e[i++];
        else if (A->e[i].i > B->e[j].i)
            C->e[k++] = B->e[j++];
        else if (A->e[i].i < B->e[j].i)
            C->e[k++] = A->e[i++];
    }

    // COPY REMAINING ELEMENTS
    for (; i < A->numOfElements; i++)
    {
        C->e[k++] = A->e[i];
    }

    for (; j < B->numOfElements; j++)
    {
        C->e[k++] = B->e[j];
    }

    C->numOfElements = k;

    return C;
}

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *t;
};

struct Poly *CreatePoly(struct Poly *poly)
{
    printf("Enter no. of non-zero terms\n");
    scanf("%d", &poly->n);

    poly->t = (struct Term *)malloc(poly->n * sizeof(struct Term));

    printf("Enter coefficients and powers\n");

    for (int i = 0; i < poly->n; i++)
    {
        scanf("%d %d", &poly->t[i].coeff, &poly->t[i].exp);
    }
};

void DisplayPoly(struct Poly *poly)
{
    for (int i = 0; i < poly->n; i++)
    {
        if (i == poly->n - 1)
            printf("%dx%d", poly->t[i].coeff, poly->t[i].exp);
        else
            printf("%dx%d+", poly->t[i].coeff, poly->t[i].exp);
    }
    printf("\n");
};

struct Poly *AddPoly(struct Poly *p1, struct Poly *p2)
{
    struct Poly *p3 = (struct Poly *)malloc(sizeof(struct Poly));
    p3->t = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < p1->n && j < p2->n)
    {
        if (p1->t[i].exp > p2->t[j].exp)
            p3->t[k++] = p1->t[i++];
        else if (p1->t[i].exp < p2->t[j].exp)
            p3->t[k++] = p2->t[j++];
        else
        {
            p3->t[k] = p1->t[i++];
            p3->t[k++].coeff += p2->t[j++].coeff;
        }
    };

    for (; i < p1->n; i++)
        p3->t[k++] = p1->t[i];

    for (; j < p2->n; j++)
        p3->t[k++] = p2->t[j];

    p3->n = k;
    return p3;
}

int main()
{
    struct Poly p1;
    CreatePoly(&p1);
    DisplayPoly(&p1);

    struct Poly p2;
    CreatePoly(&p2);
    DisplayPoly(&p2);

    struct Poly *p3 = AddPoly(&p1, &p2);
    DisplayPoly(p3);
    return 0;
}