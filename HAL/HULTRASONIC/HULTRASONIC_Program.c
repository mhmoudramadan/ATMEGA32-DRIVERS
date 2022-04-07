/*
 * HULTRASONIC_Program.c
 *
 *  Created on: Mar 21, 2022
 *      Author: Dell
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"../../MCAL/MTIMER1/MTIMER1_Config.h"
#include"../../MCAL/MTIMER1/MTIMER1_Interface.h"
#include"../../MCAL/MEXTI/MEXTI_Config.h"
#include"../../MCAL/MEXTI/MEXTI_Interface.h"
#include"../../MCAL/MGIE/MGIE_Interface.h"

#include<util/delay.h>

static uint32 Global_uint32t1;
static uint32 Global_uint32t2;
static uint16 Global_uint16Flag=0;
static uint32 Global_uint32counter=0;

void APP_TOV(void)
{
	Global_uint32counter++;
}
void APP_ICU (void)
{
	if(Global_uint16Flag==0)
	{
		Global_uint32counter=0;
		Global_uint32t1=MTIMER1_uint32Read_ICR1();
		MEXTI_VidSenseControlSelect(EXTI1,MEXTI_FALLING_EDGE);
		Global_uint16Flag=1;
	}
	else if(Global_uint16Flag==1)
	{
		Global_uint32t2=MTIMER1_uint32Read_ICR1();
		MEXTI_VidSenseControlSelect(EXTI1,MEXTI_RISING_EDGE);
		Global_uint16Flag=2;
	}
}
void HULTRASONIC_VidInit(void)
{
	/*initialize timer1 in overflow mode */
	MTIMER1_VidInit();
	MTIMER1_VidTimer1_ICU_SetCallBack(APP_ICU);
	MTIMER1_VidTimer1_OverFlow_SetCallBack(APP_TOV);

	/*initialize interrupt 1*/
	MEXTI_VidInitEXTI1();
	MGIE_Enable();
}

void HULTRASONIC_VidStart(uint8 copy_TriggerPort,uint8 copy_TriggerPin)
{
	/*Set Trigger port as output*/
	MDIO_Errorstate_SetPinDirection(copy_TriggerPort,copy_TriggerPin,PIN_OUTPUT);

	if(Global_uint16Flag==0)
		{
		/*initialize trigger port and pin*/
		MDIO_Errorstate_SetPinValue(copy_TriggerPort,copy_TriggerPin,PIN_HIGH);
		_delay_us(10);
		MDIO_Errorstate_SetPinValue(copy_TriggerPort,copy_TriggerPin,PIN_LOW);
		MEXTI_VidSenseControlSelect(EXTI1,MEXTI_RISING_EDGE);
		}
}
uint8 HULTRASONIC_GetDistance(uint8 copy_TriggerPort,uint8 copy_TriggerPin)
{
	uint8 Loc_uint8Distance;
	uint32 Loc_uint32Time;
	Global_uint32counter = 0;
	Global_uint16Flag = 0;

	MDIO_Errorstate_SetPinValue(copy_TriggerPort,copy_TriggerPin,PIN_HIGH);
	_delay_us(10);
	MDIO_Errorstate_SetPinValue(copy_TriggerPort,copy_TriggerPin,PIN_LOW);
	MEXTI_VidSenseControlSelect(EXTI1,MEXTI_RISING_EDGE);

	while(Global_uint16Flag<2);
	Loc_uint32Time=(Global_uint32t1+Global_uint32t2)+(Global_uint32counter*65535);
	Loc_uint8Distance=Loc_uint32Time/58;
	return Loc_uint8Distance;
}
uint8 HULTRASONIC_GetDistanceNoBlock(uint8* returnDistance)
{
	uint8 Loc_uint8Distance;
	uint32 Loc_uint32Time;
	if(Global_uint16Flag==2)
		{
			Loc_uint32Time=(Global_uint32t1+Global_uint32t2)+(Global_uint32counter*65535);
			Loc_uint8Distance=Loc_uint32Time/58;
			*returnDistance=Loc_uint8Distance;
			Global_uint16Flag=0;
			return 1;
		}
	return 0;
}

