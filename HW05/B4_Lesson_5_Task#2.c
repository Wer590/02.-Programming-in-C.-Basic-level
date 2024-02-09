/*
 *	B4 Урок 5 ДЗ 2 
 *  (как в задачи 10 лекции 4 может указать как решать данную задачю, например через цикл или if)
 * 
 *	Ровно три цифры
 * 
 *	Ввести целое число и определить, верно ли, что в нём ровно 3 цифры. 
 *
 *	Данные на входе:	Целое положительное число 
 *	Данные на выходе:	Одно слово: YES или NO 
 *
 *	Пример №1
 *	Данные на входе:	123 
 *	Данные на выходе:	YES 
 *
 *	Пример №2
 *	Данные на входе:	1234 
 *	Данные на выходе:	NO 
 *
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int num;
	scanf("%d", &num);
	//Через if
/*
	if ((num >= 100) && (num <= 999))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
*/	
	//Через Тернарный оператор
	//printf("%s\n", ((num > 99) && (num < 1000)) ? "YES" : "NO" );
	
	//Через цикл 
	int inc = 0; 
    while (num > 0) 
    { 
        inc ++; 
        num /= 10; 
    } 
	printf("%s\n", (inc == 3) ? "YES" : "NO");
	
	return 0;
}
