#ifndef _TEST_H
#define _TEST_H

#include <stdint.h>

typedef struct
{
    char name[50];
    uint16_t pin;
    char ext[20];
    uint8_t con;
}gpio_t;

int test(char *name, gpio_t connector[], gpio_t pullpin, int n);
#endif
