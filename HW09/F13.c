/*
 * F13
 * В заданном интервале
 * Написать функцию и программу, демонстрирующую работу данной функции,
 * которая возвращает количество элементов на заданном отрезке [from, to] для массива.
 * Прототип функции
 * int count_between(int from, int to, int size, int a[])

 * Данные на входе:     Функция принимает значения концов отрезка from и to,
 *                      размер массива, массив целых чисел.
 * Данные на выходе:    Функция возвращает целое число - количество чисел в интервале [from, to]
 *
 * Пример
 * Данные на входе:     4 6 1 2 3 4 5 6 7 8 9 10
 * Данные на выходе:    3
 *
 *
 */

#include <stdio.h>


void Input(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int count_between(int from, int to, int size, int a[])
{
    int result = 0;
    for (int i = from - 1; i <= to - 1 && i < size; i++)
    {
        result++;
    }
    return result;
}

int main()
{
    enum {BUFFER_SIZE = 10};
    int arr[BUFFER_SIZE];
    int from = 0;
    int to = 0;
    scanf("%d %d", &from, &to);
    Input(arr, BUFFER_SIZE);
    int res = count_between(from, to, BUFFER_SIZE, arr);
    printf("%d", res);
    return 0;
}



