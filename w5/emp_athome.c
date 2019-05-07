/*
Name:Abiodun Oke
Student number:117180166
Email:
Workshop:5
Section:
Date:
*/

// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements
#include <stdio.h>
#define SIZE 4
// Define Number of Employees "SIZE" to be 4


// Declare Struct Employee

struct employee
{
	int emp_id;
	int age;
	double salary;
};
/* main program */

int main(void) {

	struct employee emp[SIZE] = { { 0 } };
	int option = 0;
	int count = 0;
	int i, j;

	int temp = 0;
	int suceed = 0;

	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements
	// and initialize all elements to zero

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");

		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");
		// Capture input to option variable		

		switch (option) {
		case 0: // Exit the program

			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1: // Display Employee Data
				// @IN-LAB
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < count; i++)
			{
				if (emp[i].emp_id > 0)
					printf("%6d%9d%11.2lf\n", emp[i].emp_id, emp[i].age, emp[i].salary);
			}
			printf("\n");

			// Use "%6d%9d%11.2lf" formatting in a
			// printf statement to display
			// employee id, age and salary of,
			// all  employees using a loop construct

			// The loop construct will be run for SIZE times
			// and will only display Employee data
			// where the EmployeeID is > 0
			break;
		case 2: // Adding Employee
				// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");
			if (count >= SIZE)
			{
				printf("ERROR!!! Maximum Number of Employees Reached\n");
				printf("\n");
				break;
			}
			else {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[count].emp_id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[count].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[count].salary);
				printf("\n");
				// Check for limits on the array and add employee
				// data accordingly.

				count++;
			}

			break;
		case 3:

			printf("Update Employee Salary\n");
			printf("======================\n");
			
			do
			{

				printf("Enter Employee ID: ");
				scanf("%d", &temp);
				
				
				for (j = 0; j < count; j++ )
				{
		
					if (temp == emp[j].emp_id)
					{
						suceed = 1;
						printf("The current salary is %.2lf\n", emp[j].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[j].salary);
					}
				}
				//if suceed ==0 print error
			
			} while (suceed ==0 );       //udate employee salary

			
			printf("\n");
			break;
		case 4:
		

			printf("Remove Employee\n");
			printf("===============\n");
			/*printf("Enter Employee ID: ");
			scanf("%d", temp);
		
				for (j = 0; j < count; j++)
				{

					if (temp == emp[j].emp_id)
					{
						suceed = 1;
						printf("Employee %d will be removed\n", emp[j].emp_id);
						

						break;
					}
				}*/
			do
			{

				printf("Enter Employee ID: ");
				scanf("%d", &temp);


				for (j = 0; j < count; j++)
				{

					if (temp == emp[j].emp_id)
					{
						suceed = 1;
						printf("Employee %d will be removed\n", emp[j].emp_id);
						emp[j].emp_id = 0;
						emp[j].age = 0;
						emp[j].salary = 0;
					}
				}
				//if suceed ==0 print error

			} while (suceed == 0);
			printf("\n");
			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0;
}






// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 113
Enter Employee Age: 53
Enter Employee Salary: 120345.78

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 114
Enter Employee Age: 25
Enter Employee Salary: 46780

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 112
The current salary is 65000.00
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   99999.99
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 112
Employee 112 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!
*/
