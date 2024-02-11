/*
    G20 Практ 2
    Проверка на палиндром
    Считать предложение из файла .txt и определить можно ли из английских букв
    предложения записанного в файле получить одно слово - палиндром. Ответ напечатать
    на стандартный поток вывода. Требуется реализовать логическую функцию и применить
    ее.

     is_palindrom(string)

    Данные на входе: 	Строка из маленьких английских букв и пробелов.
                        Не более 1000 символов.
    Данные на выходе: 	YES или NO

    Пример №1
    Данные на входе: 	kak za
    Данные на выходе: 	YES

    Пример №2
    Данные на входе: 	abc
    Данные на выходе: 	NO

    Пример №3
    Данные на входе: 	car race
    Данные на выходе: 	YES

*/

#include <stdio.h>
#include <string.h>

const int line_width = 1024;

void bubble_sort(int size, char *array)
{
    char buf;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (array[i] > array[j])
            {
                buf = array[i];
                array[i] = array[j];
                array[j] = buf;
            }
}

int ShiftArray(int pos, int size, char *arr)
{
    for (int k = pos; k < size; k++)
    {
        arr[k] = arr[k + 1];
    }
    size -= 1;
    return size;
}

void make_palindrome(int size, char *line)
{
    char letters[size][2];
    int letters_count = 0;
    int idx = 0;

    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == ' ')
        {
            size = ShiftArray(i, strlen(line), line);
        }
    }

    bubble_sort(strlen(line), line);

    for (int i = 0; i < size; i++)
    {
        idx = -1;
        for (int j = 0; j < letters_count; j++)
            if (line[i] == letters[j][0])
            {
                idx = j;
                letters[idx][1]++;
                break;
            }
        if (idx < 0)
        {
            idx = letters_count++;
            letters[idx][0] = line[i];
            letters[idx][1] = 1;
        }
    }

    int p_length = 0;
    int l_length, m_p = -1;
    for (int i = 0; i < letters_count; i++)
    {
        while (letters[i][1] && (letters[i][1] / 2 > 0))
        {
            line[p_length++] = letters[i][0];
            letters[i][1] -= 2;
        }
        if ((m_p < 0) && (letters[i][1] % 2 == 1))
            m_p = i;
    }
    l_length = p_length;
    if (m_p >= 0)
        line[p_length++] = letters[m_p][0];
    for (int i = l_length - 1; i >= 0; i--)
        line[p_length++] = line[i];
    line[p_length] = '\0';
}

int is_palindrom(int size, char *string)
{
    int flag = 0;

    for (int i = 0; i < size; i++)
    {
        if (string[i] != string[size - i - 1])
        {
            flag = 1;
            break;
        }
    }
    return (flag) ? 0 : 1;
}

int main(void)
{
    char *input_fn = "input txt\\g20_input.txt";
    char *output_fn = "output txt\\g20_output.txt";
    char line[line_width];
    FILE *fp;

    fp = fopen(input_fn, "r");
    fscanf(fp, "%[^\n]", line);
    fclose(fp);

    make_palindrome(strlen(line), line);

    printf("%s\n", line);
    printf("%s\n", (is_palindrom(strlen(line), line)) ? "YES" : "NO");

    fp = fopen(output_fn, "w");
    fprintf(fp, "%s", (is_palindrom(strlen(line), line)) ? "YES" : "NO");
    fclose(fp);

    return 0;
}
