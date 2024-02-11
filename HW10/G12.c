/*
    G12
    Разобрать на слова
    В файле .txt дано предложение требуется разобрать его на отдельные слова.
    Напечатать каждое слово на отдельной строке в файл .txt.

    Данные на входе: 	Одна строка из английских букв и пробелов не более
                        1000 символов.
    Данные на выходе: 	Каждое слово на отдельной строке

    Пример
    Данные на входе: 	Mama mila ramu
    Данные на выходе: 	Mama
                        mila
                        ramu

*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr)
{
    FILE *f_in;
    char name_in[] = "input txt\\g12_input.txt";
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
    return count;
}

int FileWrite(int size, char *arr)
{
    FILE *f_out;
    char name_out[] = "output txt\\g12_output.txt";
    char *sp;

    if ((f_out = fopen(name_out, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return -1;
    }

    sp = strtok(arr, " ");
    while (sp)
    {
        fprintf(f_out, "%s\n", sp);
        sp = strtok(NULL, " ");
    }

    fclose(f_out);
    return 0;
}

int Handler(char *in_arr, char *out_arr)
{
    int len_in_arr = 0;
    char *sp;
    sp = strtok(in_arr, " ");
    while (sp)
    {
        len_in_arr = strlen(sp);
        char out_arr[len_in_arr];
        memset(out_arr, 0, len_in_arr);
        memcpy(out_arr, sp, len_in_arr);
        out_arr[len_in_arr] = '\0';

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
    char arr[BUFFER_SIZE];

    count = FileRead(BUFFER_SIZE, arr);
    FileWrite(count, arr);

    return 0;
}
