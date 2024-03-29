/*
 * C3 Практ 1
 *
 *	Среднее арифметическое чисел
 *	Написать функцию, которая возвращает среднее арифметическое 
 * 	двух переданных ей аргументов (параметров).
 *	int middle(int a, int b)
 *	Данные на входе: 	Два целых неотрицательных числа 
 *	Данные на выходе: 	Одно целое число 
 *
 *	Пример №1
 *	Данные на входе: 	5 7 
 *	Данные на выходе: 	6 
 *
 *	Пример №2
 *	Данные на входе: 	10 20 
 *	Данные на выходе: 	15 
 * 
 * 
 */


#include <stdio.h>

int middle(int a, int b)
{
    return (a + b) / 2;
}

int main(int argc, char **argv)
{
    int nunber_a, nunber_b;	
    scanf("%d %d", &nunber_a, &nunber_b);
    printf("%d\n", middle(nunber_a, nunber_b));	
    return 0;
}

