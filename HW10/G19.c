/*
    G19 Демо 2
    Составить палиндром
    Разработать функцию дана строка из маленьких английских букв. Составить из
    символов палиндром максимальной длинны. При составлении палиндрома буквы в
    палиндроме должны быть расположены в лексикографическом порядке. Записать ответ
    в файл .txt.

    Данные на входе: 	Строка из маленьких английских букв. Не более 1000 символов.
    Данные на выходе: 	Строка из маленьких английских букв.

    Пример №1
    Данные на входе: 	kazaki
    Данные на выходе: 	akika

    Пример №2
    Данные на входе: 	knak
    Данные на выходе: 	kak

    Пример №3
    Данные на входе: 	zzzzbbaaa
    Данные на выходе: 	abzzazzba

*/

#include <stdio.h>

#define ALPHABET 26

int main()
{
    FILE *f_in = fopen("input txt\\g19_input.txt", "r");
    FILE *f_out = fopen("output txt\\g19_output.txt", "w");

    char str[1002];
    int odd;
    int a[ALPHABET] = {0};

    fgets(str, 1002, f_in);

    for (int i = 0; str[i] != '\n' && str[i]; ++i)
        a[str[i] - 'a']++;

    for (int i = 0; i < ALPHABET; ++i)
        if (a[i] % 2 != 0)
        {
            odd = i;
            break;
        }

    for (int i = 0; i < ALPHABET; ++i)
        if (a[i] > 0)
            for (int j = 0; j < a[i] / 2; ++j)
                fprintf(f_out, "%c", i + 'a');

    fprintf(f_out, "%c", odd + 'a');

    for (int i = ALPHABET - 1; i >= 0; --i)
        if (a[i] > 0)
            for (int j = 0; j < a[i] / 2; ++j)
                fprintf(f_out, "%c", i + 'a');
    fclose(f_in);
    fclose(f_out);
    return 0;
}
