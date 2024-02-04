/*
 * F14
 * Сумма в интервале
 * Написать функцию и программу, демонстрирующую работу данной функции,
 * которая возвращает сумму элементов в заданном отрезке [from, to] для
 * массива. Прототип функции
 * int sum_between_ab(int from, int to, int size, int a[])
 *
 * Данные на входе:    Функция принимает концы отрезка from и to, размер
 *                      массива, массив целых чисел
 * Функция возвращает сумму элементов в интервале [from, to]
 *
 * Пример №1
 * Данные на входе:    4 6 1 2 3 4 5 6 7 8 9 10
 * Данные на выходе:   15
 *
 * Пример №2
 * Данные на входе:    6 4 1 2 3 4 5 6 7 8 9 10
 * Данные на выходе:   15
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

int sum_between_ab(int from, int to, int size, int a[])
{
    int result = 0;
    int temp = 0;
    if (from > to) {
        temp = to;
        to = from;
        from = temp;
    }
    for (int i = from; i <= to && i < size; i++)
    {
        result+= a[i];
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
    int res = sum_between_ab(from, to, BUFFER_SIZE, arr);
    printf("%d", res);
    return 0;
}



