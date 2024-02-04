/*
 *	C5 ДЗ 
 *
 *	Сумма от 1 до N
 *	Составить функцию, которая определяет сумму всех чисел 
 *	от 1 до N и привести пример ее использования. 
 *
 *	Пример №1
 *	Данные на входе: 	Одно целое положительное число N 
 *	Данные на выходе: 	Целое число - сумма чисел от 1 до N 
 *
 *	Пример №2
 *	Данные на входе: 	100 
 *	Данные на выходе: 	5050 
 *
 * 
 */


#include <stdio.h>

int num_sum(int n)
{
	/*
	int summa = 0;
	for(int i = 1; i <= n; i++)
	{
		printf ("summa = %d\n", summa);
		summa += i;
	}
	return summa;
	*/ 
	return n * (n + 1) / 2;
}

int main(int argc, char **argv)
{
	int N;
	scanf("%d", &N);
	printf("%d", num_sum(N));
	return 0;
}


