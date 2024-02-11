/*
    G10
    Самое длинное слово
    В файле .txt дана строка слов, разделенных пробелами. Найти самое
    длинное слово и вывести его в файл .txt. Случай, когда самых длинных
    слов может быть несколько, не обрабатывать.

    Данные на входе: 	Строка из английских букв и пробелов.
                        Не более 1000 символов.
    Данные на выходе: 	Одно слово из английских букв.

    Пример
    Данные на входе: 	Hello beautiful world
    Данные на выходе: 	beautiful

*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr)
{
    FILE *f_in;
    char name_in[] = "txt\\g10_input.txt";
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
    char name_out[] = "txt\\g10_output.txt";

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

int Handler(char *in_arr, char *out_arr)
{
    int len_in_arr = 0;
    char *sp;
    sp = strtok(in_arr, " ");
    while (sp)
    {
        if (strlen(sp) > len_in_arr)
        {
            len_in_arr = strlen(sp);
            memset(out_arr, 0, len_in_arr);
            memcpy(out_arr, sp, len_in_arr);
            out_arr[len_in_arr] = '\0';
        }
        sp = strtok(NULL, " ");
    }
    return len_in_arr;
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 1001
    };
    int count = 0;
    char arr_in[BUFFER_SIZE];
    char arr_out[BUFFER_SIZE];

    FileRead(BUFFER_SIZE, arr_in);

    count = strlen(arr_in);
    count = Handler(arr_in, arr_out);
    FileWrite(count, arr_out);

    return 0;
}
