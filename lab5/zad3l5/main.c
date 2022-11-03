#include <stdio.h>
#include <stdlib.h>
#include "ff.h"

int main()
{
    srand(time(NULL));
    int n;

    printf("select how to enter matrix rows: 1 for random input, 2 for keyboard input: ");
    int choice1=check_choice();

    if (choice1==2){
        printf("Enter the number of matrix rows: ");
        n=input_check();
    }
    else {
        n = 1+rand()%100;
        printf("The number of matrix rows: %d\n", n);
    }
    printf("select how to enter matrix rows: 1 for random input, 2 for keyboard input: ");
    int choice2 = check_choice();

    int** mas;
    int m;
    mas = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
		printf("input amount of numbers in %d row  ", i + 1);
		m = input_check();

		*(mas + i) = (int*)calloc(m, sizeof(int));
		printf("input numbers in row, -100 will be added automatically\n");
		if (choice2==2) {
            for (int j = 0; j < m - 1; j++) {
                while (scanf("%d", *(mas+i)+j) != 1 || *(*(mas + i) + j)==-100 || getchar() != '\n') {
                    printf("Wrong! Try again.\n");
                    rewind(stdin);
                }
            }
		}
		else {
            for (int j = 0; j<m-1; j++) {
                *(*(mas + i) + j) = 1+rand()%100;
            }
		}

		*(*(mas + i) + m - 1) = -100;
	}
	printf("Your array:\n");
	output(mas,n);

	for (int i=0; i<n; i++) {
        if (i%2!=0) {
            for (int j=0; j<last(mas,i); j++) {
                if ((*(*(mas + i) + j))%2 != 0) {
                    int t=last(mas,i); t++;
                    *(mas + i) = (int*)realloc(*(mas+i), t * sizeof(int));
                    move(*(mas + i), j);
                    j++;
                }
            }
        }
	}
    printf("New array:\n");
	output(mas,n);
    return 0;
}
