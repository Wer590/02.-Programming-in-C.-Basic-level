/*
    G17
    Пары соседних символов
    В файле .txt записаны символы. Необходимо разработать функцию, которая
    меняет местами пары соседних символов не обращая внимание на символы
    пробел. Если количество символов нечетно (пробелы не считаем), то
    последний символ не меняем. Результат записать в файл .txt.

    Данные на входе: 	Строка из английских букв, пробелов и знаков
                        препинания. Не более 1000 символов.
    Данные на выходе: 	Строка из английских букв, пробелов и знаков
                        препинания.

    Пример №1
    Данные на входе: 	Hello world!
    Данные на выходе: 	eHllw orodl!

    Пример №2
    Данные на входе: 	abc def
    Данные на выходе: 	bad cfe

*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr)
{
    FILE *f_in;
    char name_in[] = "input txt\\g17_input.txt";
    char c;

    if ((f_in = fopen(name_in, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return -1;
    }

    int count = 0;
    while (((c = getc(f_in)) != EOF) && (c != '\n'))
    {
        arr[count++] = c;
    }
    arr[count] = '\0';

    fclose(f_in);
    return 0;
}

int FileWrite(int size, char *arr)
{
    FILE *f_out;
    char name_out[] = "output txt\\g17_output.txt";

    if ((f_out = fopen(name_out, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return -1;
    }

    for (int i = 0; i < size; i++)
    {

        fprintf(f_out, "%c", arr[i]);
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

void SwapArray(char *arr, int i, int j)
{
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int Handler(char *in_arr, char *out_arr)
{
    int len_in_arr = strlen(in_arr);
    for (int i = 0; i < len_in_arr; i += 2)
    {
        if (in_arr[i + 1] == 0x20)
        {
            SwapArray(in_arr, i, i + 2);
           i++;
        }
        else if (in_arr[i + 1] == '\0')
        {           
           break;
        }
        else
        {
            SwapArray(in_arr, i, i + 1);
        }
    }
    memcpy(out_arr, in_arr, len_in_arr);
    int len_out_arr = strlen(out_arr);
    return len_out_arr;
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 1001
    };
    int count = 0;
    char arr_in[BUFFER_SIZE];
    char arr_out[BUFFER_SIZE] = {
        0,
    };

    FileRead(BUFFER_SIZE, arr_in);

    count = strlen(arr_in);
    count = Handler(arr_in, arr_out);
    FileWrite(count, arr_out);

    return 0;
}
