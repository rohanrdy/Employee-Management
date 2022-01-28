// An Employee Management application using structure, functions and arrays in C. By Rohan (https://github.com/rohanrdy).

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define SIZE 100
#define LINE "\n*******************************************************************************\n"
int i = 0;

struct empinfo {
    char fname[50];
    char lname[50];
    int IDno;
    float salary;
}emp[SIZE];
  
// Function to add the employee details
void add_employee()
{
    if (i < SIZE) {
        printf("Add the Employee Details\n");
        printf("-------------------------\n");
        printf("Enter the First name of employee : ");
        scanf("%s", emp[i].fname);
        printf("Enter the Last name : ");
        scanf("%s", emp[i].lname);
        printf("Enter the ID Number : ");
        scanf("%d", &emp[i].IDno);
        printf("Enter the Salary : ");
        scanf("%f", &emp[i].salary);
      printf("%s",LINE);
      i++;
   }
    else {
        printf("Cannot add any more records. Please delete any record to continue or exit the program.\n");
        printf("%s",LINE);
    }
    getch();
}
  
// Function to find the employee by their ID number
void find()
{
    printf("Find the Employee Details by :\n"
           "1. ID Number\n"
           "2. First Name\n"
           "3. Last Name\n"
           "4. Amount of Salary\n");
    printf("Enter your choice : ");
    int choice,no,c=0;
    char name[50];
    float sal;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the ID Number of the employee : ");
            scanf("%d", &no);
            printf("\n");
            for (int j = 0; j < i; j++) {
            if (no == emp[j].IDno) {
                printf("\nThe Employees Details are\n");
                    printf("------------------------\n");
                    printf("The First name is %s\n", emp[j].fname);
                    printf("The Last name is %s\n", emp[j].lname);
                    printf("Salary is %.2f\n", emp[j].salary);
                    printf("%s",LINE);
                }
            }
            getch();
            break;
        case 2:
            printf("Enter the First Name of the employee : ");
            scanf("%s", name);
            for (int j = 0; j < i; j++) {
                if (!strcmp(emp[j].fname, name)) {
                    printf("\nThe Employees Details are\n");
                    printf("------------------------\n");
                    printf("The First name is %s\n", emp[j].fname);
                    printf("The Last name is %s\n", emp[j].lname);
                    printf("ID Number is %d\n", emp[j].IDno);
                    printf("Salary is %.2f\n", emp[j].salary);
                    printf("%s",LINE);
                    c=1;
                }
            }
            if(c==0) {
                printf("The First Name not Found\n");
                printf("%s",LINE);
            }
            getch();
            break;
        case 3:
            printf("Enter the Last Name of the employee : ");
            scanf("%s", name);
            for (int j = 0; j < i; j++) {
                if (!strcmp(emp[j].lname, name)) {
                    printf("\nThe Employees Details are\n");
                    printf("------------------------\n");
                    printf("The First name is %s\n", emp[j].fname);
                    printf("The Last name is %s\n", emp[j].lname);
                    printf("ID Number is %d\n", emp[j].IDno);
                    printf("Salary is %.2f\n", emp[j].salary);
                    printf("%s",LINE);
                    c=1;
                }
            }
            if(c==0) {    
                printf("The Last Name not Found\n");
                printf("%s",LINE);
            }
            getch();
            break;
        case 4:
            printf("Enter the Salary : ");
            scanf("%f", &sal);
            for (int j = 0; j < i; j++) {
                if (sal == emp[j].salary){
                    printf("\nThe Employees Details are\n");
                    printf("------------------------\n");
                    printf("The First name is %s\n", emp[j].fname);
                    printf("The Last name is %s\n", emp[j].lname);
                    printf("ID Number is %d\n ", emp[j].IDno);
                    printf("%s",LINE);
                    c=1;
                }
            }
            if(c==0) {
                printf("Employee with this salary not Found\n");
                printf("%s",LINE);
            }
            getch();
            break;
        default:
            printf("\nError! Enter any number from 1 to 4\n\n");
    }
}

