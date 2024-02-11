/*
    G8 ДЗ 3
    Числа в массив
    В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые числа и
    иные символы. Требуется все числа, которые встречаются в строке, поместить в
    отдельный целочисленный массив. Например, если дана строка
    "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
    Вывести массив по возрастанию в файл .txt.

    Данные на входе: 	Строка из английских букв, цифр и знаков препинания
    Данные на выходе: 	Последовательность целых чисел отсортированная по возрастанию

    Пример
    Данные на входе: 	data 48 call 9 read13 blank0a
    Данные на выходе: 	0 9 13 48

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int FileRead(int size, char *arr)
{
    FILE *f_in;
    char name_in[] = "txt\\g08_input.txt";
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

int FileWrite(int size, int *arr)
{
    FILE *f_out;
    char name_out[] = "txt\\g08_output.txt";

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

void SwapArray(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int SortArray(int size, int *arr)
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
    return size;
}
int Handler(int size, char *in_arr, int *out_arr)
{
    int count = 0;
    char tmp[100];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        while (isdigit(in_arr[i]))
        {
           tmp[j++] = in_arr[i++]; 
        } 
        if (j != 0)
        {
            tmp[j++] = '\0';
            out_arr[count] = atoi(tmp);
            j = 0;
            count++;
        }
    }
    count = SortArray(count, out_arr);
    return count;
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 1001
    };
    int count = 0;
    char arr_in[BUFFER_SIZE];
    int arr_int[BUFFER_SIZE];

    count = FileRead(BUFFER_SIZE, arr_in);
    count = Handler(count, arr_in, arr_int);
    FileWrite(count, arr_int);

    return 0;
}
