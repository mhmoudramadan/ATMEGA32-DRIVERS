/*
 * HLDR_Program.c
 *
 *  Created on: Mar 22, 2022
 *      Author: Dell
 */

#include"../../LIB/LSTD_TYPES.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"../../MCAL/MADC/MADC_Interface.h"

void HLDR_VidInit(void)
{
	MADC_VidSingleConversion_Init();
}
uint32 HLDR_uint32GetValue(uint8 copy_uint8channel)
{
	uint16 Loc_uint16Analogvalue;
	uint16 Loc_uint16Digitalvalue;
	uint32 Loc_uint32Result;

	MADC_VidADCStartSingleConversion(copy_uint8channel);
	Loc_uint16Analogvalue=MADC_uint16Read();
	Loc_uint16Digitalvalue=(5 * Loc_uint16Analogvalue)/1024;
	Loc_uint32Result=(Loc_uint16Digitalvalue*1000)/(5-Loc_uint16Digitalvalue);
	return Loc_uint32Result;
}
