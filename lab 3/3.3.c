#include <stdio.h>

int main()
{
    int n,res;
    int NotCorrected=0;
    while (NotCorrected==0) {
        printf("Enter the number of elements of the first array: ");
        res=scanf("%i", &n);
        fflush(stdin);
        if (res==1) {NotCorrected=1;}
        else {printf("Wrong! Try again.\n");}
    }

    int mas1[100];
    for (int i=0; i<n; i++) {
        NotCorrected=0;
        while (NotCorrected==0) {
            printf("Enter value %i of the first array: ", i+1);
            res=scanf("%d", &mas1[i]);
            fflush(stdin);
            if (res==1) {NotCorrected=1;}
            else {printf("Wrong! Try again.\n");}
        }
    }

    int m; NotCorrected=0;
    while (NotCorrected==0) {
        printf("Enter the number of elements of the second array: ");
        res=scanf("%i", &m);
        fflush(stdin);
        if (res==1) {NotCorrected=1;}
        else {printf("Wrong! Try again.\n");}
    }

    int mas2[100];
    for (int i=0; i<m; i++) {
        NotCorrected=0;
        while (NotCorrected==0) {
            printf("Enter value %i of the second array: ", i+1);
            res=scanf("%d", &mas2[i]);
            fflush(stdin);
            if (res==1) {NotCorrected=1;}
            else {printf("Wrong! Try again.\n");}
        }
    }

    int NewMas[100],i=0,j=m-1,k=0;
    while (i<n || j>=0) {
        if (i>=n) { NewMas[k]=mas2[j]; k++; j--;}
        else  {
            if (j<0) {NewMas[k]=mas1[i]; k++; i++;}
            else {
                if (mas1[i]>mas2[j]) {NewMas[k]=mas1[i]; k++; i++;}
                else {NewMas[k]=mas2[j]; k++; j--;}
            }
        }
    }

    for (i=0; i<n+m; i++) {
        printf("Element %d of the new array: %d\n", i+1, NewMas[i]);
    }

    return 0;
}
