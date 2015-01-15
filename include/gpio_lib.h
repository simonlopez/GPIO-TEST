#ifndef _GPIO_LIB_H_
#define _GPIO_LIB_H_

#include <stdint.h>

#if defined(RK3188)
#include "RK3188.h"
#endif

#if defined(AM3352)
#include "AM3352.h"
#endif
/* Define some constants */
#define GPIO_INPUT			0
#define GPIO_OUTPUT			1

#define GPIO_PULL_DIS		0
#define GPIO_PULL_UP		1
#define GPIO_PULL_DOWN		2

//#define __DEBUG
#ifdef __DEBUG
#define debug(fmt, ...) \
	do { fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, __VA_ARGS__); } while(0)
#else
#define debug(...)
#endif



extern int gpio_init(void);

#if defined(RK3188)
/* FIXME: Rework RK3188 pin mux */
extern int gpio_make_gpio(unsigned int pin);
/* TODO: Add pull-up implementation for AM3352 */
extern int gpio_set_pullup(unsigned int pin, unsigned int pull);
#endif

#if defined (AM3352)
extern int gpio_get_mux(unsigned int pin);
//FIXME: Not working setting mux
extern int gpio_set_mux(unsigned int pin, unsigned long mux);
#endif

/* Read/write direction functions */
extern int gpio_set_cfgpin(unsigned int pin, unsigned int val);
extern int gpio_get_cfgpin(unsigned int pin);

extern int gpio_input(unsigned int pin);
extern int gpio_output(unsigned int pin, unsigned int val);

#if defined(RK3188) || defined(AM3352)
typedef struct {
	unsigned int gpio_pio_base;
	unsigned int swgpio_io_base;
} gpio_base_t;

extern gpio_base_t gpio[4];
#endif

#endif // _GPIO_LIB_H_ 
