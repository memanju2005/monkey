#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
struct polyt
{
int cf,px, py,pz;
struct polyt* next;
};
typedef struct polyt* PTR;
PTR insert(PTR poly, int cf, int px, int py, int pz)
{
PTR cur;
PTR nn = (PTR)malloc(sizeof(struct polyt));
nn->cf = cf;
nn->px = px;
nn->py = py;
nn->pz = pz;
nn->next = NULL;
cur = poly;
while(cur->next != poly)
{
cur = cur->next;
}
cur->next = nn;
nn->next = poly;
return poly;
}
void disp(PTR poly)
{
if (poly->next == poly)
{
printf("Polynomial is empty.\n");
return;
}
PTR cur = poly->next;
do
{
printf("%dx^%dy^%dz^%d ", cur->cf, cur->px, cur->py, cur->pz);
cur = cur->next;
if (cur != poly)
{
printf("+ ");
}
} while (cur != poly);
printf("\n");
}
int evaluate(PTR poly, int x, int y, int z)
{
int result = 0;
if (poly->next == poly)
{
return result;
}
PTR cur = poly->next;
do
{
int termValue = cur->cf;
termValue *= pow(x, cur->px);
termValue *= pow(y, cur->py);
termValue *= pow(z, cur->pz);
result += termValue;
cur = cur->next;
} while (cur != poly);
return result;
}
bool fmatch(PTR p1, PTR p2)
{
bool match = true;
if(p1->px != p2->px)
match = false;
if(p1->py != p2->py)
match = false;
if(p1->pz != p2->pz)
match = false;
return match;
}
PTR add(PTR poly1, PTR poly2, PTR polySum)
{
PTR cur1 = poly1->next;
PTR cur2 = poly2->next;
do
{
polySum = insert(polySum, cur1->cf, cur1->px, cur1->py, cur1->pz);
cur1 = cur1->next;
} while(cur1 != poly1);
do
{
cur1 = polySum->next;
bool matchfound = false;
do
{
if(fmatch(cur1, cur2))
{
cur1->cf += cur2->cf;
matchfound = true;
break;
}
cur1 = cur1->next;
} while(cur1 != polySum);
if(!matchfound)
{
polySum = insert(polySum, cur2->cf, cur2->px, cur2->py, cur2->pz);
}
cur2 = cur2->next;
} while(cur2 != poly2);
return polySum;
}
int main()
{
PTR poly1 = (PTR)malloc(sizeof(struct polyt));
poly1->next = poly1;
PTR poly2 = (PTR)malloc(sizeof(struct polyt));
poly2->next = poly2;
PTR polySum = (PTR)malloc(sizeof(struct polyt));
polySum->next = polySum;
poly1 = insert(poly1, 6, 2, 2, 1);
poly1 = insert(poly1, 4, 0, 1, 5);
poly1 = insert(poly1, 3, 3, 1, 1);
poly1 = insert(poly1, 2, 1, 5, 1);
poly1 = insert(poly1, 2, 1, 1, 3);
// Display the polynomial P(x, y, z)
printf("POLY1(x, y, z) = ");
disp(poly1);
// Read and evaluate the second polynomial POLY2(x, y, z)
// Represent the polynomial P(x, y, z) = xyz + 4x^3yz
poly2 = insert(poly2, 1, 1, 1, 1); // Example term
poly2 = insert(poly2, 4, 3, 1, 1);
// Display the second polynomial POLY2(x, y, z)
printf("POLY2(x, y, z) = ");
disp(poly2);
// Add POLY1(x, y, z) and POLY2(x, y, z) and store the result in POLYSUM(x, y, z)
polySum = add(poly1, poly2, polySum);
// Display the sum POLYSUM(x, y, z)
printf("\nPOLYSUM(x, y, z) = ");
disp(polySum);
// Evaluate POLYSUM(x, y, z) for specific values
int x = 2, y = 1, z = 3;
int res = evaluate(polySum, x, y, z);
printf("\nResult of POLYSUM(%d, %d, %d): %d\n", x, y, z, res);
return 0;
}