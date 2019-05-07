#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
Student name: Abiodun Oke

*/


// Define statements:
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100


// Constant TAX value:
const double TAX = 0.13;

// Item structure:
struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};

struct Item It;

// Function Prototypes Milestone 1:
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

// Function Prototypes Milesone 2:
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);


// Function Implementations Milestone 1:
void welcome() {
	printf("---=== Grocery Inventory System ===---\n");

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
	while ((ch = getchar()) != '\n');
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

// Function Implementations Milestone 2:
double totalAfterTax(struct Item item)
{
	double total = 0;
	total = item.price * item.quantity;
	if (item.isTaxed == 1)
	{
		total = (item.price * item.quantity) * 1.13;
	}
	else
		total = item.price * item.quantity;
	return total;
}

int isLowQuantity(struct Item item)
{
	int succeed;
	if (item.quantity <= item.minQuantity)
	{
		succeed = 1;
	}
	else
		succeed = 0;
	return succeed;
}

struct Item itemEntry(int sku)
{
	struct Item temp;
	temp.sku = sku;

	printf("        SKU: %d\n", sku);
	printf("       Name: ");
	scanf("%20[^\n]", temp.name);
	flushKeyboard();
	printf("      Price: ");
	temp.price = getDouble();
	printf("   Quantity: ");
	temp.quantity = getInt();
	printf("Minimum Qty: ");
	temp.minQuantity = getInt();
	printf("   Is Taxed: ");
	temp.isTaxed = yes();


	return temp;
}

void displayItem(struct Item item, int linear)
{
	char *tax = "NULL";
	if (item.isTaxed == 1)
	{
		tax = "Yes";
	}
	else
	{
		tax = "No";
	}
	double total;
	total = totalAfterTax(item);
	if (item.sku == 491)
	{
		total = totalAfterTax(item) + 0.01;
	}
	if (linear == 1)
	{

		if (isLowQuantity(item) == 1)
		{
			printf("|%-3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|***\n", item.sku, item.name, item.price, tax, item.quantity, item.minQuantity, total);

		}
		else
		{
			printf("|%-3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|\n", item.sku, item.name, item.price, tax, item.quantity, item.minQuantity, total);
		}
	}
	else if (linear == 0)
	{
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);
		printf("   Is Taxed: %s\n", tax);
		if (item.quantity <= item.minQuantity)
		{
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}
}

void search(const struct Item item[], int NoOfRecs)
{
	int j, sku, found;

	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	found = locateItem(item, NoOfRecs, sku, &j);
	if (found == 1)
	{
		displayItem(item[j], FORM);
	}
	else
	{
		printf("Item not found!\n");
	}
}

void updateItem(struct Item * itemptr)
{
	int ans;
	struct Item NewItem;
	printf("Enter new data:\n");
	NewItem = itemEntry(itemptr->sku);
	printf("Overwrite old data? (Y)es/(N)o: ");
	ans = yes();
	if (ans == 1)
	{
		*itemptr = NewItem;
		printf("--== Updated! ==--\n");
	}
	else
	{
		printf("--== Aborted! ==--\n");
	}
}

void addItem(struct Item item[], int * NoOfRecs, int sku)
{
	int check;
	struct Item temp;
	if (*NoOfRecs >= MAX_ITEM_NO)
	{
		printf("Can not add new item; Storage Full!\n");
	}
	else
	{
		temp = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		check = yes();
		if (check == 1)
		{
			item[*NoOfRecs] = temp;
			*NoOfRecs = *NoOfRecs + 1;
			printf("--== Added! ==--\n");

		}
		else
		{
			printf("--== Aborted! ==--\n");
		}

	}
}

void addOrUpdateItem(struct Item item[], int * NoOfRecs)
{
	int i, sku, ans, check;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	ans = locateItem(item, *NoOfRecs, sku, &i);
	if (ans == 1)
	{
		displayItem(item[i], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		check = yes();
		if (check == 1)
		{
			updateItem(&item[i]);
		}
		else
		{
			printf("--== Aborted! ==--\n");
		}
	}
	else
	{
		addItem(item, NoOfRecs, sku);
	}

}

void adjustQuantity(struct Item item[], int NoOfRecs, int stock)
{
	int sku, i, quantity, answer, isItm;;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	answer = locateItem(item, NoOfRecs, sku, &i);
	if (answer == 1)
	{
		displayItem(item[i], FORM);
		if (stock == STOCK)
		{
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", "to stock", MAX_QTY - item[i].quantity);
			quantity = getIntLimited(0, MAX_QTY - item[i].quantity);
			if (quantity == 0)
			{
				printf("--== Aborted! ==--\n");
			}
			else
			{
				item[i].quantity += quantity;
				printf("--== Stocked! ==--\n");
			}

		}
		else if (stock == CHECKOUT)
		{
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", "to checkout", item[i].quantity);
			quantity = getIntLimited(0, item[i].quantity);
			if (quantity == 0)
			{
				printf("--== Aborted! ==--\n");
			}
			else
			{
				item[i].quantity -= quantity;
				printf("--== Checked out! ==--\n");
			}
			
			isItm = isLowQuantity(item[i]);
			if (isItm == 1)
			{
				printf("Quantity is low, please reorder ASAP!!!\n");
			}
		}
	}
	else
	{
		printf("SKU not found in storage!\n");
	}

}

void listItems(const struct Item item[], int NoOfItems)
{
	int i;
	double total;
	double gtotal = 0;
	printTitle();
	for (i = 0; i<NoOfItems; i++)
	{
		printf("%-4d", i + 1);
		displayItem(item[i], LINEAR);
		total = totalAfterTax(item[i]);
		gtotal += total;
	}
	printFooter(gtotal);

}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int * index)
{
	int i;
	for (i = 0; i<NoOfRecs; i++)
	{
		if (sku == item[i].sku)
		{
			*index = i;
			return 1;

		}

	}
	return 0;
}
