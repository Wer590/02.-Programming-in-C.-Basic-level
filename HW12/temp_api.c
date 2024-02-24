#include "temp_api.h"

void AddRecord(struct sensor *info, int number,
               uint16_t year, uint8_t month, uint8_t day,
               uint8_t hour, uint8_t minutes, int8_t t)
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minutes = minutes;
    info[number].temperature = t;
}

void DeleteRecord(struct sensor *info, struct data *counter, int number)
{
    uint32_t cnt = (counter->number) - 1;
    //uint32_t cnt = counter - 1;
    printf ("cnt = %d", cnt);
    for (uint32_t i = number; i < cnt; i++)
    {
        info[i].year = info[i + 1].year;
        info[i].month = info[i + 1].month;
        info[i].day = info[i + 1].day;
        info[i].hour = info[i + 1].hour;
        info[i].minutes = info[i + 1].minutes;
        info[i].temperature = info[i + 1].temperature;
    }
    counter->number--;
}

void cgangeIJ(struct sensor *info, int i, int j)
{
    struct sensor temp;
    temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}

// sorting the array in ascending temperature order within a specified month
void SortByTempUp(struct sensor *info, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (info[i].temperature >= info[j].temperature)
            {
                cgangeIJ(info, i, j);
            }
        }
    }
}

// Sorting the array in descending order of temperature within a specified month
void SortByTempDn(struct sensor *info, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (info[i].temperature < info[j].temperature)
            {
                cgangeIJ(info, i, j);
            }
        }
    }
}

unsigned int DateToInt(struct sensor *info)
{
    return info->year << 16 | info->month << 8 |
           info->day;
}

// sort by date
void SortByDate(struct sensor *info, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (DateToInt(info + i) >=
                DateToInt(info + j))
            {
                cgangeIJ(info, i, j);
            }
        }
    }
}

void Print(struct sensor *info, int number)
{
    printf("===================================\n");
    for (int i = 0; i < number; i++)
        printf("%04d-%02d-%02d %02d:%02d t = %2d\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].minutes,
               info[i].temperature);
}

int8_t MonthAvgTemp(struct sensor *info, uint16_t size, uint8_t month)
{
    int avg = 0;
    int cnt = 0;
    for (uint16_t i = 0; i < size; i++)
    {
        if (info[i].month == month)
        {
            avg += info[i].temperature;
            cnt++;
        }
    }
    avg /= cnt;
    return avg;
}
int8_t MonthMinTemp(struct sensor *info, uint16_t size, uint8_t month)
{
    int min = 100;
    for (uint16_t i = 0; i < size; i++)
    {
        if (info[i].month == month)
        {
            if (min > info[i].temperature)
            {
                min = info[i].temperature;
            }
        }
    }
    return min;
}
int8_t MonthMaxTemp(struct sensor *info, uint16_t size, uint8_t month)
{
    int max = -100;

    for (uint16_t i = 0; i < size; i++)
    {
        if (info[i].month == month)
        {
            if (max <= info[i].temperature)
            {
                max = info[i].temperature;
            }
        }
    }
    return max;
}

int8_t YearhAvgTemp(struct sensor *info, uint16_t size)
{
    int avg = 0;
    int cnt = 0;
    for (uint16_t i = 0; i < size; i++)
    {
        avg += info[i].temperature;
        cnt++;
    }
    avg /= cnt;
    return avg;
}
int8_t YearhMinTemp(struct sensor *info, uint16_t size)
{
    int min = 0;
    for (uint16_t i = 0; i < size; i++)
    {
        if (min > info[i].temperature)
        {
            min = info[i].temperature;
        }
    }
    return min;
}
int8_t YearhMaxTemp(struct sensor *info, uint16_t size)
{
    int max = 0;
    for (uint16_t i = 0; i < size; i++)
    {
        if (max <= info[i].temperature)
        {
            max = info[i].temperature;
        }
    }
    return max;
}

int8_t AvgTemp(struct sensor *info, uint16_t size, uint8_t month)
{

    if (month == 0)
    {
        return YearhAvgTemp(info, size);
    }
    else
    {
        return MonthAvgTemp(info, size, month);
    }
}

int8_t MinTemp(struct sensor *info, uint16_t size, uint8_t month)
{
    if (month == 0)
    {
        return YearhMinTemp(info, size);
    }
    else
    {
        return MonthMinTemp(info, size, month);
    }
}

int8_t MaxTemp(struct sensor *info, uint16_t size, uint8_t month)
{
    if (month == 0)
    {
        return YearhMaxTemp(info, size);
    }
    else
    {
        return MonthMaxTemp(info, size, month);
    }
}

uint32_t LoadSVGSenRaw(struct sensor *info, char *mane_file)
{
    FILE *in_file;

    if ((in_file = fopen(mane_file, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return -1;
    }

    fclose(in_file);
    return 0;
}