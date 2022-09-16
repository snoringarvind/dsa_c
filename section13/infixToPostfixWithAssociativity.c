#include <stdlib.h>
#include <stdio.h>

struct StackChar
{
    int Size;
    int Top;
    char *S;
};

void Create(struct StackChar *St, int size)
{
    St->Size = size;
    St->S = (char *)malloc(St->Size * sizeof(int));
    St->Top = -1;
}

void Push(struct StackChar *St, char x)
{
    if (St->Top == St->Size - 1)
        printf("Stack overflow\n");
    else
        St->S[++St->Top] = x;
}

int Pop(struct StackChar *St)
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

int StackTop(struct StackChar *St)
{
    int x = -1;

    if (St->Top != -1)
    {
        x = St->S[St->Top];
    }
    return x;
}

int GetStringLength(char *exp)
{
    int i = 0;

    while (exp[i] != '\0')
        i++;

    return i;
}

int IsEmpty(struct StackChar *St)
{
    if (St->Top == -1)
        return 1;
    else
        return 0;
}

int GetOutStackPrecedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
    return 0;
}

int GetInStackPrecedence(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    return 0;
}

int checkOperand(char x)
{
    if (x == '+' || x == '-' || x == '/' || x == '*' || x == '^' || x == '(' || x == ')')
        return 0;
    else
        return 1;
}

// convert infix to postfix
char *Convert(char *exp)
{
    struct StackChar St;
    int length = GetStringLength(exp);
    Create(&St, length);

    // length +1 for '\0';
    char *postfix = (char *)malloc(length + 1 * sizeof(int));

    int i = 0;
    int j = 0;
    while (exp[i] != '\0')
    {
        if (checkOperand(exp[i]))
        {
            postfix[j++] = exp[i];
            i++;
        }
        else
        {
            if (IsEmpty(&St) || GetOutStackPrecedence(exp[i]) > GetInStackPrecedence(StackTop(&St)))
            {
                Push(&St, exp[i]);
                i++;
            }
            else
            {
                if (StackTop(&St) == '(' && exp[i] == ')')
                {
                    Pop(&St);
                    i++;
                }
                else
                    postfix[j++] = Pop(&St);
            }
        }
    };

    while (!IsEmpty(&St))
    {
        postfix[j++] = Pop(&St);
    };

    postfix[j++] = '\0';

    return postfix;
}

double eval()
{
}

int main()
{

    char exp[] = "((a+b)*c)-d^e^f";
    char *postfix = Convert(exp);
    int i = 0;
    while (postfix[i] != '\0')
    {
        printf("%c ", postfix[i]);
        i++;
    };
    return 0;
}