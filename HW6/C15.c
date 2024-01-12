/*
 *	C15 Практ 
 *	
 *	Цифры по возрастанию
 *	Составить функцию логическую функцию, которая определяет, верно ли, 
 * 	что в заданном числе все цифры стоят по возрастанию. 
 * 	Используя данную функцию решить задачу.
 *
 *	int grow_up(int n)
 *
 *	Данные на входе: 	Одно целое не отрицательное число 
 *	Данные на выходе: 	YES или NO 
 *
 *	Пример №1
 *	Данные на входе: 	258 
 *	Данные на выходе: 	YES 
 *
 *	Пример №2
 *	Данные на входе: 	528 
 *	Данные на выходе: 	NO 
 * 
 * 
 */


#include <stdio.h>

int grow_up(int n)
{
	int c = 0, d = 0;
	int result = 0;	
	c = n % 10;
	n /= 10;
	while (n != 0)
	{
		if (n % 10 >= c)
		{
			 d = 1;
		}
		c = n % 10;
		n /= 10;
	}
	if (!d)
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
		printf("%s", (grow_up(nunber)) ? "YES" : "NO");
	}
	return 0;
}

