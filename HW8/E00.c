/*
 *  Все функции используемые в модуле E
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
    for (int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void SwapArr(int arr[], int i, int j)
{
    //int temp = arr[i];
    //arr[i]=arr[j];
    //arr[j]=temp;
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}

float Average(int arr[], int size)
{
    int average = 0;
    for (int i=0; i<size; i++)
    {
        average += arr[i];
    }
    return (float)average/size;
}

void InversionToPrint(int arr[], int size)
{
    for( int i = 0; i < size; i++) {
        if ((i == 0) || (i == 1))
        {
            SwapArr(arr, i, size/2-i-1);
        }
        if (( i == size/2 ) ||( i == size/2 + 1))
        {
            SwapArr(arr, i, (size -1) -(i-size/2));
        }
        printf("%d ", arr[i]);
    }
}

int MaxPoz(int arr[], int size)
{
    int max = arr[0];
    int max_poz = 1;
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            max_poz = i + 1;
        }
    }
    return max_poz;
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

int MinPoz(int arr[], int size)
{
    int min = arr[0];
    int min_poz = 1;
    for (int i = 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            min_poz = i + 1;
        }
    }
    return min_poz;
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

int Sum2Max(int arr[], int size)
{
    int max1 = 0;
    int max2 = 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[max1])
        {
            max2 = max1;
            max1 = i;
        }
        else if (arr[i] > arr[max2])
        {
            max2 = i;
        }

    }
    return arr[max1] + arr[max2];
}

int SumPositive(int arr[], int size)
{
    int sum = 0;
    for (int i=0; i<size; i++)
    {
        if (arr[i] > 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

void ShiftRightArray(int arr[], int size, int shift)

{
    for (int j = 0; j < shift; j++ )
    {
        int temp = arr[size-1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i -1];
        }
        arr[0] = temp;
    }
}

void SortArr(int arr[], int size)
{
    for( int i = 0; i < size - 1; i++)
    {
        if (arr[i] % 10 > arr[i+1] % 10)
        {
            SwapArr(arr, i, i+1);
            i = -1;
        }
    }
}

void SortArr(int arr[], int size)
{
    for( int i = 0; i < (size / 2) - 1; i++)
    {
        for (int j = i + 1; j < (size / 2); j++)
        {
            if (arr[i] > arr[j])
            {
                SwapArr(arr, i, j);
            }
        }
    }
    for( int i = (size / 2); i < (size - 1); i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (arr[j] > arr[i])
            {
                SwapArr(arr, j, i);
            }
        }
    }
}

int main(int argc, char **argv)
{
    int arr[ARRAY_SIZE];
    Input(arr, ARRAY_SIZE);
    Print(arr, ARRAY_SIZE);
    SwapArr(arr, 0, 4);
    Print(arr, ARRAY_SIZE);
    InversionToPrint(arr, ARRAY_SIZE);
    return 0;
}
