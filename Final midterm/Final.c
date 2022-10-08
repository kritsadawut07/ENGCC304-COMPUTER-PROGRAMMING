 #include <stdio.h>
#include <string.h>

int static_time[] = {21, 6, 2018};
int max_year = 0, min_year = 99, max_month, min_month;
char max_name[99], min_name[99];

void main()
{
    FILE *data;
    data = fopen("a.txt", "r");

    data == NULL ? printf("\nNothing Data In This File [Err: Error Opening File]") : 0; // Check File is Empty or Not?

    calculate(data);
    show_min_max();
    fclose(data);
    while (getch() != ' ');
}

void calculate(FILE *info)
{
    char name[99];
    int no, day, month, year;
    fscanf(info, "%*[^\n]");
    while (fscanf(info, "%d %s %d-%d-%d", &no, &name, &year, &month, &day) != EOF)
    {
        day > static_time[0] ? month = month + 1 : 0;
        month = month + static_time[1] == 12 ? 0 : (month + static_time[1]) > 12 ? 12 - month + static_time[1] : (month + static_time[1]) < 12   ? static_time[1] - month : 0;
        year = month + static_time[1] >= 12 ? static_time[2] - year - 1 : static_time[2] - year;
        year > max_year ? max(name, year, month) : year < min_year ? min(name, year, month): 0;
        printf("%3s %d Years, %d Month \n", name, year, month);
    }
}

void max(char *n, int y, int m)
{
    strcpy(max_name, n);
    max_year = y;
    max_month = m;
}

void min(char *n, int y, int m)
{
    strcpy(min_name, n);
    min_year = y;
    min_month = m;
}

void show_min_max()
{
    printf("\nMax: %s [%d Years, %d Months]", max_name, max_year, max_month);
    printf("\nMin: %s [%d Years, %d Months]", min_name, min_year, min_month);
    printf("\nPress space bar to continue...\n");
}
