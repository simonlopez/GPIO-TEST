#ifndef AM3352_H
#define AM3352_H

#define GPIO0_IO_BASE 		0x44e07000
#define GPIO1_IO_BASE 		0x4804c000
#define GPIO2_IO_BASE 		0x481ac000
#define GPIO3_IO_BASE 		0x481ae000

#define GPIO_NUM(pin)		pin % 32
#define GPIO_BANK(pin)		pin / 32
#define GPIO_OFFSET(pin)	1u << (pin % 32)
#endif
