/*
 *  E2
 *  Найти минимум
 *  Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.
 *
 *  Данные на входе:    5 целых чисел через пробел
 *  Данные на выходе:   Одно единственное целое число
 *
 *  Пример №1
 *  Данные на входе:    4 15 3 10 14
 *  Данные на выходе:   3
 *
 *  Пример №2
 *  Данные на входе:    1 2 3 4 -5
 *  Данные на выходе:   -5
 *
 *
 */

#include <stdio.h>

enum {ARRAY_SIZE = 5};

void Input(int arr[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int Min(int arr[], int size)
{
    int min = arr[0];
    for (int i=1; i<size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

int main(int argc, char **argv)
{
    int arr[ARRAY_SIZE];
    Input(arr, ARRAY_SIZE);
    printf("%d\n", Min(arr,ARRAY_SIZE));
    return 0;
}
