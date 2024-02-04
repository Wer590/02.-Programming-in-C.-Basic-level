/*
 *	C13 Практика 
 *
 *	Вычислить cos
 *	Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
 *
 *	cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... 
 *	(x в радианах)
 *	float cosinus(float x)
 *
 *	Данные на входе: 	Целое число от 0 до 90 
 *	Данные на выходе: 	Вещественное число в формате "%.3f"
 *
 *	Пример
 *	Данные на входе: 	60 
 *	Данные на выходе: 	0.500 
 * 
 * 
 */


#include <stdio.h>

double power(float n, long p);	// возведение в спепень x^y
double factorial(int n); 		// вычесление факториала
double cosinus(float x); 


int main(int argc, char **argv)
{
	unsigned int nunber;
	scanf("%d", &nunber);
	if ((nunber >= 0) && (nunber <= 90))
	{
		printf("%.3f", cosinus(nunber));
	}
	return 0;
}

double power(float n, long p)
{
	if (p == 0)
	{
		return 1;
	}
	if (n == 0)
	{
		return 0;
	}
	if (n < 0)
	{
		n *= (-1);
	}
	double j = n;
	for (int i = 1; i < p; i++)
	{
		j *= n;
	}
	return j;
}

double factorial(int n)
{
	double result = 1;
	if ((n == 0) || (n == 1)) 
	{
		return result;
	}
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

double cosinus(float x)
{
	double result = 0;
	float pi = 3.142;
	int  i = 0, minus = -1;	
	float rad = x * (pi / 180);	
	if (x == 90) 
	{
		return 0;
	}
	while (i <= x)
	{
		minus *= -1.0;
		result = result + (minus * (power(rad, i) / factorial(i)));
		i += 2;
	}
	return (result);
}
