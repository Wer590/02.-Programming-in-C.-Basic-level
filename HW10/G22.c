/*
    G22
    Soundex
    Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет, похожи
    ли два английских слова по звучанию. На вход он принимает слово и заменяет его на некоторый
    четырёхсимвольный код. Если коды двух слов совпадают, то слова, как правило, звучат похоже.

    Вам требуется реализовать этот алгоритм. Он работает так:
    Первая буква слова сохраняется.
    В остальной части слова:
    буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются;
    оставшиеся буквы (согласные) заменяются на цифры от 1 до 6, причём похожим по звучанию буквам
    соответствуют одинаковые цифры:

    1: b, f, p, v
    2: c, g, j, k, q, s, x, z
    3: d, t
    4: l
    5: m, n
    6: r

    Любая последовательность одинаковых цифр сокращается до одной такой цифры. Итоговая строка
    обрезается до первых четырёх символов. Если длина строки меньше требуемой, недостающие символы
    заменяются знаком 0.

    Примеры:
    аmmonium → ammnm → a5555 → a5 → a500
    implementation → implmnttn → i51455335 → i514535 → i514

    Данные на входе: 	Во входном файле .txt находится одно непустое слово, записанное строчными
                        латинскими буквами. Длина слова не превосходит 20 символов.
    Данные на выходе: 	Напечатайте четырёхбуквенный код, соответствующий слову в файл .txt.

    Пример №1
    Данные на входе: 	ammonium
    Данные на выходе: 	a500

    Пример №2
    Данные на входе: 	implementation
    Данные на выходе: 	i514

*/

#include <stdio.h>
#include <string.h>

int FileRead(int size, char *arr)
{
    FILE *f_in;
    char name_in[] = "input txt\\g22_input.txt";
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
    char name_out[] = "output txt\\g22_output.txt";

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

void DeleteChar(int size, char *arr)
{
    char c[9] = {'a', 'e', 'h', 'i', 'o', 'u', 'w', 'y', 0};
    int flag = 0;
    while (flag == 0)
    {
        flag = 1;
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (arr[i] == c[j])
                {
                    size = ShiftArray(i, size, arr);
                    flag = 0;
                }
            }
        }
    }
}

void ChangingALetterToANumber(int size, char *arr)
{
    for (int i = 1; i < size; i++)
    {
        switch (arr[i])
        {
        case 'b':
        case 'f':
        case 'p':
        case 'v':
            arr[i] = '1';
            break;
        case 'c':
        case 'g':
        case 'j':
        case 'k':
        case 'q':
        case 's':
        case 'x':
        case 'z':
            arr[i] = '2';
            break;
        case 'd':
        case 't':
            arr[i] = '3';
            break;
        case 'l':
            arr[i] = '4';
            break;
        case 'm':
        case 'n':
            arr[i] = '5';
            break;
        case 'r':
            arr[i] = '6';
            break;
        }
    }
}

void Delete2Num(int size, char *arr)
{
    int flag = 0;
    while (flag == 0)
    {
        flag = 1;
        for (int i = 1; i < size; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                size = ShiftArray(i, size, arr);
                flag = 0;
            }
        }
    }
}

void Alignment(int size, char *arr)
{
    if (size > 4)
    {
        arr[4] = '\0';
    }
    if (size < 4)
    {
        int size_tmp = 4 - size;
        for (int i = size; i < size + size_tmp; i++)
            arr[i] = '0';
    }
}

void Soundex(int size, char *arr)
{
    DeleteChar(strlen(arr), arr);
    ChangingALetterToANumber(strlen(arr), arr);
    Delete2Num(strlen(arr), arr);
    Alignment(strlen(arr), arr);
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 21
    };
    int count = 0;
    char arr[BUFFER_SIZE];

    FileRead(BUFFER_SIZE, arr);
    Soundex(strlen(arr), arr);
    FileWrite(strlen(arr), arr);

    return 0;
}
