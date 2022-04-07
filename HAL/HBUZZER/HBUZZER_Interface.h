/*
 * HBUZZER_Interface.h
 *
 *  Created on: Mar 21, 2022
 *      Author: Dell
 */

#ifndef HAL_HBUZZER_HBUZZER_INTERFACE_H_
#define HAL_HBUZZER_HBUZZER_INTERFACE_H_

typedef enum
{
	Buzzer_off=0,
	Buzzer_on
}Buzzer_State;

void HBUZZER_Vidinit(void);
void HBUZZER_VidBuzzerSatate(Buzzer_State State);


#endif /* HAL_HBUZZER_HBUZZER_INTERFACE_H_ */
