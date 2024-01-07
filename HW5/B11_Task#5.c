/*
 *	B11 ДЗ 5 (название задачи не как у предыдущих, B0-B7)
 *
 *	Перевернуть число
 *
 *	Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д. 
 *
 *	Данные на входе:	Целое неотрицательное число 
 *	Данные на выходе:	Целое не отрицательное число наоборот 
 *
 *	Пример №1
 *	Данные на входе:	1234 
 *	Данные на выходе:	4321 
 *
 *	Пример №2
 *	Данные на входе:	782 
 *	Данные на выходе:	287 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int num_input;
	scanf("%d", &num_input);
	int digit = num_input % 10;
	num_input /= 10;
	int num_output = digit;
	while (num_input > 0) 
    { 
		digit = num_input % 10;
        num_input /= 10; 
        num_output *= 10;
        num_output += digit;
    } 
	printf("%d", num_output);	
	return 0;
}

