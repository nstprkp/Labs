
#include <stdio.h>

int main()
{
    int n,res;
    int NotCorrected=0;
    while (NotCorrected==0) {
        printf("Enter the number: ");
        res=scanf("%i", &n);
        fflush(stdin);
        if (res==1) {NotCorrected=1;}
        else {printf("Wrong! Try again.\n");}
    }
    int mas[100];
    for (int i=0; i<n; i++) {
        NotCorrected=0;
        while (NotCorrected==0) {
            printf("Enter value %i: ", i+1);
            res=scanf("%d", &mas[i]);
            fflush(stdin);
            if (res==1) {NotCorrected=1;}
            else {printf("Wrong! Try again.\n");}
        }
    }

    int i=n-1;
    int second;
    while (i>=0 && mas[i]%2!=0) {i--;}
    if (i<0) {second=-1;}
    else {second=i;}

 //   printf("%i, %i\n", first, second);
    int NewMas[100];
    if (second==-1) {
        printf("We don't have even numbers.");
    }
    else {
        for (i=0; i<=second; i++) {
            NewMas[i]=mas[i];
            printf("Value %d: %d\n", i+1, NewMas[i]);
        }
    }

    return 0;
}