#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5
void insert(char [], int*, int*, char);
char del(char[], int*, int*);
void display(char [], int, int);
bool qfull(int, int);
bool qempty(int, int);
int main()
{
char q[SIZE];
int f = -1, r = -1;
int ch;
char elem;
for(;;)
{
printf("\nQueue Operations\n");
printf("=====================");
printf("\n1.Qinsert\n2.Qdelete\n3.Qdisplay\n4.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
getchar();
switch(ch)
{
case 1: if(!qfull(f,r))
{
printf("\nEnter an element : ");
scanf("%c", &elem);
insert(q, &f, &r, elem);
}
else
{
printf("\nQueue is Full\n");
}
break;

case 2: if(!qempty(f, r))
{
elem = del(q, &f, &r);
printf("\nDeleted element is %c\n", elem);
}
else
{
printf("\nQueue is Empty\n");
}
break;
case 3: if(!qempty(f, r))
{
printf("\nContents of the Queue is \n");
display(q, f, r);
}
else
{
printf("\nQueue is Empty\n");
}
break;
case 4: exit(0);
default: printf("\nInvalid choice\n");
break;
}
}
return 0;
}
bool qfull(int fr, int rr)
{
if((rr+1) % SIZE == fr)
return true;
else
return false;
}
bool qempty(int fr, int rr)
{
if(fr == -1)
return true;
else
return false;
}
void insert(char queue[], int *f, int *r, char val)
{
if(*r == -1)
{
*f = *f + 1;

*r = *r + 1;
}
else
*r = (*r + 1)%SIZE;
queue[*r] = val;
}
char del(char queue[], int *f, int *r)
{
char el;
el = queue[*f];
if(*f == *r)
{
*f = -1;
*r = -1;
}
else
{
*f = (*f + 1)%SIZE;
}
return el;
}
void display(char queue[], int fr, int rr)
{
int i;
if(fr<=rr)
{
for(i=fr; i<=rr; i++)
{
printf("%c\t", queue[i]);
}
printf("\n");
}
else
{
for(i=fr; i<=SIZE-1; i++)
{
printf("%c\t", queue[i]);
}
for(i=0; i<=rr; i++)
{
printf("%c\t", queue[i]);
}
printf("\n");
}
}
