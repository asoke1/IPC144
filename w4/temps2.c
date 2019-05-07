#include<stdio.h>
#include<stdlib.h>
int main(void) {
        int done =0;
	int high[11];
        int low[11];
	int numDay, i;
	double sum = 0;
	double avg = 0.0;

	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &numDay);
	printf("\n");

	while (numDay < 3 || numDay > 10){
	        printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
	        scanf("%d", &numDay);
	        printf("\n");
	}
										
	for (i = 0; i < numDay; i++){
	        printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}

	printf("\n");
	printf("Day  Hi  Low\n");
	for(i = 0; i < numDay; i++){
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);
	}

	printf("\n");

	while (done >= 0) {
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", numDay);
		scanf("%d", &done);
		printf("\n");

		if (done < 0){
			printf("Goodbye!\n");
			exit(0); 
		}
		
		while (done < 1 || done > numDay){
	       		printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", numDay);
	       		scanf("%d", &done);
	        	printf("\n");
		}

		for(i =0; i < done; i++){       	
                	sum += high[i] + low[i];
			}
		avg = sum / (done * 2);
		
		printf("The average temperature up to day %d is: %.2lf\n\n", done, avg);
		sum = 0;
		avg = 0;
	}
	
	return 0;
}
