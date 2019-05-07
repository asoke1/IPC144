#include <stdio.h>
// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
 //app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);


// code your functions here:
void welcome() {
	printf("---=== Grocery Inventory System ===---\n");
	//getchar();
}

void printTitle() {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double grandTotal) {
	printf("--------------------------------------------------------+----------------\n");
	if (grandTotal > 0) {
		printf("%57s %11.2lf\n", "Grand Total: |", grandTotal);

	}
}

void flushKeyboard() {
	char ch;
	while (ch = getchar() != '\n');
}

void pause() {
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}


int getInt(void) {

	int input;
	char NL;
	scanf("%d%c", &input, &NL);

	while (NL != '\n')
	{
		flushKeyboard();
		printf("Invalid integer, please try again: ");
		scanf("%d%c", &input, &NL);

	}
	return input;
}

int getIntLimited(int lowerLimit, int upperLimit)
{
	int answer;
	answer = getInt();
	while (answer < lowerLimit || answer > upperLimit)
	{
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		answer = getInt();

	}
	return answer;

}



double getDouble() {
	double input2;
	char NL;
	scanf("%lf%c", &input2, &NL);

	while (NL != '\n')
	{
		flushKeyboard();
		printf("Invalid number, please try again: ");
		scanf("%lf%c", &input2, &NL);

	}
	return input2;

}



double getDoubleLimited(double lowerLimit, double upperLimit)
{
	double answer3;
	answer3 = getDouble();
	while (answer3 < lowerLimit || answer3 > upperLimit)
	{
		printf("Invalid value, %lf < value < %lf: ", lowerLimit, upperLimit);
		answer3 = getDouble();
	}
	return answer3;
}

int yes(void)
{
	char yes;
	char yeah[2];
	int exit;

	do
	{
		int i = 0;

		while (((yes = getchar()) != '\n'))
		{
			yeah[i] = yes;
			i++;
		}

		if (yeah[0] == 'Y' || yeah[0] == 'y')
		{

			exit = 1;
		}
		else if (yeah[0] == 'N' || yeah[0] == 'n')
		{
			exit = 0;
		}
		else
		{
			printf("Only (Y)es or (N)o are acceptable: ");
			exit = 2;
		}
	} while (exit == 2);

	return exit;
}

void GroceryInventorySystem(void)
{

	int select, exit;
	welcome();
	do
	{
		select = menu();

		switch (select)
		{

		case 1:
		{
			printf("List Items!\n");
			pause();
		}
		break;
		case 2:
		{
			printf("Search Items!\n");
			pause();
		}
		break;
		case 3:
		{
			printf("Checkout Item!\n");
			pause();
		}
		break;
		case 4:
		{
			printf("Stock Item!\n");
			pause();
		}
		break;
		case 5:
		{
			printf("Add/Update Item!\n");
			pause();
		}
		break;
		case 6:
		{
			printf("Delete Item!\n");
			pause();
		}
		break;
		case 7:
		{
			printf("Search by name!\n");
			pause();
		}
		break;
		case 0:
			printf("Exit the program? (Y)es/(N)o : ");
			exit = yes();
			break;

		}

	} while (select != 0 || exit != 1);

}

int menu(void)
{
	int select;

	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	select = getIntLimited(0, 7);

	return select;

}

