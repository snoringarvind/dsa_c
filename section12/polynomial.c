#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Poly
{
    int num;
    struct Node *term;
};

void Create(struct Poly *poly)
{
    printf("Enter number of terms\n");
    scanf("%d", &poly->num);

    poly->term = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = poly->term;
    p->next = NULL;
    struct Node *last = NULL;

    for (int i = 0; i < poly->num; i++)
    {
        if (last != NULL)
        {
            p = (struct Node *)malloc(sizeof(struct Node));
            p->next = NULL;
        }

        printf("Enter coeff and exp\n");
        scanf("%d %d", &p->coeff, &p->exp);

        if (last)
            last->next = p;
        last = p;
    }
};

double eval(struct Poly *poly, int x)
{
    double sum = 0;
    while (poly->term != NULL)
    {
        sum += poly->term->coeff * pow(x, poly->term->exp);
        poly->term = poly->term->next;
    };
    return sum;
};

int main()
{
    struct Poly poly;
    Create(&poly);
    double x = eval(&poly, 2);
    printf("%f", x);
    return 0;
}