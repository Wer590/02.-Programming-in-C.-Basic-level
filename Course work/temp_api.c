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

void DeleteRecord(struct sensor *info, int number)
{
    uint32_t cnt = (info->number) - 1;
    // uint32_t cnt = counter - 1;
#ifdef DEBUG
    printf("cnt = %d\n", cnt);
#endif
    for (uint32_t i = number; i < cnt; i++)
    {
        info[i].year = info[i + 1].year;
        info[i].month = info[i + 1].month;
        info[i].day = info[i + 1].day;
        info[i].hour = info[i + 1].hour;
        info[i].minutes = info[i + 1].minutes;
        info[i].temperature = info[i + 1].temperature;
    }
    info->number--;
}

void cgangeIJ(struct sensor *info, uint32_t i, uint32_t j)
{
    struct sensor temp;
    temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}

// sorting the array in ascending temperature order within a specified month
void SortByTempUp(struct sensor *info, struct management *st)
{
    if (st->flag_sort_temp_up == 1)
    {
        uint32_t n = info->number;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (info[j].temperature < info[i].temperature)
                {
                    cgangeIJ(info, i, j);
                }
            }
        }
    }
}

// Sorting the array in descending order of temperature within a specified month
void SortByTempDn(struct sensor *info, struct management *st)
{
    if (st->flag_sort_temp_dn == 1)
    {
        uint32_t n = info->number;
        for (uint32_t i = 0; i < n; i++)
        {
            for (uint32_t j = i; j < n; j++)
            {
                if (info[j].temperature > info[i].temperature)
                {
                    cgangeIJ(info, j, i);
                }
            }
        }
    }
}

uint64_t DateToInt(struct sensor *info)
{
    return ((uint64_t)info->year << 40 | (uint64_t)info->month << 24 |
            (uint64_t)info->day << 16 | (uint64_t)info->hour << 8 | (uint64_t)info->minutes);
}

int CompareDate(const void *x, const void *y)
{
    struct sensor *a = (struct sensor *)x;
    struct sensor *b = (struct sensor *)y;
    if ((a->year - b->year) != 0)
        return a->year - b->year;
    else if ((a->month - b->month) != 0)
        return a->month - b->month;
    else if ((a->day - b->day) != 0)
        return a->day - b->day;
    else if ((a->hour - b->hour) != 0)
        return a->hour - b->hour;
    // else if ((a->minutes - b->minutes) != 0)
    //    return a->minutes - b->minutes;
    return 0;
}

// sort by date
void SortByDate(struct sensor *info, struct management *st)
{

    if (st->flag_sort_date == 1)
    {
        // size_t qty = sizeof(info) / sizeof(info[0]);
        // qsort(info, info->number, sizeof(info), CompareDate);
        for (int i = 0; i < info->number; ++i)
        {
            for (int j = i; j < info->number; ++j)
            {
                // qsort(info, info->number, sizeof(info), CompareDate(info + i, info + j));
                // if (CompareDate(info + i, info + j) > 0)
                if (DateToInt(info + i) >= DateToInt(info + j))
                {
#ifdef DEBUG
                    printf("%" PRId64 " %" PRId64 "\n", DateToInt(info + i), DateToInt(info + j));
#endif
                    cgangeIJ(info, i, j);
                }
            }
        }
    }
}

void Print(struct sensor *info, struct management *st)
{

    if (st->flag_print == 1)
    {
#ifdef DEBUG
        printf("info->number = %d\n", info->number);
#endif
        printf("===================================\n");
        for (int i = 0; i < info->number; i++)
        {

            if ((st->month != 0) && (st->month == info[i].month))
            {
                printf("%04d-%02d-%02d %02d:%02d t = %2d\n",
                       info[i].year,
                       info[i].month,
                       info[i].day,
                       info[i].hour,
                       info[i].minutes,
                       info[i].temperature);
            }
            else if (st->month == 0)
            {
                printf("%04d-%02d-%02d %02d:%02d t = %2d\n",
                       info[i].year,
                       info[i].month,
                       info[i].day,
                       info[i].hour,
                       info[i].minutes,
                       info[i].temperature);
            }
        }
    }
}

float MonthAvgTemp(struct sensor *info, struct management *st)
{
    float avg = 0;
    int cnt = 0;
    for (uint32_t i = 0; i < info->number; i++)
    {
        if (info[i].month == st->month)
        {
            avg += info[i].temperature;
            cnt++;
        }
    }
    avg /= cnt;
    return avg;
}
int8_t MonthMinTemp(struct sensor *info, struct management *st)
{
    int8_t min = 100;
    for (uint32_t i = 0; i < info->number; i++)
    {
        if (info[i].month == st->month)
        {
            if (min > info[i].temperature)
            {
                min = info[i].temperature;
                st->min_year = info[i].year;
                st->min_month = info[i].month;
                st->min_day = info[i].day;
                st->min_hour = info[i].hour;
                st->min_minutes = info[i].minutes;
#ifdef DEBUG
                printf("Month minimum temperature %.2f recorded %04d-%02d-%02d %02d:%02d\n",
                       min,
                       st->min_year,
                       st->min_month,
                       st->min_day,
                       st->min_hour,
                       st->min_minutes);
#endif
            }
        }
    }
    return min;
}
int8_t MonthMaxTemp(struct sensor *info, struct management *st)
{
    int8_t max = -100;

    for (uint32_t i = 0; i < info->number; i++)
    {
        if (info[i].month == st->month)
        {
            if (max <= info[i].temperature)
            {
                max = info[i].temperature;
                st->max_year = info[i].year;
                st->max_month = info[i].month;
                st->max_day = info[i].day;
                st->max_hour = info[i].hour;
                st->max_minutes = info[i].minutes;
#ifdef DEBUG
                printf("Month maximum temperature %.2frecorded %04d-%02d-%02d %02d:%02d\n",
                       max,
                       st->max_year,
                       st->max_month,
                       st->max_day,
                       st->max_hour,
                       st->max_minutes);
#endif
            }
        }
    }
    return max;
}

