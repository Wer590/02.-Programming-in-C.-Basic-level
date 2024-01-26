/*
 *  E1 ДЗ 1
 *  Среднее арифметическое чисел
 *  Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.
 *
 *  Данные на входе:    5 целых ненулевых чисел через пробел
 *  Данные на выходе:   Одно число в формате "%.3f"
 *
 *  Пример №1
 *  Данные на входе:    4 15 3 10 14
 *  Данные на выходе:   9.200
 *
 *  Пример №2
 *  Данные на входе:    1 2 3 4 5
 *  Данные на выходе:   3.000
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

float Average(int arr[], int size)
{
    int average = 0;
    for (int i=0; i<size; i++)
    {
        average += arr[i];
    }
    return (float)average/size;
}

int main(int argc, char **argv)
{
    int arr[ARRAY_SIZE];
    Input(arr, ARRAY_SIZE);
    printf("%.3f\n", Average(arr,ARRAY_SIZE));
    return 0;
}
