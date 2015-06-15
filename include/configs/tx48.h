/*
 * tx48.h
 *
 * Copyright (C) 2012-2014 Lothar Waßmann <LW@KARO-electronics.de>
 *
 * based on: am335x_evm
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 * SPDX-License-Identifier:      GPL-2.0
 *
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_AM33XX			/* must be set before including omap.h */

#include <linux/sizes.h>
#include <asm/arch/omap.h>

/*
 * Ka-Ro TX48 board - SoC configuration
 */
#define CONFIG_OMAP
#define CONFIG_AM33XX_GPIO
#define CONFIG_SYS_HZ			1000	/* Ticks per second */

#ifndef CONFIG_SPL_BUILD
#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_SHOW_ACTIVITY
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO
#define CONFIG_BOARD_LATE_INIT
#define CONFIG_SYS_GENERIC_BOARD

/* LCD Logo and Splash screen support */
#ifdef CONFIG_LCD
#define CONFIG_VIDEO_DA8XX
#define CONFIG_SPLASH_SCREEN
#define CONFIG_SPLASH_SCREEN_ALIGN
#define CONFIG_AM335X_LCD
#define DAVINCI_LCD_CNTL_BASE		0x4830e000
#define CONFIG_LCD_LOGO
#define LCD_BPP				LCD_COLOR32
#define CONFIG_CMD_BMP
#define CONFIG_VIDEO_BMP_RLE8
#endif /* CONFIG_LCD */
#endif /* CONFIG_SPL_BUILD */

/* Clock Defines */
#define V_OSCK				24000000  /* Clock output from T2 */
#define V_SCLK				V_OSCK

/*
 * Memory configuration options
 */
#define CONFIG_SYS_SDRAM_DDR3
#define CONFIG_NR_DRAM_BANKS		0x1		/* '1' would be converted to 'y' by define2mk.sed */
#define PHYS_SDRAM_1			0x80000000	/* SDRAM Bank #1 */
#define CONFIG_MAX_RAM_BANK_SIZE	SZ_1G

#define CONFIG_STACKSIZE		SZ_64K
#define CONFIG_SYS_MALLOC_LEN		SZ_4M

#define CONFIG_SYS_MEMTEST_START	(PHYS_SDRAM_1 + SZ_64M)
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_MEMTEST_START + SZ_8M)

#define CONFIG_SYS_CACHELINE_SIZE	64

/*
 * U-Boot general configurations
 */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_PROMPT		"TX48 U-Boot > "
