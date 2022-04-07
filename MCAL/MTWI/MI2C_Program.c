/*
 * MI2C_Program.c
 *
 *  Created on: Mar 9, 2022
 *      Author: Dell
 */

#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include "../MTWI/MI2C_Config.h"
#include "../MTWI/MI2C_Interface.h"
#include "../MTWI/MI2C_Private.h"

/*TWI Initialize as a master*/

void MTWI_VidInitMaster(uint8 copy_uint8Address)
{
	/*Enable ACK*/
	SET_BIT(TWCR,6);
	/*Set SCL Freq to 400KHZ ,With 16MHZ system Freq--> "Rate Bit" */
	TWBR=3;
	/*Set PreScaler =1 */
	CLR_BIT(TWSR,1);
	CLR_BIT(TWSR,0);
	/*Enable TWI*/
	SET_BIT(TWCR,2);
	/*write Address */
	if(copy_uint8Address !=0)
	{
		TWAR=copy_uint8Address<<1;
	}
	else
	{
		//Nothing
	}
}

/*TWI Initialize as a Salve*/

void MTWI_VidInitSalve(uint8 copy_uint8Address)
{
	/*Enable ACK*/
	SET_BIT(TWCR,6);
	/*Enable TWI*/
	SET_BIT(TWCR,2);
	/*Enable interrupt flag*/
	SET_BIT(TWCR,7);
	/*write Address */
	if(copy_uint8Address !=0)
	{
		TWAR=copy_uint8Address<<1;
	}
	else
	{
		//Nothing
	}
}

/*TWI Start condition*/
TWI_ErrorState MTWI_SendSatrtCondition(void)
{
	TWI_ErrorState Loc_Error=NoError;
	/*send start condition*/
	SET_BIT(TWCR,5);
	/*Clear  TWI flag*/
	SET_BIT(TWCR,7);
	/*wait until the operation finish and Flag Is Raised*/
	while(GET_BIT(TWCR,7)==0);
	/*Check the operation statues of start condition*/
	if((TWSR&0xF8) != 0x08)
	{
		Loc_Error=StartConditionError;
	}
	else
	{
		Loc_Error=0;
		/*Do nothing*/
	}
	return Loc_Error;
}
/*TWI Start Repeated Function*/
TWI_ErrorState  MTWI_SendSatrtRepeatedCondition(void)
{
	TWI_ErrorState Loc_Error=NoError;
		/*send start condition*/
		SET_BIT(TWCR,5);
		/*Clear  TWI flag*/
		SET_BIT(TWCR,7);
		/*wait until the operation finish and Flag Is Rasised*/
		while(GET_BIT(TWCR,7)==0);
		/*Check the operation statues*/
		if((TWSR&0xF8) != 0x10)
		{
			Loc_Error=RepeatedStartConditionError;
		}
		else
		{
			Loc_Error=0;
		}
		return Loc_Error;
}
/*TWI send  SLave Address with Write*/

