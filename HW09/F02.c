/*
 * F2 ДЗ 2
 * Четные в начало
 * Написать функцию и программу, демонстрирующую работу данной функции,
 * которая ставит в начало массива все четные элементы, а в конец – все нечетные.
 * Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:
 * void sort_even_odd(int n, int a[])

 * Данные на входе:     Функция принимает на вход целые числа
 * Данные на выходе:    Отсортированный исходный массив

 * Пример №1
 * Данные на входе:     20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
 * Данные на выходе:    20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1

 * Пример №2
 * Данные на входе:     1 0 1 0 1
 * Данные на выходе:    0 0 1 1 1
 *
 *
 */

#include <stdio.h>
#include <string.h>


void Input(int size, int a[])
{
    int i;
    for (i=0; i<size; i++)
    {
        scanf("%d", &a[i]);
    }
}

void Print(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void SwapArr(int arr[], int i, int j)
{
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}

void sort_even_odd(int size, int a[])
{
    int temp_array[size];
    int k = 0;


    for(int i = 0; i < size; i++)
    {

        if (a[i] % 2 == 0) {
            temp_array[k] = a[i];
            k ++;
        }
    }

    for( int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0)
        {
            temp_array[k] = a[i];
            k ++;
        }
    }

    memcpy(a, temp_array, sizeof(temp_array));
}

int main(int argc, char **argv)
{
    printf("Enter the number of array elements\nsize = ");
    int size = 0;
    scanf("%d", &size);
    int array[size];
    Input(size, array);
    sort_even_odd(size, array);
    Print(size, array);
    return 0;
}

