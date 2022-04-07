/*
 * HULTRASONIC_Interface.h
 *
 *  Created on: Mar 21, 2022
 *      Author: Dell
 */

#ifndef HAL_HULTRASONIC_HULTRASONIC_INTERFACE_H_
#define HAL_HULTRASONIC_HULTRASONIC_INTERFACE_H_


void HULTRASONIC_VidInit(void);
void HULTRASONIC_VidStart(uint8 copy_TriggerPort,uint8 copy_TriggerPin);
uint8 HULTRASONIC_GetDistance(uint8 copy_TriggerPort,uint8 copy_TriggerPin);
uint8 HULTRASONIC_GetDistanceNoBlock(uint8* returnDistance);
#endif /* HAL_HULTRASONIC_HULTRASONIC_INTERFACE_H_ */
