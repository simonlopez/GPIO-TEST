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

extern int16_t gpio_init(void);

#if defined(RK3188)
/* FIXME: Rework RK3188 pin mux */
extern int16_t gpio_make_gpio(uint16_t pin);
/* TODO: Add pull-up implementation for AM3352 */
extern int16_t gpio_set_pullup(uint16_t pin, uint16_t pull);
#endif

#if defined (AM3352)
extern int16_t gpio_get_mux(uint16_t pin);
extern int16_t gpio_set_mux(uint16_t pin);
#endif

/* Read/write direction functions */
extern int16_t gpio_set_cfgpin(uint16_t pin, uint16_t val);
extern int16_t gpio_get_cfgpin(uint16_t pin);

extern int16_t gpio_input(uint16_t pin);
extern int16_t gpio_output(uint16_t pin, uint16_t val);

#if defined(RK3188) || defined(AM3352)
typedef struct {
	uint32_t gpio_pio_base;
	uint32_t swgpio_io_base;
} gpio_base_t;

#if defined(RK3188)
struct gpio_int {
	uint32_t gpio_inten;			// @ 0x30
	uint32_t gpio_intmask;			// @ 0x34
	uint32_t gpio_inttype_level;	// @ 0x38
	uint32_t gpio_int_polarity;	// @ 0x3c
	uint32_t gpio_int_status;		// @ 0x40
	uint32_t gpio_int_rawstatus;	// @ 0x44
	uint32_t gpio_debounce;		// @ 0x48
	uint32_t gpio_ports_eoi;		// @ 0x4c

};
struct gpio_reg {
	uint32_t gpio_swport_dr;		// @ 0x00
	uint32_t gpio_swport_ddr;		// @ 0x04
	uint32_t res[10];				// Reserved memory
	struct gpio_int gpio_int;
	uint32_t gpio_ext_port;		// @ 0x50
	uint32_t rsrv[3];
	uint32_t gpio_ls_sync;			// @ 0x60;
};
#endif

#if defined(AM3352)
struct gpio_reg {
	uint32_t gpio_revision;			// @ 00h
	uint32_t : 32;					// @ 04h
	uint32_t : 32;					// @ 08h
	uint32_t : 32;					// @ 0Ch

	uint32_t gpio_sysconfig;		// @ 10h
	uint32_t : 32; 					// @ 14h
	uint32_t : 32; 					// @ 18h
	uint32_t : 32; 					// @ 1Ch

	uint32_t : 32; 					// @ 20h
	uint32_t gpio_irqstatus_raw_0; 	// @ 24h
	uint32_t gpio_irqstatus_raw_1; 	// @ 28h
	uint32_t gpio_irqstatus_0;     	// @ 2Ch

	uint32_t gpio_irqstatus_1;     	// @ 30h
	uint32_t gpio_irqstatus_set_0; 	// @ 34h
	uint32_t gpio_irqstatus_set_1; 	// @ 38h
	uint32_t gpio_irqstatus_clr_0; 	// @ 3Ch

	uint32_t gpio_irqstatus_clr_1; 	// @ 40h
	uint32_t gpio_irqwaken_0;		// @ 44h
	uint32_t gpio_irqwaken_1;		// @ 48h
	uint32_t : 32;					// @ 4Ch

	uint32_t : 32;					// @ 50h
	uint32_t : 32;					// @ 54h
	uint32_t : 32;					// @ 58h
	uint32_t : 32;					// @ 5Ch

	uint32_t : 32;					// @ 60h
	uint32_t : 32;					// @ 64h
	uint32_t : 32;					// @ 68h
	uint32_t : 32;					// @ 6Ch

	uint32_t : 32;					// @ 70h
	uint32_t : 32;					// @ 74h
	uint32_t : 32;					// @ 78h
	uint32_t : 32;					// @ 7Ch

	uint32_t : 32;					// @ 80h
	uint32_t : 32;					// @ 84h
	uint32_t : 32;					// @ 88h
	uint32_t : 32;					// @ 8Ch

	uint32_t : 32;					// @ 90h
	uint32_t : 32;					// @ 94h
	uint32_t : 32;					// @ 98h
	uint32_t : 32;					// @ 9Ch

	uint32_t : 32;					// @ A0h
	uint32_t : 32;					// @ A4h
	uint32_t : 32;					// @ A8h
	uint32_t : 32;					// @ ACh

	uint32_t : 32;					// @ B0h
	uint32_t : 32;					// @ B4h
	uint32_t : 32;					// @ B8h
	uint32_t : 32;					// @ BCh

	uint32_t : 32;					// @ C0h
	uint32_t : 32;					// @ C4h
	uint32_t : 32;					// @ C8h
	uint32_t : 32;					// @ CCh

	uint32_t : 32;					// @ D0h
	uint32_t : 32;					// @ D4h
	uint32_t : 32;					// @ D8h
	uint32_t : 32;					// @ DCh

	uint32_t : 32;					// @ E0h
	uint32_t : 32;					// @ E4h
	uint32_t : 32;					// @ E8h
	uint32_t : 32;					// @ ECh

	uint32_t : 32;					// @ F0h
	uint32_t : 32;					// @ F4h
	uint32_t : 32;					// @ F8h
	uint32_t : 32;					// @ FCh

	uint32_t : 32;					// @ 100h
	uint32_t : 32;					// @ 104h
	uint32_t : 32;					// @ 108h
	uint32_t : 32;					// @ 10Ch

	uint32_t : 32;					// @ 110h
	uint32_t gpio_sysstatus;		// @ 114h
	uint32_t : 32;					// @ 118h
	uint32_t : 32;					// @ 11Ch

	uint32_t : 32;					// @ 120h
	uint32_t : 32;					// @ 124h
	uint32_t : 32;					// @ 128h
	uint32_t : 32;					// @ 12Ch

	uint32_t gpio_ctrl;				// @ 130h
	uint32_t gpio_oe;				// @ 134h
	uint32_t gpio_datain;			// @ 138h
	uint32_t gpio_dataout;			// @ 13Ch

	uint32_t gpio_leveldetect0;		// @ 140h
	uint32_t gpio_leveldetect1;		// @ 144h
	uint32_t gpio_risingdetect;		// @ 148h
	uint32_t gpio_fallingdetect;	// @ 14Ch

	uint32_t gpio_debouncenable;	// @ 150h
	uint32_t gpio_debouncingtime;	// @ 154h
	uint32_t : 32;					// @ 158h
	uint32_t : 32;					// @ 15Ch

	uint32_t : 32;					// @ 160h
	uint32_t : 32;					// @ 164h
	uint32_t : 32;					// @ 168h
	uint32_t : 32;					// @ 16Ch

	uint32_t : 32;					// @ 170h
	uint32_t : 32;					// @ 174h
	uint32_t : 32;					// @ 178h
	uint32_t : 32;					// @ 17Ch

	uint32_t : 32;					// @ 180h
	uint32_t : 32;					// @ 184h
	uint32_t : 32;					// @ 188h
	uint32_t : 32;					// @ 18Ch

	uint32_t gpio_cleardataout;		// @ 190h
	uint32_t gpio_setdataout;		// @ 194h


};
#endif


extern gpio_base_t gpio[4];
#endif

#endif // _GPIO_LIB_H_ 
