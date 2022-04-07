/*
 * HTEMPERATURE_Program.c
 *
 *  Created on: Mar 21, 2022
 *      Author: Dell
 */

#include"../../LIb/LSTD_TYPES.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"../../MCAL/MADC/MADC_Interface.h"
#include"HTEMPERATURE_Interface.h"

void HTEMP_VidInit(void)
{
	MADC_VidSingleConversion_Init();
}

uint8 HTEMP_uintGetTemp(uint8 copy_uint8Channel)
{
	MADC_VidADCStartSingleConversion(copy_uint8Channel);
	uint16 Loc_AnalogValue=0;
	uint32 Loc_TemperatureValue=0;
	Loc_AnalogValue = MADC_uint16Read();
	Loc_TemperatureValue=(Loc_AnalogValue*150*50) / (1023*1.5);
	return Loc_TemperatureValue;
}

