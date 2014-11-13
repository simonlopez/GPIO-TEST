#ifndef _EXT_H
#define _EXT_H

#include "gpio_lib.h"
#include "test.h"




#define PINN(port, pin)	RK30_PIN ## port ## _P ## pin
#define PIN(port, pin)	PINN(port, pin)


gpio_t uext1[] = {
		{"GPIO1_A1/UART0_TX",	PIN(1,A1), "UEXT-1", 3},
		{"GPIO1_A0/UART0_RX",	PIN(1,A0), "UEXT-1", 4},
		{"GPIO1_D1/I2C0_SCL",	PIN(1,D1), "UEXT-1", 5},
		{"GPIO1_D0/I2C0_SDA",	PIN(1,D0), "UEXT-1", 6},
		{"GPIO1_A4/SPI0_MISO",	PIN(1,A4), "UEXT-1", 7},
		{"GPIO1_A5/SPI0_MOSI",	PIN(1,A5), "UEXT-1", 8},
//		{"GPIO1_A6/SPI0_SCK",	PIN(1,A6), "UEXT-1", 9},
		{"GPIO1_A7/SPI0_CSN0",	PIN(1,A7), "UEXT-1", 10},
};

gpio_t uext2[] = {
		{"GPIO1_B3/UART3_TX",	PIN(1,B3), "UEXT-2", 3},
		{"GPIO1_B2/UART3_RX",	PIN(1,B2), "UEXT-2", 4},
		{"GPIO1_D7/I2C4_SCL",	PIN(1,D7), "UEXT-2", 5},
		{"GPIO1_D6/I2C4_SDA",	PIN(1,D6), "UEXT-2", 6},
		{"GPIO0_D4/SPI1_MISO",	PIN(0,D4), "UEXT-2", 7},
		{"GPIO0_D5/SPI1_MOSI",	PIN(0,D5), "UEXT-2", 8},
//		{"GPIO0_D6/SPI1_CLK",	PIN(0,D6), "UEXT-2", 9},
		{"GPIO0_D7/SPI1_CSNO",	PIN(0,D7), "UEXT-2", 10},

};

gpio_t ext1[] = {
	//	{"GPIO0_B4/LED1",		PIN(0, B4), "EXT1", 18},
		{"GPIO0_B6/LED2",		PIN(0, B6), "EXT1", 20},
		{"GPIO3_D5/PWM2",		PIN(3, D5), "EXT1", 22},
		{"GPIO0_D0/FLASH_DQS",	PIN(0, D0), "EXT1", 23},
		{"GPIO3_D6",			PIN(3, D6), "EXT1", 24},
		{"GPIO0_D1/FLASH_CSN1",	PIN(0, D1), "EXT1", 25},
		{"GPIO0_C0",			PIN(0, C0), "EXT1", 26},
		{"GPIO0_D2/FLASH_CSN2",	PIN(0, D2), "EXT1", 27},
		{"GPIO0_C1",			PIN(0, C1), "EXT1", 28},
		{"GPIO0_D3/FLASH_CSN3",	PIN(0, D3), "EXT1", 29},
		{"GPIO0_C2",			PIN(0, C2), "EXT1", 30},
		{"GPIO1_C0",			PIN(1, C0), "EXT1", 31},
		{"GPIO0_C3",			PIN(0, C3), "EXT1", 32},
		{"GPIO1_C4",			PIN(1, C4), "EXT1", 33},
		{"GPIO0_C4",			PIN(0, C4), "EXT1", 34},
		{"GPIO1_B4",			PIN(1, B4), "EXT1", 35},
		{"GPIO0_C5",			PIN(0, C5), "EXT1", 36},
		{"GPIO1_B5",			PIN(1, B5), "EXT1", 37},
		{"GPIO0_C6",			PIN(0, C6), "EXT1", 38},
	//	{"GPIO1_B7/SDO",		PIN(1, B7), "EXT1", 39},	AR1021 IRQ PIN
		{"GPIO0_C7",			PIN(0, C7), "EXT1", 40},
};

gpio_t ext2[] = {
		{"GPIO0_A1",			PIN(0, A1), "EXT2", 5},
		{"GPIO0_B0",			PIN(0, B0), "EXT2", 6},
		{"GPIO0_A5",			PIN(0, A5), "EXT2", 7},
		{"GPIO0_B1",			PIN(0, B1), "EXT2", 8},
		{"GPIO0_A6",			PIN(0, A6), "EXT2", 9},
		{"GPIO0_B2",			PIN(0, B2), "EXT2", 10},

		{"GPIO0_A7",			PIN(0, A7), "EXT2", 11},
		{"GPIO0_B7",			PIN(0, B7), "EXT2", 12},
		{"CIF_D0",				PIN(3, B4), "EXT2", 13},
		{"GPIO1_A2",			PIN(1, A2), "EXT2", 14},
		{"CIF_D1",				PIN(3, B5), "EXT2", 15},
		{"GPIO1_A3",			PIN(1, A3), "EXT2", 16},

		{"CIF_CLKO",			PIN(3, B3), "EXT2", 22},

		{"CIF_D10/SDA",			PIN(3, B6), "EXT2", 33},
		{"CIF_D11/SCL",			PIN(3, B7), "EXT2", 34},
		{"GPIO2_D4",			PIN(2, D4), "EXT2", 35},
		{"GPIO2_D5",			PIN(2, D5), "EXT2", 36},
	//	{"GPIO3_A0",			PIN(3, A0), "EXT2", 37},
		{"GPIO3_B1",			PIN(3, B1), "EXT2", 38},
};
gpio_t uext1_pp = {"GPIO1_A6/SPI0_SCK",	PIN(1,A6), "UEXT-1", 9};
gpio_t uext2_pp = {"GPIO0_D6/SPI1_CLK", PIN(0,D6), "UEXT-2", 9};
gpio_t ext1_pp = {"GPIO0_B4/LED1",		PIN(0, B4), "EXT1", 18};
gpio_t ext2_pp = {"GPIO3_A0",			PIN(3, A0), "EXT2", 37};

#endif
