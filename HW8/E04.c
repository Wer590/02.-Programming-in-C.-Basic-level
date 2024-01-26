/*
 *  E4 Демо 1
 *  Два максимума
 *  Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.
 *
 *  Данные на входе:    10 целых чисел через пробел.
 *  Данные на выходе:   Сумма двух максимальных элементов.
 *
 *  Пример №1
 *  Данные на входе:    4 -5 3 10 -4 -6 8 -10 1 0
 *  Данные на выходе:   18
 *
 *  Пример №2
 *  Данные на входе:    1 2 3 4 5 6 7 8 9 10
 *  Данные на выходе:   19
 *
 *
 */

#include <stdio.h>

enum {ARRAY_SIZE = 10};

void Input(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int Sum2Max(int arr[], int size)
{
    int max1 = 0;
    int max2 = 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[max1])
        {
            max2 = max1;
            max1 = i;
        }
        else if (arr[i] > arr[max2])
        {
            max2 = i;
        }

    }
    return arr[max1] + arr[max2];
}

int main(int argc, char **argv)
{
    int arr[ARRAY_SIZE];
    Input(arr, ARRAY_SIZE);
    printf("%d ", Sum2Max(arr, ARRAY_SIZE));
    return 0;
}
