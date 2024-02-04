/*
 * F8 Практ 2
 * Пропущенное число
 * По мотивам статьи на сайте https://itnan.ru/post.php?c=1&p=538298
 * Написать функцию и программу, демонстрирующую работу данной функции.
 * В последовательности записаны целые числа от M до N ( M меньше N,
 * M больше или равно 1) в произвольном порядке, но одно из чисел пропущено
 * (остальные встречаются ровно по одному разу). N не превосходит 1000.
 * Последовательность заканчивается числом 0. Определить пропущенное число.
 *
 * Данные на входе:     Последовательность целых чисел от M до N. M, N не превосходит 1000.
 * Данные на выходе:    Одно целое число
 *
 * Пример №1
 * Данные на входе:     2 3 1 4 7 6 9 8 10 0
 * Данные на выходе:    5
 *
 * Пример №2
 * Данные на входе:     41 40 39 38 37 36 34 33 32 31 50 49 48 47 46 45 44 43 42 30 0
 * Данные на выходе:    35
 *
 *
 */

#include <stdio.h>

void Input(int arr[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
}


int Max(int arr[], int size)
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

int Min(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

int FindMissing(int arr[], int size)
{
    int result = 0;
    int min = Min(arr, size);
    int max = Max(arr, size);

    for (int i = min; i <= max; i++)
    {
        result ^= i;
        //result += i;
    }

    for (int i = 0; i < size; i++)
    {
        result ^=arr[i];
        //result -=arr[i];
    }
    return result;
}

int main()
{
    printf("Enter the number of array elements\nsize = ");
    int size = 0;
    scanf("%d", &size);
    int array[size];
    Input(array, size);
    printf("%d\n", FindMissing(array, size));
    return 0;
}


