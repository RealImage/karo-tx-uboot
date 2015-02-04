/*
 * Copyright (C) 2015 Lothar Waßmann <LW@KARO-electronics.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <common.h>
#include <i2c.h>

#include "pmic.h"

static struct {
	uchar addr;
	int (*init)(uchar addr);
} i2c_addrs[] = {
#ifdef CONFIG_LTC3676
	{ 0x3c, ltc3676_pmic_setup, },
#endif
#ifdef CONFIG_RN5T618
	{ 0x32, rn5t618_pmic_setup, },
#endif
#ifdef CONFIG_RN5T567
	{ 0x33, rn5t567_pmic_setup, },
#endif
};

int tx6_pmic_init(void)
{
	int ret;
	int i;

	for (i = 0; i < ARRAY_SIZE(i2c_addrs); i++) {
		ret = i2c_probe(i2c_addrs[i].addr);
		if (ret == 0) {
			i2c_addrs[i].init(i2c_addrs[i].addr);
			break;
		}
	}
	return ret;
}
