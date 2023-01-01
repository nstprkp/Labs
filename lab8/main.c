#include "header.h"

void main(int argc, char **argv) {
    printf("Your string:\n");
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    int* mas =  made_mas(argv,argc);

    for (int i=0; i<argc-1; i++) {argv[i]=argv[i+1];}
    for (int i=0; i<argc-1; i++) {mas[i]=mas[i+1];}

    sort(mas,argv,0, argc-1);

    printf("\nAfter sort:\n");
    for (int i=0; i<argc-1; i++) { printf("%s\n", argv[i]);}
}
