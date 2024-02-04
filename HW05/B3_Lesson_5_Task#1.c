/*
 *	B3 Урок 5 ДЗ 1
 *
 *	Сумма квадратов маленьких чисел
 * 
 *	Ввести два целых числа a и b (a ≤ b) и 
 *	вывести сумму квадратов всех чисел от a до b. 
 *
 *	Данные на входе:	Два целых числа по модулю не больше 100 
 *	Данные на выходе:	Сумма квадратов от первого введенного числа до второго 
 *
 *	Пример №1
 *	Данные на входе:	4 10 
 *	Данные на выходе:	371 
 *
 *	Пример №2
 *	Данные на входе:	1 5 
 *	Данные на выходе:	55 
 *
 */


#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	int a, b, sum = 0;
	scanf("%d %d", &a, &b);
	if ((a <= b) && (fabs(a) <=100) && (fabs(b) <=100))
	{
		while (a <= b)
		{
			sum += a * a;//sum = sum + (a * a);
			a++;
		}
		printf("%d\n", sum);
	}
	else 
	{
		printf("The numbers entered do not correspond to the conditions of the task\n");
	}
	return 0;
}

