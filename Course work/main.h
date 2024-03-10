#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include "argc.h"
#include "temp_api.h"
#include <locale.h>

// #define DEBUG

struct management
{
    uint16_t min_year;
    uint16_t max_year;
    uint8_t min_month;
    uint8_t max_month;
    uint8_t min_day;
    uint8_t max_day;
    uint8_t min_hour;
    uint8_t max_hour;
    uint8_t min_minutes;
    uint8_t max_minutes;
    uint8_t month;
    uint8_t flag_print;
    uint8_t flag_sort_date;
    uint8_t flag_sort_temp_up;
    uint8_t flag_sort_temp_dn;
    uint8_t flag_out_file;
    char input_file[255];
    char output_file[255];
};

struct management *control;

#endif