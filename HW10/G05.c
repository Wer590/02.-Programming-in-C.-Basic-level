/*
    G5 ДЗ 2
    Заменить a на b
    В файле .txt дана символьная строка не более 1000 символов. Необходимо заменить
    все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат
    записать в .txt.

    Данные на входе: 	Строка из маленьких и больших английских букв, знаков
                        препинания и пробелов.
    Данные на выходе: 	Строка из маленьких и больших английских букв, знаков
                        препинания и пробелов.

    Пример
    Данные на входе: 	aabbccddABCD
    Данные на выходе: 	bbaaccddBACD

*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr_a)
{
    FILE *f_in;
    char name_in[] = "input txt\\g05_input.txt";
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

int FileWrite(int size, char *arr)
{
    FILE *f_out;
    char name_out[] = "output txt\\g05_output.txt";

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

int Handler(char *in_a_arr, char *out_arr)
{
    int count = 0;
    int len_a_arr = strlen(in_a_arr);
    for (int i = 0; i < len_a_arr; i++)
    {
        switch (in_a_arr[i])
        {
        case 'a':
        case 'A':
            out_arr[i] = in_a_arr[i] + 0x01;
            break;
        case 'b':
        case 'B':
            out_arr[i] = in_a_arr[i] - 0x01;
            break;
        default:
            out_arr[i] = in_a_arr[i];
            break;
        }
    }
    return len_a_arr;
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 1001
    };
    char arr_in[BUFFER_SIZE];
    char arr_out[BUFFER_SIZE];

    FileRead(BUFFER_SIZE, arr_in);
    int count = Handler(arr_in, arr_out);
    FileWrite(count, arr_out);

    return 0;
}
