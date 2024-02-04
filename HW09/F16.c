/*
 * F16 ДЗ
 * Клетки
 * Известно, что шахматная доска имеет размерность 8х8 и состоит из клеток 2х цветов,
 * например, черного и белого (см. рисунок). Каждая клетка имеет координату,
 * состоящую из буквы и цифры. Горизонтальное расположение клетки определяется
 * буквой от A до H, а вертикальное – цифрой от 1 до 8. Заметим, что клетка
 * с координатой А1 имеет черный цвет. Требуется по заданной координате
 * определить цвет клетки.
 *
 * Данные на входе:     В единственной строке записана координата клетки
 *                      на шахматной доске: всего два символа – буква и цифра (без пробелов).
 * Данные на выходе:    В выходной файл нужно вывести «WHITE»,
 *                      если указанная клетка имеет белый цвет и «BLACK», если она черная.
 *
 * Пример №1
 * Данные на входе:     C3
 * Данные на выходе:    BLACK
 *
 * Пример №2
 * Данные на входе:     G8
 * Данные на выходе:    WHITE
 *
 *
 */

#include <stdio.h>

int odd(int n)
{
    if (n % 2 == 0)
        return 1;
    return 0;
}

void InputArray(int size_a, int size_b, int arr[size_a][size_b])
{

    for (int i = 1; i < size_a; i++)
    {
        for (int j = 1; j < size_b; j++)
        {
            //scanf("%d", &arr[i][j]);
            if (odd(i))
            {
                if (odd(j))
                {
                    arr[i][j] = 0;
                }
                else
                {
                    arr[i][j] = 1;
                }
            }
            else
            {
                if (odd(j))
                {
                    arr[i][j] = 1;
                }
                else
                {
                    arr[i][j] = 0;
                }
            }

        }
    }
}

void Input(char *s1, char *s2)
{
    scanf("%[A-Z]%[0-9]", s1, s2);
}

int CellColor(char *s1, char *s2,int size_a, int size_b, int arr[size_a][size_b])
{
    int result = 0;  
    for (int i = 1; i < size_a; i++)
    {
        for (int j = 1; j < size_b; j++)
        {
            if ((i == (s1[0] - 'A') + 1) && (j == (s2[0] - '0')))
            {
                result = arr[i][j];
            }
        }
     }
    return result;
}

void Print(int size_a, int size_b, int arr[size_a][size_b])
{
    for (int i = 1; i < size_a; i++)
    {
        for (int j = 1; j < size_b; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    enum {BUFFER_SIZE_A = 9, BUFFER_SIZE_B = 9};
    int arr[BUFFER_SIZE_A][BUFFER_SIZE_B] = {0};
    char s1[2] = {0};
    char s2[2] = {0};
    InputArray(BUFFER_SIZE_A, BUFFER_SIZE_B, arr);
    Input(s1,s2);
    int color = CellColor(s1, s2, BUFFER_SIZE_A, BUFFER_SIZE_B, arr);
    printf("%s", (color) ? "WHITE" : "BLACK");
    return 0;
}



