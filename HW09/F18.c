/*
 * F18
 * Массив максимумов
 * Написать функцию и программу, демонстрирующую работу данной функции.
 * Дана целочисленная квадратная матрица 10 х 10. реализовать алгоритм
 * вычисления суммы максимальных элементов из каждой строки. Напечатать
 * значение этой суммы. Предполагается, что в каждой строке такой элемент
 * единственный. Реализовать функцию поиска максимума в строке из 10 элементов
 *
 * Данные на входе:     10 строк, состоящих из 10 целых чисел через пробел.
 * Данные на выходе:    Одно целое число
 *
 * Пример
 * Данные на входе:     61 75 55 2 35 34 77 93 28 49 11 34 22 78 19 14 67 67 11 0 72 39 23 53 92 51 60 34 71 63 14 27 72 6 0 79 98 56 30 15 31 16 3 4 95 59 25 17 11 20 5 93 21 61 96 30 79 38 73 40 89 4 66 19 36 99 67 67 92 36 87 54 7 35 40 43 44 46 4 69 98 57 20 75 9 66 85 9 39 31 8 90 94 25 12 30 18 10 23 15
 * Данные на выходе:    930
 *
 *
 */

#include <stdio.h>

void InputArray(int size_a, int size_b, int arr[size_a][size_b])
{

    for (int i = 0; i < size_a; i++)
    {
        for (int j = 0; j < size_b; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

int Max(int size_a, int size_b, int arr[size_a][size_b])
{
    int max = arr[size_a][0];
    for (int i = 1; i < size_b; i++)
    {
        if (max < arr[size_a][i])
        {
            max = arr[size_a][i];
        }
    }
    return max;
}

void SumMax(int size_a, int size_b, int arr[size_a][size_b])
{
    int sum = 0;
    for (int i = 0; i < size_a; i++)
    {
        sum += Max(i, size_b, arr);
    }
    printf("%d\n", sum);
}

int main()
{
    enum {BUFFER_SIZE_A = 10, BUFFER_SIZE_B = 10};
    int arr[BUFFER_SIZE_A][BUFFER_SIZE_B] = {0};
    InputArray(BUFFER_SIZE_A, BUFFER_SIZE_B, arr);
    SumMax(BUFFER_SIZE_A, BUFFER_SIZE_B, arr);
    return 0;
}



