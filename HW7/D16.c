/*
 *  D16 Практик 3
 * 
 *  Точная степень двойки
 *  Написать логическую рекурсивную функцию и используя ее определить 
 *  является ли введенное натуральное число точной степенью двойки.
 *  int is2pow(int n)
 *  Данные на входе:    Одно натуральное число. 
 *  Данные на выходе:   YES или NO 
 *
 *  Пример №1
 *  Данные на входе:    8 
 *  Данные на выходе:   YES 
 *
 *  Пример №2
 *  Данные на входе:    7 
 *  Данные на выходе:   NO 
 * 
 * 
 */


#include <stdio.h>

int is2pow(int num) 
{
    if (num == 1 || num == 2) 
    {
        return 1;
    }
    if ((num % 2) != 0)
    {
        return 0;
    }
    else 
    {
        return is2pow(num / 2);
    }
}


int main(int argc, char **argv)
{
    int number;
    scanf("%d", &number);
    if (number > 0) 
    {
        printf ("%s", (is2pow(number) == 1) ? "YES" : "NO");
    }
    return 0;
}
