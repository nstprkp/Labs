#include <stdio.h>
#include <stdlib.h>
#include "ff.h"

int main()
{
    int n;
    float *mas=NULL;

    printf("Enter the number of elements: ");
    n=input_check();

    mas = memory_alloc(n);

    printf("Enter array:\n");
    input_mas(mas,n);

    delete_check(mas,&n);

    output(mas,n);
    free(mas);
    return 0;
}

