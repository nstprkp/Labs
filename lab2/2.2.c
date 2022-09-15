#include <stdio.h>

int main()
{
    float n;
    printf("Enter the number: ");
    scanf("%f", &n);
    float ans=0;
    float i=1;
    while (i<=n) {
        ans+=(1.0/i);
        i++;
    }
    if (n==0) {printf("We can't do this.\n");}
    else { printf("Answer: %.2f\n", ans);}
    return 0;
}