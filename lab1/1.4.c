#include <stdio.h>

int main()
{
    int a;
    printf("Enter the number: "); scanf("%i", &a);
    if (a==0) {printf("Zero\n");}
    else {
        if (a==1) {printf("One\n");}
        else {
            if (a==2) {printf("Two\n");}
            else {
                if (a==3) {printf("Three\n");}
                else {
                    if (a==4) {printf("Four\n");}
                    else {
                        if (a==5) {printf("Five\n");}
                        else {
                            if (a==6) {printf("Six\n");}
                            else {
                                if (a==7) {printf("Seven\n");}
                                else {
                                    if (a==8) {printf("Eight\n");}
                                    else {printf("Nine\n");}
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}