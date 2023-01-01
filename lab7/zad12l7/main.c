#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(void)
{
    void (*message) (void);

    printf("select task: 1 for first task, 2 for second task: ");
    int choice=check_choice();
    if (choice==1) {
        message=first;
        message();
    }
    else {
        message=second;
        message();
    }

    return 0;
}
