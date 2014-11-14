/*
 * test.c
 * 
 * Copyright 2013 Stefan Mavrodiev <support@olimex.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#define _BSD_SOURCE

#include <stdio.h>
#include <unistd.h>

#include "test.h"
#include "gpio_lib.h"
#include "color.h"

#include "board_AM3352-SOM.h"

int test(char *name, gpio_t connector[], gpio_t pullpin, int n) {

	int fail = 0;
	int i;
	int j;
	int delay = 10000;

	printf("\n%sTest %s%s\n", WHITE, name, ESC);
	printf("--------------------\n");

	if (gpio_init())
		return 0;

	gpio_set_cfgpin(PIN(3, 20), GPIO_OUTPUT);
	gpio_set_cfgpin(PIN(3, 21), GPIO_OUTPUT);

	while(1){
		gpio_output(PIN(3, 20), 1);
		gpio_output(PIN(3, 21), 0);
		sleep(1);
		gpio_output(PIN(3, 20), 0);
		gpio_output(PIN(3, 21), 1);
		sleep(1);
	}

#if defined(RK3188)
	/* If using RK3188 make all needed pins as gpio */
	gpio_make_gpio(pullpin.pin);

	for (i = 0; i < n; i++) {
		gpio_make_gpio(connector[i].pin);
		usleep(delay);
	}
#endif
	/* 1. Pull-Pin output */
	gpio_set_cfgpin(pullpin.pin, GPIO_OUTPUT);

	/* 2. All inputs */
	for (i = 0; i < n; i++) {
		gpio_set_cfgpin(connector[i].pin, GPIO_INPUT);
	}

#if defined(RK3188)
	for (i = 0; i < n; i++) {
		gpio_set_pullup(connector[i].pin, GPIO_PULL_DIS);
		usleep(delay);
	}
#endif


	/* 3. Pull-Pin High */
	printf("All HIGH...");
	gpio_output(pullpin.pin, 1);
	usleep(delay);


	/* 4. Read inputs */
	for (i = 0; i < n; i++) {
		if (!gpio_input(connector[i].pin)) {
			//GND short
			if (!fail) {
				printf("%sFail\n%s", RED, ESC);
				fail = 1;
			}
			printf("\t%s%s(%s:%d)%s -> GND SHORT\n", WHITE, connector[i].name,
					connector[i].ext, connector[i].con, ESC);
		}
	}
	if (!fail)
		printf("%sDone%s\n", GREEN, ESC);
	else
		goto fail;
	fail = 0;

	/* 5. Pull-Pin Low */
	printf("All LOW...");
	gpio_output(pullpin.pin, 0);
	usleep(delay);

	/* 6. Read inputs */
	for (i = 0; i < n; i++) {
		if (gpio_input(connector[i].pin)) {
			//VCC short
			if (!fail) {
				printf("%sFail\n%s", RED, ESC);
				fail = 1;
			}
			printf("\t%s%s(%s:%d)%s -> VCC SHORT\n", WHITE, connector[i].name,
					connector[i].ext, connector[i].con, ESC);
		}
	}

	if (!fail)
		printf("%sDone%s\n", GREEN, ESC);
	else
		goto fail;
	fail = 0;

	/* 7. Running zero */
	printf("Running zero...");
	gpio_output(pullpin.pin, 1);
	usleep(delay);

	for (i = 0; i < n; i++) {
		gpio_set_cfgpin(connector[i].pin, GPIO_OUTPUT);
		gpio_output(connector[i].pin, 0);
		usleep(delay);

		for (j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (!gpio_input(connector[j].pin)) {
				if (!fail) {
					printf("%sFail\n%s", RED, ESC);
					fail = 1;
				}
				printf("\t%s%s(%s:%d)%s -> %s%s(%s:%d)%s  SHORT\n",
				WHITE, connector[i].name, connector[i].ext, connector[i].con,
				ESC,
				WHITE, connector[j].name, connector[i].ext, connector[j].con,
						ESC);
			}
		}
		gpio_set_cfgpin(connector[i].pin, GPIO_INPUT);
	}
	if (!fail)
		printf("%sDone%s\n", GREEN, ESC);
	else
		goto fail;
	fail = 0;

	/* 8. Running one */
	printf("Running one...");
	gpio_output(pullpin.pin, 0);
	usleep(delay);

	for (i = 0; i < n; i++) {
		gpio_set_cfgpin(connector[i].pin, GPIO_OUTPUT);
		gpio_output(connector[i].pin, 1);
		usleep(delay);

		for (j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (gpio_input(connector[j].pin)) {
				if (!fail) {
					printf("%sFail\n%s", RED, ESC);
					fail = 1;

				}
				printf("\t%s%s(%s:%d)%s -> %s%s(%s:%d)%s  SHORT\n",
				WHITE, connector[i].name, connector[i].ext, connector[i].con,
				ESC,
				WHITE, connector[j].name, connector[i].ext, connector[j].con,
						ESC);


			}
		}
		gpio_set_cfgpin(connector[i].pin, GPIO_INPUT);
	}
	if (!fail)
		printf("%sDone%s\n", GREEN, ESC);
	else
		goto fail;
	fail = 0;

fail:
	return 0;

}

