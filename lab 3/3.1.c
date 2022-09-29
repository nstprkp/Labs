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
    float a[100];
    for (int i=0; i<n; i++) {
        NotCorrected=0;
        while (NotCorrected==0) {
            printf("Enter value %i: ", i+1);
            res=scanf("%f", &a[i]);
            fflush(stdin);
            if (res==1) {NotCorrected=1;}
            else {printf("Wrong! Try again.\n");}
        }
    }
    float min=a[0];
    for (int i=0; i<n; i++) {
        if (a[i]<min) {min=a[i];}
    }
    printf("Min value: %.2f.\n", min);

    int i=0,first;
    while (i<n && a[i]<0) {i++;}
    if (i>=n) {first=-1;}
    else {first=i;}

    i=n-1;
    int second;
    while (i>=0 && a[i]<0) {i--;}
    if (i<0) {second=-1;}
    else {second=i;}

    float sum=0;
    if (first==-1 || second==-1) {
        printf("We don't have positive number.");
    }
    else {
        for (i=first+1; i<second; i++) {sum+=a[i];}
        printf("Sum value: %.2f.\n", sum);
    }

    return 0;
}
