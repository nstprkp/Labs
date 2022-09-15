#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%i", &n);
    int x=1,y=2;
    while (y!=n) {
        int t=y;
        y=x+y; x=t;
    }
    printf("Previous number: %i\n", x);
    printf("Subsequent number: %i\n", x+y);
    return 0;
}