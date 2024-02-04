/*
 *  E16 Д3 6
 *  Чаще других
 *  Дан массив из 10 элементов. Определить, какое число в массиве
 *  встречается чаще всего. Гарантируется, что такое число ровно 1.
 *
 *  Данные на входе:    10 целых числе через пробел
 *  Данные на выходе:   Одно число, которое встречается чаще других.
 *
 *  Пример
 *  Данные на входе:    4 1 2 1 11 2 34 11 0 11
 *  Данные на выходе:   11
 *
 *
 */

#include <stdio.h>

enum {ARRAY_SIZE = 10};

void Input(int arr[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void Print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
}

int Func(int arr_input[], int size)
{
    int num = arr_input[0];
    int max_frq = 1;
    int frq = 1;
    for (int i = 0; i < size - 1; i++) {
        frq = 1;
        for (int k = i + 1; k< size; k++)
            if (arr_input[i] == arr_input[k])
                frq += 1;
        if (frq > max_frq) {
            max_frq = frq;
            num = arr_input[i];
        }
    }

    return num;
}

int main(int argc, char **argv)
{
    int input_arr[ARRAY_SIZE] = {0,};
    Input(input_arr,ARRAY_SIZE);
    int num = Func(input_arr, ARRAY_SIZE);
    printf("%d", num);
    return 0;
}



