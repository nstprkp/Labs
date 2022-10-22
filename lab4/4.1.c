#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int mas[100][100];

void sort_charact_and_mas(int *mass, int *val, int size, int str)
{
    for (int k=0; k<size-1; k++) {
        for (int j = (size - 1); j > k; j--)
        {
            if (mass[j - 1] > mass[j])
            {
                int temp;
                temp = mass[j - 1]; mass[j - 1] = mass[j]; mass[j] = temp;
                temp = val[j-1]; val[j-1]=val[j]; val[j]=temp;
                for (int i=0; i<str; i++) {
                    temp=mas[i][j-1]; mas[i][j-1]=mas[i][j]; mas[i][j]=temp;
                }
            }
        }
    }
}

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
                mas[i][j]=rand()%20000-10000;
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

    int charact[100],sum[100],signal[100];
    for (j=0; j<col; j++) {
        charact[j]=0; signal[j]=0;
        for (i=0; i<row; i++) {
            if (mas[i][j]%2!=0 && mas[i][j]<0) {charact[j]+=abs(mas[i][j]); }
            if (mas[i][j]<0) {signal[j]=1;}
        }
    }

    sort_charact_and_mas(charact,signal,col,row);

    for (j=0; j<col; j++) {
        sum[j]=0;
        if (signal[j]==1) {
            for (i=0; i<row; i++) {sum[j]+=mas[i][j];}
        }
    }

    printf("You'r new array:\n");
    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }

    for (i=0; i<col; i++) {
        if (signal[i]==1) {printf("Sum of elements of %d column = %d\n", i+1, sum[i]);}
        else {printf("No negative elements in %d column.\n", i+1); }
    }
    return 0;
}
