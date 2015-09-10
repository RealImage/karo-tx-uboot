/*
 * K2HK: Clock management APIs
 *
 * (C) Copyright 2012-2014
 *     Texas Instruments Incorporated, <www.ti.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __ASM_ARCH_CLOCK_K2HK_H
#define __ASM_ARCH_CLOCK_K2HK_H

#define CLK_LIST(CLK)\
	CLK(0, core_pll_clk)\
	CLK(1, pass_pll_clk)\
	CLK(2, tetris_pll_clk)\
	CLK(3, ddr3a_pll_clk)\
	CLK(4, ddr3b_pll_clk)\
	CLK(5, sys_clk0_clk)\
	CLK(6, sys_clk0_1_clk)\
	CLK(7, sys_clk0_2_clk)\
	CLK(8, sys_clk0_3_clk)\
	CLK(9, sys_clk0_4_clk)\
	CLK(10, sys_clk0_6_clk)\
	CLK(11, sys_clk0_8_clk)\
	CLK(12, sys_clk0_12_clk)\
	CLK(13, sys_clk0_24_clk)\
	CLK(14, sys_clk1_clk)\
	CLK(15, sys_clk1_3_clk)\
	CLK(16, sys_clk1_4_clk)\
	CLK(17, sys_clk1_6_clk)\
	CLK(18, sys_clk1_12_clk)\
	CLK(19, sys_clk2_clk)\
	CLK(20, sys_clk3_clk)

#define PLLSET_CMD_LIST		"<pa|arm|ddr3a|ddr3b>"

#define KS2_CLK1_6 sys_clk0_6_clk

#define CORE_PLL_799    {CORE_PLL,	13,	1,	2}
#define CORE_PLL_983    {CORE_PLL,	16,	1,	2}
#define CORE_PLL_999	{CORE_PLL,	122,	15,	1}
#define CORE_PLL_1167   {CORE_PLL,	19,	1,	2}
#define CORE_PLL_1228   {CORE_PLL,	20,	1,	2}
#define CORE_PLL_1200	{CORE_PLL,	625,	32,	2}
#define PASS_PLL_1228   {PASS_PLL,	20,	1,	2}
#define PASS_PLL_983    {PASS_PLL,	16,	1,	2}
#define PASS_PLL_1050   {PASS_PLL,	205,    12,	2}
#define TETRIS_PLL_500  {TETRIS_PLL,	8,	1,	2}
#define TETRIS_PLL_750  {TETRIS_PLL,	12,	1,	2}
#define TETRIS_PLL_800	{TETRIS_PLL,	32,	5,	1}
#define TETRIS_PLL_687  {TETRIS_PLL,	11,	1,	2}
#define TETRIS_PLL_625  {TETRIS_PLL,	10,	1,	2}
#define TETRIS_PLL_812  {TETRIS_PLL,	13,	1,	2}
#define TETRIS_PLL_875  {TETRIS_PLL,	14,	1,	2}
#define TETRIS_PLL_1000	{TETRIS_PLL,	40,	5,	1}
#define TETRIS_PLL_1188 {TETRIS_PLL,	19,	2,	1}
#define TETRIS_PLL_1200 {TETRIS_PLL,	48,	5,	1}
#define TETRIS_PLL_1350	{TETRIS_PLL,	54,	5,	1}
#define TETRIS_PLL_1375 {TETRIS_PLL,	22,	2,	1}
#define TETRIS_PLL_1400 {TETRIS_PLL,	56,	5,	1}
#define DDR3_PLL_200(x)	{DDR3##x##_PLL,	4,	1,	2}
#define DDR3_PLL_400(x)	{DDR3##x##_PLL,	16,	1,	4}
#define DDR3_PLL_800(x)	{DDR3##x##_PLL,	16,	1,	2}
#define DDR3_PLL_333(x)	{DDR3##x##_PLL,	20,	1,	6}

/* k2h DEV supports 800, 1000, 1200 MHz */
#define DEV_SUPPORTED_SPEEDS	0x383
/* k2h ARM supportd 800, 1000, 1200, 1350, 1400 MHz */
#define ARM_SUPPORTED_SPEEDS	0x3EF

#endif
