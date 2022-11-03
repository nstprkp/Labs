#ifndef FF_H_INCLUDED
#define FF_H_INCLUDED

//�������� ����� ���������� ��������� �������
int input_check()
{
    int val;
    while (scanf("%d", &val) != 1 || getchar()!='\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}

//�������� ����� ��������� �������
float input_check_mas()
{
    float val;
    while (scanf("%f", &val) != 1 || getchar()!='\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}

//���� �������
void input_mas(float* m, int n)
{
    for (int i=0; i<n; i++) {
        m[i]=input_check_mas();
    }
}

//��������� ������ ��� �������
int* memory_alloc(int n)
{
    int *val=(float*)malloc(n * sizeof(float));
    return val;
}

//��������
void deleteElement(float** array, int* size, int index)
{
    *size = *size - 1;

    for (int i = index; i < *size; i++)
        (*array)[i] = (*array)[i + 1];

    *array = realloc(*array, *size * sizeof(float));
}

//����� �������
void output(float* m,int n)
{
    printf("New array:\n");
    for (int i=0; i<n; i++) {
        printf("%.2f ", m[i]);
    }
}

#endif // FF_H_INCLUDED
