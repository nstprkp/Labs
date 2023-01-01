#include "header.h"

int size_str(char *str)
{
    int i=0;
    while (str[i]!='\0') i++;
    return i;
}

int made_mas(char** argv, int argc)
{
    int* mas = (int*)calloc(argc, sizeof(int));
    for (int i=1; i<argc; i++){
        mas[i]=1;
        for (int j=0; j<size_str(argv[i]); j++) {
            if (argv[i][j]==' ') {mas[i]++;}
        }
    }
    return mas;
}

void sort(int* array[], char** argv, int low, int high) {
    if (high <= low)
        return;
    int mid = low + (high - low) / 2;
    sort(array, argv, low, mid);
    sort(array, argv, mid + 1, high);
    merge(array, argv, low, mid, high);
};

void merge(int* array[], char** argv, int low, int mid, int high) {
    int sizeLeft = mid - low + 1;
    int sizeRight= high - mid;
    int left[sizeLeft];
    int right[sizeRight];
    char** left_str = (char**)calloc(sizeLeft, sizeof(char*));
    char** right_str = (char**)calloc(sizeRight, sizeof(char*));


    for (int i = 0; i < sizeLeft; i++) {
        left[i] = array[low + i];

        int q=size_str(argv[low + i]);
        free(left_str[i]);
        *(left_str + i) = calloc(q, sizeof(char));
        int p=0,r=0;
        while (p<q) {left_str[i][p++]=argv[low + i][r++];}
    }
    for (int i = 0; i < sizeRight; i++) {
        right[i] = array[mid + i + 1];

        int q=size_str(argv[mid + i + 1]);
        free(right_str[i]);
        *(right_str + i) = calloc(q, sizeof(char));
        int p=0,r=0;
        while (p<q) {right_str[i][p++]=argv[mid + i + 1][r++];}
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int i = low;
    while (leftIndex < sizeLeft && rightIndex < sizeRight) {
        if (left[leftIndex] < right[rightIndex]) {
            array[i] = left[leftIndex];

            int q=size_str(left_str[leftIndex]);
            free(argv[i]);
            *(argv + i) = calloc(q, sizeof(char));
            int p=0,r=0;
            while (p<q) {argv[i][p++]=left_str[leftIndex][r++];}

            leftIndex++;
        } else {
            array[i] = right[rightIndex];

            int q=size_str(right_str[rightIndex]);
            free(argv[i]);
            *(argv + i) = calloc(q, sizeof(char));
            int p=0,r=0;
            while (p<q) {argv[i][p++]=right_str[rightIndex][r++];}

            rightIndex++;
        }
        i++;
    }
    while (leftIndex < sizeLeft) {
        array[i] = left[leftIndex];

        int q=size_str(left_str[leftIndex]);
        free(argv[i]);
        *(argv + i) = calloc(q, sizeof(char));
        int p=0,r=0;
        while (p<q) {argv[i][p++]=left_str[leftIndex][r++];}

        leftIndex++;
        i++;
    }
    while (rightIndex < sizeRight) {
        array[i] = right[rightIndex];

        int q=size_str(right_str[rightIndex]);
        free(argv[i]);
        *(argv + i) = calloc(q, sizeof(char));
        int p=0,r=0;
        while (p<q) {argv[i][p++]=right_str[rightIndex][r++];}

        rightIndex++;
        i++;
    }
}
