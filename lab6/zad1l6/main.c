#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "ff.h"

int main()
{
    srand(time(NULL));
    double time_spent = 0.0, time_sp = 0.0;
    int n;

    printf("select how to enter the number of elements: 1 for random input, 2 for keyboard input: ");
    int choice1=check_choice();
    n = input_number(choice1);

    printf("select how to enter array: 1 for random input, 2 for keyboard input: ");
    int choice2 = check_choice();

    int *mas;
    mas = input_mas(n,choice2);
    int *a;
    a = mas_same(mas,n);
   /* if (choice2==1) {
        printf("Your array:\n");
        output(mas,n);
    }*/

    clock_t begin = clock();
    selectSort(mas,n);
    clock_t end = clock();
    time_spent += (double)(end-begin)/CLOCKS_PER_SEC;

 //   printf("New array:\n");
   // output(mas,n);
   // output(a,n);
    printf("Time for select sort is: %f s\n", time_spent);
    clock_t beg = clock();
    shellSort(a,n);
    clock_t en = clock();
    time_sp += (double)(en-beg)/CLOCKS_PER_SEC;
    printf("Time for Shell sort is: %f s", time_sp);
    free(mas);
    return 0;
}
