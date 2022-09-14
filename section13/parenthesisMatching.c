#include <stdlib.h>
#include <stdio.h>

struct Stack
{
    int Size;
    int Top;
    char *S;
};

void Create(struct Stack *St, int size)
{
    St->Size = size;
    St->S = (char *)malloc(St->Size * sizeof(int));
    St->Top = -1;
}

void Push(struct Stack *St, char x)
{
    if (St->Top == St->Size - 1)
        printf("Stack overflow\n");
    else
        St->S[++St->Top] = x;
}

int Pop(struct Stack *St)
{
    int x = -1;

    if (St->Top == -1)
        printf("Stack underflow\n");
    else
    {
        x = St->S[St->Top];
        St->S[St->Top--] = 0;
    }
    return x;
}

int StackTop(struct Stack *St)
{
    int x = -1;

    if (St->Top != -1)
    {
        x = St->S[St->Top];
    }
    return x;
}

int Peek(struct Stack *St, int pos)
{
    int index = St->Top - pos + 1;

    if (index < 0 || index > St->Top)
        return -1;
    else
        return St->S[index];
}

int IsEmpty(struct Stack *St)
{
    if (St->Top == -1)
        return 1;
    else
        return 0;
}

int IsFull(struct Stack *St)
{
    if (St->Top == St->Size - 1)
        return 1;
    else
        return 0;
}

int GetStringLength(char *exp)
{
    int i = 0;

    while (exp[i] != '\0')
        i++;

    return i;
}

// exp-type (((a + b) + (c + d)) / 2)
int IsBalanceForRoundBrackets(char *exp)
{
    int size = 0;

    int length = GetStringLength(exp);

    struct Stack St;
    Create(&St, length);

    for (int i = 0; i < length; i++)
    {
        if (exp[i] == '(')
            Push(&St, exp[i]);
        else if (exp[i] == ')')
        {
            if (IsEmpty(&St))
                return 0;
            else
                Pop(&St);
        }
    }

    if (IsEmpty(&St))
        return 1;

    return 0;
}

// exp type = [ {(a + b) - (c + d)} / 2 ]
int IsBalance(char *exp)
{
    int length = GetStringLength(exp);
    struct Stack St;

    Create(&St, length);

    for (int i = 0; i < length; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            Push(&St, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (IsEmpty(&St))
                return 0;
            else
            {
                if (exp[i] == 41 && StackTop(&St) == 40)
                    Pop(&St);
                else if (exp[i] == 93 && StackTop(&St) == 91)
                    Pop(&St);
                else if (exp[i] == 125 && StackTop(&St) == 123)
                    Pop(&St);
                else
                    return 0;
            }
        }
    }

    if (IsEmpty(&St))
        return 1;
    else
        return 0;
}

int main()
{
    char exp[] = "[{(a+b)+(c+d)}/2]";

    int check = IsBalance(exp);

    if (check)
        printf("balanced\n");
    else
        printf("not balanced\n");

    return 0;
}
