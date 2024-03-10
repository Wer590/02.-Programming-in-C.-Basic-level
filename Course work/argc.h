#ifndef _ARGC_H_
#define _ARGC_H_

#include "main.h"
#include <unistd.h>
#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern struct management *control;

int ArgHandler(int argc, char **argv, struct management *st);

#endif