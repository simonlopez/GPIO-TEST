#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#include "gpio_lib.h"
#include "color.h"

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
unsigned int iomux = 0;
unsigned int pmu = 0;
#endif


int gpio_init(void) {
	int fd;

	unsigned int addr_start, addr_offset;
	unsigned int PageSize, PageMask;
	void *pc;

	debug("enter: %s%s%s\n", UL_CYAN, __func__, ESC);

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if (fd < 0) {
		perror("failed to open /dev/mem");
		return errno;
	}

	PageSize = sysconf(_SC_PAGESIZE);
	PageMask = (~(PageSize - 1));

	debug("%sPageSize%s: %d\n", BOLD_WHITE, ESC, PageSize);
	debug("%sPageMask%s: 0x%08x\n", BOLD_WHITE, ESC, PageMask);

	unsigned char i;
	for (i = 0; i < 4; i++) {
		addr_start = gpio[i].swgpio_io_base & PageMask;
		addr_offset = gpio[i].swgpio_io_base & ~PageMask;

#if defined(RK3188)
		/* PAGESIZE is 4096. We are reading 8k */
		pc = (void *) mmap(0, PageSize * 2, PROT_READ | PROT_WRITE, MAP_SHARED,
				fd, addr_start);
#elif defined(AM3352)
		/* PAGESIZE is 4096. We are reading 4k */
		pc = (void *) mmap(0, PageSize, PROT_READ | PROT_WRITE, MAP_SHARED,
				fd, addr_start);
#endif
		if (pc == MAP_FAILED) {
			return (-1);
		}

		gpio[i].gpio_pio_base = (unsigned int) pc;
		gpio[i].gpio_pio_base += addr_offset;
		debug("%p mapped at: %p\n", (void *)gpio[i].swgpio_io_base, (void *)gpio[i].gpio_pio_base);
	}

#if defined(RK3188)
	addr_start = GPIO_GRF_BASE & PageMask;
	addr_offset = GPIO_GRF_BASE & ~PageMask;

	pc = (void *) mmap(0, PageSize * 2, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
			addr_start);

	iomux = (unsigned int) pc;
	iomux += addr_offset;
	debug("%p mapped at: %p\n", (void *)GPIO_GRF_BASE, (void *)iomux);

	addr_start = RK30_PMU_BASE & PageMask;
	addr_offset = RK30_PMU_BASE & ~PageMask;

	pc = (void *) mmap(0, PageSize * 2, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
			addr_start);

	pmu = (unsigned int) pc;
	pmu += addr_offset;
	debug("%p mapped at: %p\n", (void *)RK30_PMU_BASE, (void *)pmu);
#endif

	close(fd);

	debug("exit: %s%s%s\n\n", BOLD_YELLOW, __func__, ESC);

	return 0;
}
#if defined(RK3188)
int gpio_make_gpio(unsigned int pin) {
	debug("enter: %s%s%s\n", UL_CYAN, __func__, ESC);
	unsigned int gpio_num = GPIO_NUM(pin);		//23
	unsigned int bank = GPIO_BANK(gpio_num);	// 0
	unsigned int offset = (gpio_num % 32) / 8;			// 2

	if (iomux == 0) {
		return -1;
	}

	//0x20008060 + bank*0x10 + 4*(gpio_num / 8)
	unsigned int *ptr = (unsigned int *) (iomux + GPIO_GRF_IOMUX + bank * 16
				+ 4 * offset);

	unsigned long value = *((unsigned long *) ptr)
			& ~(0x03 << 2 * (gpio_num % 8));
	value |= 3 << (2 * (gpio_num % 8) + 16);

	*((unsigned long*) ptr) = value;

	debug("exit: %s%s%s\n\n", BOLD_YELLOW, __func__, ESC);
	return 0;
}

int gpio_set_pullup(unsigned int pin, unsigned int pull) {
	debug("enter: %s%s%s\n", UL_CYAN, __func__, ESC);
	unsigned int gpio_num = GPIO_NUM(pin);
	unsigned int bank = GPIO_BANK(gpio_num);
	unsigned int offset = gpio_num % 32;

	if (pmu == 0 || iomux == 0) {
		return -1;
	}

	if (pin < RK30_PIN0_PB4) {
		unsigned long *base = (unsigned long *) (pmu + PMU_GPIO0A_PULL
				+ ((offset / 8) * 4));
		offset = (offset % 8) * 2;

		unsigned long value = *base;
		value &= ~(0x03 << offset);
		value |= (0x03 << (16 + offset) | (pull << offset));
		*base = value;
	} else {
		unsigned long *base = (unsigned long *) (iomux + GRF_GPIO0B_PULL - 4
				+ bank * 16 + ((offset / 8) * 4));

		unsigned long value = *base;
		value &= ~(0x03 << offset);
		value |= ((0x03 << (16 + offset)) | (pull << offset));
		*base = value;
	}
	debug("exit: %s%s%s\n\n", BOLD_YELLOW, __func__, ESC);
	return 0;

}
#endif


