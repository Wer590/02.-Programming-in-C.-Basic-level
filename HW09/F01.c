/*
 * F1
 * Сортировка по возрастанию
 * Написать функцию и программу, демонстрирующую работу данной функции, которая сортирует массив по возрастанию.
 * Строго согласно прототипу. Имя функции и все аргументы должны быть:
 * void sort_array(int size, int a[])
 *
 * Данные на входе:     Функция принимает на вход, первый аргумент - размер массива, второй аргумент - адрес нулевого элемента.
 * Данные на выходе:    Функция ничего не возвращает. Производит сортировку переданного ей массива по возрастанию.
 *
 * Пример №1
 * Данные на входе:     20 19 4 3 2 1 18 17 13 12 11 16 15 14 10 9 8 7 6 5.
 * Данные на выходе:    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20.
 *
 * Пример №2
 * Данные на входе:     5 4 3 2 1.
 * Данные на выходе:    1 2 3 4 5
 *
 *
 */

//
// У немя пример приведеный к данной задачи не работает
// падает при выполнение, прошу проверить
//

#include <stdio.h>


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

void sort_array(int size, int a[])
{
    for( int i = 0; i < size - 1; i++)
    {
        if (a[i] > a[i+1])
        {
            SwapArr(a, i, i+1);
            i = -1;
        }
    }
}

int main(int argc, char **argv)
{
    printf("Enter the number of array elements\nsize = ");
    int size = 0;
    scanf("%d", &size); 
    int array[size];   
    Input(size, array);
    sort_array(size, array);
    Print(size, array);
    return 0;
}

