#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NUM_DAYS_IN_WEEKS 7
typedef struct 
{
    char* acDayName;
    int iDate;
    char* acActivity;
} DAYTYPE;
void fnDispCal(DAYTYPE *);
void fnReadCal(DAYTYPE *);
DAYTYPE* fnCreateCal();

DAYTYPE* fnCreateCal() 
{
    DAYTYPE* calendar = (DAYTYPE*)malloc(NUM_DAYS_IN_WEEKS * sizeof(DAYTYPE));
    for (int i = 0; i < NUM_DAYS_IN_WEEKS; i++) 
    {
        calendar[i].acDayName = NULL;
        calendar[i].iDate = 0;
        calendar[i].acActivity = NULL;
    }
    return calendar;
}

void fnReadCal(DAYTYPE* calendar) 
{
    char cChoice;
    for (int i = 0; i < NUM_DAYS_IN_WEEKS; i++) 
    {
        printf("Do you want to enter the details for day %d [Y/N]: ", i + 1);
        scanf(" %c", &cChoice); // Notice the space before %c to consume the newline character.
        getchar(); // To consume the newline character after scanf
        
        if (tolower(cChoice) == 'n') 
        {
            continue;
        }
        
        printf("Day Name: ");
        char nameBuffer[50];
        scanf("%49s", nameBuffer); // Limiting input to 49 characters to prevent buffer overflow
        calendar[i].acDayName = strdup(nameBuffer);
        printf("Date: ");
        scanf("%d", &calendar[i].iDate);
        printf("Activity: ");
        char activityBuffer[100];
        scanf(" %99[^\n]", activityBuffer); // Correcting the scanf format specifier
        calendar[i].acActivity = strdup(activityBuffer);
        printf("\n");
        getchar(); // To consume the newline character after scanf
    }
}

void fnDispCal(DAYTYPE* calendar) 
{
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < NUM_DAYS_IN_WEEKS; i++) 
    {
        printf("Day %d:\n", i + 1);
        if (calendar[i].iDate == 0) 
        {
            printf("No Activity\n\n");
            continue;
        }
        printf("Day Name: %s\n", calendar[i].acDayName);
        printf("Date: %d\n", calendar[i].iDate);
        printf("Activity: %s\n\n", calendar[i].acActivity);
    }
}
int main() 
{
    DAYTYPE *weeklyCalendar = fnCreateCal();
    fnReadCal(weeklyCalendar);
    fnDispCal(weeklyCalendar);
    return 0;
}
