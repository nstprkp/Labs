#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c;
    scanf("%f %f %f", &a, &b, &c);
    if (a!=0 && b!=0 && c!=0) {
        float srg,t;
        t=1.0/3.0;
        srg = pow(a*b*c,t);
        printf("Geometric mean = %.2f\n", srg);
    }
    else {
        float sra=0;
        sra=(a+b+c)/3.0;
        printf("Average = %.2f\n", sra);
    }
    return 0;
}