#include <stdio.h>
#include <math.h>
#include <string.h>
void push(int[], int *, int);
int pop(int[], int *);
int main()
{
    int iastack[50], i, op1, op2, res;
    char expr[50], symb;
    int top = -1;
    printf("\nEnter a valid postfix expression : \n");
    scanf("%s", expr);
    for (i = 0; i < strlen(expr); i++)
    {
        symb = expr[i];
        if (isdigit(symb))
        {
            printf("%c",symb - '0');
            push(iastack, &top, symb - '0');
            
        }
        else
        {
            op2 = pop(iastack, &top);
            op1 = pop(iastack, &top);
            switch (symb)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '%':
                res = op1 % op2;
                break;
            case '^':
                res = (int)pow(op1, op2);
                break;
            }
            push(iastack, &top, res);
        }
    }
    res = pop(iastack, &top);
    printf("\nValue of %s expression is : %d\n", expr, res);
    return 0;
}
void push(int Stack[], int *t, int elem)
{
    *t = *t + 1;
    Stack[*t] = elem;
}
int pop(int Stack[], int *t)
{
    int elem;
    elem = Stack[*t];
    *t = *t - 1;
    return elem;
}
