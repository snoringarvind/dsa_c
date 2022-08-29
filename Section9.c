#include <stdio.h>

// for diagonal Matrix
struct Matrix
{
    int A[15];
    int n; // sizeofMatrix;
};

// for diagonal Matrix
void SetDiagonal(struct Matrix *m, int i, int j, int x)
{
    if (i == j && i < m->n)
    {
        m->A[i] = x;
    }
};

// for diagonal Matrix
int GetDiagonal(struct Matrix m, int i, int j)
{
    if (i == j && i < m.n)
        return m.A[i];
    else
        return 0;
}

// display it as 2D array
void DisplayDiagonal(struct Matrix m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
};

// for lower triangular matrix, using row mapping
void SetLowerTriangularMatrixUsingR(struct Matrix *m, int i, int j, int x)
{
    i = i + 1;
    j = j + 1;
    if (i >= j && i <= m->n && j <= m->n)
        m->A[(i * (i - 1)) / 2 + (i - j)] = x;
}

int GetLowerTriangularMatrix(struct Matrix *m, int i, int j)
{
    i = i + 1;
    j = j + 1;
    if (i >= j && i <= m->n && j <= m->n)
        return m->A[(i * (i - 1)) / 2 + (i - j)];
    else
        return 0;
}

void DisplayLowerTriangularMatrixUsingR(struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[(i * (i - 1)) / 2 + (i - j)]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

// for lower triangular matrix using column mapping
void SetLowerTriangularMatrixUsingC(struct Matrix *m, int i, int j, int x)
{
    i += 1;
    j += 1;

    if (i >= j && i <= m->n && j <= m->n)
    {
        m->A[(m->n * (j - 1)) - (((j - 2) * (j - 1)) / 2) + (i - j)] = x;
    }
}

int GetLowerTriangularMatrixusingC(struct Matrix *m, int i, int j, int x)
{
    i += 1;
    j += 1;

    if (i >= j && i <= m->n && j <= m->n)
    {
        return m->A[(m->n * (j - 1)) - (((j - 2) * (j - 1)) / 2) + (i - j)];
    }
    else
    {
        return 0;
    }
}

void DisplayLowerTriangularMatrixUsingC(struct Matrix *m)
{
    for (int i = 1; i <= m->n; i++)
    {
        for (int j = 1; j <= m->n; j++)
        {
            if (i >= j)
                printf("%d  ", m->A[(m->n * (j - 1)) - (((j - 2) * (j - 1)) / 2) + (i - j)]);
            else
                printf("%d  ", 0);
        }
        printf("\n");
    }
}

void SetUpperTriangularMatrixUsingR(struct Matrix *m, int i, int j, int x)
{
    i += 1;
    j += 1;
    if (j >= i && i <= m->n && j <= m->n)
    {
        m->A[(m->n * (i - 1)) - (((i - 2) * (i - 1)) / 2) + (j - i)] = x;
    }
}

int GetUpperTriangularMatrixUsingR(struct Matrix *m, int i, int j)
{
    i += 1;
    j += 1;
    if (j >= i && i <= m->n && j <= m->n)
    {
        return m->A[(m->n * (i - 1)) - (((i - 2) * (i - 1)) / 2) + (j - i)];
    }
    else
    {
        return 0;
    }
}

void DisplayUpperTriangularMatrixUsingR(struct Matrix *m)
{
    for (int i = 1; i <= m->n; i++)
    {
        for (int j = 1; j <= m->n; j++)
        {
            if (j >= i)
                printf("%d ", m->A[(m->n * (i - 1)) - (((i - 2) * (i - 1)) / 2) + (j - i)]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

void SetUpperTriangularMatrixUsingC(struct Matrix *m, int i, int j, int x)
{
    i += 1;
    j += 1;
    if (j >= i && i <= m->n && j <= m->n)
    {
        m->A[(j * (j - 1)) / 2 - (i - 1)] = x;
    }
}

int GetUpperTriangularMatrixUsingC(struct Matrix *m, int i, int j)
{
    i += 1;
    j += 1;
    if (j >= i && i <= m->n && j <= m->n)
    {
        return m->A[(j * (j - 1)) / 2 - (i - 1)];
    }
    else
    {
        return 0;
    }
}

void DisplayUpperTriangularMatrixUsingC(struct Matrix *m)
{
    for (int i = 1; i <= m->n; i++)
    {
        for (int j = 1; j <= m->n; j++)
        {
            if (j >= i)
                printf("%d ", m->A[(j * (j - 1)) / 2 - (i - 1)]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    m.n = 5;

    SetUpperTriangularMatrixUsingC(&m, 0, 0, 5);
    SetUpperTriangularMatrixUsingC(&m, 0, 1, 6);
    SetUpperTriangularMatrixUsingC(&m, 0, 2, 7);
    SetUpperTriangularMatrixUsingC(&m, 0, 3, 9);
    SetUpperTriangularMatrixUsingC(&m, 0, 4, 3);

    SetUpperTriangularMatrixUsingC(&m, 1, 1, 23);
    SetUpperTriangularMatrixUsingC(&m, 1, 2, 1);
    SetUpperTriangularMatrixUsingC(&m, 1, 3, 8);
    SetUpperTriangularMatrixUsingC(&m, 1, 4, 4);

    SetUpperTriangularMatrixUsingC(&m, 2, 2, 7);
    SetUpperTriangularMatrixUsingC(&m, 2, 3, 12);
    SetUpperTriangularMatrixUsingC(&m, 2, 4, 15);

    SetUpperTriangularMatrixUsingC(&m, 3, 3, 25);
    SetUpperTriangularMatrixUsingC(&m, 3, 4, 35);

    SetUpperTriangularMatrixUsingC(&m, 4, 4, 15);

    DisplayUpperTriangularMatrixUsingC(&m);

    return 0;
}