float YearhAvgTemp(struct sensor *info, struct management *st)
{
    float avg = 0;
    uint32_t cnt = 0;
    for (uint32_t i = 0; i < info->number; i++)
    {
        avg += info[i].temperature;
        cnt++;
    }
    avg /= cnt;
    return avg;
}
int8_t YearhMinTemp(struct sensor *info, struct management *st)
{
    int8_t min = 100;
    for (uint32_t i = 0; i < info->number; i++)
    {
        if (min > info[i].temperature)
        {
            min = info[i].temperature;
            st->min_year = info[i].year;
            st->min_month = info[i].month;
            st->min_day = info[i].day;
            st->min_hour = info[i].hour;
            st->min_minutes = info[i].minutes;
#ifdef DEBUG
            printf("Year minimum temperature %.2f recorded %04d-%02d-%02d %02d:%02d\n",
                   min,
                   st->min_year,
                   st->min_month,
                   st->min_day,
                   st->min_hour,
                   st->min_minutes);
#endif
        }
    }
    return min;
}
int8_t YearhMaxTemp(struct sensor *info, struct management *st)
{
    int8_t max = -100;
    for (uint32_t i = 0; i < info->number; i++)
    {
        if (max <= info[i].temperature)
        {
            max = info[i].temperature;
            st->max_year = info[i].year;
            st->max_month = info[i].month;
            st->max_day = info[i].day;
            st->max_hour = info[i].hour;
            st->max_minutes = info[i].minutes;
#ifdef DEBUG
            printf("Year maximum temperature %.2f recorded %04d-%02d-%02d %02d:%02d\n",
                   max,
                   st->max_year,
                   st->max_month,
                   st->max_day,
                   st->max_hour,
                   st->max_minutes);
#endif
        }
    }
    return max;
}

float AvgTemp(struct sensor *info, struct management *st)
{

    if (st->month == 0)
    {
        return YearhAvgTemp(info, st);
    }
    else
    {
        return MonthAvgTemp(info, st);
    }
}

int8_t MinTemp(struct sensor *info, struct management *st)
{
    if (st->month == 0)
    {
        return YearhMinTemp(info, st);
    }
    else
    {
        return MonthMinTemp(info, st);
    }
}

int8_t MaxTemp(struct sensor *info, struct management *st)
{
    if (st->month == 0)
    {
        return YearhMaxTemp(info, st);
    }
    else
    {
        return MonthMaxTemp(info, st);
    }
}

uint32_t LoadSVGSenRaw(struct sensor *info, char *mane_file)
{

    // char buffer[100];
    uint32_t count = 0;
    uint32_t count_file = 0;
    FILE *in_file;

    if ((in_file = fopen(mane_file, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return -1;
    }
#ifdef DEBUG
    fseek(in_file, 0, SEEK_END);
    uint32_t length = ftell(in_file);
    printf("file size = %" PRIu32 " bytes\n", length);
    fseek(in_file, 0, SEEK_SET);
#endif
    int Y, M, D, H, MM;
    int T;
    int r;
    char ch = 0;
    while ((r = fscanf(in_file, "%d;%d;%d;%d;%d;%d", &Y, &M, &D, &H, &MM, &T)) > 0)
    {
        count_file++;
#ifdef DEBUG
        printf("r = %d ", r);
#endif
        if (r < NUNBER_READ)
        {
            printf("Error reading line %d from file: %s - invalid data ", count_file, mane_file);
            do
            {
                putchar(ch);
                ch = fgetc(in_file);
            } while (EOF != ch && '\n' != ch);
            // пропускаем оставшиеся символы до конца файла
            // или строки (на случай, если строка была
            // чересчур длинной
            ch = 0;
            printf("\n");
        }
        else
        {
            AddRecord(info, count, Y, M, D, H, MM, T);
#ifdef DEBUG
            printf("count = %d %d = %d;%d;%d;%d;%d;%d\n", count, r, Y, M, D, H, MM, T);
#endif
            count++;
        }
    }

    fclose(in_file);
#ifdef DEBUG
    printf("count = %d\n", count);
#endif
    return count;
}

uint32_t SaveSVGSen(struct sensor *info, struct management *st)
{
    if (st->flag_out_file == 0)
    {
        return 0;
    }

    FILE *out_file;
    if ((out_file = fopen(st->output_file, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return -1;
    }

    for (uint32_t i = 0; i < info->number; i++)
    {
        fprintf(out_file, "%4d;%2d;%2d;%2d;%2d;%2d\n",
                info[i].year,
                info[i].month,
                info[i].day,
                info[i].hour,
                info[i].minutes,
                info[i].temperature);
    }

    fclose(out_file);
    return 0;
}