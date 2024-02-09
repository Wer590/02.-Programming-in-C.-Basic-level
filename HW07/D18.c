/*
 *  D18 Практик 2
 * 
 *  Цифры слева направо
 *  Написать рекурсивную функцию и используя ее решить задачу. 
 *  Напечатать цифры введенного натурального числа в порядке 
 *  следования (слева направо) через пробел.
 *  void print_digits(int n)
 *  Данные на входе:    Натуральное число 
 *  Данные на выходе:   Последовательность цифр в слева направо через пробел 
 *  
 *  Пример №1
 *  Данные на входе:    12345 
 *  Данные на выходе:   1 2 3 4 5 
 *  
 *  Пример №2
 *  Данные на входе:    709 
 *  Данные на выходе:   7 0 9 
 * 
 * 
 */


#include <stdio.h>

void print_digits(int n) 
{
    if (n > 0)
    {
        print_digits (n / 10);
        printf ("%d ", n % 10);
    }
}

int main(int argc, char **argv)
{
    unsigned int num;
    scanf("%d", &num);
    if (num == 0)
        printf ("0");
    if (num > 0)
        print_digits(num);
    return 0;
}