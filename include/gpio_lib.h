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
#define debug(...) printf(__VA_ARGS__)
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
extern int gpio_set_mux(unsigned int pin);
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

#if defined(RK3188)
struct gpio_int {
	unsigned long gpio_inten;			// @ 0x30
	unsigned long gpio_intmask;			// @ 0x34
	unsigned long gpio_inttype_level;	// @ 0x38
	unsigned long gpio_int_polarity;	// @ 0x3c
	unsigned long gpio_int_status;		// @ 0x40
	unsigned long gpio_int_rawstatus;	// @ 0x44
	unsigned long gpio_debounce;		// @ 0x48
	unsigned long gpio_ports_eoi;		// @ 0x4c

};
struct gpio_reg {
	unsigned long gpio_swport_dr;		// @ 0x00
	unsigned long gpio_swport_ddr;		// @ 0x04
	unsigned long res[10];				// Reserved memory
	struct gpio_int gpio_int;
	unsigned long gpio_ext_port;		// @ 0x50
	unsigned long rsrv[3];
	unsigned long gpio_ls_sync;			// @ 0x60;
};
#endif

#if defined(AM3352)
#if 0
struct gpio_reg {
	unsigned long gpio_revision;			// @ 00h
	unsigned long : 32;					// @ 04h
	unsigned long : 32;					// @ 08h
	unsigned long : 32;					// @ 0Ch

	unsigned long gpio_sysconfig;		// @ 10h
	unsigned long : 32; 					// @ 14h
	unsigned long : 32; 					// @ 18h
	unsigned long : 32; 					// @ 1Ch

	unsigned long : 32; 					// @ 20h
	unsigned long gpio_irqstatus_raw_0; 	// @ 24h
	unsigned long gpio_irqstatus_raw_1; 	// @ 28h
	unsigned long gpio_irqstatus_0;     	// @ 2Ch

	unsigned long gpio_irqstatus_1;     	// @ 30h
	unsigned long gpio_irqstatus_set_0; 	// @ 34h
	unsigned long gpio_irqstatus_set_1; 	// @ 38h
	unsigned long gpio_irqstatus_clr_0; 	// @ 3Ch

	unsigned long gpio_irqstatus_clr_1; 	// @ 40h
	unsigned long gpio_irqwaken_0;		// @ 44h
	unsigned long gpio_irqwaken_1;		// @ 48h
	unsigned long : 32;					// @ 4Ch

	unsigned long : 32;					// @ 50h
	unsigned long : 32;					// @ 54h
	unsigned long : 32;					// @ 58h
	unsigned long : 32;					// @ 5Ch

	unsigned long : 32;					// @ 60h
	unsigned long : 32;					// @ 64h
	unsigned long : 32;					// @ 68h
	unsigned long : 32;					// @ 6Ch

	unsigned long : 32;					// @ 70h
	unsigned long : 32;					// @ 74h
	unsigned long : 32;					// @ 78h
	unsigned long : 32;					// @ 7Ch

	unsigned long : 32;					// @ 80h
	unsigned long : 32;					// @ 84h
	unsigned long : 32;					// @ 88h
	unsigned long : 32;					// @ 8Ch

	unsigned long : 32;					// @ 90h
	unsigned long : 32;					// @ 94h
	unsigned long : 32;					// @ 98h
	unsigned long : 32;					// @ 9Ch

	unsigned long : 32;					// @ A0h
	unsigned long : 32;					// @ A4h
	unsigned long : 32;					// @ A8h
	unsigned long : 32;					// @ ACh

	unsigned long : 32;					// @ B0h
	unsigned long : 32;					// @ B4h
	unsigned long : 32;					// @ B8h
	unsigned long : 32;					// @ BCh

	unsigned long : 32;					// @ C0h
	unsigned long : 32;					// @ C4h
	unsigned long : 32;					// @ C8h
	unsigned long : 32;					// @ CCh

	unsigned long : 32;					// @ D0h
	unsigned long : 32;					// @ D4h
	unsigned long : 32;					// @ D8h
	unsigned long : 32;					// @ DCh

	unsigned long : 32;					// @ E0h
	unsigned long : 32;					// @ E4h
	unsigned long : 32;					// @ E8h
	unsigned long : 32;					// @ ECh

