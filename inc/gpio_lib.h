#ifndef _GPIO_LIB_H_
#define _GPIO_LIB_H_

#if defined(RK3188)
#define PIN_BASE	160
#define NUM_GROUP	32

#define	RK30_PIN0_PA0		(0*NUM_GROUP + PIN_BASE + 0)
#define	RK30_PIN0_PA1		(0*NUM_GROUP + PIN_BASE + 1)
#define	RK30_PIN0_PA2		(0*NUM_GROUP + PIN_BASE + 2)
#define	RK30_PIN0_PA3		(0*NUM_GROUP + PIN_BASE + 3)
#define	RK30_PIN0_PA4		(0*NUM_GROUP + PIN_BASE + 4)
#define	RK30_PIN0_PA5		(0*NUM_GROUP + PIN_BASE + 5)
#define	RK30_PIN0_PA6		(0*NUM_GROUP + PIN_BASE + 6)
#define	RK30_PIN0_PA7		(0*NUM_GROUP + PIN_BASE + 7)
#define	RK30_PIN0_PB0		(0*NUM_GROUP + PIN_BASE + 8)
#define	RK30_PIN0_PB1		(0*NUM_GROUP + PIN_BASE + 9)
#define	RK30_PIN0_PB2		(0*NUM_GROUP + PIN_BASE + 10)
#define	RK30_PIN0_PB3		(0*NUM_GROUP + PIN_BASE + 11)
#define	RK30_PIN0_PB4		(0*NUM_GROUP + PIN_BASE + 12)
#define	RK30_PIN0_PB5		(0*NUM_GROUP + PIN_BASE + 13)
#define	RK30_PIN0_PB6		(0*NUM_GROUP + PIN_BASE + 14)
#define	RK30_PIN0_PB7		(0*NUM_GROUP + PIN_BASE + 15)
#define	RK30_PIN0_PC0		(0*NUM_GROUP + PIN_BASE + 16)
#define	RK30_PIN0_PC1		(0*NUM_GROUP + PIN_BASE + 17)
#define	RK30_PIN0_PC2		(0*NUM_GROUP + PIN_BASE + 18)
#define	RK30_PIN0_PC3		(0*NUM_GROUP + PIN_BASE + 19)
#define	RK30_PIN0_PC4		(0*NUM_GROUP + PIN_BASE + 20)
#define	RK30_PIN0_PC5		(0*NUM_GROUP + PIN_BASE + 21)
#define	RK30_PIN0_PC6		(0*NUM_GROUP + PIN_BASE + 22)
#define	RK30_PIN0_PC7		(0*NUM_GROUP + PIN_BASE + 23)
#define	RK30_PIN0_PD0		(0*NUM_GROUP + PIN_BASE + 24)
#define	RK30_PIN0_PD1		(0*NUM_GROUP + PIN_BASE + 25)
#define	RK30_PIN0_PD2		(0*NUM_GROUP + PIN_BASE + 26)
#define	RK30_PIN0_PD3		(0*NUM_GROUP + PIN_BASE + 27)
#define	RK30_PIN0_PD4		(0*NUM_GROUP + PIN_BASE + 28)
#define	RK30_PIN0_PD5		(0*NUM_GROUP + PIN_BASE + 29)
#define	RK30_PIN0_PD6		(0*NUM_GROUP + PIN_BASE + 30)
#define	RK30_PIN0_PD7		(0*NUM_GROUP + PIN_BASE + 31)

