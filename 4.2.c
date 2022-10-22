#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int row,i,j,col;

    int choice;
    printf("select how to input matrix rows: 1 for random input, 2 for keyboard input: ");
	while (scanf("%d", &choice) != 1 || getchar()!='\n' || (choice!=1 && choice != 2)) {
		printf("Wrong! Try again.\n");
		printf("select how to input matrix rows: 1 for random input, 2 for keyboard input: ");
		rewind(stdin);
	}

	if (choice==2) {
        printf("Enter the number of matrix rows: ");
        while (scanf("%d", &row) != 1 || getchar()!='\n' || row<=0 || row>100) {
            printf("Wrong! Try again.\n");
            printf("Enter the number of matrix rows: ");
            rewind(stdin);
        }
	}
	else {
        row = 1+rand()%100;
        printf("The number of matrix rows: %d\n", row);
	}

	int choice1;
    printf("select how to input matrix columns: 1 for random input, 2 for keyboard input: ");
	while (scanf("%d", &choice1) != 1 || getchar()!='\n' || (choice1!=1 && choice1 != 2)) {
		printf("Wrong! Try again.\n");
		printf("select how to input matrix columns: 1 for random input, 2 for keyboard input: ");
		rewind(stdin);
	}

	if (choice1==2) {
        printf("Enter the number of matrix columns: ");
        while (scanf("%d", &col) != 1 || getchar()!='\n' || col<=0 || col>100) {
            printf("Wrong! Try again.\n");
            printf("Enter the number of matrix columns: ");
            rewind(stdin);
        }
	}
	else {
        col = 1+rand()%100;
        printf("The number of matrix columns: %d\n", col);
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
        for (i=0; i<row; i++) {
            for (j=0; j<col; j++) {
                while (scanf("%d", &mas[i][j]) != 1 || getchar()!='\n') {
                    printf("Wrong! Try again.\n");
                    rewind(stdin);
                }
            }
        }
        printf("You'r array: \n");
        for (i=0; i<row; i++) {
            for (j=0; j<col; j++) {
                printf("%d ", mas[i][j]);
            }
            printf("\n");
        }
	}
	else {
        for (i=0; i<row; i++) {
            for (j=0; j<col; j++) {
                mas[i][j]=rand()%200-100;
            }
        }
        printf("You'r array: \n");
        for (i=0; i<row; i++) {
            for (j=0; j<col; j++) {
                printf("%d ", mas[i][j]);
            }
            printf("\n");
        }
	}

    int signal[100];
    for (i=0; i<row; i++) {
        signal[i]=0;
        for (j=0; j<col; j++) {
            if (mas[i][j]>0) {signal[i]=1;}
        }
    }

    int kol=0;
    for (i=0; i<row; i++) {
        if (signal[i]==1) {kol++;}
    }

    if (kol==row) {
        printf("We have positive elements in every line.\n");
        for (i=0; i<row; i++) {
            for (j=0; j<col; j++) {
                mas[i][j]=-mas[i][j];
                printf("%d ", mas[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("We don't have positive elements in every line.\n");
        for (i=0; i<row; i++) {
            for (j=0; j<col; j++) {
                printf("%d ", mas[i][j]);
            }
            printf("\n");
        }

    }

    return 0;
}
