/*
    G18
    Удалить пробелы из текста
    В файле .txt необходимо удалить все лишние пробелы (в начале предложения
     и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
      записать в .txt.

    Данные на входе: 	Строка из английских букв, знаков препинания и
                        пробелов. Не более 1000 символов.
    Данные на выходе: 	Строка из английских букв, знаков препинания и
                        пробелов.


    Пример
    Данные на входе: 	 Hello  world!
    Данные на выходе: 	Hello world!

*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr)
{
    FILE *f_in;
    char name_in[] = "input txt\\g18_input.txt";
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
    char name_out[] = "output txt\\g18_output.txt";

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
            if (arr[0] == ' ')
            {
                len_in_arr = ShiftArray(0, len_in_arr, arr);
                flag = 0;
            }

            if ((arr[i] == ' ') && (arr[i + 1] == ' '))
            {
                len_in_arr = ShiftArray(i, len_in_arr, arr);
                flag = 0;
            }
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
