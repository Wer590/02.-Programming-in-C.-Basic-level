/*
 *  E15 Практик 3
 *  Положительные и отрицательные
 *  Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам:
 *  в одни помещать только положительные, во второй - только отрицательные.
 *  Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.
 *
 *  Данные на входе:    10 целых чисел через пробел.
 *  Данные на выходе:   Сперва положительные числа, потом отрицательыне числа, через пробел.
 *
 *  Пример
 *  Данные на входе:    5 -4 0 1 4 -3 -3 3 0 2
 *  Данные на выходе:   5 1 4 3 2 -4 -3 -3
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

int* Func(int arr_input[], int size, int arr_pos[], int arr_neg[])
{
    static int a[2];    
    int index_positive = 0;
    int index_negative = 0;
    for( int i = 0; i < size; i++)
    {
        if (( arr_input[i] >= -500 ) && ( arr_input[i] < 0 ))
        {
            arr_neg[index_negative] = arr_input[i];
            index_negative ++;            
        }
        if (( arr_input[i] > 0 ) && ( arr_input[i] <= 500 ))
        {
            arr_pos[index_positive] = arr_input[i];
            index_positive ++;            
        }
    }
    a[0] = index_positive;
    a[1] = index_negative;
    return a;
}

int main(int argc, char **argv)
{
    int input_arr[ARRAY_SIZE] = {0,};
    int arr_positive[ARRAY_SIZE] = {0,};
    int arr_negative[ARRAY_SIZE] = {0,};
    Input(input_arr,ARRAY_SIZE);
    int *size = Func(input_arr, ARRAY_SIZE, arr_positive, arr_negative);
    Print(arr_positive, size[0]);
    Print(arr_negative, size[1]);
    return 0;
}



