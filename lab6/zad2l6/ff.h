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

int input_check_mas()
{
    int val;
    while (scanf("%d", &val) != 1 || getchar()!='\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}

int** input_mas(int n, int m, int choice)
{
    int** mas;
    mas = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
		*(mas + i) = (int*)calloc(m, sizeof(int));
		if (choice==2) {
            for (int j=0; j<m; j++) {
                *(*(mas+i)+j) = input_check_mas();
            }
		}
		else {
            for (int j=0; j<m; j++) {
                *(*(mas+i)+j) = 1+rand()%100;
            }
        }
    }
    return mas;
}

int* find_sum(int **mas, int n, int m)
{
    int *sum;
    sum = (int*)calloc(n, sizeof(int));
    for (int i=0; i<n; i++) {
        sum[i]=0;
        for (int j=0; j<m; j++) {
            if (mas[i][j]%2==0) {sum[i]+=mas[i][j];}
        }
    }
    return sum;
}

void merge(int **mas, int n, int m)
{
    int mid = n / 2;
    if (n % 2 == 1) {mid++;}
    int t = 1;
    int **ar = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++)
    {
        ar[i]=(int*)malloc(m*sizeof(int));
    }
    int step;
    while (t < n) {
        step = t;
        int i = 0;
        int j = mid;
        int k = 0;
        int sum1=0, sum2=0;
        while (step <= mid) {
            while ((i < step) && (j < n) && (j < (mid + step))) {
                for(int p=0; p<m; p++) {
                    if(mas[i][p]%2==0) sum1+=mas[i][p];
                    if(mas[j][p]%2==0) sum2+=mas[j][p];
                }
                if (sum1<sum2) {
                    for(int p=0; p<m; p++){
                        ar[k][p] = mas[i][p];}
                    i++; k++;
                }
                else {
                    for(int p=0; p<m; p++){
                        ar[k][p] = mas[j][p];}
                    j++; k++;
                }
            }
            while (i < step) {
                for(int p=0; p<m; p++){
                    ar[k][p] = mas[i][p];}
                i++; k++;
            }
            while ((j < (mid + step)) && (j<n)) {
                for(int p=0; p<m; p++){
                    ar[k][p] = mas[j][p];}
                j++; k++;
            }
            step = step + t;
        }
        t = t * 2;
        for (i = 0; i<n; i++)
            for(int p=0; p<m; p++)
                mas[i][p] = ar[i][p];
    }
}

void output(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", *(*(mas + i) + j));
        printf("\n");
	}
}
