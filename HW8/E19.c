/*
 *  E19 ДЗ *
 *  Цифры по порядку
 *  Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N.
 *
 *  Данные на входе:    Одно натуральное число N
 *  Данные на выходе:   Цифры через пробел
 *
 *  Пример
 *  Данные на входе:    54412
 *  Данные на выходе:   5 4 4 1 2
 *
 *
 */

#include <stdio.h>

enum {ARRAY_SIZE = 12};


void Print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[size-i-1]);
    }
}

int Func(int arr[], int num)
{
    int index = 0;
    while (num > 0)
    {
        arr[index] = num % 10;
        index ++;
        num /= 10;
    }
    return index;
}

int main(int argc, char **argv)
{
    int arr[ARRAY_SIZE] = {0};
    int number = 0;
    scanf("%d", &number);
    int index = Func(arr, number);
    Print(arr, index);
    return 0;
}



