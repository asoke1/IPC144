 /*
Name: Abiodun Oke
Workshop: workshop3
Section: in lab
Date: 02/02/2017
*/
#include<stdio.h>
#define NUMS 4
int main(void) {

	int high[NUMS];
	int low[NUMS];
	int i = 0;
	double total = 0;
	double avg = 0;
	int max = -41;
	int min = 41;
	int max_day = 0;
	int min_day = 0;
	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++) {
		printf("Enter the high value for day %d: ", i+1);
		scanf("%d", &high[i]);
		printf("\n");
		printf("Enter the low value for day %d: ", i+1);
		scanf("%d", &low[i]);
		printf("\n");
		while (high[i] < low[i] || high[i] > 40 || low[i] < -40)
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");
			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &high[i]);
			printf("\n");
			printf("Enter the low value for day %d: ", i+1);
			scanf("%d", &low[i]);
			printf("\n");
		}
		if(high[i] > max){
			max = high[i];
			max_day = i+1;	
		}
		if (low[i] < min){
			min = low[i];
			min_day = i+1;
		}

		total += high[i] + low[i];
		avg = total / (NUMS * 2);
	}
	

	printf("The average (mean) temperature was: %.2lf\n", avg);
	printf("The highest temperature was %d, on day %d\n", max ,max_day);
	printf("The lowest temperature was %d, on day %d\n", min, min_day);


	return 0;
}





