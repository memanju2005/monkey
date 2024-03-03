#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char usn[11], name[40], prog[4];
    int sem;
    char ph[11];
    struct node *link;
};
typedef struct node *PTR;
PTR get(void);
void freeN(PTR);
PTR insrear(PTR);
PTR delfront(PTR);
PTR insfront(PTR);
PTR delrear(PTR);
void disp(PTR);
int main()
{
    PTR first = NULL;
    int ch, num, i;
    printf("\nEnter the number of Students N : ");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        printf("\nEnter Data for Node %d :\n", i + 1);
        first = insfront(first);
    }
    for (;;)
    {
        printf("\nQUEUE OPERATIONS\n");
        printf("====================");
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            first = insfront(first);
            break;
        case 2:
            first = insrear(first);
            break;
        case 3:
            first = delfront(first);
            break;
        case 4:
            first = delrear(first);
            break;
        case 5:
            disp(first);
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}
PTR get()
{
    PTR newborn;
    newborn = (PTR)malloc(sizeof(struct node));
    if (newborn == NULL)
    {
        printf("\nMemory Overflow");
        exit(0);
    }
    printf("\nEnter USN : ");
    scanf("%s", newborn->usn);
    printf("\nEnter name : ");
    scanf("%s", newborn->name);
    printf("\nEnter Program name : ");
    scanf("%s", newborn->prog);
    printf("\nEnter semester : ");
    scanf("%d", &newborn->sem);
    printf("\nEnter Phone no : ");
    scanf("%s", newborn->ph);
    return newborn;
}
void freeN(PTR x)
{
    free(x);
}

PTR insrear(PTR first)
{
    PTR temp, cur;
    temp = get();
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}
PTR delfront(PTR first)
{
    PTR temp;
    if (first == NULL)
    {
        printf("\nSLL is empty cannot delete\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf("\nNode deleted is %s\n", temp->name);
    freeN(temp);
    return first;
}
void disp(PTR first)
{
    PTR curr;
    int count = 0;
    if (first == NULL)
    {
        printf("\nSLL is empty\n");
        return;
    }
    printf("\nThe contents of SLL are :\n");
    curr = first;
    printf("\nUSN\t\tName\tProgram\tSem\tPhone num");
    while (curr->link != NULL)
    {
        printf("\n%s\t%s\t%s\t%d\t%s", curr->usn, curr->name, curr->prog, curr->sem, curr->ph);

        curr = curr->link;
        count++;
    }
    printf("\n\nSLL has %d nodes\n", count);
}
PTR insfront(PTR first)
{
    PTR temp;
    temp = get();
    temp->link = NULL;
    temp->link = first;
    first = temp;
    return first;
}
PTR delrear(PTR first)
{
    PTR cur, prev;
    if (first == NULL)
    {
        printf("\nSLL is empty cannot delete\n");
        return first;
    }
    prev = NULL;
    cur = first;
    if (cur->link == NULL)
    {
        printf("\nNode deleted for %s\n", cur->name);
        freeN(cur);
        return NULL;
    }
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = cur->link;
    printf("\nNode deleted for %s\n", cur->name);
    freeN(cur);
    return first;
}
