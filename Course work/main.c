#include "main.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "RUS");

    control = (struct management *)calloc(1, sizeof(struct management) * 1);
    if (control == NULL)
    {
        printf("Error! memory not allocated.");
        return 1;
    }

    if (ArgHandler(argc, argv, control) == -1)
    {
        return 1;
    }

    struct sensor *ptr = (struct sensor *)malloc(sizeof(struct sensor) * 100UL * 6000UL);
    if (ptr == NULL)
    {
        printf("Error! memory not allocated.");
        free(control);
        return 1;
    }

    ptr->number = LoadSVGSenRaw(ptr, control->input_file);
    if (ptr->number == -1)
    {
        free(control);
        free(ptr);
        return 1;
    }
#ifdef DEBUG
    printf("main.c: month = %d\n", control->month);
    printf("ptr->number = %d\n", ptr->number);
#endif

    // Print(ptr, control);

    int8_t min = MinTemp(ptr, control);
    printf("Minimum temperature %d recorded %04d-%02d-%02d %02d:%02d\n",
           min,
           control->min_year,
           control->min_month,
           control->min_day,
           control->min_hour,
           control->min_minutes);
    int8_t max = MaxTemp(ptr, control);
    printf("Maximum temperature %d recorded %04d-%02d-%02d %02d:%02d\n",
           max,
           control->max_year,
           control->max_month,
           control->max_day,
           control->max_hour,
           control->max_minutes);
    printf("Average temperature %.2f\n", AvgTemp(ptr, control));

    SortByDate(ptr, control);
    SortByTempUp(ptr, control);
    //SortByTempDn(ptr, control);
    Print(ptr, control);
    //int u = SaveSVGSen(ptr, control);

    free(control);
    free(ptr);

    return 0;
}
