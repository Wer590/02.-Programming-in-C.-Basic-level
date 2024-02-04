/*
 *  E8 Демо 2
 *  Инверсия каждой трети
 *  Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.
 *
 *  Данные на входе:    12 целых чисел через пробел
 *  Данные на выходе:   12 целых чисел через пробел
 *
 *  Пример №1
 *  Данные на входе:    4 -5 3 10 -4 -6 8 -10 1 0 5 7
 *  Данные на выходе:   10 3 -5 4 -10 8 -6 -4 7 5 0 1
 *
 *  Пример №2
 *  Данные на входе:    1 2 3 4 5 6 7 8 9 10 11 12
 *  Данные на выходе:   4 3 2 1 8 7 6 5 12 11 10 9
 *
 *
 */

#include <stdio.h>

enum {ARRAY_SIZE = 12};

void Input(int arr[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void SwapArr(int arr[], int i, int j)
{
    // при помощи XOR
    // А все таки что лучше XOR или отдельная переменная temp?
    // где выиграваем в скорости или в занимаеной памяти?
    // короче не понятно, но интересно.
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}

void InversionToPrint(int arr[], int size)
{
    for( int i = 0; i < size; i++) {
        if (i == 0 || i == 1)
        {
            SwapArr(arr, i, size / 3 - i - 1);
        }
        else if (i == size / 3)
        {
            SwapArr(arr, i, (size / 3 + i - 1));
        }
        else if (i == size / 3 + 1)
        {
            SwapArr(arr, i, (size / 3 + i - 3));
        }
        else if (i == size - size / 3)
        {
            SwapArr(arr, i, (size / 3 + i - 1));
        }
        else if (i == size - size / 3 + 1)
        {
            SwapArr(arr, i, (size / 3 + i - 3));
        }
        printf("%d ", arr[i]);
    }
}

int main(int argc, char **argv)
{
    int arr[ARRAY_SIZE];
    Input(arr, ARRAY_SIZE);
    InversionToPrint(arr, ARRAY_SIZE);
    return 0;
}