#define CONFIG_SYS_CBSIZE		2048	/* Console I/O buffer size */
#define CONFIG_SYS_PBSIZE \
	(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
						/* Print buffer size */
#define CONFIG_SYS_MAXARGS		256	/* Max number of command args */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
						/* Boot argument buffer size */
#define CONFIG_VERSION_VARIABLE			/* U-BOOT version */
#define CONFIG_AUTO_COMPLETE			/* Command auto complete */
#define CONFIG_CMDLINE_EDITING			/* Command history etc */

#define CONFIG_SYS_64BIT_VSPRINTF

/*
 * Flattened Device Tree (FDT) support
*/

/*
 * Boot Linux
 */
#define xstr(s)				str(s)
#define str(s)				#s
#define __pfx(x, s)			(x##s)
#define _pfx(x, s)			__pfx(x, s)

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_BOOTDELAY		3
#define CONFIG_ZERO_BOOTDELAY_CHECK
#define CONFIG_SYS_AUTOLOAD		"no"
#define CONFIG_BOOTFILE			"uImage"
#define CONFIG_BOOTARGS			"init=/linuxrc console=ttyO0,115200 ro debug panic=1"
#define CONFIG_BOOTCOMMAND		"run bootcmd_${boot_mode} bootm_cmd"
#define CONFIG_LOADADDR			83000000
#define CONFIG_FDTADDR			81000000
#define CONFIG_SYS_LOAD_ADDR		_pfx(0x, CONFIG_LOADADDR)
#define CONFIG_SYS_FDT_ADDR		_pfx(0x, CONFIG_FDTADDR)
#define CONFIG_U_BOOT_IMG_SIZE		SZ_1M

/*
 * Extra Environment Settings
 */
#define CONFIG_SYS_CPU_CLK_STR		xstr(CONFIG_SYS_MPU_CLK)

#define CONFIG_EXTRA_ENV_SETTINGS					\
	"autostart=no\0"						\
	"baseboard=stk5-v3\0"						\
	"bootargs_jffs2=run default_bootargs;set bootargs ${bootargs}"	\
	" root=/dev/mtdblock4 rootfstype=jffs2\0"			\
	"bootargs_mmc=run default_bootargs;set bootargs ${bootargs}"	\
	" root=/dev/mmcblk0p2 rootwait\0"				\
	"bootargs_nfs=run default_bootargs;set bootargs ${bootargs}"	\
	" root=/dev/nfs nfsroot=${nfs_server}:${nfsroot},nolock"	\
	" ip=dhcp\0"							\
	"bootargs_ubifs=run default_bootargs;set bootargs ${bootargs}"	\
	" ubi.mtd=rootfs root=ubi0:rootfs rootfstype=ubifs\0"		\
	"bootcmd_jffs2=set autostart no;run bootargs_jffs2"		\
	";nboot linux\0"						\
	"bootcmd_mmc=set autostart no;run bootargs_mmc"			\
	";fatload mmc 0 ${loadaddr} uImage\0"				\
	"bootcmd_nand=set autostart no;run bootargs_ubifs"		\
	";nboot linux\0"						\
	"bootcmd_net=set autoload y;set autostart n;run bootargs_nfs"	\
	";dhcp\0"							\
	"bootm_cmd=bootm ${loadaddr} - ${fdtaddr}\0"			\
	"boot_mode=nand\0"						\
	"cpu_clk=" CONFIG_SYS_CPU_CLK_STR "\0"				\
	"default_bootargs=set bootargs " CONFIG_BOOTARGS		\
	" ${append_bootargs}\0"						\
	"fdtaddr=" xstr(CONFIG_FDTADDR) "\0"				\
	"fdtsave=fdt resize;nand erase.part dtb"			\
	";nand write ${fdtaddr} dtb ${fdtsize}\0"			\
	"mtdids=" MTDIDS_DEFAULT "\0"					\
	"mtdparts=" MTDPARTS_DEFAULT "\0"				\
	"nfsroot=/tftpboot/rootfs\0"					\
	"otg_mode=device\0"						\
	"touchpanel=tsc2007\0"						\
	"video_mode=VGA\0"

#define MTD_NAME			"omap2-nand.0"
#define MTDIDS_DEFAULT			"nand0=" MTD_NAME

/*
 * U-Boot Commands
 */
#include <config_cmd_default.h>

/*
 * Serial Driver
 */
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_MEM32
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		48000000
#define CONFIG_SYS_NS16550_COM1		0x44e09000	/* UART0 */
#define CONFIG_SYS_NS16550_COM2		0x48022000	/* UART1 */
#define CONFIG_SYS_NS16550_COM6		0x481aa000	/* UART5 */

#define CONFIG_SYS_NS16550_COM3		0x481aa000	/* UART2 */
#define CONFIG_SYS_NS16550_COM4		0x481aa000	/* UART3 */
#define CONFIG_SYS_NS16550_COM5		0x481aa000	/* UART4 */
#define CONFIG_CONS_INDEX		1		/* one based! */
#define CONFIG_BAUDRATE			115200		/* Default baud rate */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200, }
#define CONFIG_SYS_CONSOLE_INFO_QUIET

/*
 * Ethernet Driver
 */
#ifdef CONFIG_CMD_NET
#define CONFIG_DRIVER_TI_CPSW
#define CONFIG_PHY_GIGE
#define CONFIG_CMD_MII
/* Add for working with "strict" DHCP server */
#define CONFIG_BOOTP_SUBNETMASK
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_DNS
#define CONFIG_BOOTP_DNS2
#endif

/*
 * NAND flash driver
 */
#ifdef CONFIG_NAND
#define CONFIG_NAND_OMAP_GPMC
#ifndef CONFIG_SPL_BUILD
#define CONFIG_SYS_GPMC_PREFETCH_ENABLE
#endif
#define GPMC_NAND_ECC_LP_x8_LAYOUT
#define GPMC_NAND_HW_ECC_LAYOUT_KERNEL	GPMC_NAND_HW_ECC_LAYOUT
#define CONFIG_SYS_NAND_U_BOOT_OFFS	0x20000
#define CONFIG_SYS_NAND_PAGE_SIZE	2048
#define CONFIG_SYS_NAND_OOBSIZE		64
#define CONFIG_SYS_NAND_ECCSIZE		512
#define CONFIG_SYS_NAND_ECCBYTES	14
#define CONFIG_SYS_NAND_MAX_CHIPS	0x1
#define CONFIG_SYS_NAND_MAXBAD		20 /* Max. number of bad blocks guaranteed by manufacturer */
#define CONFIG_SYS_MAX_NAND_DEVICE	0x1
#define CONFIG_SYS_NAND_5_ADDR_CYCLE
#ifdef CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(CONFIG_U_BOOT_IMG_SIZE + CONFIG_SYS_NAND_U_BOOT_OFFS)
#define CONFIG_ENV_SIZE			SZ_128K
#define CONFIG_ENV_RANGE		0x60000
#endif /* CONFIG_ENV_IS_IN_NAND */
#define CONFIG_SYS_NAND_BASE		0x00100000
#define CONFIG_SYS_NAND_SIZE		SZ_128M
#define NAND_BASE			CONFIG_SYS_NAND_BASE
#endif /* CONFIG_CMD_NAND */

/*
 * MMC Driver
 */
#ifdef CONFIG_CMD_MMC
#define CONFIG_OMAP_HSMMC
#define CONFIG_OMAP_MMC_DEV_1

#define CONFIG_CMD_FAT
#define CONFIG_FAT_WRITE
#define CONFIG_CMD_EXT2

/*
 * Environments on MMC
 */
#ifdef CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV		0
#define CONFIG_ENV_OVERWRITE
/* Associated with the MMC layout defined in mmcops.c */
#define CONFIG_ENV_OFFSET		SZ_1K
#define CONFIG_ENV_SIZE			(SZ_128K - CONFIG_ENV_OFFSET)
#define CONFIG_DYNAMIC_MMC_DEVNO
#endif /* CONFIG_ENV_IS_IN_MMC */
#endif /* CONFIG_CMD_MMC */

#ifdef CONFIG_ENV_IS_NOWHERE
#define CONFIG_ENV_SIZE			SZ_4K
#endif

#ifdef CONFIG_ENV_OFFSET_REDUND
#define MTDPARTS_DEFAULT		"mtdparts=" MTD_NAME ":"	\
	"128k(u-boot-spl),"						\
	"1m(u-boot),"							\
	xstr(CONFIG_ENV_RANGE)						\
	"(env),"							\
	xstr(CONFIG_ENV_RANGE)						\
	"(env2),6m(linux),32m(rootfs),89216k(userfs),512k@0x7f00000(dtb),512k@0x7f80000(bbt)ro"
#else
#define MTDPARTS_DEFAULT		"mtdparts=" MTD_NAME ":"	\
	"128k(u-boot-spl),"						\
	"1m(u-boot),"							\
	xstr(CONFIG_ENV_RANGE)						\
	"(env),6m(linux),32m(rootfs),89600k(userfs),512k@0x7f00000(dtb),512k@0x7f80000(bbt)ro"
#endif

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define SRAM0_SIZE			SZ_64K
#define OCMC_SRAM_BASE			0x40300000
#define CONFIG_SPL_STACK		(OCMC_SRAM_BASE + 0xb800)
#define CONFIG_SYS_INIT_SP_ADDR		(PHYS_SDRAM_1 + SZ_32K)

 /* Platform/Board specific defs */
#define CONFIG_SYS_TIMERBASE		0x48040000	/* Use Timer2 */
#define CONFIG_SYS_PTV			2	/* Divisor: 2^(PTV+1) => 8 */

/* Defines for SPL */
#define CONFIG_SPL_FRAMEWORK
#define CONFIG_SPL_MAX_SIZE		(SRAM_SCRATCH_SPACE_ADDR - CONFIG_SPL_TEXT_BASE)
#define CONFIG_SPL_GPIO_SUPPORT
#ifdef CONFIG_NAND_OMAP_GPMC
#define CONFIG_SPL_NAND_SUPPORT
#define CONFIG_SPL_NAND_DRIVERS
#define CONFIG_SPL_NAND_BASE
#define CONFIG_SPL_NAND_ECC
#define CONFIG_SPL_NAND_AM33XX_BCH
#define CONFIG_SYS_NAND_5_ADDR_CYCLE
#define CONFIG_SYS_NAND_PAGE_COUNT	(CONFIG_SYS_NAND_BLOCK_SIZE /	\
					CONFIG_SYS_NAND_PAGE_SIZE)
