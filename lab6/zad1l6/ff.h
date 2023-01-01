

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

int input_number(int choice1)
{
    int n;
    if (choice1==2){
        printf("Enter the number of matrix rows and columns: ");
        n=input_check();
    }
    else {
        n = 1+rand()%100;
        printf("The number of matrix rows and columns: %d\n", n);
    }
    return n;
}

int* memory_alloc(int n)
{
    int *val=(int*)malloc(n * sizeof(int));
    return val;
}

//ввод массива
int* input_mas(int n, int choice2)
{
    int* mas;
    mas = (int*)calloc(n, sizeof(int));

    if (choice2==2){
        for (int i=0; i<n; i++) {
            *(mas+i) = input_check();
        }
    }
    else {
        for (int i=0; i<n; i++) {
            *(mas+i) = 1+rand()%100;
        }
    }
    return mas;
}

void selectSort(int *mas, int n)
{
    for (int i=0; i<n-1; i++) {
        int i1=i;
        if (*(mas+i)%2==0) {
            for (int j=i+1; j<n; j++) {
                if (mas[j]<mas[i1] && mas[j]%2==0) { i1=j;}
            }
            int temp=mas[i];
            mas[i]=mas[i1];
            mas[i1]=temp;
        }
    }
}

int mas_same(int *mas, int n)
{
    int* a;
    a = (int*)calloc(n, sizeof(int));
    for (int i=0; i<n; i++) {
        a[i]=mas[i];
    }
    return a;
}

void shellSort(int *a, int n)
{
    int flg=0;
    for (int gap = n/2; gap>0; gap/=2)
    do {
        flg=0;
        for (int i=0, j=gap; j<n; i++, j++)
            if (a[i]%2==0 && a[j]%2==0 && a[i]>a[j]){
                int t=a[j];
                a[j]=a[i];
                a[i]=t;
                flg=1;
            }
    } while (flg);
}

void output(int *mas, int n)
{
    for (int i=0; i<n; i++) {
        printf("%d ", *(mas+i));
    }
    printf("\n");
}

