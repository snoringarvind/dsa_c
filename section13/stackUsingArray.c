#include <stdlib.h>
#include <stdio.h>

struct Stack
{
    int top;
    int size;
    int *S;
};

void CreateStack(struct Stack *stack)
{
    printf("Enter size\n");
    scanf("%d", &stack->size);
    stack->top = -1;
    stack->S = (int *)malloc(stack->size * sizeof(int));
}

void Display(struct Stack *stack)
{
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->S[i]);
    }
    printf("\n");
}

void Push(struct Stack *stack, int x)
{
    if (stack->top == stack->size - 1)
        printf("stack overflow\n");
    else
        stack->S[++stack->top] = x;
}

int Pop(struct Stack *stack)
{
    int x = -1; 

    if (stack->top == -1)
        printf("stack underflow\n");
    else
    {
        x = stack->S[stack->top];
        stack->S[stack->top--] = 0;
    }
    return x;
}

int StackTop(struct Stack *stack)
{
    int x = -1;

    if (stack->top != -1)
    {
        x = stack->S[stack->top];
    }
    return x;
}

int Peek(struct Stack *stack, int pos)
{
    int index = stack->top - pos + 1;

    if (index < 0 || index > stack->top)
        return -1;
    else
        return stack->S[index];
}

int IsEmpty(struct Stack *stack)
{
    if (stack->top == -1)
        return 0;
    else
        return 1;
}

int IsFull(struct Stack *stack)
{
    if (stack->top == stack->size - 1)
        return 1;
    else
        return 0;
}

int main()
{
    struct Stack S;

    CreateStack(&S);
    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);
    Push(&S, 4);
    Push(&S, 5);
    Push(&S, 6);
    Display(&S);

    return 0;
}