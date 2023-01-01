int check_choice()
{
    int choice;
	while (scanf("%d", &choice) != 1 || getchar()!='\n' || (choice!=1 && choice != 2)) {
		printf("Wrong! Try again.\n");
		rewind(stdin);
	}
}

int input_number(int choice1)
{
    int n;
    if (choice1==2){
        printf("Enter the number of elements in string: ");
        n=input_check();
    }
    else {
        n = 1+rand()%100;
        printf("The number of of elements in string: %d\n", n);
    }
    return n;
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

int size_str(char *str)
{
    int i=0;
    while (str[i]!='\0') i++;
    return i;
}

int ent_kol(int n, char *str)
{
    int kol=0;
    for (int i=0; i<n; i++) {
        if (*(str+i)==' ') {kol++;}
    }
    return kol;
}

char** add_string(int kol, char* str, int n)
{
    printf("%d", kol);
    for (int i=0; i<n; i++) {
        printf("%s", str[i]);
    }

    char** s;
    s = (char**)calloc(kol, sizeof(char*));
    int t=0;
    printf("%d\n", kol);
    for (int i = 0; i < kol; i++) {
        int m=1000;
		*(s + i) = (char*)calloc(m, sizeof(char));

		int j=0;
		printf("%s\n", str[t]);
		while (str[t]!=' ' && t<n) {s[i][j]+=s[i][j]+str[t]; t++; printf("%s", s[i]);}
		t++;
		printf("\n");

		m=size_str(s[i]);

		printf("m=%s\n", m);
		*(s+i) = (char*)realloc(*(s+i), m*sizeof(char));
    }
    return s;
}

void first()
{
    int n=1000;
   // printf("select how to enter the number of elements in string: 1 for random input, 2 for keyboard input: ");
   // int choice=check_choice();
   // n=input_number(choice);

    char *str;
    str = (char*)calloc(n, sizeof(char));

    fgets(str, n+1, stdin);
    n=size_str(str);
    str = (char*)realloc(str, n * sizeof(char));
    for (int i=0; i<n; i++) {
        printf("%s", str[i]);
    }
    int kol = ent_kol(n,str);
    kol++;
    printf("koll=%d\n", kol);
    char **s;

  //  s=add_string(kol,str,n);

   /* for (int i=0; i<kol; i++) {
        printf("%s\n", *(s+i));
    } */

    printf("%s", str);
}
