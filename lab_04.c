#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define STK_SIZE 10
void fnPush(char [], int*, char);
char fnPop(char [], int*);
int fnPrecd(char);
int main()
{
int i, j=0;
char acExpr[50], acStack[50], acPost[50], cSymb;
int top = -1;
printf("\nEnter a valid infix expression : \n");
scanf("%s", acExpr);
fnPush(acStack, &top, '#');
for(i=0;acExpr[i]!='\0'; ++i)
{
cSymb = acExpr[i];
if(isalnum(cSymb))
{
acPost[j++] = cSymb;
}
else if(cSymb == '(')
{
fnPush(acStack, &top, cSymb);
}
else if(cSymb == ')')
{
while(acStack[top] != '(')

{
acPost[j++] = fnPop(acStack, &top);
}
fnPop(acStack, &top);
}
else
{
while(fnPrecd(acStack[top]) >= fnPrecd(cSymb))
{
if((cSymb == '^') && (acStack[top] == '^'))
break;
acPost[j++] = fnPop(acStack, &top);
}
fnPush(acStack, &top, cSymb);
}
}
while(acStack[top] != '#')
{
acPost[j++] = fnPop(acStack, &top);
}
acPost[j] = '\0';
printf("\nInfix Expression is :%s\n", acExpr);
printf("\nPostfix Expression is :%s\n", acPost);
return 0;
}
void fnPush(char Stack[], int *t , char elem)
{
*t = *t + 1;
Stack[*t] = elem;
}
char fnPop(char Stack[], int *t)
{
char elem;
elem = Stack[*t];
*t = *t -1;

return elem;
}
int fnPrecd(char ch)
{
int iPrecdVal;
switch(ch)
{
case '#' : iPrecdVal = -1; break;
case '(' : iPrecdVal = 0; break;
case '+' :
case '-' : iPrecdVal = 1; break;
case '%' :
case '*' :
case '/' : iPrecdVal = 2; break;
case '^' : iPrecdVal = 3; break;
}
return iPrecdVal;
}
