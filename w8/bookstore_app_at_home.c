/*
Name:Abiodun Oke
Student number: 117180166
Email:
Workshop:
Section:
Date:
*/

#include <stdio.h>
#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20

struct Book {
	
		
		int _isbn;
		
		float _price;
		
		int _year;
	
		char _title[MAX_TITLE_SIZE]; 

		int _qty;
	
};

//place functions below^M
void menu();
void displayInventory(const struct Book book[], const int size);
int searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);



int main(void) {
		
			
			//An array of Book representing the inventory
			struct Book book[MAX_BOOKS];
			int size = 0;
			int select;
			

			printf("Welcome to the Book Store\n");
			printf("=========================\n");
			do {
				menu();
					scanf("%d", &select);
					
					switch (select)
					{
					case 0: printf("Goodbye!\n");
				break;
				
					case 1: displayInventory(book, size);
					break;
					
					case 2: addBook(book, &size);
					break;
					
					case 3: checkPrice(book, size);
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
	printf("0) Exit.\n\nSelect: ");
}

void displayInventory(const struct Book book[], const int size) {

	if (size <= 0) {
		printf("The inventory is empty!\n");
		printf("===================================================\n\n");
	}
	else {

		printf("\n\nInventory\n===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		int i;
		for (i = 0; i < size; i++) {
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
		}
		printf("===================================================\n\n");
	}
}


	int searchInventory(const struct Book book[], const int isbn, const int size)
	{
		int i, suceed = -1;
		for (i = 0; i < size; i++) {
			if (isbn == book[i]._isbn)
			{
				suceed = i;
			}
		}
		return suceed;
	}

	void addBook(struct Book book[], int * size) {
		int tempIsbn, tempQty, res;

			printf("ISBN:");
			scanf("%d", &tempIsbn);
			printf("Quantity:");
			scanf("%d", &tempQty);

			res = searchInventory(book, tempIsbn, *size);

			if (res == -1)
			{
				if (*size == MAX_BOOKS) {
					printf("The invectory is full\n");
				}
				else {

					book[*size]._isbn = tempIsbn;
					book[*size]._qty = tempQty;
					printf("Title:");
					while (getchar() != '\n')
						;
					scanf("%20[^\n]", book[*size]._title);
					printf("Year:");
					scanf("%d", &book[*size]._year);
					printf("Price:");
					scanf("%f", &book[*size]._price);

					(*size)++;
					printf("The book is successfully added to the inventory.\n");
					printf("\n");
				}
			}
			else
			{
				book[res]._qty = book[res]._qty + tempQty;
				printf("The book exists in the repository, quantity is updated.\n\n");
			}
			
			
   }

	void checkPrice(const struct Book book[], const int size)
	{
		int isbn;
		printf("Please input the ISBN number of the book:\n\n");
		scanf("%d", &isbn);
		int number = searchInventory(book, isbn, size);
		if(number!=-1){
			printf("Book %d costs $%.2f\n\n", book[number]._isbn, book[number]._price);
		}
		else {
			printf("Book does not exist in the bookstore! Please try again.\n\n");
		}
		//printf("Not implemented\n");
	}

