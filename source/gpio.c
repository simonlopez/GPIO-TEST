/*
 * gpio.c
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

#include <stdio.h>
#include <unistd.h>
#include "color.h"
#include "gpio_lib.h"

#if defined (RK3188_SOM)
#include "board_RK3188-SOM.h"
#elif defined (AM3352_SOM)
#include "board_AM3352-SOM.h"
#endif

#include "test.h"

int main(int argc, char **argv)
{
#if defined (RK3188_SOM)
	printf("RK3188-SOM TEST\n");
#endif

#if defined (AM3352_SOM)
	printf("AM3352-SOM TEST\n");
#endif

#if defined (AM3352_SOM)
	if(gpio_init() < 0){
		printf("Error gpio init\n");
	}

	gpio_set_cfgpin(116, GPIO_OUTPUT);


#elif defined (RK3188_SOM)
	test("UEXT-1", uext1, uext1_pp, sizeof(uext1)/sizeof(gpio_t));


#endif


	return 0;
}

