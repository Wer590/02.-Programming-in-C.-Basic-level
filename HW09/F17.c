/*
 * F17
 * След матрицы
 * Написать функцию и программу, демонстрирующую работу данной функции,
 * которая находит след матрицы в двумерном массиве. Показать пример ее
 * работы на матрице из 5 на 5 элементов. След матрицы - это сумма
 * элементов на главной диагонали.
 *
 * Данные на входе:     25 целых чисел через пробел.
 * Данные на выходе:    Одно целое число.
 *
 * Пример
 * Данные на входе:     1 1 1 1 1
 *                      2 2 2 2 2
 *                      3 3 3 3 3
 *                      4 4 4 4 4
 *                      5 5 5 5 5
 * Данные на выходе:    15
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

void MatrixTrace(int size_a, int size_b, int arr[size_a][size_b])
{
    int sum = 0;
    for (int i = 0; i < size_a; i++)
    {
        for (int j = 0; j < size_b; j++)
        {
            if (i == j)
            {
                sum += arr[i][j];
            }
        }        
    }
    printf("%d\n", sum);
}

int main()
{
    enum {BUFFER_SIZE_A = 5, BUFFER_SIZE_B = 5};
    int arr[BUFFER_SIZE_A][BUFFER_SIZE_B] = {0};
    InputArray(BUFFER_SIZE_A, BUFFER_SIZE_B, arr);
    MatrixTrace(BUFFER_SIZE_A, BUFFER_SIZE_B, arr);    
    return 0;
}