	unsigned long : 32;					// @ F0h
	unsigned long : 32;					// @ F4h
	unsigned long : 32;					// @ F8h
	unsigned long : 32;					// @ FCh

	unsigned long : 32;					// @ 100h
	unsigned long : 32;					// @ 104h
	unsigned long : 32;					// @ 108h
	unsigned long : 32;					// @ 10Ch

	unsigned long : 32;					// @ 110h
	unsigned long gpio_sysstatus;		// @ 114h
	unsigned long : 32;					// @ 118h
	unsigned long : 32;					// @ 11Ch

	unsigned long : 32;					// @ 120h
	unsigned long : 32;					// @ 124h
	unsigned long : 32;					// @ 128h
	unsigned long : 32;					// @ 12Ch

	unsigned long gpio_ctrl;				// @ 130h
	unsigned long gpio_oe;				// @ 134h
	unsigned long gpio_datain;			// @ 138h
	unsigned long gpio_dataout;			// @ 13Ch

	unsigned long gpio_leveldetect0;		// @ 140h
	unsigned long gpio_leveldetect1;		// @ 144h
	unsigned long gpio_risingdetect;		// @ 148h
	unsigned long gpio_fallingdetect;	// @ 14Ch

	unsigned long gpio_debouncenable;	// @ 150h
	unsigned long gpio_debouncingtime;	// @ 154h
	unsigned long : 32;					// @ 158h
	unsigned long : 32;					// @ 15Ch

	unsigned long : 32;					// @ 160h
	unsigned long : 32;					// @ 164h
	unsigned long : 32;					// @ 168h
	unsigned long : 32;					// @ 16Ch

	unsigned long : 32;					// @ 170h
	unsigned long : 32;					// @ 174h
	unsigned long : 32;					// @ 178h
	unsigned long : 32;					// @ 17Ch

	unsigned long: 32;					// @ 180h
	unsigned long: 32;					// @ 184h
	unsigned long: 32;					// @ 188h
	unsigned long: 32;					// @ 18Ch

	unsigned long gpio_cleardataout;		// @ 190h
	unsigned long gpio_setdataout;		// @ 194h
};
#endif
struct gpio_reg {
	unsigned long gpio_revision;			// @ 00h
	unsigned long junk0[3];					// @ 04h

	unsigned long gpio_sysconfig;		// @ 10h
	unsigned long junk1[4];

	unsigned long gpio_irqstatus_raw_0; 	// @ 24h
	unsigned long gpio_irqstatus_raw_1; 	// @ 28h
	unsigned long gpio_irqstatus_0;     	// @ 2Ch

	unsigned long gpio_irqstatus_1;     	// @ 30h
	unsigned long gpio_irqstatus_set_0; 	// @ 34h
	unsigned long gpio_irqstatus_set_1; 	// @ 38h
	unsigned long gpio_irqstatus_clr_0; 	// @ 3Ch

	unsigned long gpio_irqstatus_clr_1; 	// @ 40h
	unsigned long gpio_irqwaken_0;		// @ 44h
	unsigned long gpio_irqwaken_1;		// @ 48h


	unsigned long junk2[50];					// @ 110h
	unsigned long gpio_sysstatus;		// @ 114h
	unsigned long junk3[6];

	unsigned long gpio_ctrl;				// @ 130h
	unsigned long gpio_oe;				// @ 134h
	unsigned long gpio_datain;			// @ 138h
	unsigned long gpio_dataout;			// @ 13Ch

	unsigned long gpio_leveldetect0;		// @ 140h
	unsigned long gpio_leveldetect1;		// @ 144h
	unsigned long gpio_risingdetect;		// @ 148h
	unsigned long gpio_fallingdetect;	// @ 14Ch

	unsigned long gpio_debouncenable;	// @ 150h
	unsigned long gpio_debouncingtime;	// @ 154h
	unsigned long junk4[10];

	unsigned long gpio_cleardataout;		// @ 190h
	unsigned long gpio_setdataout;		// @ 194h
};
#endif


extern gpio_base_t gpio[4];
#endif

#endif // _GPIO_LIB_H_ 
