#ifndef _TEMP_API_H_
#define _TEMP_API_H_

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

uint32_t LoadSVGSenRaw(struct sensor *info, char *mane_file);

void AddRecord(struct sensor *info, int number,
               uint16_t year, uint8_t month, uint8_t day,
               uint8_t hour, uint8_t minutes, int8_t t);
void Print(struct sensor *info, int number);
void DeleteRecord(struct sensor *info, struct data *counter, int number);
void SortByTempUp(struct sensor *info, int n);
void SortByTempDn(struct sensor *info, int n);
void SortByDate(struct sensor *info, int n);

int8_t AvgTemp(struct sensor *info, uint16_t size, uint8_t month);
int8_t MinTemp(struct sensor *info, uint16_t size, uint8_t month);
int8_t MaxTemp(struct sensor *info, uint16_t size, uint8_t month);

/*
int32_t MonthAvgTemp(struct sensor *info, uint16_t size, uint8_t month);
int8_t MonthMinTemp(struct sensor *info, uint16_t size, uint8_t month);
int8_t MonthMaxTemp(struct sensor *info, uint16_t size, uint8_t month);
int32_t YearhAvgTemp(struct sensor *info, uint16_t size);
int8_t YearhMinTemp(struct sensor *info, uint16_t size);
int8_t YearhMaxTemp(struct sensor *info, uint16_t size);
*/
#endif