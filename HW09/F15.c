/*
 * F15
 * Больше по модулю
 * Написать функцию и программу, демонстрирующую работу данной функции, 
 * которая определяет в массиве, состоящем из положительных и отрицательных чисел, 
 * сколько элементов превосходят по модулю максимальный элемент. 
 * Прототип функции
 * int count_bigger_abs(int n, int a[]);
 * 
 * Данные на входе:     Функция получает размер массива и массив целых чисел 
 * Данные на выходе:    Функция возвращает целое число равное количеству элементов 
 *                      превосходящих по модулю максимальный элемент. 
 * 
 * Пример
 * Данные на входе:     1 -20 3 4 -50 6 7 8 9 10 
 * Данные на выходе:    2 
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>


void Input(int size, int arr[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int Max(int size, int arr[])
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int count_bigger_abs(int n, int a[])
{
    int result = 0;
    int max = Max(n, a);
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) > max)
        {
            result++;
        }
    }
    return result;
}

int main()
{
    enum {BUFFER_SIZE = 10};
    int arr[BUFFER_SIZE] = {0};
    Input(BUFFER_SIZE, arr);
    int res = count_bigger_abs(BUFFER_SIZE, arr);
    printf("%d", res);
    return 0;
}



