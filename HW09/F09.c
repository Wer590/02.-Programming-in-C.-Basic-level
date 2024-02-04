/*
 * F9
 * Поменять местами
 * Написать функцию и программу, демонстрирующую работу данной функции, 
 * которая в массиве находит максимальный из отрицательных элементов и 
 * меняет его местами с последним элементом массива. Гарантируется, что 
 * в массиве только один такой элемент или же такой элемент отсутствует. 
 * Если отрицательных элементов нет - массив не менять.
 * 
 * Прототип функции:
 * void swap_negmax_last(int size, int a[])
 * 
 * Данные на входе:     Функция принимает на вход размер массива и указатель 
 *                      на начало массива. Массив состоит из целых чисел. 
 * 
 * Пример
 * Данные на входе:     1 -2 -3 -4 5 6 7 8 9 10 
 * Данные на выходе:    1 10 -3 -4 5 6 7 8 9 -2 
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


int NegMax(int arr[], int size)
{
    int max = -200;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i] && arr[i] < 0)
        {
            max = arr[i];
        }
    }
    return max;
}

void SwapArr(int arr[], int i, int j)
{
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}

void swap_negmax_last(int size, int a[])
{
    int neg_max = NegMax(a, size);
    for (int i = 0; i < size; i++)
    {
        if (neg_max == a[i])
        {
           SwapArr(a, i, size - 1);
           return;
        }
    }    
}

void Print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the number of array elements\nsize = ");
    int size = 0;
    scanf("%d", &size);
    int array[size];
    Input(array, size);
    swap_negmax_last(size, array);
    Print(array, size);
    return 0;
}


