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
#include <string.h>
#include <stdlib.h>

#include "test.h"
#include "gpio_lib.h"
#include "color.h"

static const char padder[] = "........................................";

#define _print(...)		printf("%s%s%s",BOLD_WHITE, __VA_ARGS__, ESC); \
						printf("%s", padder+strlen(__VA_ARGS__));
#define print_fail()	printf("[%sFail%s]\n", RED, ESC)
#define print_success() printf("[%sDone%s]\n", GREEN, ESC)

int test(char *name, gpio_t connector[], gpio_t pullpin, int n) {


	int fail = 0;
	int i;
	int j;
	int q,z;
	unsigned delay = 10000;

	printf("\n%sTesting%s %s%s%s\n", BOLD_WHITE, ESC, UL_YELLOW, name, ESC);
	printf("--------------------\n");

	if (gpio_init())
		return 0;

#if defined(RK3188)
	/* If using RK3188 make all needed pins as gpio */
	gpio_make_gpio(pullpin.pin);

	for (i = 0; i < n; i++) {
		gpio_make_gpio(connector[i].pin);
//		pthread_create(&thread[i], &attr, gpio_make_gpio, (void *)connector[i].pin);
	}
	usleep(delay);
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
	_print("Pull pin high");
	gpio_output(pullpin.pin, 1);
	usleep(delay);

	/* 4. Read inputs */
	z = 0;
	for (i = 0; i < n; i++) {
		if (!gpio_input(connector[i].pin)) {

			for(q = 0; q < 5; q++){
				if (!gpio_input(connector[i].pin))
					z++;
				usleep(delay);
			}
			if(z == 5){
				//GND short
				if (!fail) {
					print_fail();
					fail = 1;
				}
				printf("\t%s%s%s(%s%s:%d%s -> %s%s:%d%s) -> GND SHORT\n", BOLD_CYAN,
						connector[i].name, ESC, BOLD_BLUE, connector[i].ext, connector[i].con, ESC,
						BOLD_PURPLE, connector[i].ext_som, connector[i].con_som, ESC);
				getchar();
			}
		}
	}
	if (!fail) {
		print_success();
	} else {
		goto fail;
	}
	fail =0;
	z = 0;

	/* 5. Pull-Pin Low */
	_print("Pull pin low");
	gpio_output(pullpin.pin, 0);
	usleep(delay);

	/* 6. Read inputs */
	for (i = 0; i < n; i++) {
		if (gpio_input(connector[i].pin)) {
			for(q = 0; q < 5; q++){
				if (gpio_input(connector[i].pin))
					z++;
				usleep(delay);
			}
			if(z == 5){
				//VCC short
				if (!fail) {
					print_fail();
					fail = 1;
				}
				printf("\t%s%s(%s:%d)%s -> VCC SHORT\n", BOLD_CYAN,
						connector[i].name, connector[i].ext, connector[i].con, ESC);
				getchar();
			}
		}
	}

	if (!fail)
		print_success();
	else
		goto fail;
	fail = 0;
	z = 0;

	/* 7. Running zero */
	_print("Running zero");
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
				for(q = 0; q < 5; q++){
					if (!gpio_input(connector[i].pin))
						z++;
					usleep(delay);
				}

				if(z == 5){

					if (!fail) {
						print_fail();
						fail = 1;
					}
					printf("\t%s%s(%s:%d)%s -> %s%s(%s:%d)%s  SHORT\n",
					BOLD_CYAN, connector[i].name, connector[i].ext,
							connector[i].con,
							ESC,
							BOLD_CYAN, connector[j].name, connector[i].ext,
							connector[j].con,
							ESC);
					getchar();
				}
			}
		}
		gpio_set_cfgpin(connector[i].pin, GPIO_INPUT);
	}
	if (!fail)
		print_success();
	else
		goto fail;
	fail = 0;

	/* 8. Running one */
	_print("Running one");
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
				for(q = 0; q < 5; q++){
					if (gpio_input(connector[i].pin))
						z++;
					usleep(delay);
				}

				if(z == 5){

					if (!fail) {
						print_fail();
						fail = 1;
					}
					printf("\t%s%s(%s:%d)%s -> %s%s(%s:%d)%s  SHORT\n",
					BOLD_CYAN, connector[i].name, connector[i].ext,
							connector[i].con,
							ESC,
							BOLD_CYAN, connector[j].name, connector[i].ext,
							connector[j].con,
							ESC);
					getchar();
				}
			}
		}
		gpio_set_cfgpin(connector[i].pin, GPIO_INPUT);
	}
	if (!fail)
		print_success();
	else
		goto fail;
	fail = 0;

	fail: return 0;;

}