// Function to print the total number of employees
void tot_e()
{
    printf("The total number of employees are %d\n\n", i);
    printf("You can store the data of maximum %d employees\n", SIZE);
    printf("You can store %d more employees data\n", SIZE - i);
    printf("%s",LINE);
    getch();
}
    
// Function to delete a employee by their ID number
void del_e()
{
    int a,c;
    printf("Enter the Employee ID Number whose record you want to delete : ");
    scanf("%d", &a);
    for (int j = 0; j < i; j++) {
        if (a == emp[j].IDno) {
            for (int k = j; k < SIZE; k++) {
                emp[k] = emp[k + 1];
                }
            i--;
            c=1;
        }
    }
    if(c==1) {
        printf("\nThe Record corresponding to ID Number %d is removed successfully\n",a);
    }
    else {
        printf("\nNo record found with this ID number\n");
    }
    printf("%s",LINE);
    getch();
}
  
// Function to update an employee's entry
void update_e()
{
    printf("Enter the ID number to update the entry : ");
    long int x;
    int c=0;
    scanf("%ld", &x);
    printf("---------------------------------\n");
    for (int j = 0; j < i; j++) {
        if (emp[j].IDno == x) {
            c=1;
            printf("Choose a number to update that particular entry\n"
                   "1. First name\n"
                   "2. Last name\n"
                   "3. ID no.\n"
                   "4. Salary\n");
            printf("Enter your choice : ");
            int choice;
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                printf("Enter the new first name : ");
                scanf("%s", emp[j].fname);
                break;
            case 2:
                printf("Enter the new last name : ");
                scanf("%s", emp[j].lname);
                break;
            case 3:
                printf("Enter the new IDno numnber : ");
                scanf("%d", &emp[j].IDno);
                break;
            case 4:
                printf("Enter the new salary : ");
                scanf("%f", &emp[j].salary);
                break;
            }
            printf("\nUPDATED SUCCESSFULLY.\n");
            printf("%s",LINE);
        }
    }
    if(c==0) {
    printf("\nNo record found with this ID number\n");
    printf("%s",LINE);
    }
    getch();
}

//Function to display all employee details
void disp()
{
    printf("The Following are the Employee Details\n");
    printf("--------------------------------------\n");
     printf("ID   Name  \t\tSalary\n");
     printf("--   ----   \t\t------\n");
    for (int j=0;j<i;j++)
    {
        printf("%2d   %s %s  \t\t%.2f\n", emp[j].IDno, emp[j].fname, emp[j].lname, emp[j].salary);
    }
    printf("%s",LINE);
    getch();
}


// The main part starting with a cool ascii art :)
int main()  
{
    int choice, count;
    printf("  ______                 _                         __  __                                                   _   \n"
           " |  ____|               | |                       |  \\/  |                                                 | |  \n"
           " | |__   _ __ ___  _ __ | | ___  _   _  ___  ___  | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_ \n"
           " |  __| | '_ ` _ \\| '_ \\| |/ _ \\| | | |/ _ \\/ _ \\ | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|\n"
           " | |____| | | | | | |_) | | (_) | |_| |  __/  __/ | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_ \n"
           " |______|_| |_| |_| .__/|_|\\___/ \\__, |\\___|\\___| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|\n"
           "                  | |             __/ |                                      __/ |                              \n"
           "                  |_|            |___/                                      |___/                               \n\n\n");
    while (1) {
        printf("The Task you want to perform\n\n");
        printf("1. Add the Employee Details\n");
        printf("2. Find the Record of an Employee\n");
        printf("3. Find the Total number of Employees\n");
        printf("4. Delete the Employee Details by ID Number\n");
        printf("5. Update a Record\n");
        printf("6. Display all Details of Employees\n");       
        printf("7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                find();
                break;
            case 3:
                tot_e();
                break;
            case 4:
                del_e();
                break;
            case 5:
                update_e();
                break;
            case 6:
                disp();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Error! Enter any number from 1 to 7\n\n");
        }
    }
return 0;
}
