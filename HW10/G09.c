/*
    G9 ДЗ 4
    Удалить повторяющиеся символы
    В файле .txt строка из меленьких и больших английских букв, знаков препинания и
    пробелов. Требуется удалить из нее повторяющиеся символы и все пробелы.
    Результат записать в файл .txt.

    Данные на входе: 	Строка из меленьких и больших английских букв,
                        знаков препинания и пробелов.
                        Размер строки не более 1000 сивмолов.
    Данные на выходе: 	Строка из меленьких и больших английских букв.

    Пример
    Данные на входе: 	abc cde def
    Данные на выходе: 	abcdef

*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr)
{
    FILE *f_in;
    char name_in[] = "g09_input.txt";
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
    char name_out[] = "g09_output.txt";

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

int ShiftArray(int pos, int size, char *arr)
{
 for (int k = pos; k < size; k++)
                {
                    arr[k] = arr[k + 1];
                }
size -= 1;
return size;
}

int Handler(char *arr)
{
    int count = 0;
    int num_nom = 0;
    int flag = 0;
    int len_in_arr = strlen(arr);
    int j;

    while (flag == 0)
    {
        flag = 1;
        for (int i = 0; i < len_in_arr; i++)
        {
            for (j = 0; j < len_in_arr; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    num_nom = j;
                }
            }
            if (count >= 2)
            {
                flag = 0;
                len_in_arr= ShiftArray(num_nom, len_in_arr, arr);
            }
            count = 0;
        }
    }

    for (int i = 0; i < len_in_arr; i++)
    {
        if (arr[i] == ' ')
        {
            len_in_arr = len_in_arr= ShiftArray(i, len_in_arr, arr);
        }
    }

    count = len_in_arr;
    return count;
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 101
    };
    int count = 0;
    char arr[BUFFER_SIZE];

    FileRead(BUFFER_SIZE, arr);
    count = Handler(arr);
    FileWrite(count, arr);

    return 0;
}
