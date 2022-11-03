#ifndef FF_H_INCLUDED
#define FF_H_INCLUDED

int check_choice()
{
    int choice;
	while (scanf("%d", &choice) != 1 || getchar()!='\n' || (choice!=1 && choice != 2)) {
		printf("Wrong! Try again.\n");
		rewind(stdin);
	}
}

int input_check()
{
    int val;
    while (scanf("%d", &val) != 1 || getchar()!='\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}

void move(int* row, int i) {
    int t=*(row+i);
    int temp;
	for (int j = i; *(row+j)!=-100; j++) {
        temp = *(row+1+j);
        *(row+1+j)=t;
        t=temp;
	}
}

int last(int** a, int n)
{
    for (int i=0;; i++) {
        if (*(*(a + n) + i) == -100) {return i+1;}
    }
}

void output(int** mas, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; *(*(mas + i) + j) != -100; j++)
			printf("%d ", *(*(mas + i) + j));
		printf("-100\n");
	}
}

#endif // FF_H_INCLUDED