#define	RK30_PIN1_PA0		(1*NUM_GROUP + PIN_BASE + 0)
#define	RK30_PIN1_PA1		(1*NUM_GROUP + PIN_BASE + 1)
#define	RK30_PIN1_PA2		(1*NUM_GROUP + PIN_BASE + 2)
#define	RK30_PIN1_PA3		(1*NUM_GROUP + PIN_BASE + 3)
#define	RK30_PIN1_PA4		(1*NUM_GROUP + PIN_BASE + 4)
#define	RK30_PIN1_PA5		(1*NUM_GROUP + PIN_BASE + 5)
#define	RK30_PIN1_PA6		(1*NUM_GROUP + PIN_BASE + 6)
#define	RK30_PIN1_PA7		(1*NUM_GROUP + PIN_BASE + 7)
#define	RK30_PIN1_PB0		(1*NUM_GROUP + PIN_BASE + 8)
#define	RK30_PIN1_PB1		(1*NUM_GROUP + PIN_BASE + 9)
#define	RK30_PIN1_PB2		(1*NUM_GROUP + PIN_BASE + 10)
#define	RK30_PIN1_PB3		(1*NUM_GROUP + PIN_BASE + 11)
#define	RK30_PIN1_PB4		(1*NUM_GROUP + PIN_BASE + 12)
#define	RK30_PIN1_PB5		(1*NUM_GROUP + PIN_BASE + 13)
#define	RK30_PIN1_PB6		(1*NUM_GROUP + PIN_BASE + 14)
#define	RK30_PIN1_PB7		(1*NUM_GROUP + PIN_BASE + 15)
#define	RK30_PIN1_PC0		(1*NUM_GROUP + PIN_BASE + 16)
#define	RK30_PIN1_PC1		(1*NUM_GROUP + PIN_BASE + 17)
#define	RK30_PIN1_PC2		(1*NUM_GROUP + PIN_BASE + 18)
#define	RK30_PIN1_PC3		(1*NUM_GROUP + PIN_BASE + 19)
#define	RK30_PIN1_PC4		(1*NUM_GROUP + PIN_BASE + 20)
#define	RK30_PIN1_PC5		(1*NUM_GROUP + PIN_BASE + 21)
#define	RK30_PIN1_PC6		(1*NUM_GROUP + PIN_BASE + 22)
#define	RK30_PIN1_PC7		(1*NUM_GROUP + PIN_BASE + 23)
#define	RK30_PIN1_PD0		(1*NUM_GROUP + PIN_BASE + 24)
#define	RK30_PIN1_PD1		(1*NUM_GROUP + PIN_BASE + 25)
#define	RK30_PIN1_PD2		(1*NUM_GROUP + PIN_BASE + 26)
#define	RK30_PIN1_PD3		(1*NUM_GROUP + PIN_BASE + 27)
#define	RK30_PIN1_PD4		(1*NUM_GROUP + PIN_BASE + 28)
#define	RK30_PIN1_PD5		(1*NUM_GROUP + PIN_BASE + 29)
#define	RK30_PIN1_PD6		(1*NUM_GROUP + PIN_BASE + 30)
#define	RK30_PIN1_PD7		(1*NUM_GROUP + PIN_BASE + 31)

#define	RK30_PIN2_PA0		(2*NUM_GROUP + PIN_BASE + 0)
#define	RK30_PIN2_PA1		(2*NUM_GROUP + PIN_BASE + 1)
#define	RK30_PIN2_PA2		(2*NUM_GROUP + PIN_BASE + 2)
#define	RK30_PIN2_PA3		(2*NUM_GROUP + PIN_BASE + 3)
#define	RK30_PIN2_PA4		(2*NUM_GROUP + PIN_BASE + 4)
#define	RK30_PIN2_PA5		(2*NUM_GROUP + PIN_BASE + 5)
#define	RK30_PIN2_PA6		(2*NUM_GROUP + PIN_BASE + 6)
#define	RK30_PIN2_PA7		(2*NUM_GROUP + PIN_BASE + 7)
#define	RK30_PIN2_PB0		(2*NUM_GROUP + PIN_BASE + 8)
#define	RK30_PIN2_PB1		(2*NUM_GROUP + PIN_BASE + 9)
#define	RK30_PIN2_PB2		(2*NUM_GROUP + PIN_BASE + 10)
#define	RK30_PIN2_PB3		(2*NUM_GROUP + PIN_BASE + 11)
#define	RK30_PIN2_PB4		(2*NUM_GROUP + PIN_BASE + 12)
#define	RK30_PIN2_PB5		(2*NUM_GROUP + PIN_BASE + 13)
#define	RK30_PIN2_PB6		(2*NUM_GROUP + PIN_BASE + 14)
#define	RK30_PIN2_PB7		(2*NUM_GROUP + PIN_BASE + 15)
#define	RK30_PIN2_PC0		(2*NUM_GROUP + PIN_BASE + 16)
#define	RK30_PIN2_PC1		(2*NUM_GROUP + PIN_BASE + 17)
#define	RK30_PIN2_PC2		(2*NUM_GROUP + PIN_BASE + 18)
#define	RK30_PIN2_PC3		(2*NUM_GROUP + PIN_BASE + 19)
#define	RK30_PIN2_PC4		(2*NUM_GROUP + PIN_BASE + 20)
#define	RK30_PIN2_PC5		(2*NUM_GROUP + PIN_BASE + 21)
#define	RK30_PIN2_PC6		(2*NUM_GROUP + PIN_BASE + 22)
#define	RK30_PIN2_PC7		(2*NUM_GROUP + PIN_BASE + 23)
#define	RK30_PIN2_PD0		(2*NUM_GROUP + PIN_BASE + 24)
#define	RK30_PIN2_PD1		(2*NUM_GROUP + PIN_BASE + 25)
#define	RK30_PIN2_PD2		(2*NUM_GROUP + PIN_BASE + 26)
#define	RK30_PIN2_PD3		(2*NUM_GROUP + PIN_BASE + 27)
#define	RK30_PIN2_PD4		(2*NUM_GROUP + PIN_BASE + 28)
#define	RK30_PIN2_PD5		(2*NUM_GROUP + PIN_BASE + 29)
#define	RK30_PIN2_PD6		(2*NUM_GROUP + PIN_BASE + 30)
#define	RK30_PIN2_PD7		(2*NUM_GROUP + PIN_BASE + 31)

