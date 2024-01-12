/*
 *	C9 Практ 2
 *
 *	Факториал
 *	Составить функцию вычисления N!. Использовать ее при вычислении факториала
 *	int factorial(int n)
 *
 *	Данные на входе: 	Целое положительное число не больше 20 
 *	Данные на выходе: 	Целое положительное число 
 *
 *	Пример №1
 *	Данные на входе: 	5 
 *	Данные на выходе: 	120 
 *
 * 
 */


#include <stdio.h>
#include <inttypes.h>

unsigned long long factorial(int n) 
{	
	unsigned long long result = 1;
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


int main(int argc, char **argv)
 {
	int number;
	scanf ("%d", &number);	
	if ((number >= 0) && ( number <= 20))
	{
		printf ("%"PRIu64, factorial(number));
	}
	return 0;
}
