/*

Name: Abiodun Oke
Email:
Workshop:
Section:
Date:
*/

#include <stdio.h>
#define SIZE 3




void decompose(long long phone_number, int *AAA, int *PPP, int *LLLL);
void decompose(long long phone_number, int *AAA, int *PPP, int *LLLL) {
	*AAA = (int)(phone_number / (10000000));
	*PPP = (int)(phone_number % (10000000) / 10000);
	*LLLL = (int)(phone_number % (10000));
}


/* main program */
int main(void) {

	long long phoneNumber[SIZE] = { 0ll, 0ll, 0ll };
	int option;
	int area, prefix, lineNum;
	int count = 0;
       	int j = 0;

	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");



		switch (option) {
		case 0:	// Exit the program

			printf("Exiting Phone Number App. Good Bye!!!\n");
			break;

		case 1: // Display the Phone List
				// @IN-LAB
			
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form
			for (j = 0; j < count; j++) {
				decompose(phoneNumber[j], &area, &prefix, &lineNum);
				printf("(%3d)-%3d-%4d", area, prefix, lineNum);
				printf("\n");
			}
			 printf("\n");
			
			break;
		case 2:	// Add a Phone Number
				// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");
			if (count >= SIZE) {
				printf("ERROR!!! Phone Number List is Full");
				printf("\n\n");
				break;
			}
			else
			{
				scanf("%llu", &phoneNumber[count]);
				printf("\n");

				count++;
			}
			


			break;
		default:
			printf("ERROR!!! Phone Number is not Valid");
			printf("\n");
		}

	} while (option != 0);

	return 0;
}


