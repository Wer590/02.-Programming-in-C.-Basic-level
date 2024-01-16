/*
 *  D8 ДЗ 2
 * 
 *  От A до B
 *  Составить рекурсивную функцию, Выведите все числа от A до B 
 *  включительно, в порядке возрастания, если A < B, 
 *  или в порядке убывания в противном случае. 
 *
 *  Данные на входе: 	Два целых числа через пробел. 
 *  Данные на выходе: 	Последовательность целых чисел. 
 *
 *  Пример №1
 *  Данные на входе: 	5 2 
 *  Данные на выходе: 	5 4 3 2 
 *
 *  Пример №2
 *  Данные на входе: 	2 7 
 *  Данные на выходе: 	2 3 4 5 6 7
 * 
 * 
 */


#include <stdio.h>

void print_num(int num_a, int num_b) 
{
    if (num_a == num_b) 
    { 
        printf("%d ", num_a);
        return;
    }
    if (num_a > num_b)
    {
        printf("%d ", num_a);
        print_num(num_a - 1, num_b);
    }
    else 
    {
        print_num(num_a, num_b - 1);
        printf("%d ", num_b);
    }
}

int main(int argc, char **argv)
{
    int number_a, number_b;
    scanf("%d%d", &number_a, &number_b);
    print_num(number_a, number_b);
    return 0;
}
