#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#include "gpio_lib.h"

#if defined(RK3188)
#include "RK3188.h"
#elif defined(AM3352)
#include "AM3352.h"
#endif

#if defined(RK3188) || defined(AM3352)
gpio_base_t gpio[] = {
		{ 0, GPIO0_IO_BASE },
		{ 0, GPIO1_IO_BASE },
		{ 0, GPIO2_IO_BASE },
		{ 0, GPIO3_IO_BASE },
};
#endif

#if defined(RK3188)
uint32_t iomux = 0;
uint32_t pmu = 0;
#endif


int16_t gpio_init(void) {
	int16_t fd;

	uint32_t addr_start, addr_offset;
	uint16_t PageSize, PageMask;
	void *pc;

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if (fd < 0) {
		perror("failed to open /dev/mem");
		return errno;
	}

	PageSize = sysconf(_SC_PAGESIZE);
	PageMask = (~(PageSize - 1));

	uint8_t i;
	for (i = 0; i < 4; i++) {
		addr_start = gpio[i].swgpio_io_base & PageMask;
		addr_offset = gpio[i].swgpio_io_base & ~PageMask;

		/* PAGESIZE is 4096. We are reading 8k */
		pc = (void *) mmap(0, PageSize * 2, PROT_READ | PROT_WRITE, MAP_SHARED,
				fd, addr_start);
		if (pc == MAP_FAILED) {
			return (-1);
		}

		gpio[i].gpio_pio_base = (uint32_t) pc;
		gpio[i].gpio_pio_base += addr_offset;
	}

#if defined(RK3188)
	addr_start = GPIO_GRF_BASE & PageMask;
	addr_offset = GPIO_GRF_BASE & ~PageMask;

	pc = (void *) mmap(0, PageSize * 2, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
			addr_start);

	iomux = (uint16_t) pc;
	iomux += addr_offset;

	addr_start = RK30_PMU_BASE & PageMask;
	addr_offset = RK30_PMU_BASE & ~PageMask;

	pc = (void *) mmap(0, PageSize * 2, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
			addr_start);

	pmu = (uint16_t) pc;
	pmu += addr_offset;
#endif

	close(fd);

	return 0;
}
#if defined(RK3188)
int16_t gpio_make_gpio(uint16_t pin) {
	uint16_t gpio_num = GPIO_NUM(pin);		//23
	uint16_t bank = GPIO_BANK(gpio_num);	// 0
	uint16_t offset = (gpio_num % 32) / 8;			// 2

	if (iomux == 0) {
		return -1;
	}

	//0x20008060 + bank*0x10 + 4*(gpio_num / 8)
	uint16_t *ptr = (uint16_t *) (iomux + GPIO_GRF_IOMUX + bank * 16
			+ 4 * offset);

	uint32_t value = *((uint32_t *) ptr)
			& ~(0x03 << 2 * (gpio_num % 8));
	value |= 3 << (2 * (gpio_num % 8) + 16);

	*((uint32_t*) ptr) = value;

	return 0;
}

int16_t gpio_set_pullup(uint16_t pin, uint16_t pull) {
	uint16_t gpio_num = GPIO_NUM(pin);
	uint16_t bank = GPIO_BANK(gpio_num);
	uint16_t offset = gpio_num % 32;

#if 0
	printf("\n-----------------\n");
	printf("GPIO_NUM: %d\n", gpio_num);
	printf("BANK: %d\n", bank);
	printf("OFFSET: %d\n", offset);
#endif

	if (pmu == 0 || iomux == 0) {
		return -1;
	}

	if (pin < RK30_PIN0_PB4) {
		uint32_t *base = (uint32_t *) (pmu + PMU_GPIO0A_PULL
				+ ((offset / 8) * 4));
		offset = (offset % 8) * 2;

		uint32_t value = *base;
		value &= ~(0x03 << offset);
		value |= (0x03 << (16 + offset) | (pull << offset));
		*base = value;
	} else {
		uint32_t *base = (uint32_t *) (iomux + GRF_GPIO0B_PULL - 4
				+ bank * 16 + ((offset / 8) * 4));
#if 0
		printf("BASE: %p -> %x\n", base, *base);
#endif
		offset = (7 - (offset % 8)) * 2;
#if 0
		printf("OFFSET: %d\n", offset);
#endif
		uint32_t value = *base;
		value &= ~(0x03 << offset);
		value |= ((0x03 << (16 + offset)) | (pull << offset));
		*base = value;
	}

	return 0;

}
#endif


int16_t gpio_set_cfgpin(uint16_t pin, uint16_t val) {

	uint16_t gpio_num = GPIO_NUM(pin);
	uint16_t bank = GPIO_BANK(gpio_num);
	uint16_t offset = GPIO_OFFSET(gpio_num);

	if (gpio[bank].gpio_pio_base == 0) {
		return -1;
	}

	struct gpio_reg *pio = ((struct gpio_reg *) gpio[bank].gpio_pio_base);

	if (val == GPIO_INPUT) {
#if defined(RK3188)
		pio->gpio_swport_ddr &= ~offset;
#elif defined(AM3352)
		pio->gpio_oe |= offset;
#endif
	} else {
#if defined(RK3188)
		pio->gpio_swport_ddr |= offset;
#elif defined(AM3352)
		pio->gpio_oe &= ~offset;
#endif
	}
	return 0;
}

int16_t gpio_get_cfgpin(uint16_t pin) {

	uint16_t gpio_num = GPIO_NUM(pin);
	uint16_t bank = GPIO_BANK(gpio_num);
	uint16_t offset = GPIO_OFFSET(gpio_num);

	if (gpio[bank].gpio_pio_base == 0) {
		return -1;
	}

	struct gpio_reg *pio = ((struct gpio_reg *) gpio[bank].gpio_pio_base);
#if defined(RK3188)
	return !!(pio->gpio_swport_ddr & offset);
#elif defined(AM3352)
	return !!(pio->gpio_oe & offset);
#endif
}
int16_t gpio_output(uint16_t pin, uint16_t val) {

	uint16_t gpio_num = GPIO_NUM(pin);
	uint16_t bank = GPIO_BANK(gpio_num);
	uint16_t offset = GPIO_OFFSET(gpio_num);

	if (gpio[bank].gpio_pio_base == 0) {
		return -1;
	}

	struct gpio_reg *pio = ((struct gpio_reg *) gpio[bank].gpio_pio_base);

	if (!val) {
#if defined(RK3188)
		pio->gpio_swport_dr &= ~offset;
#elif defined(AM3352)
		pio->gpio_cleardataout = offset;
#endif
	} else {
#if defined(RK3188)
		pio->gpio_swport_dr |= offset;
#elif defined(AM3352)
		pio->gpio_setdataout = offset;
#endif
	}

	return 0;
}

int16_t gpio_input(uint16_t pin) {

	uint16_t gpio_num = GPIO_NUM(pin);
	uint16_t bank = GPIO_BANK(gpio_num);
	uint16_t offset = GPIO_OFFSET(gpio_num);

	if (gpio[bank].gpio_pio_base == 0) {
		return -1;
	}

	struct gpio_reg *pio = ((struct gpio_reg *) gpio[bank].gpio_pio_base);

#if defined(RK3188)
	return !!(pio->gpio_ext_port & offset);
#elif defined(AM3352)
	return !!(pio->gpio_datain & offset);
#endif
}