#define	RK30_PIN3_PA0		(3*NUM_GROUP + PIN_BASE + 0)
#define	RK30_PIN3_PA1		(3*NUM_GROUP + PIN_BASE + 1)
#define	RK30_PIN3_PA2		(3*NUM_GROUP + PIN_BASE + 2)
#define	RK30_PIN3_PA3		(3*NUM_GROUP + PIN_BASE + 3)
#define	RK30_PIN3_PA4		(3*NUM_GROUP + PIN_BASE + 4)
#define	RK30_PIN3_PA5		(3*NUM_GROUP + PIN_BASE + 5)
#define	RK30_PIN3_PA6		(3*NUM_GROUP + PIN_BASE + 6)
#define	RK30_PIN3_PA7		(3*NUM_GROUP + PIN_BASE + 7)
#define	RK30_PIN3_PB0		(3*NUM_GROUP + PIN_BASE + 8)
#define	RK30_PIN3_PB1		(3*NUM_GROUP + PIN_BASE + 9)
#define	RK30_PIN3_PB2		(3*NUM_GROUP + PIN_BASE + 10)
#define	RK30_PIN3_PB3		(3*NUM_GROUP + PIN_BASE + 11)
#define	RK30_PIN3_PB4		(3*NUM_GROUP + PIN_BASE + 12)
#define	RK30_PIN3_PB5		(3*NUM_GROUP + PIN_BASE + 13)
#define	RK30_PIN3_PB6		(3*NUM_GROUP + PIN_BASE + 14)
#define	RK30_PIN3_PB7		(3*NUM_GROUP + PIN_BASE + 15)
#define	RK30_PIN3_PC0		(3*NUM_GROUP + PIN_BASE + 16)
#define	RK30_PIN3_PC1		(3*NUM_GROUP + PIN_BASE + 17)
#define	RK30_PIN3_PC2		(3*NUM_GROUP + PIN_BASE + 18)
#define	RK30_PIN3_PC3		(3*NUM_GROUP + PIN_BASE + 19)
#define	RK30_PIN3_PC4		(3*NUM_GROUP + PIN_BASE + 20)
#define	RK30_PIN3_PC5		(3*NUM_GROUP + PIN_BASE + 21)
#define	RK30_PIN3_PC6		(3*NUM_GROUP + PIN_BASE + 22)
#define	RK30_PIN3_PC7		(3*NUM_GROUP + PIN_BASE + 23)
#define	RK30_PIN3_PD0		(3*NUM_GROUP + PIN_BASE + 24)
#define	RK30_PIN3_PD1		(3*NUM_GROUP + PIN_BASE + 25)
#define	RK30_PIN3_PD2		(3*NUM_GROUP + PIN_BASE + 26)
#define	RK30_PIN3_PD3		(3*NUM_GROUP + PIN_BASE + 27)
#define	RK30_PIN3_PD4		(3*NUM_GROUP + PIN_BASE + 28)
#define	RK30_PIN3_PD5		(3*NUM_GROUP + PIN_BASE + 29)
#define	RK30_PIN3_PD6		(3*NUM_GROUP + PIN_BASE + 30)
#define	RK30_PIN3_PD7		(3*NUM_GROUP + PIN_BASE + 31)

#define GPIO_SWPORT_DR		0x00
#define GPIO_SWPORT_DDR		0x04
#define GPIO_INTEN			0x30
#define GPIO_INTMASK		0x34
#define GPIO_INTTYPE_LEVEL	0x38
#define GPIO_INT_POLARITY	0x3c
#define GPIO_INT_STATUS		0x40
#define GPIO_INT_RAWSTATUS	0x44
#define GPIO_DEBOUNCE		0x48
#define GPIO_PORTS_EOI		0x4c
#define GPIO_EXT_PORT		0x50
#define GPIO_LS_SYNC		0x60

#define GPIO0_IO_BASE 		0x2000a000
#define GPIO1_IO_BASE 		0x2003c000
#define GPIO2_IO_BASE 		0x2003e000
#define GPIO3_IO_BASE 		0x20080000

#define GPIO_GRF_BASE		0x20008000
#define GPIO_GRF_IOMUX		0x0060
#define GRF_GPIO0B_PULL     0x0164

#define RK30_PMU_BASE		0x20004000
#define PMU_GPIO0A_PULL		0x64

#define GPIO_NUM(pin)		pin - 160
#define GPIO_BANK(pin)		pin >> 5
#define GPIO_OFFSET(pin)	1u << (pin % 32)

/* Define some constants */
#define GPIO_INPUT			0
#define GPIO_OUTPUT			1

#define GPIO_PULL_DIS		0
#define GPIO_PULL_UP		1
#define GPIO_PULL_DOWN		2

#endif

extern int gpio_init(void);

#if defined(RK3188)
extern int gpio_make_gpio(unsigned int pin);
/* TODO: Add pull-up implementation for AM3352 */
extern int gpio_set_pullup(unsigned int pin, unsigned int pull);
#endif

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

	uint32_t cleardataout;			// @ 190h
	uint32_t setdataout;			// @ 194h


};
#endif
extern gpio_base_t gpio[4];
#endif

#endif // _GPIO_LIB_H_ 
