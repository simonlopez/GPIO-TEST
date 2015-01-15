#ifndef AM3352_H
#define AM3352_H

#define GPIO0_IO_BASE 		0x44e07000
#define GPIO1_IO_BASE 		0x4804c000
#define GPIO2_IO_BASE 		0x481ac000
#define GPIO3_IO_BASE 		0x481ae000
#define CONTROL_MODULE		0x44e10800

#define GPIO_NUM(pin)		(pin % 32)
#define GPIO_BANK(pin)		(pin / 32)


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




union conf_pad {
	unsigned long conf;
	struct {
		unsigned mode		: 	3;
		unsigned puden		:	1;
		unsigned putypesel	:	1;
		unsigned rxactive	:	1;
		unsigned slectrl	:	1;
		unsigned 			:	25;
	};
};

struct conf_module_pad {
	union conf_pad conf_gpmc_ad0;
	union conf_pad conf_gpmc_ad1;
	union conf_pad conf_gpmc_ad2;
	union conf_pad conf_gpmc_ad3;
	union conf_pad conf_gpmc_ad4;
	union conf_pad conf_gpmc_ad5;
	union conf_pad conf_gpmc_ad6;
	union conf_pad conf_gpmc_ad7;
	union conf_pad conf_gpmc_ad8;
	union conf_pad conf_gpmc_ad9;
	union conf_pad conf_gpmc_ad10;
	union conf_pad conf_gpmc_ad11;
	union conf_pad conf_gpmc_ad12;
	union conf_pad conf_gpmc_ad13;
	union conf_pad conf_gpmc_ad14;
	union conf_pad conf_gpmc_ad15;
	union conf_pad conf_gpmc_a0;
	union conf_pad conf_gpmc_a1;
	union conf_pad conf_gpmc_a2;
	union conf_pad conf_gpmc_a3;
	union conf_pad conf_gpmc_a4;
	union conf_pad conf_gpmc_a5;
	union conf_pad conf_gpmc_a6;
	union conf_pad conf_gpmc_a7;
	union conf_pad conf_gpmc_a8;
	union conf_pad conf_gpmc_a9;
	union conf_pad conf_gpmc_a10;
	union conf_pad conf_gpmc_a11;
	union conf_pad conf_gpmc_wait0;
	union conf_pad conf_gpmc_wpn;
	union conf_pad conf_gpmc_ben1;
	union conf_pad conf_gpmc_csn0;
	union conf_pad conf_gpmc_csn1;
	union conf_pad conf_gpmc_csn2;
	union conf_pad conf_gpmc_csn3;
	union conf_pad conf_gpmc_clk;
	union conf_pad conf_gpmc_advn_ale;
	union conf_pad conf_gpmc_oen_ren;
	union conf_pad conf_gpmc_wen;
	union conf_pad conf_gpmc_ben0_cle;
	union conf_pad conf_lcd_data0;
	union conf_pad conf_lcd_data1;
    union conf_pad conf_lcd_data2;
	union conf_pad conf_lcd_data3;
	union conf_pad conf_lcd_data4;
	union conf_pad conf_lcd_data5;
	union conf_pad conf_lcd_data6;
	union conf_pad conf_lcd_data7;
	union conf_pad conf_lcd_data8;
	union conf_pad conf_lcd_data9;
	union conf_pad conf_lcd_data10;
	union conf_pad conf_lcd_data11;
	union conf_pad conf_lcd_data12;
	union conf_pad conf_lcd_data13;
	union conf_pad conf_lcd_data14;
	union conf_pad conf_lcd_data15;
	union conf_pad conf_lcd_vsync;
	union conf_pad conf_lcd_hsync;
	union conf_pad conf_lcd_pclk;
	union conf_pad conf_lcd_ac_bias_en;
	union conf_pad conf_mmc0_dat3;
	union conf_pad conf_mmc0_dat2;
	union conf_pad conf_mmc0_dat1;
	union conf_pad conf_mmc0_dat0;
	union conf_pad conf_mmc0_clk;
	union conf_pad conf_mmc0_cmd;
	union conf_pad conf_mii1_col;
	union conf_pad conf_mii1_crs;
	union conf_pad conf_mii1_rx_er;
	union conf_pad conf_mii1_tx_en;
	union conf_pad conf_mii1_rx_dv;
	union conf_pad conf_mii1_txd3;
	union conf_pad conf_mii1_txd2;
	union conf_pad conf_mii1_txd1;
	union conf_pad conf_mii1_txd0;
	union conf_pad conf_mii1_tx_clk;
	union conf_pad conf_mii1_rx_clk;
	union conf_pad conf_mii1_rxd3;
	union conf_pad conf_mii1_rxd2;
	union conf_pad onf_mii1_rxd1;
	union conf_pad onf_mii1_rxd0;
	union conf_pad onf_rmii1_ref_clk;
	union conf_pad onf_mdio;
	union conf_pad onf_mdc;
	union conf_pad onf_spi0_sclk;
	union conf_pad onf_spi0_d0;
	union conf_pad onf_spi0_d1;
	union conf_pad onf_spi0_cs0;
	union conf_pad onf_spi0_cs1;
	union conf_pad onf_ecap0_in_pwm0_ou;
	union conf_pad onf_uart0_ctsn;
	union conf_pad onf_uart0_rtsn;
	union conf_pad onf_uart0_rxd;
	union conf_pad onf_uart0_txd;
	union conf_pad onf_uart1_ctsn;
	union conf_pad onf_uart1_rtsn;
	union conf_pad onf_uart1_rxd;
	union conf_pad onf_uart1_txd;
	union conf_pad onf_i2c0_sda;
	union conf_pad onf_i2c0_scl;
	union conf_pad conf_mcasp0_aclkx;
	union conf_pad conf_mcasp0_fsx;
	union conf_pad conf_mcasp0_axr0;
	union conf_pad conf_mcasp0_ahclkr;
	union conf_pad conf_mcasp0_aclkr;
	union conf_pad conf_mcasp0_fsr;
	union conf_pad conf_mcasp0_axr1;
	union conf_pad conf_mcasp0_ahclkx;
	union conf_pad conf_xdma_event_intr0;
	union conf_pad conf_xdma_event_intr1;
};


