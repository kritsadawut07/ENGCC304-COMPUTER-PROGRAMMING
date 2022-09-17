#include <stdio.h>
#include <string.h>

char name[99];
int salary = 0, year = 0, avg = 0, count = 0;

char most_name[99];
int most_salary = 0, most_year = 0;

void main()
{
    char c = 'y';
    while (c == 'y')
    {
        printf("Do you want to Enter Employee Information(y/n): ");
        scanf(" %c", &c);
        c == 'y' ? employee_info() : output();
    }
    while (c != ' ')
        c = getch();
}

void employee_info()
{
    printf("name: ");
    scanf("%s", &name);
    printf("Salary (Bath/Month): ");
    scanf("%d", &salary);
    printf("Duration (Year): ");
    scanf("%d", &year);
    salary >= most_salary ? check_most(year) : 0;
    avg += salary;
    count++;
}

void check_most(int x)
{
    strcpy(most_name, name);
    most_salary = salary;
    most_year = x;
}

void output()
{
    printf("\nAveage of Salary: %.2f Bath", count == 0 ? 0 : (float)avg / (float)count);
    printf("\nPayment of every month: %.2f Bath", count == 0 ? 0 : (float)avg);
    printf("\n<-- Most duration in this business -->");
    printf("\nName: %s (%d Years)", count == 0 ? "No Data Input" : most_name, count == 0 ? 0 : most_year);
    printf("\nSalary: %.2f Bath", count == 0 ? 0 : (float)most_salary);
    printf("\n\nGood Bye");
    printf("\nPress space bar to continue...\n");
}