int gpio_set_cfgpin(unsigned int pin, unsigned int val) {

	unsigned int gpio_num = GPIO_NUM(pin);
#if defined(RK3188)
	unsigned int bank = GPIO_BANK(gpio_num);
	unsigned int offset = GPIO_OFFSET(gpio_num);
#elif defined(AM3352)
	unsigned int bank = GPIO_BANK(pin);
	unsigned long offset = 1 << gpio_num;
#endif

	debug("enter: %s%s%s\n", UL_CYAN, __func__, ESC);

	if (gpio[bank].gpio_pio_base == 0) {
		return -1;
	}

	debug("%sgpio[%d]%s: %p\n", BOLD_WHITE, bank, ESC, (void *)gpio[bank].gpio_pio_base);

	struct gpio_reg *pio = ((struct gpio_reg *) gpio[bank].gpio_pio_base);

	debug("%spio%s: %p\n", BOLD_WHITE, ESC, (void *)pio);

	debug("%s%p%s -> 0x%08x\n", BOLD_WHITE, (void *)gpio[bank].gpio_pio_base, ESC, 0);


	if (val == GPIO_INPUT) {
		debug("Setiing input\n");
#if defined(RK3188)
		pio->gpio_swport_ddr &= ~offset;
#elif defined(AM3352)
		pio->gpio_oe |= offset;
#endif
	} else {
		debug("Setting output\n");
#if defined(RK3188)
		pio->gpio_swport_ddr |= offset;
#elif defined(AM3352)
//		pio->gpio_oe &= ~offset;
//		debug("gpio_oe: %p\n", pio->gpio_oe);
#endif
	}

	debug("exit: %s%s%s\n\n", BOLD_YELLOW, __func__, ESC);

	return 0;
}

int gpio_get_cfgpin(unsigned int pin) {

	debug("enter: %s%s%s\n", UL_CYAN, __func__, ESC);
	unsigned int gpio_num = GPIO_NUM(pin);
#if defined(RK3188)
	unsigned int bank = GPIO_BANK(gpio_num);
	unsigned int offset = GPIO_OFFSET(gpio_num);
#elif defined(AM3352)
	unsigned int bank = GPIO_BANK(pin);
	unsigned int offset = 1 << gpio_num;
#endif

	if (gpio[bank].gpio_pio_base == 0) {
		return -1;
	}

	struct gpio_reg *pio = ((struct gpio_reg *) gpio[bank].gpio_pio_base);
	debug("exit: %s%s%s\n\n", BOLD_YELLOW, __func__, ESC);
#if defined(RK3188)
	return !!(pio->gpio_swport_ddr & offset);
#elif defined(AM3352)
	return !!(pio->gpio_oe & offset);
#endif
}
int gpio_output(unsigned int pin, unsigned int val) {
	debug("enter: %s%s%s\n", UL_CYAN, __func__, ESC);


	unsigned int gpio_num = GPIO_NUM(pin);
#if defined(RK3188)
	unsigned int bank = GPIO_BANK(gpio_num);
	unsigned int offset = GPIO_OFFSET(gpio_num);
#elif defined(AM3352)
	unsigned int bank = GPIO_BANK(pin);
	unsigned int offset = 1 << gpio_num;
#endif
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

	debug("exit: %s%s%s\n\n", BOLD_YELLOW, __func__, ESC);
	return 0;
}

int gpio_input(unsigned int pin) {

	debug("enter: %s%s%s\n", UL_CYAN, __func__, ESC);
	unsigned int gpio_num = GPIO_NUM(pin);
#if defined(RK3188)
	unsigned int bank = GPIO_BANK(gpio_num);
	unsigned int offset = GPIO_OFFSET(gpio_num);
#elif defined(AM3352)
	unsigned int bank = GPIO_BANK(pin);
	unsigned int offset = 1 << gpio_num;
#endif

	if (gpio[bank].gpio_pio_base == 0) {
		return -1;
	}

	struct gpio_reg *pio = ((struct gpio_reg *) gpio[bank].gpio_pio_base);

	debug("exit: %s%s%s\n\n", BOLD_YELLOW, __func__, ESC);
#if defined(RK3188)
	return !!(pio->gpio_ext_port & offset);
#elif defined(AM3352)
	return !!(pio->gpio_datain & offset);
#endif
}
