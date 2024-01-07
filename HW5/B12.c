/*
 *	B12 (название задачи не как у предыдущих, B0-B7)
 *	
 *	Наименьшая и наибольшая цифра
 *	(вообще не понятно надо делать или нет, выполним на всякий случай)
 *
 *	Организовать ввод натурального числа с клавиатуры. 
 *	Программа должна определить наименьшую и наибольшую цифры, 
 *	которые входят в состав данного натурального числа. 
 *
 *	Данные на входе:	Целое неотрицательное число 
 *	Данные на выходе:	Две цифры через пробел. 
 *						Сначала наименьшая цифра числа, затем наибольшая. 
 *
 *	Пример №1
 *	Данные на входе:	15 
 *	Данные на выходе:	1 5 
 *
 *	Пример №2
 *	Данные на входе:	2457 
 *	Данные на выходе:	2 7 
 *
 *	Пример №3
 *	Данные на входе:	22 
 *	Данные на выходе:	2 2 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int num;
	scanf("%d", &num);
	int min = num % 10, max = num % 10;
	num /= 10;
	while (num > 0) 
    {   
		int digit = num % 10;
		min = (min > digit) ? digit : min;   
		max = (max < digit) ? digit : max;    
        num /= 10; 
    } 
	printf("%d %d", min, max);
	return 0;
}

