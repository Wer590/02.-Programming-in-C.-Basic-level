/*
    G11
    Заканчивается на a
    В файле .txt дано предложение. Необходимо определить, сколько слов
    заканчиваются на букву 'а'. Ответ записать в файл .txt.

    Данные на входе: 	Строка из английских букв и пробелов не более 1000
                        символов.
    Данные на выходе: 	Одно целое число

    Пример
    Данные на входе: 	Mama mila ramu
    Данные на выходе: 	2

*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr)
{
    FILE *f_in;
    char name_in[] = "g11_input.txt";
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

int FileWrite(int size, int *arr)
{
    FILE *f_out;
    char name_out[] = "g11_output.txt";

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
    int count = 0;
    char *sp;
    sp = strtok(in_arr, " ");
    while (sp)
    {
        if (sp[strlen(sp) - 1] == 'a')
        {
            count++;
        }
        sp = strtok(NULL, " ");
    }
    out_arr[0] = count;
    return 1;
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 1001
    };
    int count = 0;
    char arr_in[BUFFER_SIZE];
    int arr_out[BUFFER_SIZE];

    FileRead(BUFFER_SIZE, arr_in);

    count = strlen(arr_in);
    count = Handler(arr_in, arr_out);
    FileWrite(count, arr_out);

    return 0;
}
