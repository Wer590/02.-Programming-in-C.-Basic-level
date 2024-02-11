/*
    G14
    Hello name
    В файле .txt в одной строке фамилию, имя и отчество. Сформировать файл
    приветствие .txt, где останутся имя и фамилия
    Данные на входе: 	Строка состоящая из английских букв и пробелов не
                        более 100 символов. Формат: Фамилия Имя Отчество
    Данные на выходе: 	Строка состоящая из английских букв и пробелов

    Пример
    Данные на входе: 	Pupkin Vasiliy Ivanovich
    Данные на выходе: 	Hello, Vasiliy Pupkin!

*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr)
{
    FILE *f_in;
    char name_in[] = "txt\\g14_input.txt";
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
    char name_out[] = "txt\\g14_output.txt";

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
    int buff_size = 50;
    char *str_hello = "Hello, ";
    char surname[buff_size];
    char name[buff_size];
    char *sp;
    int count = 0;
    int len_in_arr = strlen(in_arr);

    sp = strtok(in_arr, " ");
    while (sp)
    {
        if (count == 0)
        {
            int len_surname = strlen(sp);
            memset(surname, 0, buff_size);
            memcpy(surname, sp, len_surname); 
        }
        if (count == 1)
        {
            int len_name = strlen(sp);
            memset(name, 0, buff_size);
            memcpy(name, sp, len_name);
            name[len_name] = ' ';
        }
        sp = strtok(NULL, " ");
        count++;
    }
    memcpy(out_arr, str_hello, 7);
    strcat(out_arr, name);
    strcat(out_arr, surname);
    int len_out_arr = strlen(out_arr);
    out_arr[len_out_arr] = '!';
    len_out_arr = strlen(out_arr);
    return len_out_arr;
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 101
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
