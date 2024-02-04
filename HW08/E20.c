/*
 *  E20 ДЗ *
 *  Переставить цифры
 *  Переставить цифры в числе так, чтобы получилось максимальное число.
 *  Данные на входе:    Одно целое не отрицательное число
 *  Данные на выходе:   Целое неотрицательное число
 *
 *  Пример №1
 *  Данные на входе:    1229
 *  Данные на выходе:   9221
 *
 *  Пример №2
 *  Данные на входе:    19
 *  Данные на выходе:   91
 *
 *
 */

#include <stdio.h>

enum {ARRAY_SIZE = 12};

void SwapArr(int arr[], int i, int j)
{
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}

int Func(int arr[], int num)
{
    int index = 0;
    while (num > 0)
    {
        arr[index] = num % 10;
        index ++;
        num /= 10;
    }
    return index;
}

void ArrSort(int arr[], int size)
{
    int no_swap = 1;
    for( int i = 0; i < size - 1; i++)
    {
        no_swap = 1;
        for (int j = i + 1; j < size; j++)
        {

            if (arr[i] > arr[j])
            {
                SwapArr(arr, i, j);
                no_swap = 0;
            }
        }
        if(no_swap)
            break;
    }
}

int ConvertArrToNum(int arr[], int size)
{
    int result = 0;
    for(int i = size-1; i >= 0; i--)
    {
        result += arr[i];
        if (i > 0)
            result *= 10;
    }
    return result;
}

int main(int argc, char **argv)
{
    int arr[ARRAY_SIZE] = {0};
    int number = 0;
    scanf("%d", &number);
    int index = Func(arr, number);
    ArrSort(arr, index);
    int num_out = ConvertArrToNum(arr, index);
    printf("%d", num_out);
    return 0;
}



