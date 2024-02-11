/*
    G13
    Изменить расширение
    В файле .txt записан полный адрес файла (возможно, без расширения). 
    Необходимо изменить его расширение на ".html" и записать результат в 
    файл .txt. 

    Данные на входе: 	Строка состоящая из символов: a-z, A-Z, 0-9, / 
    Данные на выходе: 	Исходная строка с измененным расширением. 

    Пример №1
    Данные на входе: 	/DOC.TXT/qqq 
    Данные на выходе: 	/DOC.TXT/qqq.html 

    Пример №2
    Данные на входе: 	/DOC.TXT/qqq.com 
    Данные на выходе: 	/DOC.TXT/qqq.html 

*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr)
{
    FILE *f_in;
    char name_in[] = "txt\\g13_input.txt";
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
    char name_out[] = "txt\\g13_output.txt";

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
    int len_in_arr = strlen(in_arr);
    char *n = strrchr(in_arr, '.');
    printf("len_in_arr = %d, n = %d\n", len_in_arr, n - in_arr + 1);
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
