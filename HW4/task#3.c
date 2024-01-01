/*
	
	Задача №3 к лекции №4
	
	Дано трехзначное число, напечатать максимальную цифру

	Данные на входе:      Целое положительное трехзначное число
	Данные на выходе:     Одна цифра

*/

#include "stdio.h"

int main(void)
{
	int num;
	
	scanf ("%d", &num);

	int a = num%10;
	int b = (num/10)%10;
	int c = (num/100)%10;
	
	int max = (a > b) && (a > c) ? a : (b > c) ? b : c;

	printf("%d", max);
	
 
	return 0;
}
