#ifndef _PRINT_H
#define _PRINT_H

#include "stdint.h"

int printk(const char *format, ...);
int write_console(const char *buffer, int size);

#endif