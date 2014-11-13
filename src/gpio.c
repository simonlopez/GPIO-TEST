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
#include "../inc/color.h"
#include "../inc/gpio_lib.h"
#include "../inc/EXT.h"
#include "../inc/test.h"

int main(int argc, char **argv)
{	
    printf("\f");
    printf("\n");
    printf("RK3188-SOM GPIO TEST\n\n");

    test("UEXT-1", uext1, uext1_pp, sizeof(uext1)/sizeof(gpio_t));
    test("UEXT-2", uext2, uext2_pp, sizeof(uext2)/sizeof(gpio_t));
    test("EXT-1", ext1, ext1_pp, sizeof(ext1)/sizeof(gpio_t));
    test("EXT-2", ext2, ext2_pp, sizeof(ext2)/sizeof(gpio_t));


	return 0;
}

