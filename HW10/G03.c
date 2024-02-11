/*
    G3 Практ 1
    Последний номер символа
    В файле .txt дана строка из 1000 символов. Показать номера символов, совпадающих
    с последним символом строки. Результат записать в файл .txt

    Данные на входе: 	Строка не более 1000 символов
    Данные на выходе: 	Целые числа через пробел - номера символа, который совпадает
                        с последним символом строки.

    Пример
    Данные на входе: 	aabbcdb
    Данные на выходе: 	2 3
*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr)
{
    FILE *f_in;
    char name_in[] = "txt\\g03_input.txt";
    char c;
    int count = 0;

    if ((f_in = fopen(name_in, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return -1;
    }

    while (((c = getc(f_in)) != EOF) && (c != '\n'))
    {
        arr[count++] = c;
    }
    arr[count] = '\0';

    fclose(f_in);
    return count;
}

int FileWrite(int size, int *arr)
{
    FILE *f_out;
    char name_out[] = "txt\\g03_output.txt";

    if ((f_out = fopen(name_out, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {

        fprintf(f_out, "%d ", arr[i]);
    }

    fclose(f_out);
    return 0;
}

void PrintArray(int size, char *arr)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}

int Handler(int size, char *in_arr, int *out_arr)
{
    int count = -1;
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (in_arr[i] == in_arr[size - 1])
        {
            if (count == -1)
            {
                count = i;
            }
            cnt++;
        }
    }
    out_arr[0] = count;
    out_arr[1] = cnt;
    return count;
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 1000
    };

    int count;

    char line[BUFFER_SIZE];
    int out[BUFFER_SIZE];

    count = FileRead(BUFFER_SIZE, line);
    // PrintArray(count, line);
    Handler(count, line, out);
    FileWrite(2, out);

    return 0;
}
