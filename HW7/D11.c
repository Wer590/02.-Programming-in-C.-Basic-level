/*
 *  D11 ДЗ 3
 * 
 *  Количество 1
 *  Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. 
 *  Данные на входе: 	Натуральное число 
 *  Данные на выходе: 	Целое число - количество единиц в двоичной записи числа. 
 *
 *  Пример №1
 *  Данные на входе: 	5 
 *  Данные на выходе: 	2 
 *
 *  Пример №2
 *  Данные на входе: 	255 
 *  Данные на выходе: 	8 
 * 
 * 
 */


#include <stdio.h>

int print_sum_one(int num) 
{
    static int sum = 0;
    if (num > 0)
    {
        print_sum_one (num / 2);
        if (num % 2 == 1)
        {
            sum ++;
        }
    }
    return sum;
}

int main(int argc, char **argv)
{
    unsigned int number;
    scanf("%d", &number);
    if (number > 0)
        printf ("%d", print_sum_one(number));
    return 0;
}