struct conf_pins {
	unsigned long gpio_1_0;
	unsigned long gpio_1_1;
	unsigned long gpio_1_2;
	unsigned long gpio_1_3;
	unsigned long gpio_1_4;
	unsigned long gpio_1_5;
	unsigned long gpio_1_6;
	unsigned long gpio_1_7;
	unsigned long gpio_0_22;
	unsigned long gpio_0_23;
	unsigned long gpio_0_26;
	unsigned long gpio_0_27;
	unsigned long gpio_1_12;
	unsigned long gpio_1_13;
	unsigned long gpio_1_14;
	unsigned long gpio_1_15;
	unsigned long gpio_1_16;
	unsigned long gpio_1_17;
	unsigned long gpio_1_18;
	unsigned long gpio_1_19;
	unsigned long gpio_1_20;
	unsigned long gpio_1_21;
	unsigned long gpio_1_22;
	unsigned long gpio_1_23;
	unsigned long gpio_1_24;
	unsigned long gpio_1_25;
	unsigned long gpio_1_26;
	unsigned long gpio_1_27;
	unsigned long gpio_0_30;
	unsigned long gpio_0_31;
	unsigned long gpio_1_28;
	unsigned long gpio_1_29;
	unsigned long gpio_1_30;
	unsigned long gpio_1_31;
	unsigned long gpio_2_0;
	unsigned long gpio_2_1;
	unsigned long gpio_2_2;
	unsigned long gpio_2_3;
	unsigned long gpio_2_4;
	unsigned long gpio_2_5;
	unsigned long gpio_2_6;
	unsigned long gpio_2_7;
	unsigned long gpio_2_8;
	unsigned long gpio_2_9;
	unsigned long gpio_2_10;
	unsigned long gpio_2_11;
	unsigned long gpio_2_12;
	unsigned long gpio_2_13;
	unsigned long gpio_2_14;
	unsigned long gpio_2_15;
	unsigned long gpio_2_16;
	unsigned long gpio_2_17;
	unsigned long gpio_0_8;
	unsigned long gpio_0_9;
	unsigned long gpio_0_10;
	unsigned long gpio_0_11;
	unsigned long gpio_2_22;
	unsigned long gpio_2_23;
	unsigned long gpio_2_24;
	unsigned long gpio_2_25;
	unsigned long gpio_2_26;
	unsigned long gpio_2_27;
	unsigned long gpio_2_28;
	unsigned long gpio_2_29;
	unsigned long gpio_2_30;
	unsigned long gpio_2_31;
	unsigned long gpio_3_0;
	unsigned long gpio_3_1;
	unsigned long gpio_3_2;
	unsigned long gpio_3_3;
	unsigned long gpio_3_4;
	unsigned long gpio_0_16;
	unsigned long gpio_0_17;
	unsigned long gpio_0_21;
	unsigned long gpio_0_28;
	unsigned long gpio_3_9;
	unsigned long gpio_3_10;
	unsigned long gpio_2_18;
	unsigned long gpio_2_19;
	unsigned long gpio_2_20;
	unsigned long gpio_2_21;
	unsigned long gpio_0_29;
	unsigned long gpio_0_0;
	unsigned long gpio_0_1;
	unsigned long gpio_0_2;
	unsigned long gpio_0_3;
	unsigned long gpio_0_4;
	unsigned long gpio_0_5;
	unsigned long gpio_0_6;
	unsigned long gpio_0_7;
	unsigned long gpio_1_8;
	unsigned long gpio_1_9;
	unsigned long gpio_1_10;
	unsigned long gpio_1_11;
	unsigned long gpio_0_12;
	unsigned long gpio_0_13;
	unsigned long gpio_0_14;
	unsigned long gpio_0_15;
	unsigned long gpio_3_5;
	unsigned long gpio_3_6;
	unsigned long gpio_3_14;
	unsigned long gpio_3_15;
	unsigned long gpio_3_16;
	unsigned long gpio_3_17;
	unsigned long gpio_3_18;
	unsigned long gpio_3_19;
	unsigned long gpio_3_20;
	unsigned long gpio_3_21;
	unsigned long gpio_0_19;
	unsigned long gpio_0_20;


};


