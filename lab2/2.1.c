#include <stdio.h>

int main()
{
    int x=1,y=1;
    int Solution=0;
    while (x<=9 && Solution==0) {
        y=1;
        while (y<=9 && Solution==0) {
            if (x+y==11 && x*10+y+27==y*10+x) { Solution=1;}
            else {y++;}
        }
        if (Solution==0) {x++;}
    }
    if (x>9) { printf("We don't have a solution.\n");}
    else {printf("Your solution is: x=%i, y=%i.\n", x, y);}
    return 0;
}