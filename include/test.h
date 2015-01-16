#ifndef _TEST_H
#define _TEST_H

#include <stdint.h>

typedef struct
{
    char name[50];
    uint16_t pin;
    char ext[20];
    uint8_t con;
    char ext_som[20];
    uint8_t con_som;
}gpio_t;

int test(char *name, gpio_t connector[], gpio_t pullpin, int n);
#endif