#define PADS_TO_PINS 	&pins->gpio_0_0,\
		&pins->gpio_0_1,                \
		&pins->gpio_0_2,                        \
		&pins->gpio_0_3,                        \
		&pins->gpio_0_4,                        \
		&pins->gpio_0_5,                        \
		&pins->gpio_0_6,                        \
		&pins->gpio_0_7,                        \
		&pins->gpio_0_8,                        \
&pins->gpio_0_9,                        \
&pins->gpio_0_10,                       \
&pins->gpio_0_11,                       \
&pins->gpio_0_12,                       \
&pins->gpio_0_13,                       \
&pins->gpio_0_14,                       \
&pins->gpio_0_15,                       \
&pins->gpio_0_16,                       \
&pins->gpio_0_17,                       \
NULL,                                   \
&pins->gpio_0_19,                       \
&pins->gpio_0_20,                       \
&pins->gpio_0_21,                       \
&pins->gpio_0_22,                       \
&pins->gpio_0_23,                       \
NULL,                                   \
NULL,                                   \
&pins->gpio_0_26,                       \
&pins->gpio_0_27,                       \
&pins->gpio_0_28,                       \
&pins->gpio_0_29,                       \
&pins->gpio_0_30,                       \
&pins->gpio_0_31,                       \
&pins->gpio_1_0,                        \
&pins->gpio_1_1,                        \
&pins->gpio_1_2,                        \
&pins->gpio_1_3,                        \
&pins->gpio_1_4,                        \
&pins->gpio_1_5,                        \
&pins->gpio_1_6,                        \
&pins->gpio_1_7,                        \
&pins->gpio_1_8,                        \
&pins->gpio_1_9,                        \
&pins->gpio_1_10,                       \
&pins->gpio_1_11,                       \
&pins->gpio_1_12,                       \
&pins->gpio_1_13,                       \
&pins->gpio_1_14,                       \
&pins->gpio_1_15,                       \
&pins->gpio_1_16,                       \
&pins->gpio_1_17,                       \
&pins->gpio_1_18,                       \
&pins->gpio_1_19,                       \
&pins->gpio_1_20,                       \
&pins->gpio_1_21,                       \
&pins->gpio_1_22,                       \
&pins->gpio_1_23,                       \
&pins->gpio_1_24,                       \
&pins->gpio_1_25,                       \
&pins->gpio_1_26,                       \
&pins->gpio_1_27,                       \
&pins->gpio_1_28,                       \
&pins->gpio_1_29,                       \
&pins->gpio_1_30,                       \
&pins->gpio_1_31,                       \
&pins->gpio_2_0,                        \
&pins->gpio_2_1,                        \
&pins->gpio_2_2,                        \
&pins->gpio_2_3,                        \
&pins->gpio_2_4,                        \
&pins->gpio_2_5,                        \
&pins->gpio_2_6,                        \
&pins->gpio_2_7,                        \
&pins->gpio_2_8,                        \
&pins->gpio_2_9,                        \
&pins->gpio_2_10,                       \
&pins->gpio_2_11,                       \
&pins->gpio_2_12,                       \
&pins->gpio_2_13,                       \
&pins->gpio_2_14,                       \
&pins->gpio_2_15,                       \
&pins->gpio_2_16,                       \
&pins->gpio_2_17,                       \
&pins->gpio_2_18,                       \
&pins->gpio_2_19,                       \
&pins->gpio_2_20,                       \
&pins->gpio_2_21,                       \
&pins->gpio_2_22,                       \
&pins->gpio_2_23,                       \
&pins->gpio_2_24,                       \
&pins->gpio_2_25,                       \
&pins->gpio_2_26,                       \
&pins->gpio_2_27,                       \
&pins->gpio_2_28,                       \
&pins->gpio_2_29,                       \
&pins->gpio_2_30,                       \
&pins->gpio_2_31,                       \
&pins->gpio_3_0,                        \
&pins->gpio_3_1,                        \
&pins->gpio_3_2,                        \
&pins->gpio_3_3,                        \
&pins->gpio_3_4,                        \
&pins->gpio_3_5,                        \
&pins->gpio_3_6,                        \
NULL,                                   \
NULL,                                   \
&pins->gpio_3_9,                        \
&pins->gpio_3_10,                       \
NULL,									\
NULL,									\
NULL,									\
&pins->gpio_3_14,                       \
&pins->gpio_3_15,                       \
&pins->gpio_3_16,                       \
&pins->gpio_3_17,                       \
&pins->gpio_3_18,                       \
&pins->gpio_3_19,                       \
&pins->gpio_3_20,                       \
&pins->gpio_3_21,                       \
NULL,                 \
NULL,                 \
NULL,                 \
NULL,                 \
NULL,                 \
NULL,                 \
NULL,                 \
NULL,                 \
NULL,                 \
NULL,
#endif
