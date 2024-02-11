/*
    G16 Практ 3
    Ling заменить на Cao
    В файле .txt дано предложение. Необходимо заменить все имена «Ling» на
    «Cao» и результат записать в файл .txt.

    Данные на входе: 	Строка из английских букв, пробелов и знаков
                        препинания. Не более 1000 символов.
    Данные на выходе: 	Строка из английских букв, пробелов и знаков
                        препинания.

    Пример
    Данные на входе: 	Ling, Ling, Ling and Ling!!!
    Данные на выходе: 	Cao, Cao, Cao and Cao!!!

*/

#include <stdio.h>
#include <string.h>

#define SIZE 10001

void input(char *strIn)
{
    FILE *in;

    in = fopen("txt\\g16_input.txt", "r");

    while (fscanf(in, "%[^\n]", strIn) == 1)
        ;

    fclose(in);
}

void changeName(char *strExt, char *buffer)
{
    int count = 0;

    for (int i = 0; i < strlen(strExt); i++)
    {
        if (!memcmp(strExt + i, "Ling", 4))
        {
            strcat(buffer, "Cao");
            count += 3;
            i += 4;
        }
        buffer[count++] = strExt[i];
    }
}
void output(char *strOut)
{
    FILE *out;
    out = fopen("txt\\g16_output.txt", "w");
    fprintf(out, "%s", strOut);
    fclose(out);
}

int main(int argc, char **argv)
{
    char str[SIZE] = {0}, strFinal[SIZE] = {0};
    input(str);
    changeName(str, strFinal);
    output(strFinal);
    return 0;
}
