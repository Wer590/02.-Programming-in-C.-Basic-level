#include "temp_api.h"

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
    int min = 0;
    for (uint16_t i = 0; i < size; i++)
    {
        if (info[i].month == month)
        {
        }
    }
    return min;
}
int8_t MonthMaxTemp(struct sensor *info, uint16_t size, uint8_t month)
{
    int max = 0;
    for (uint16_t i = 0; i < size; i++)
    {
        if (info[i].month == month)
        {
        }
    }
    return max;
}
int8_t YearhAvgTemp(struct sensor *info, uint16_t size, uint8_t year)
{
    int avg = 0;
    int cnt = 0;
    for (uint16_t i = 0; i < size; i++)
    {
        if (info[i].month == year)
        {
            avg += info[i].temperature;
            cnt++;
        }
    }
    avg /= cnt;
    return avg;
}
int8_t YearhMinTemp(struct sensor *info, uint16_t size, uint8_t year)
{
    int min = 0;
    for (uint16_t i = 0; i < size; i++)
    {
        if (info[i].month == year)
        {
        }
    }
    return min;
}
int8_t YearhMaxTemp(struct sensor *info, uint16_t size, uint8_t year)
{
    int max = 0;
    for (uint16_t i = 0; i < size; i++)
    {
        if (info[i].month == year)
        {
        }
    }
    return max;
}