/*

Name: Abiodun Oke
Email:
Workshop:
Section:
Date:
*/

#include <stdio.h>
#define SIZE 3

int isValid(const long long int);


void decompose(const long long phone_number, int *AAA, int *PPP, int *LLLL);
void decompose(const long long phone_number, int *AAA, int *PPP, int *LLLL) {

	*AAA = (int)(phone_number / 10000000);
	*PPP = (int)((phone_number % 10000000) / 10000);
	*LLLL = (int)(phone_number % 10000);
}

int isValid(const long long int valid) {

	int i;
	int validArea[] = {416, 647, 905};
	int area, prefix, line;
	// 0 = false, 1 = true
	int result = 0;

	decompose(valid, &area, &prefix, &line);
	//printf("isValid: (%3d)-%3d-%4d\n", area, prefix, line);

	if (prefix >= 100 && prefix <= 999)
		{
		for (i = 0; i < 3; i++) {
			if(validArea[i] == area)
				result = 1;
			}
		}
		
	//printf("result %d \n", result);
	return result;

}

/* main program */
int main(void) {

	long long phoneNumber[SIZE] = { 0ll, 0ll, 0ll };
	int option;
	int area, prefix, lineNum;
	int count = 0;
    	int j = 0;
	long long int tempNum = 0LL;
//	int check;

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
			}
			
            		scanf("%lld", &tempNum);
			if (isValid(tempNum) == 1) {
				phoneNumber[count] = tempNum;
				count++;
				printf("\n");
		
			}
			else
			{
				printf("ERROR!!! Phone Number is not Valid\n");
				printf("\n");
			
			}
			


			break;
		default:
			printf("ERROR!!!: Incorrect Option: Try Again");
			printf("\n\n");
		}
			
	} while (option != 0);

	return 0;
}


