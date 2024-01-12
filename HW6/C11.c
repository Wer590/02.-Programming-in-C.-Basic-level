/*
 *	C11 ДЗ
 *  
 *	НОД
 *	Составить функцию, которая определяет наибольший общий делитель 
 * 	двух натуральных и привести пример ее использования.
 *	int nod(int a, int b)
 *	Данные на входе: 	Два целых положительных числа 
 *	Данные на выходе: 	Одно целое число - наибольший общий делитель. 
 *
 *	Пример №1
 *	Данные на входе: 	14 21 
 *	Данные на выходе: 	7 
 * 
 * 
 */


#include <stdio.h>

int nod(int a, int b)
{
	while (a && b) 
	{	
		if (a >= b) 
		{
			a %= b;
		}
		else 
		{
			b %= a;
		}
	}
	printf("a = %d\n", a);	
	if (a) 
	{
		return a;
	}
	else 
	{
		return b;
	}
}

int main(int argc, char **argv)
{
	unsigned int nunber_a, nunber_b;
	scanf("%d%d", &nunber_a, &nunber_b);
	printf("%d", nod(nunber_a, nunber_b));
	return 0;
}

