/*
 *	C17 ДЗ
 *
 *	Сумма цифр равна произведению
 *
 *	Составить логическую функцию, которая определяет, верно ли, 
 *	что в данном числе сумма цифр равна произведению.
 *
 *	int is_happy_number(int n)
 *
 *	Данные на входе: 	Целое не отрицательное число 
 *	Данные на выходе: 	YES или NO 
 *
 *	Пример №1
 *	Данные на входе: 	123 
 *	Данные на выходе: 	YES 
 *
 *	Пример №2
 *	Данные на входе: 	528 
 *	Данные на выходе: 	NO
 * 
 * 
 */


#include <stdio.h>

int is_happy_number(int n)
{
	int sum = 0, proiz = 1;
	int result = 0;
	while (n != 0) 
	{
		sum += n % 10;
		proiz *= n % 10;
		n /= 10;
	}
	if (sum == proiz)
	{
		return result = 1;
	}
	return result;
}

int main(int argc, char **argv)
{
	unsigned int nunber;
	scanf("%d", &nunber);
	if (nunber >= 0)
	{
		printf("%s", (is_happy_number(nunber)) ? "YES" : "NO");
	}
	return 0;
}

