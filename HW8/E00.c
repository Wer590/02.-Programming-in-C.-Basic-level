/*
 *  E7 Практик 2
 *  Инверсия половинок
 *  Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива.
 *  Необходимо изменить считанный массив и напечатать его одним циклом.
 *
 *  Данные на входе:    10 целых элементов массива через пробел.
 *  Данные на выходе:   10 целых элементов массива через пробел.
 *
 *  Пример №1
 *  Данные на входе:    4 -5 3 10 -4 -6 8 -10 1 0
 *  Данные на выходе:   -4 10 3 -5 4 0 1 -10 8 -6
 *
 *  Пример №2
 *  Данные на входе:    1 2 3 4 5 6 7 8 9 10
 *  Данные на выходе:   5 4 3 2 1 10 9 8 7 6
 *
 *
 */

#include <stdio.h>

enum {ARRAY_SIZE = 10};

void Input(int arr[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void SwapArr(int arr[], int i, int j)
{
    //int temp = arr[i];
    //arr[i]=arr[j];
    //arr[j]=temp;
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}

void Print(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void SwapArr(int arr[], int i, int j)
{
    //int temp = arr[i];
    //arr[i]=arr[j];
    //arr[j]=temp;
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}

void InversionToPrint(int arr[], int size)
{
    for( int i = 0; i < size; i++) {
        if ((i == 0) || (i == 1))
        {
            SwapArr(arr, i, size/2-i-1);
        }
        if (( i == size/2 ) ||( i == size/2 + 1))
        {
            SwapArr(arr, i, (size -1) -(i-size/2));
        }
        printf("%d ", arr[i]);
    }
}

int main(int argc, char **argv)
{
    int arr[ARRAY_SIZE];
    Input(arr, ARRAY_SIZE);
    Print(arr, ARRAY_SIZE);
    SwapArr(arr, 0, 4);
    Print(arr, ARRAY_SIZE);
    InversionPrint(arr, ARRAY_SIZE);
    return 0;
}
