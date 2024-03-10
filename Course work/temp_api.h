#ifndef _TEMP_API_H_
#define _TEMP_API_H_

#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1
#define NUNBER_READ 6

struct sensor
{
    uint32_t number;
    uint16_t year;
    uint8_t day;
    uint8_t month;
    uint8_t hour;
    uint8_t minutes;
    int8_t temperature;
};

struct data
{
    int32_t number;
    struct sensor info[SIZE];
};

union sensor_serdes
{
    struct data _data;
    uint8_t bytes[sizeof(struct data)];
};

extern struct management *control;

uint32_t LoadSVGSenRaw(struct sensor *info, char *mane_file);
uint32_t SaveSVGSen(struct sensor *info, struct management *st);

void AddRecord(struct sensor *info, int number,
               uint16_t year, uint8_t month, uint8_t day,
               uint8_t hour, uint8_t minutes, int8_t t);
void Print(struct sensor *info, struct management *st);
void DeleteRecord(struct sensor *info, int number);
void SortByTempUp(struct sensor *info, struct management *st);
void SortByTempDn(struct sensor *info, struct management *st);
void SortByDate(struct sensor *info, struct management *st);

void cgangeIJ(struct sensor *info, uint32_t i, uint32_t j);

float AvgTemp(struct sensor *info, struct management *st);
int8_t MinTemp(struct sensor *info, struct management *st);
int8_t MaxTemp(struct sensor *info, struct management *st);

#endif