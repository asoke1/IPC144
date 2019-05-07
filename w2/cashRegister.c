// Abiodun Oke, IPC144SOO
#include<stdio.h>

int main(void) {

	int loonies = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;
	double amountOwing = 0, gst = 0.0, balOwing = 0.0;



	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountOwing);

	gst = amountOwing * .13 + .005; 
	printf("GST: %.2lf\n", gst);

	balOwing = amountOwing + gst; 
	printf("Balance owing: $%.2lf\n", balOwing);

    loonies = balOwing / 1;    // Divid the balance by loonies Dollar value 
	balOwing = balOwing - loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, balOwing);

	quarters = balOwing / 0.25;   
	balOwing = balOwing - (quarters * 0.25);
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, balOwing);

	dimes = balOwing / 0.10;
	balOwing = balOwing - (dimes * 0.10);
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, balOwing);

	nickels = balOwing / 0.05;
	balOwing = balOwing - (nickels * 0.05);
	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, balOwing);

	pennies = balOwing / 0.01;
	balOwing = balOwing - (pennies * 0.01);
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, balOwing);
    



	return 0;
}

