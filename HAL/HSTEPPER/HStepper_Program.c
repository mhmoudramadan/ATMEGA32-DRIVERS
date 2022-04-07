/*
 * HSTTEPEER_Program.c
 *
 *  Created on: Jan 29, 2022
 *      Author: Dell
 */

#include "../../LIB/LSTD_TYPES.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include "../HSTEPPER/HStepper_Config.h"
#include "../HSTEPPER/HStepper_Interface.h"
#define F_CPU 16000000UL
#include<util/delay.h>

void HStepper_Init(void)
{
	MDIO_Errorstate_SetPinDirection(STEPPER_PORT,STEPPER_COIL1,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(STEPPER_PORT,STEPPER_COIL2,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(STEPPER_PORT,STEPPER_COIL3,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(STEPPER_PORT,STEPPER_COIL4,PIN_OUTPUT);
}
void HStepper_SetStepsDirection(uint16 copy_uint16Steps,uint8 copy_uint8Direction)
{
								/*Full steps*/
	switch(copy_uint8Direction)
		{
	                         /*clock wise */
		     case CW:
			for(uint16 i=0 ;i<copy_uint16Steps;i++)
					{
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
					_delay_ms(MAX_SPEED_DELAY);

					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
					_delay_ms(MAX_SPEED_DELAY);

					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
					_delay_ms(MAX_SPEED_DELAY);

					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
					MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
					_delay_ms(MAX_SPEED_DELAY);
					}
			break;

                                        /* counter clock wise*/
		case CCW :
			for(uint16 i=0 ;i<copy_uint16Steps;i++)
			{
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
				_delay_ms(MAX_SPEED_DELAY);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(MAX_SPEED_DELAY);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(MAX_SPEED_DELAY);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(MAX_SPEED_DELAY);
				}
			break;
		}
										/*half step*/
	switch (copy_uint8Direction)
	{
	case CW:
		for(uint16 i=0;i<copy_uint16Steps;i++)
		{
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(MAX_SPEED_DELAY);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(MAX_SPEED_DELAY);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(MAX_SPEED_DELAY);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(MAX_SPEED_DELAY);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(MAX_SPEED_DELAY);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(MAX_SPEED_DELAY);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(MAX_SPEED_DELAY);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(MAX_SPEED_DELAY);
		}
		break;

	case CCW:
		for(uint16 i=0;i<copy_uint16Steps;i++)
				{
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
				_delay_ms(MAX_SPEED_DELAY);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
				_delay_ms(MAX_SPEED_DELAY);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(MAX_SPEED_DELAY);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(MAX_SPEED_DELAY);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(MAX_SPEED_DELAY);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(MAX_SPEED_DELAY);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(MAX_SPEED_DELAY);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
				_delay_ms(MAX_SPEED_DELAY);
				}
		break;
	}
}
void HStepper_SetSpeedDirection(uint16 copy_uint16Speed,uint8 copy_uint8Direction)
{
	/*Full Step*/
		switch(copy_uint8Direction)
		{
								/*clock wise */
		case CW:
			{
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
				_delay_ms(copy_uint16Speed);
			break;
			}

								/* counter clock wise*/
		case CCW :

			{
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);
				break;
			}
		default:
			break;
		}
		/*Half Step*/
		switch(copy_uint8Direction)
		{
		case CW:
		{
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);
			break;
		}
		case CCW:
		{
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);
			break;
		}
		default:
			break;
		}

}
void HStepper_SetAngel(uint16 copy_uint16Angel,uint16 copy_uint16Speed,uint8 copy_uint8Direction)
{
	/*for full step
	 * full steps in complete cycle
	 * steps=(full resolution/(stride angle)-->(360/(11.25/64)=2048 steps
	 * steps in specific angle =(angle*steps)/full resolution--->(angle*2048)/360=..*/
	uint16 Loc_CalcFull=0;
	Loc_CalcFull=((copy_uint16Angel*2048)/360);

		switch(copy_uint8Direction)
		{
		case CW:
		{
			for(uint16 count=0;count<Loc_CalcFull;Loc_CalcFull++)
			{
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
				_delay_ms(copy_uint16Speed);
			}
			break;
		}
		case CCW:
		{
			for(uint16 count=0;count<Loc_CalcFull;count++)
			{
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);

				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
				MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
				_delay_ms(copy_uint16Speed);
			}
			break;
		}
		default:
		break;
		}

	/*for half step
	 *  full steps in complete cycle
	 * steps=(full resolution/(stride angle)-->(360/(5.625/64)=4096 steps
	 * steps in specific angle =(angle*steps)/full resolution--->(angle*4096)/360=..*/
	uint16 Loc_CalcHalf=0;
	Loc_CalcHalf=((copy_uint16Angel*2048)/360);
	switch(copy_uint8Direction)
	{
	case CW:
	{
		for(uint16 count=0;count<Loc_CalcHalf;count++)
		{
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);
		}
		break;
	}
	case CCW:
	{
		for(uint16 count=0;count<Loc_CalcHalf;count++)
		{
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_LOW);
			_delay_ms(copy_uint16Speed);

			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL1,PIN_HIGH);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL2,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL3,PIN_LOW);
			MDIO_Errorstate_SetPinValue(STEPPER_PORT,STEPPER_COIL4,PIN_HIGH);
			_delay_ms(copy_uint16Speed);
		}
		break;
	}
	default:
		break;
	}
}
