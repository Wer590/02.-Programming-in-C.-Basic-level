#include <stdio.h>
#include "temp_api.h"
#include "argc.h"
#include <locale.h>

int main(int argc, char *argv[])
{
    char file[255] = "\0";

    setlocale(LC_ALL, "RUS");

    uint8_t month = ArgHandler(argc, argv, file);
    if (month == -1)
    {
        return 1;
    }
    struct data d;
    union sensor_serdes *ds = (union sensor_serdes *)&d;
    if (LoadSVGSenRaw(d.info, file) == -1)
    {
        return 1;
    }
    printf("main.c: month = %d\n", month);
    d.number = LoadSVGSenRaw(d.info, file);
    printf("d.number = %d\n", d.number);
    d.number = 0;
    AddRecord(d.info, d.number++, 2023, 9, 16, 20, 38, 9);
    AddRecord(d.info, d.number++, 2023, 9, 2, 1, 15, -9);
    AddRecord(d.info, d.number++, 2023, 9, 7, 23, 59, 8);
    AddRecord(d.info, d.number++, 2023, 9, 30, 12, 30, -2);
    AddRecord(d.info, d.number++, 2023, 9, 5, 10, 18, 1);
    printf("d.number = %d\n", d.number);
    Print(d.info, d.number);
    printf("Minimum temperature %d\n", MinTemp(d.info, d.number, month));
    printf("Maximum temperature %d\n", MaxTemp(d.info, d.number, month));
    printf("Average temperature %d\n", AvgTemp(d.info, d.number, month));
    printf("Sorting the array in ascending temperature order within a specified month\n");
    SortByTempUp(d.info, d.number);
    Print(d.info, d.number);
    printf("Sorting the array in descending order of temperature within a specified month\n");
    SortByTempDn(d.info, d.number);
    Print(d.info, d.number);
    DeleteRecord(d.info, &d, 1);
    Print(d.info, d.number);
    printf("d.number = %d\n", d.number);
    return 0;
}
