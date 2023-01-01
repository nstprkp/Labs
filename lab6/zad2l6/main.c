#include <stdio.h>
#include <stdlib.h>
#include "ff.h"

int main()
{
    srand(time(NULL));
    int n,m;

    printf("select how to enter matrix rows: 1 for random input, 2 for keyboard input: ");
    int choice1=check_choice();

    if (choice1==2){
        printf("Enter the number of matrix rows: ");
        n=input_check();
    }
    else {
        n = 1+rand()%100;
        printf("The number of matrix rows: %d\n", n);
    }

    printf("select how to enter matrix columns: 1 for random input, 2 for keyboard input: ");
    int choice2=check_choice();

    if (choice2==2){
        printf("Enter the number of matrix columns: ");
        m=input_check();
    }
    else {
        m = 1+rand()%100;
        printf("The number of matrix columns: %d\n", m);
    }

    int** mas;
    printf("select how to enter matrix: 1 for random input, 2 for keyboard input: ");
    int choice3=check_choice();

    mas = input_mas(n,m,choice3);

    printf("Your array:\n");
    output(mas,n,m);

    merge(mas,n,m);
    printf("New array:\n");
    output(mas,n,m);
    free(mas);
    return 0;
}
