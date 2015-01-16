#ifndef _BOARD_AM3352_SOM_H
#define _BOARD_AM3352_SOM_H

#include "test.h"

#define PINN(port, pin)	32*port + pin
#define PIN(port, pin)	PINN(port, pin)


gpio_t uext1[] = {
		{"P0_15/UART1_TXD",	PIN(0,15), "UEXT-1", 3, "AM_CON-GPIO3", 5},
		{"P0_14/UART1_RXD",	PIN(0,14), "UEXT-1", 4, "AM_CON-GPIO3", 6},
		{"P3_6/I2C0-SCL",	PIN(3,6), "UEXT-1", 5, "AM_CON-GPIO3", 15},
		{"P3_5/I2C0-SDA",	PIN(3,5), "UEXT-1", 6, "AM_CON-GPIO3", 16},
//		{"P0_3/SPI0_D0(MISO)",	PIN(0,3), "UEXT-1", 7, "AM_CON-GPIO3", 9},
//		{"P0_4/SPI0_D1(MOSI)",	PIN(0,4), "UEXT-1", 8, "AM_CON-GPIO3", 10},
	//	{"P0_2/SPI0_SCLK",	PIN(0,2), "UEXT-1", 9},
//		{"P0_5/SPI0_CS0",	PIN(0,5), "UEXT-1", 10, "AM_CON-GPIO3", 12},
};

gpio_t uext2[] = {
		{"P1_9/UART4_TXD",	PIN(1,9), "UEXT-2", 3, "AM_CON-GPIO3", 13},
		{"P1_8/UART4_RXD",	PIN(1,8), "UEXT-2", 4, "AM_CON-GPIO3", 14},
		{"P3_6/I2C0-SCL",	PIN(3,6), "UEXT-2", 5, "AM_CON-GPIO3", 15},
		{"P3_5/I2C0-SDA",	PIN(3,5), "UEXT-2", 6, "AM_CON-GPIO3", 16},
		{"P3_15/SPI1_D0(MISO)",	PIN(3,15), "UEXT-2", 7, "AM_CON-GPIO3", 17},
		{"P3_16/SPI1_D1(MOSI)",	PIN(3,16), "UEXT-2", 8, "AM_CON-GPIO3", 18},
//		{"P3_14/SPI1_CLK",	PIN(3,14), "UEXT-2", 9},
		{"P3_17/SPI1_CS0",	PIN(3,17), "UEXT-2", 10, "AM_CON-GPIO3", 20},

};

//gpio_t ext1[] = {
//		{"P1_10/UART0_RX",		PIN(0, B4), "EXT1", 5},
//		{"P1_31/NDQS",		PIN(0, B4), "EXT1", 6},
//		{"P1_11/UART0_TX",		PIN(0, B4), "EXT1", 7},
//		{"P1_7/NDQ7",		PIN(0, B4), "EXT1", 8},
//		{"P2_4/NWE",		PIN(0, B4), "EXT1", 9},
//		{"P1_6/NDQ6",		PIN(0, B4), "EXT1", 10},
//		{"P2_2/NALE",		PIN(0, B4), "EXT1", 11},
//		{"P1_5/NDQ5",		PIN(0, B4), "EXT1", 12},
//		{"P2_5/NCLE",		PIN(0, B4), "EXT1", 13},
//		{"P1_4/NDQ4",		PIN(0, B4), "EXT1", 14},
//		{"P1_30/NCE1",		PIN(0, B4), "EXT1", 15},
//		{"P1_3/NDQ3",		PIN(0, B4), "EXT1", 16},
//		{"P1_29/NCE0",		PIN(0, B4), "EXT1", 17},
//		{"P1_2/NDQ2",		PIN(0, B4), "EXT1", 18},
//		{"P2_3/NRE",		PIN(0, B4), "EXT1", 19},
//		{"P1_1/NDQ1",		PIN(0, B4), "EXT1", 20},
//		{"P0_30/NRB0",		PIN(0, B4), "EXT1", 21},
//		{"P1_0/NDQ0",		PIN(0, B4), "EXT1", 22},
//		{"P1_28",		PIN(0, B4), "EXT1", 23},
//		{"P0_19/LED1",		PIN(0, B4), "EXT1", 25},
//		{"P3_18",		PIN(0, B4), "EXT1", 27},
//		{"P3_19",		PIN(0, B4), "EXT1", 28},
//		{"P3_20",		PIN(0, B4), "EXT1", 29},
//		{"P3_21",		PIN(0, B4), "EXT1", 30},
//		{"P3_7",		PIN(0, B4), "EXT1", 31},
//		{"P3_8",		PIN(0, B4), "EXT1", 32},
//		{"P0_7/PWM0_OUT",		PIN(0, B4), "EXT1", 33},
//
//
//
//};

gpio_t uext1_pp = {"P0_2/SPI0_SCLK",	PIN(0,2), "UEXT-1", 9, "AM_CON-GPIO3", 11};
gpio_t uext2_pp = {"P3_14/SPI1_CLK",	PIN(3,14), "UEXT-2", 9, "AM_CON-GPIO3", 19};
//gpio_t uext2_pp = {"GPIO0_D6/SPI1_CLK", PIN(0,D6), "UEXT-2", 9};
//gpio_t ext1_pp = {"GPIO0_B4/LED1",		PIN(0, B4), "EXT1", 18};

#endif
