/*
 *  E11 ДЗ 4
 *  Отсортировать по последней цифре
 *  Считать массив из 10 элементов и отсортировать его по последней цифре.
 *
 *  Данные на входе:    10 целых чисел через пробел
 *  Этот же массив отсортированный по последней цифре
 *
 *  Пример №1
 *  Данные на входе:    14 25 13 30 76 58 32 11 41 97
 *  Данные на выходе:   30 11 41 32 13 14 25 76 97 58
 *
 *  Пример №2
 *  Данные на входе:    109 118 100 51 62 73 1007 16 4 555
 *  Данные на выходе:   100 51 62 73 4 555 16 1007 118 109
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

void Print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void SwapArr(int arr[], int i, int j)
{
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}

void SortArr(int arr[], int size)
{
    for( int i = 0; i < size - 1; i++)
    {
        if (arr[i] % 10 > arr[i+1] % 10)
        {
            SwapArr(arr, i, i+1);
            i = -1;
        }
    }
}

int main(int argc, char **argv)
{
    int arr[ARRAY_SIZE];
    Input(arr,ARRAY_SIZE);
    SortArr(arr, ARRAY_SIZE);
    Print(arr, ARRAY_SIZE);
    return 0;
}



