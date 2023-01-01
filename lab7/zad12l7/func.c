#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* getStr(char *s, int k)
{
  int c, i=0;
  while(--k > 0 && (c = getchar())!=EOF && c != '\n')
      s[i++] = c;
  s[i] = '\0';
  return s;
}

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
    char** s;
    s = (char**)calloc(kol, sizeof(char*));
    int t=0;

    for (int i = 0; i < kol; i++) {
        int m=1000;
		*(s + i) = (char*)calloc(m, sizeof(char));

		int j=0;
		while (str[t]!=' ' && t<n) {s[i][j++]=str[t]; t++;}
		t++;

		m=size_str(s[i]);

		*(s+i) = (char*)realloc(*(s+i), m*sizeof(char));
    }
    return s;
}

int* made_mas(char** s, int kol)
{
    int* mas = (int*)calloc(kol, sizeof(int));
    for (int i=0; i<kol; i++) {mas[i]=1;}

    for (int i=0; i<kol-1; i++) {
        for (int j=i+1; j<kol; j++){
            if (size_str(s[i])==size_str(s[j]) && mas[i]!=-1) {
                int t=0;
                for (int k=0; k<size_str(s[i]); k++) {
                    if (s[i][k]==s[j][k]){t++;}
                }
                if (t==size_str(s[i])) {mas[i]++; mas[j]=-1;}
            }
        }
    }
    return mas;
}

int find_nom(int* mas, int kol)
{
    int maxx=mas[0], nom=0;
    for (int i=0; i<kol; i++) {
        if (mas[i]>mas[0]) {maxx=mas[i]; nom=i;}
    }
    return nom;
}

char* input_str(int n)
{
    char *str;
    str = (char*)calloc(n, sizeof(char));

    getStr(str, n+1);
  //  fgets(str, n+1, stdin);
    n=size_str(str);
    str = (char*)realloc(str, n * sizeof(char));
    return str;
}

int* check_same(char** str1, char** str2, int kol1, int kol2, char c)
{
    int* mas = (int*)calloc(kol1, sizeof(int));
    for (int i=0; i<kol1; i++) {mas[i]=0;}

    //printf("%c", str1[0][0]);

    for (int i=0; i<kol1; i++) {
        for (int j=0; j<kol2; j++) {
            if (size_str(str1[i])==size_str(str2[j]) && str1[i][0]==str2[j][0] && str1[i][0]==c) {
               // printf("YESS1 i=%d j=%d\n", i, j);
                int t=0;
                for (int k=0; k<size_str(str1[i]); k++) {
                    if (str1[i][k]==str2[j][k]){t++;}
                }
              //  printf("t=%d size=%d\n", t, size_str(str1[i]));
                if (t==size_str(str1[i])) {mas[i]=1; }
            }
        }
    }
    return mas;
}

char** new_str(char** str1, int *mas, int kol1)
{
    int kol=1000;

    char **str = (char**)calloc(kol, sizeof(char*));
    kol=0;
    for (int i=0; i<kol1; i++) {
        if (mas[i]==0) {
            int m=size_str(str1[i]);
            *(str + kol) = (char*)calloc(m, sizeof(char));

            *(str+kol)=*(str1+i);

            m=size_str(str[kol]);

            *(str+kol) = (char*)realloc(*(str+kol), m*sizeof(char));
            kol++;
        }
    }
    return str;
}

int find_kol(int *mas, int kol1)
{
    int kol=0;
    for (int i=0; i<kol1; i++){
        if (mas[i]==0) {kol++;}
    }
    return kol;
}

void first()
{
    int n=1000;
    char *str = (char*)calloc(n, sizeof(char));

    printf("Enter string: \n");
    getStr(str, n+1);

    n=size_str(str);
    str = (char*)realloc(str, n * sizeof(char));

    int kol = ent_kol(n,str);
    kol++;

    char **s;

    s=add_string(kol,str,n);

    int *mas;

    mas=made_mas(s,kol);

    int nom=find_nom(mas,kol);
    printf("The most often string: %s\n", s[nom]);

}

void second()
{
    int n=1000;
    printf("Enter string 1:\n");
    char *s1 = input_str(n);
    n=size_str(s1);
    int m=1000;
    printf("Enter string 2:\n");
    char *s2=input_str(m);
    m=size_str(s2);

    char c;
    printf("Enter char: ");
    scanf("%c", &c);

    int kol1 = ent_kol(n,s1);
    kol1++;

    int kol2 = ent_kol(m,s2);
    kol2++;

    char **str1;
    str1=add_string(kol1,s1,n+1);

    char **str2;
    str2=add_string(kol2,s2,m+1);

    int *mas=(int*)calloc(kol1, sizeof(int));
    mas=check_same(str1, str2, kol1, kol2, c);


    char **str;
    str=new_str(str1,mas, kol1);
    int kol=find_kol(mas,kol1);

    printf("Edited string:\n");
    for (int i=0; i<kol; i++) { printf("%s ", str[i]);}
    free(str1);
    free(str2);
    free(mas);
}
