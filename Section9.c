#include <stdio.h>
#include <stdlib.h>

// for diagonal Matrix
struct Matrix
{
    int *A;
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
int GetDiagonal(struct Matrix *m, int i, int j)
{
    if (i == j && i < m->n)
        return m->A[i];
    else
        return 0;
}

// display it as 2D array
void DisplayDiagonal(struct Matrix *m)
{
    for (int i = 0; i < m->n; i++)
    {
        for (int j = 0; j < m->n; j++)
        {
            if (i == j)
                printf("%d ", m->A[i]);
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

void DisplayLowerTriangularMatrixUsingR(struct Matrix *m)
{
    for (int i = 1; i <= m->n; i++)
    {
        for (int j = 1; j <= m->n; j++)
        {
            if (i >= j)
                printf("%d ", m->A[(i * (i - 1)) / 2 + (i - j)]);
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

void SetTriDiagonalMatrix(struct Matrix *m, int i, int j, int x)
{
    i += 1;
    j += 1;

    if (i > m->n || j > m->n)
        return;

    if (i - j == 1)
        m->A[i - 2] = x;
    else if (i - j == 0)
        m->A[m->n + 1 + i - 1] = x;
    else if (i - j == -1)
        m->A[2 * (m->n - 1) + i] = x;
}

int GetTriagonalMatrix(struct Matrix *m, int i, int j, int x)
{

    i += 1;
    j += 1;

    if (i - j == 1)
        return m->A[i - 2];
    else if (i - j == 0)
        return m->A[m->n + 1 + i - 1];
    else if (i - j == -1)
        return m->A[2 * (m->n - 1) + i];
    else
        return 0;
}

void DisplayTriagonalMatrix(struct Matrix *m)
{
    for (int i = 1; i <= m->n; i++)
    {
        for (int j = 1; j <= m->n; j++)
        {
            if (i - j == 1)
                printf("%d ", m->A[i - 2]);
            else if (i - j == 0)
                printf("%d ", m->A[m->n + 1 + i - 1]);
            else if (i - j == -1)
                printf("%d ", m->A[2 * (m->n - 1) + i]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

void SetToeplitxMatrix(struct Matrix *m, int i, int j, int x)
{
    i += 1;
    j += 1;

    if (i > m->n || j > m->n)
        return;

    if (i - j < 1)
        m->A[j - i] = x;
    else if (i - j >= 1)
        m->A[m->n + i - j - 1] = x;
}

int GetToeplitxMatrix(struct Matrix *m, int i, int j)
{
    i += 1;
    j += 1;

    if (i - j < 1)
        return m->A[j - i];
    else if (i - j >= 1)
        return m->A[m->n + i - j - 1];
    else
        return 0;
}

void DisplayToeplitxMatrix(struct Matrix *m)
{
    for (int i = 1; i <= m->n; i++)
    {
        for (int j = 1; j <= m->n; j++)
        {
            if (i - j < 1)
                printf("%d ", m->A[j - i]);
            else if (i - j >= 1)
                printf("%d ", m->A[m->n + i - j - 1]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

int main()
{
    int matrixSize = 5;

    struct Matrix m;
    m.n = matrixSize;
    m.A = (int *)malloc(matrixSize * sizeof(int));

    SetDiagonal(&m, 0, 0, 1);
    SetDiagonal(&m, 0, 1, 0);
    SetDiagonal(&m, 0, 2, 0);
    SetDiagonal(&m, 0, 3, 0);
    SetDiagonal(&m, 0, 4, 0);

    SetDiagonal(&m, 1, 0, 0);
    SetDiagonal(&m, 1, 1, 1);
    SetDiagonal(&m, 1, 2, 0);
    SetDiagonal(&m, 1, 3, 0);
    SetDiagonal(&m, 1, 4, 0);

    SetDiagonal(&m, 2, 0, 0);
    SetDiagonal(&m, 2, 1, 0);
    SetDiagonal(&m, 2, 2, 1);
    SetDiagonal(&m, 2, 3, 0);
    SetDiagonal(&m, 2, 4, 0);

    SetDiagonal(&m, 3, 0, 0);
    SetDiagonal(&m, 3, 1, 0);
    SetDiagonal(&m, 3, 2, 0);
    SetDiagonal(&m, 3, 3, 1);
    SetDiagonal(&m, 3, 4, 0);

    SetDiagonal(&m, 4, 0, 0);
    SetDiagonal(&m, 4, 1, 0);
    SetDiagonal(&m, 4, 2, 0);
    SetDiagonal(&m, 4, 3, 0);
    SetDiagonal(&m, 4, 4, 1);

    DisplayDiagonal(&m);

    free(m.A);
    return 0;
}