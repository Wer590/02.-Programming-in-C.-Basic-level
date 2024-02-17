#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 130000

struct sensor
{
    uint8_t day;
    uint8_t month;
    uint16_t year;
    uint8_t hour;
    uint8_t minutes;
    uint8_t seconds;
    int8_t temperature;
};

struct data
{
    uint32_t number;
    struct sensor info[SIZE];
};

union sensor_serdes
{
    struct data _data;
    uint8_t bytes[sizeof(struct data)];
};

int8_t MonthAvgTemp(struct sensor *info, uint16_t size, uint8_t month);
int8_t MonthMinTemp(struct sensor *info, uint16_t size, uint8_t month);
int8_t MonthMaxTemp(struct sensor *info, uint16_t size, uint8_t month);
int8_t YearhAvgTemp(struct sensor *info, uint16_t size, uint8_t year);
int8_t YearhMinTemp(struct sensor *info, uint16_t size, uint8_t year);
int8_t YearhMaxTemp(struct sensor *info, uint16_t size, uint8_t year);