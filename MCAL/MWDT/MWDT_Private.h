/*
 * MWDT_Private.h
 *
 *  Created on: Feb 28, 2022
 *      Author: Dell
 */

#ifndef MCAL_MWDT_MWDT_PRIVATE_H_
#define MCAL_MWDT_MWDT_PRIVATE_H_

#define WDTCR  *((volatile uint8*)0x41)

#define WDT_16K_OSC     0
#define WDT_32K_OSC     1
#define WDT_64K_OSC     2
#define WDT_128K_OSC    3
#define WDT_256K_OSC    4
#define WDT_512K_OSC    5
#define WDT_1024K_OSC   6
#define WDT_2048K_OSC   7


#endif /* MCAL_MWDT_MWDT_PRIVATE_H_ */
