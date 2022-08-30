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

int main()
{
    struct Sparse A;
    struct Sparse B;

    Create(&A);
    printf("Matrix A\n");
    Display(&A);

    Create(&B);
    printf("Matrix B\n");
    Display(&B);

    struct Sparse *S3 = AddSparse(&A, &B);
    printf("Matrix C\n");
    Display(S3);

    return 0;
}