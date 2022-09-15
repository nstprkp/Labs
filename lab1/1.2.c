#include <stdio.h>

int main()
{
    int a,b,c;
    printf("a = "); scanf("%i", &a);
    printf("b = "); scanf("%i", &b);
    printf("c = "); scanf("%i", &c);
    if (a==b || a==c || b==c) { printf("There are equal numbers.\n");}
    else { printf("There are no equal numbers.\n");}
    return 0;
}