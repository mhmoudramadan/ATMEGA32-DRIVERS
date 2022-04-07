/*
 * HBUZZER_Program.c
 *
 *  Created on: Mar 21, 2022
 *      Author: Dell
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"../../MCAL/MTIMER0/MTIMER0_Config.h"
#include"../../MCAL/MTIMER0/MTIMER0_Interface.h"
#include"HBUZZER_Private.h"
#include"HBUZZER_Interface.h"
void HBUZZER_Vidinit(void)
{
	/*set OCP Pin for timer 0 as output*/
	MDIO_Errorstate_SetPinDirection(MDIO_PORTB,PIN3,PIN_OUTPUT);
	/*initialize Timer 0 at Fast PWM MODE PreScaler 8*/
	MTIMER0_VidInit();
}
void HBUZZER_VidBuzzerSatate(Buzzer_State State)
{
	switch(State)
		{
			case Buzzer_on:
			{
				MTIMER0_VidUpdateDutyCycle(BUZZERMAXSOUND);
				break;
			}
			case Buzzer_off:
			{
				MTIMER0_VidUpdateDutyCycle(BUZZERSOUND_OFF);
				break;
			}
			default:
				break;
		}
}
