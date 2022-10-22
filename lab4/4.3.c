#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int n,i,j;

    int choice;
    printf("select how to input matrix rows and columns: 1 for random input, 2 for keyboard input: ");
	while (scanf("%d", &choice) != 1 || getchar()!='\n' || (choice!=1 && choice != 2)) {
		printf("Wrong! Try again.\n");
		printf("select how to input matrix rows: 1 for random input, 2 for keyboard input: ");
		rewind(stdin);
	}

	if (choice==2) {
        printf("Enter the number of matrix rows and columns: ");
        while (scanf("%d", &n) != 1 || getchar()!='\n' || n<=0 || n>100) {
            printf("Wrong! Try again.\n");
            printf("Enter the number of matrix rows and columns: ");
            rewind(stdin);
        }
	}
	else {
        n = 1+rand()%100;
        printf("The number of matrix rows and columns: %d\n", n);
	}


	int mas[100][100];
    int choice2;
    printf("select how to input array: 1 for random input, 2 for keyboard input: ");
	while (scanf("%d", &choice2) != 1 || getchar()!='\n' || (choice2!=1 && choice2 != 2)) {
		printf("Wrong! Try again.\n");
		printf("select how to input array: 1 for random input, 2 for keyboard input: ");
		rewind(stdin);
	}

	if (choice2==2) {
        printf("Enter the array: \n");
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                while (scanf("%d", &mas[i][j]) != 1 || getchar()!='\n') {
                    printf("Wrong! Try again.\n");
                    rewind(stdin);
                }
            }
        }
        printf("You'r array: \n");
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                printf("%d ", mas[i][j]);
            }
            printf("\n");
        }
	}
	else {
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                mas[i][j]=rand()%200-100;
            }
        }
        printf("You'r array: \n");
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                printf("%d ", mas[i][j]);
            }
            printf("\n");
        }
	}


    int nom_str;
    if (n%2==0) {nom_str=n/2;}
    else {nom_str=(n/2)+1;}

    int nom_col=n/2;

    int sum=0;
    for (i=0; i<nom_str; i++) {
        for (j=nom_col; j<n; j++) {
            sum+=mas[i][j];
        }
    }

    printf("The sum of the elements of the second quarter: %d\n", sum);
    return 0;
}
