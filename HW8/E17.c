/*
 *  E17
 *  Только один раз
 *  Дан массив из 10 элементов. В массиве найти элементы, которые в нем
 *  встречаются только один раз, и вывести их на экран.
 *
 *  Данные на входе:    10 целых чисел через пробел
 *  Данные на выходе:   Элементы которые встречаются только один раз через пробел
 *
 *  Пример
 *  Данные на входе:    5 -4 0 1 4 -3 -3 3 0 2
 *  Данные на выходе:   5 -4 1 4 3 2
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

void Func(int arr_input[], int size)
{
    int povtor = 0;
    for( int i = 0; i < size; i++) {
        povtor = 1;
        for (int j = 0; j < size; j++) {
            if ((arr_input[j] == arr_input[i]) && (i != j)) {
                povtor = 0;
                break;
            }
        }
        if (povtor == 1) {
            printf("%d ", arr_input[i]);
        }
    }
}

int main(int argc, char **argv)
{
    int input_arr[ARRAY_SIZE] = {0, };
    Input(input_arr,ARRAY_SIZE);
    Func(input_arr, ARRAY_SIZE);
    return 0;
}



