/*
 * HDFPLAYER_Program.c
 *
 *  Created on: Mar 22, 2022
 *      Author: Dell
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"../../MCAL/MUART/MUART_Interface.h"
#include"HDFPLAYER_Private.h"
#include"HDFPLAYER_Interface.h"

#include<util/delay.h>
uint8  MP3Command[MP3_CMD_Size] =
{
		MP3_StartByte,
		MP3_Version,
		MP3_Length,
		MP3_Command,
		MP3_NO_Feedback,
		MP3_PARA_MSB,
		MP3_PARA_LSB,
		MP3_CheckSum_MSB,
		MP3_CheckSum_LSB,
		MP3_EndByte
};

void HDF_VidMP3SendCommandFrame(void)
{
	uint8 Loc_uint8counter;
	uint16 Loc_uint16CheckSum=0;
	uint16 Loc_uint16AddFrame=0;
	for(Loc_uint8counter=0 ; Loc_uint8counter<10;Loc_uint8counter++)
	{
		if((Loc_uint8counter>0) && (Loc_uint8counter<7))
		{
			Loc_uint16AddFrame+=MP3Command[Loc_uint8counter];
		}
		else if(Loc_uint8counter==7)
		{
			Loc_uint16CheckSum=0xFFFF-Loc_uint16AddFrame+1;
			MP3Command[MP3_IDX_CHECKSUM_MSB]=Loc_uint16CheckSum<<8;
			MP3Command[MP3_IDX_CHECKSUM_LSB]=(uint8)Loc_uint16CheckSum;
		}
		else
		{
			/*Do nothing*/
		}
		MUART_VidSendChar(MP3Command[Loc_uint8counter]);
	}
}

void HDF_VidMP3Init(void)
{
	MUART_VidInit();
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_Reset;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
	_delay_ms(1000);
}
void HDF_VidMP3Play(void)
{
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_PLAY;
	MP3Command[MP3_IDX_PARA_MSB]=0x00;
	MP3Command[MP3_IDX_PARA_LSB]=0x00;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
}
void HDF_VidMP3Stop(void)
{
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_STOP;
	MP3Command[MP3_IDX_PARA_MSB]=0x00;
	MP3Command[MP3_IDX_PARA_LSB]=0x00;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
}
void HDF_VidMP3Pause(void)
{
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_Pause;
	MP3Command[MP3_IDX_PARA_MSB]=0x00;
	MP3Command[MP3_IDX_PARA_LSB]=0x00;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
}
void HDF_VidMP3Reset(void)
{
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_Reset;
	MP3Command[MP3_IDX_PARA_MSB]=0x00;
	MP3Command[MP3_IDX_PARA_LSB]=0x00;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
}
void HDF_VidMP3PlayNextTrack(void)
{
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_PlayNext;
	MP3Command[MP3_IDX_PARA_MSB]=0x00;
	MP3Command[MP3_IDX_PARA_LSB]=0x00;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
}
void HDF_VidMP3PlayPerviousTrack(void)
{
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_PlayPervious;
	MP3Command[MP3_IDX_PARA_MSB]=0x00;
	MP3Command[MP3_IDX_PARA_LSB]=0x00;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
}
void HDF_VidMP3PlayRandomTrack(void)
{
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_PLAY_RANDOM;
	MP3Command[MP3_IDX_PARA_MSB]=0x00;
	MP3Command[MP3_IDX_PARA_LSB]=0x00;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
}
void HDF_VidMP3IncreaseVolume(void)
{
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_Inc_Volume;
	MP3Command[MP3_IDX_PARA_MSB]=0x00;
	MP3Command[MP3_IDX_PARA_LSB]=0x00;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
}
void HDF_VidMP3DcreaseVolume(void)
{
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_Dec_Volume;
	MP3Command[MP3_IDX_PARA_MSB]=0x00;
	MP3Command[MP3_IDX_PARA_LSB]=0x00;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
}
void HDF_VidMP3SelectVolume(uint16 copy_uint16Volume)
{
	if(copy_uint16Volume>30)
	{
		copy_uint16Volume=30;
	}
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_SelectVolume;
	MP3Command[MP3_IDX_PARA_MSB]=copy_uint16Volume>>8;
	MP3Command[MP3_IDX_PARA_LSB]=(uint8)copy_uint16Volume;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
	MP3Command[MP3_IDX_PARA_MSB]=0;
	MP3Command[MP3_IDX_PARA_LSB]=0;
}
void HDF_VidMP3PlayTrack(uint16 copy_uint16Track)
{
	if(copy_uint16Track>3000)
	{
		copy_uint16Track=3000;
	}
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_PlayTrack;
	MP3Command[MP3_IDX_PARA_MSB]=copy_uint16Track<<8;
	MP3Command[MP3_IDX_PARA_LSB]=(uint8)copy_uint16Track;
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
	MP3Command[MP3_IDX_PARA_MSB]=0;
	MP3Command[MP3_IDX_PARA_LSB]=0;
}
void HDF_VidMP3PlayTrackInfloder(uint8 copy_uint8Folder,uint16 copy_uint16Track)
{
	if(copy_uint8Folder>99)
		{
			copy_uint8Folder=99;
		}
	if(copy_uint16Track>3000)
		{
			copy_uint16Track=3000;
		}
	MP3Command[MP3_IDX_COMMAND]=MP3_CMD_PlayTrackFolder;
	MP3Command[MP3_IDX_PARA_MSB]=(copy_uint8Folder<<4)|((copy_uint16Track & 0xF00)<<8);
	MP3Command[MP3_IDX_PARA_LSB]=(copy_uint16Track & 0xFF);
	HDF_VidMP3SendCommandFrame();
	MP3Command[MP3_IDX_COMMAND]=0;
	MP3Command[MP3_IDX_PARA_MSB]=0;
	MP3Command[MP3_IDX_PARA_LSB]=0;
}
