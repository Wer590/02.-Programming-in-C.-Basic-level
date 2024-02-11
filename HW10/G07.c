/*
    G7 Практ 2
    Количество букв
    В файле .txt считать символьную строку, не более 10 000 символов. Посчитать
    количество строчных (маленьких) и прописных (больших) букв в введенной строке.
    Учитывать только английские буквы. Результат записать в файл .txt.

    Данные на входе: 	Строка состоящая из английских букв, цифр, пробелов и знаков
                        препинания.
    Данные на выходе: 	Два целых числа. Количество строчных букв и количество
                        заглавных букв.

    Пример №1
    Данные на входе: 	aabbAB
    Данные на выходе: 	4 2

    Пример №2
    Данные на входе: 	HELLO WORLD
    Данные на выходе: 	0 10

*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr_a)
{
    FILE *f_in;
    char name_in[] = "txt\\g07_input.txt";
    char c;

    if ((f_in = fopen(name_in, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return -1;
    }

    int count = 0;
    while (((c = getc(f_in)) != EOF) && (c != '\n'))
    {
        arr_a[count++] = c;
    }
    arr_a[count] = '\0';

    fclose(f_in);
    return 0;
}

int FileWrite(int size, int *arr)
{
    FILE *f_out;
    char name_out[] = "txt\\g07_output.txt";

    if ((f_out = fopen(name_out, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return -1;
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

int Handler(char *in_arr, int *out_arr)
{
    int count_lower_case = 0;
    int count_upper_case = 0;
    int len_arr = strlen(in_arr) + 1;

    for (int i = 0; i < len_arr; i++)
    {
        if ((in_arr[i] >= 0x41) && (in_arr[i] <= 0x5A))
        {
            count_upper_case++;
        }

        if ((in_arr[i] >= 0x61) && (in_arr[i] <= 0x7A))
        {
            count_lower_case++;
        }
    }

    out_arr[0] = count_lower_case;
    out_arr[1] = count_upper_case;
    return len_arr;
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 10001
    };
    char arr_in[BUFFER_SIZE];
    int arr_out[BUFFER_SIZE];

    FileRead(BUFFER_SIZE, arr_in);
    int count = Handler(arr_in, arr_out);
    FileWrite(2, arr_out);

    return 0;
}
