/*
Name: Abiodun Oke
*/ 
#include <stdio.h>

#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20
//Type the struct here
struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};
//Type the function prototypes here
	void menu();
	void displayInventory(const char filename[]);
	int searchInventory(FILE *fp,const int isbn2find);
	void addBook(const char filename[], struct Book *b2Add);
	void checkPrice(const char filename[], const int isbn2find);
	int readRecord(FILE *fp, struct Book *b2read);
	float calculateCapital(const char filename[]);

int main()
{
	//struct Book mybook[MAX_BOOKS];
	char filename[] = "inventory.txt";
	int size = 0;
	int select;
   //Type your code here:
	printf("Welcome to the Book Store\n");
	printf("=========================\n");
	do {

		menu();
		scanf("%d", &select);

		switch (select)
		{
		case 0: printf("Goodbye!\n");
			break;

		case 1: displayInventory(filename);
			break;

		case 2: addBook(filename, NULL);
			break;

		case 3: checkPrice(filename, size);
			break;

		case 4: calculateCapital(filename);

			break; 

		default:  printf("Invalid input, try again:\n");
		}

	} while (select != 0);
    return 0;
}

void menu()
{
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n\nSelect: ");
}



void displayInventory(const char filename[])
{
    //Define an object of struct Book
	struct Book b;
	
    //Open the file, and check for null pointer
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error file not open\n");
	}
	else
	{
		//If the file is properly opened, display headers, similar to workshop 8
		printf("\n\nInventory\n===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		

		//Use a while loop to call readRecord and display the records.
		/*call readRecord and check its return value*/
		
		
		while (readRecord(fp,&b) == 5) {
			//display the record
			//printf("see me");
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", b._isbn,b._title,b._year,b._price,b._qty);
		}
			//Display the footer
		printf("===================================================\n\n");
			//Close the file
		fclose(fp);
	}
   
}





void addBook(const char filename[], struct Book *b2Add)
{
 //Not implemented!
 //
}

void checkPrice(const char filename[],const int isbn2find)
{
    
 printf("Not implemented!");

 
}

int searchInventory(FILE *fp,const int isbn2find)
{
 //printf("Not implemented!");
 return 0;
}


float calculateCapital(const char filename[])
{
    
    
    //Define an object of struct Book
	struct Book b;
    //Define and initialize total_capital
	float total_capaital = 0;
    
    //Open the file, and check for null pointer
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error file not open");
	}
	else {

  
    //If the file is properly opened, use a while loop to call readRecord
			/*call readRecord and check its return value*/
		while (readRecord(fp, &b) == 5)
		{
		//Accumulate the multiplication of the price of each item to its quantity
			total_capaital += b._price * b._qty;
			
	}
		printf("The total capital is: $%.2f.\n", total_capaital);
        
        
	}
  
        
    //Display the footer
	//printf("===================================================\n");
		//Close the file
	//fclose(fp);
	return total_capaital;
    
}

int readRecord(FILE *fp, struct Book *b2read)
{
    //Define a variable int rv = 0
	int rv = 0;
	/*Type your code here*/

	rv = fscanf(fp, "%d;%f;%d;%d;%[^\n]\n", &(b2read->_isbn), &(b2read->_price), &(b2read->_year), &(b2read->_qty), b2read->_title);

   //"%d;%f;%d;%d;[^\n]"
    return rv;

}