TWI_ErrorState MTWI_SendSalveAddressWithWrite(uint8 copy_uint8SalveAddress)
{
	TWI_ErrorState Loc_Error=NoError;
	/*Send Salve Address --> 7 Bit with write */
	TWDR=copy_uint8SalveAddress<<1;
	/*Set write Bit Request in The LSB in Data Register*/
	CLR_BIT(TWDR,0);
	/*Clear Start Condition*/
	CLR_BIT(TWCR,5);
	/*Clear interrupt TWI Flag*/
	SET_BIT(TWCR,7);
	/*wait until the operation finish and Flag Is Raised*/
	while(GET_BIT(TWCR,7)==0);
	/*Check the operation statuesSLA+W &ACK*/
	if((TWSR&0xF8) != 0x18)
	{
		Loc_Error=SlaveAddressWriteError;
	}
	else
	{
		Loc_Error=1;

	}
	/*Check the operation statuesSLA+W &NACK*/
	if((TWSR&0xF8) != 0x20)
		{
		/*Do Nothing*/
		}
		else
		{
			Loc_Error=2;
		}
	return Loc_Error;
}
/*TWI send SLave Address with Read*/
TWI_ErrorState MTWI_SendSalveAddressWithRead(uint8 copy_uint8SalveAddress)
{
	TWI_ErrorState Loc_Error=NoError;
	/*Send Salve Address --> 7 Bit with Read */
	TWDR=copy_uint8SalveAddress<<1;
	/*Set read Bit Request in The LSB in Data Regsiter*/
	SET_BIT(TWDR,0);
	/*Clear Start Condition*/
	CLR_BIT(TWCR,5);
	/*Clear interrupt TWI Flag*/
	SET_BIT(TWCR,7);
	/*wait until the operation finish and Flag Is Rasised*/
	while(GET_BIT(TWCR,7)==0);
	/*Check the operation statues ACK*/
	if((TWSR&0xF8) != 0x40)
	{
		Loc_Error=SlaveAddressReadError;
	}
	else
	{
		/*Do Nothing*/
	}
	/*Check the operation statues NACK*/
	if((TWSR&0xF8) != 0x48)
	{
		Loc_Error=SlaveAddressReadError;
	}
	else
	{
		/*Do Nothing*/
	}
	return Loc_Error;
}
/*TWI send data as a master*/
TWI_ErrorState MTWI_MasterWriteDataByte(uint8 copy_uint8Data)
{
	TWI_ErrorState Loc_Error=NoError;
	/*Send Data */
	TWDR=copy_uint8Data;
	/*Clear interrupt TWI Flag*/
	SET_BIT(TWCR,7);
	/*wait until the operation finish and Flag Is Rasised*/
	while(GET_BIT(TWCR,7)==0);
	/*Check the operation statues data transmit with ACK*/
	if((TWSR&0xF8) != 0x28)
	{
		Loc_Error=MasterWriteByteError;
	}
	else
	{
		/*Do Nothing*/
	}
	/*Check the operation statues data transmit with NACK*/
		if((TWSR&0xF8) != 0x30)
		{
			Loc_Error=MasterWriteByteError;
		}
		else
		{
			/*Do Nothing*/
		}
	return Loc_Error;
}
/*TWI read data as a master*/
TWI_ErrorState MTWI_MasterReadDataByte(uint8 *copy_uint8Data)
{
	TWI_ErrorState Loc_Error=NoError;

	/*Clear interrupt TWI Flag*/
	SET_BIT(TWCR,7);
	/*wait until the operation finish and Flag Is Rasied*/
	while(GET_BIT(TWCR,7)==0);
	/*Check the operation statues*/
	if((TWSR&0xF8) != 0x50)
	{
		Loc_Error=MasterReadByteError;
	}
	else
	{
		*copy_uint8Data=TWDR;
	}
	return Loc_Error;
}
/*Salve Listen to bus*/
uint8 MTWI_SalveListenToBus(void)
{
	TWI_ErrorState Loc_Error=NoError;
	while(1)
	{
		/*wait until operation finish*/
		while(GET_BIT(TWCR,7)==0);
		/*Own SLA+W with ACK return slave Receive*/
		if((TWSR&0xF8) !=0x60)

		{
			Loc_Error=MasterWriteByteError;
		}
		else
		{
			Loc_Error=0;

		}
		/*Own SlA+R with ACK return slave transmit*/
		if((TWSR&0xF8) !=0xA8)
		{
		Loc_Error=MasterReadByteError;
		}
		else
		{
			Loc_Error=1;

		}

		/*General Call with ACK return*/
		if((TWSR&0xF8) !=0x70)
		{
			Loc_Error=GeneralCallError;
		}
		else
		{
			Loc_Error=2;

		}
		return Loc_Error;
	}
}
/*Salve Receive*/
uint8 MTWI_uint8SalveReceive(void)
{
	TWI_ErrorState Loc_Error=NoError;
	/*Enable Interrupt Flag & ACK & TWI*/
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,6);
	SET_BIT(TWCR,2);
	/*wait until operation End */
	while(GET_BIT(TWCR,7)==0);
	/*check for received data with ACK*/
	if((TWSR&0xF8)!=0x80)
	{
		Loc_Error=AckError;
	}
	else
	{
		return TWDR;
	}
	/*check for received data with NACK*/
	if((TWSR&0xF8) !=0x88)
	{
		Loc_Error=NackError;
	}
	else
	{
		return TWDR;
	}
	/*Check For Stop condition*/
	if((TWSR&0xF8) !=0xA0)
	{
		Loc_Error=StopError;
	}
	{
		/*Clear Flag*/
		SET_BIT(TWCR,7);
		return -1;
	}
}


uint8 MTWI_SalveTransmit(uint8 copy_uint8Data)
{
	TWI_ErrorState Loc_Error=NoError;
	TWDR=copy_uint8Data;
	/*Enable Interrupt Flag & ACK & TWI*/
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,6);
	SET_BIT(TWCR,2);
	/*wait until operation End */
	while(GET_BIT(TWCR,7)==0);
	/*Check For Repeated Start*/
	if((TWSR&0xF8) !=0xA0)
	{
		Loc_Error=RepeatedStartConditionError;
	}
	else
	{
		/*Clear Flag*/
		TWCR|=(1<<7);
		return -1;
	}

	/*Check For Data Transmit And ACK */
	if((TWSR&0xF8) !=0xB8)
	{
		Loc_Error=AckError;
	}
	else
	{
	return 0;
	}
	/*Check For Data Transmit And NACK */
	if((TWSR&0xF8) !=0xC0)
	{
		Loc_Error=NackError;
	}
	else
	{
		/*Clear flag*/
		TWCR|=(1<<7);
		return -2;
	}

	/*Check for Last byte Transmit and ACK Received*/
	if((TWSR&0xF8) !=0xC8)
	{
		Loc_Error=AckError;
	}
	else
	{
		return -3;
	}
		return -4;
}

/*TWI Stop condition*/
void MTWI_SendStopCondtion(void)
{
	/*Clear TWI  interrupt flag*/
	SET_BIT(TWCR,7);
	/*Send Stop Condition*/
	SET_BIT(TWCR,4);
}
