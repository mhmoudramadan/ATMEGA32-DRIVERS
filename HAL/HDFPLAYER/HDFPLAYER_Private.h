/*
 * HDFPLAYER_Private.h
 *
 *  Created on: Mar 22  2022
 *      Author: Dell
 */

#ifndef HAL_HDFPLAYER_HDFPLAYER_PRIVATE_H_
#define HAL_HDFPLAYER_HDFPLAYER_PRIVATE_H_

/*MP3 Frame*/
#define MP3_CMD_Size    	10
#define MP3_StartByte   	0x7E
#define MP3_Version     	0xFF
#define MP3_Length      	0x00
#define MP3_Command     	0x00
#define MP3_NO_Feedback 	0x00
#define MP3_PARA_MSB    	0x00
#define MP3_PARA_LSB    	0x00
#define MP3_CheckSum_MSB 	0x00
#define MP3_CheckSum_LSB 	0x00
#define MP3_EndByte         0xEF

/*Frame MP3 Index frame*/

#define MP3_IDX_START_BYTE	      0
#define MP3_IDX_VERSION  	      1
#define MP3_IDX_LENGTH  	      2
#define MP3_IDX_COMMAND  	      3
#define MP3_IDX_FEEDBACK	      4
#define MP3_IDX_PARA_MSB  		  5
#define MP3_IDX_PARA_LSB   	      6
#define MP3_IDX_CHECKSUM_MSB      7
#define MP3_IDX_CHECKSUM_LSB  	  8
#define MP3_IDX_END_BYTE	      9


/*MP3 Control Command*/
#define MP3_CMD_PlayNext   			0x01
#define MP3_CMD_PlayPervious    	0x02
#define MP3_CMD_PlayTrack       	0x03
#define MP3_CMD_Inc_Volume      	0x04
#define MP3_CMD_Dec_Volume      	0x05
#define MP3_CMD_SelectVolume    	0x06
#define MP3_CMD_SetEQ           	0x07
#define MP3_CMD_RepeatTrack    		0x08
#define MP3_CMD_SetStorage      	0x09
#define MP3_CMD_Sleep           	0x0A
#define MP3_CMD_Reset           	0x0C
#define MP3_CMD_PLAY 	        	0x0D
#define MP3_CMD_Pause           	0x0E
#define MP3_CMD_PlayTrackFolder  	0x0F
#define MP3_CMD_RepeatAll       	0x11
#define MP3_CMD_PLAY_MP3_FOLDER 	0x12
#define MP3_CMD_INSERT_ADVERT   	0x13
#define MP3_CMD_PLAY_3K_FOLDER 		0x14
#define MP3_CMD_STOP_ADVERT	    	0x15
#define MP3_CMD_STOP	        	0x16
#define MP3_CMD_REPEAT_FOLDER		0x17
#define MP3_CMD_PLAY_RANDOM 		0x18
#define MP3_CMD_REPEAT_CUR_TRACK	0x19
#define MP3_CMD_SET_DAC	            0x1A



#define MP3_NO_VOLUME 	         0
#define MP3_NO_TRACK         	 0
#define MP3_MAX_VOLUME 	         30
#define MP3_MAX_TRACK_NUMBER 	 3000
#define MP3_MAX_TRACK_FOLDER 	 99

void HDF_VidMP3SendCommandFrame(void);

#endif /* HAL_HDFPLAYER_HDFPLAYER_PRIVATE_H_ */