#define CONFIG_SYS_NAND_BLOCK_SIZE	SZ_128K
#define CONFIG_SYS_NAND_BAD_BLOCK_POS	NAND_LARGE_BADBLOCK_POS
#define CONFIG_SYS_NAND_ECCPOS		{ 2, 3, 4, 5, 6, 7, 8, 9, \
					 10, 11, 12, 13, 14, 15, 16, 17, \
					 18, 19, 20, 21, 22, 23, 24, 25, \
					 26, 27, 28, 29, 30, 31, 32, 33, \
					 34, 35, 36, 37, 38, 39, 40, 41, \
					 42, 43, 44, 45, 46, 47, 48, 49, \
					 50, 51, 52, 53, 54, 55, 56, 57, }
#endif

#define CONFIG_SPL_BSS_START_ADDR	PHYS_SDRAM_1
#define CONFIG_SPL_BSS_MAX_SIZE		SZ_512K

#define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR	0x300 /* address 0x60000 */

#define CONFIG_SPL_LIBCOMMON_SUPPORT
#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_YMODEM_SUPPORT
#define CONFIG_SPL_LDSCRIPT		"$(CPUDIR)/omap-common/u-boot-spl.lds"

/*
 * 1MB into the SDRAM to allow for SPL's bss at the beginning of SDRAM
 * 64 bytes before this address should be set aside for u-boot.img's
 * header. That is 0x800FFFC0--0x80100000 should not be used for any
 * other needs.
 */
#define CONFIG_SYS_SPL_MALLOC_START	(PHYS_SDRAM_1 + SZ_2M + SZ_32K)
#define CONFIG_SYS_SPL_MALLOC_SIZE	SZ_1M

#endif	/* __CONFIG_H */
