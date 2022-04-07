/*
 * MWDT_Program.c
 *
 *  Created on: Feb 28, 2022
 *      Author: Dell
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"MWDT_Private.h"
#include"MWDT_Config.h"

void MWDT_VidEnable(void)
{
	/*Enable Watch Dog*/
	SET_BIT(WDTCR,3);

}
void MWDT_VidSleep(uint8 copy_uint8sleep)
{
	/*clear Timer PreScaler*/
		WDTCR&=0xF8;
		/*Set Timer */
		WDTCR|=copy_uint8sleep;

}
void MWDT_VidDisabled(void)
{
	/*Set Bit 4,3*/
	WDTCR|=0x18;
	WDTCR=0x00;

}

