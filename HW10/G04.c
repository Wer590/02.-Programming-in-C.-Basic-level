/*
    G4 ДЗ 1
    По одному разу
    В файле .txt даны два слова не более 100 символов каждое, разделенные одним
    пробелом. Найдите только те символы слов, которые встречаются в обоих словах
    только один раз. Напечатайте их через пробел в файл .txt в лексикографическом
    порядке.

    Данные на входе: 	Два слова из маленьких английских букв через пробел.
                        Длинна каждого слова не больше 100 символов.
    Данные на выходе: 	Маленькие английские буквы через пробел.

    Пример №1
    Данные на входе: 	hello world
    Данные на выходе: 	o


    Данные на входе:    aabcd bcef
    Данные на выходе: 	b c
*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr_a, char *arr_b)
{
    FILE *f_in;
    char name_in[] = "txt\\g04_input.txt";
    char c;

    if ((f_in = fopen(name_in, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return -1;
    }

    int count = 0;
    while (((c = getc(f_in)) != EOF) && (c != 0x20))
    {
        arr_a[count++] = c;
    }
    arr_a[count] = '\0';

    count = 0;
    while (((c = getc(f_in)) != EOF) && (c != '\n'))
    {
        arr_b[count++] = c;
    }
    arr_b[count] = '\0';

    fclose(f_in);
    return 0;
}

int FileWrite(int size, char *arr)
{
    FILE *f_out;
    char name_out[] = "txt\\g04_output.txt";

    if ((f_out = fopen(name_out, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return -1;
    }

    for (int i = 0; i < size; i++)
    {

        fprintf(f_out, "%c ", arr[i]);
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

int SortArray(int size, char *arr)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j] > arr[i])
            {
                SwapArray(arr, j, i);
                count++;
            }
        }
    }
    count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count >= 2)
        {
            for (int k = 0; k < size - count; k++)
            {
                arr[k] = arr[k + count];
            }
            size -= count;
        }
        count = 0;
    }

    return size;
}
int Handler(char *in_a_arr, char *in_b_arr, char *out_arr)
{
    int count = 0;
    int cnt = 0;
    int len_arr_one = strlen(in_a_arr);
    int len_arr_two = strlen(in_b_arr);

    for (int i = 0; i < len_arr_one; i++)
    {
        for (int j = 0; j < len_arr_two; j++)
            if (in_b_arr[j] == in_a_arr[i])
            {
                if (in_a_arr[i] != '\0')
                {
                    out_arr[count] = in_a_arr[i];
                    count++;
                    break;
                }
            }
    }
    out_arr[count] = '\0';
    count = SortArray(count, out_arr);
    return count;
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 101
    };
    int count = 0;
    char arr_one[BUFFER_SIZE];
    char arr_two[BUFFER_SIZE];
    char arr_out[BUFFER_SIZE];

    FileRead(BUFFER_SIZE, arr_one, arr_two);
    count = Handler(arr_one, arr_two, arr_out);
    FileWrite(count, arr_out);

    return 0;
}
