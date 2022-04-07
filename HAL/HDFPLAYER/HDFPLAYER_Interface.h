/*
 * HDFPLAYER_Interface.h
 *
 *  Created on: Mar 22, 2022
 *      Author: Dell
 */

#ifndef HAL_HDFPLAYER_HDFPLAYER_INTERFACE_H_
#define HAL_HDFPLAYER_HDFPLAYER_INTERFACE_H_

void HDF_VidMP3Init(void);
void HDF_VidMP3Play(void);
void HDF_VidMP3Stop(void);
void HDF_VidMP3Pause(void);
void HDF_VidMP3Reset(void);
void HDF_VidMP3PlayNextTrack(void);
void HDF_VidMP3PlayPerviousTrack(void);
void HDF_VidMP3PlayRandomTrack(void);
void HDF_VidMP3IncreaseVolume(void);
void HDF_VidMP3DcreaseVolume(void);
void HDF_VidMP3SelectVolume(uint16 copy_uint16Volume);
void HDF_VidMP3PlayTrack(uint16 copy_uint16Track);
void HDF_VidMP3PlayTrackInfloder(uint8 copy_uint8Folder,uint16 copy_uint16Track);

#endif /* HAL_HDFPLAYER_HDFPLAYER_INTERFACE_H_ */
