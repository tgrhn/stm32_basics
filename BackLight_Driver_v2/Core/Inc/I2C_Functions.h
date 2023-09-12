/*
 * I2C_Functions.h
 *
 *  Created on: Apr 30, 2021
 *      Author: deniz.gurhan
 */

#ifndef INC_I2C_FUNCTIONS_H_
#define INC_I2C_FUNCTIONS_H_

#include "main.h"

#define __I2C_Lock(__HANDLE__)					\
	do{ 										\
		uint32_t rPriMask = __get_PRIMASK();	\
		__disable_irq();                 		\
		if((__HANDLE__)->Lock == LOCKED)   		\
		{                                      	\
			__set_PRIMASK(rPriMask);     		\
			return I2C_BUSY;                    \
		}                                  		\
		else                               		\
		{                                      	\
			(__HANDLE__)->Lock = LOCKED;    	\
			__set_PRIMASK(rPriMask);      		\
		}                                 		\
	}while(0U)

#define __I2C_Unlock(__HANDLE__)      			\
	do{                                       	\
		(__HANDLE__)->Lock = UNLOCKED;    		\
	}while(0U)

typedef enum
{
  UNLOCKED = 0x00U,
  LOCKED   = 0x01U
} LockTypeDef;

typedef enum
{
  I2C_BUSY 	= 0x00U,
  I2C_READY = 0x01U,
  I2C_OK    = 0x02U
} I2CStatusTypeDef;

typedef struct __I2C_Struct
{
	uint8_t *Data;
	uint16_t RegisterAddr;
	uint8_t RegisterAddrSize;
	uint16_t DataSize;
	uint8_t SlaveAddr;
	LockTypeDef Lock;
	I2CStatusTypeDef State;
} I2C_Struct;

extern I2C_Struct I2C1_Slave;
extern I2C_Struct I2C2_Master;

void I2C2_Master_Register_Init(void);
I2CStatusTypeDef I2C2_Master_Write_to_Register(uint8_t SlaveAddr, uint16_t RegisterAddr, uint8_t RegisterAddrSize, uint8_t *Data, uint16_t DataSize);
I2CStatusTypeDef I2C2_Master_Read_from_Register(uint8_t SlaveAddr, uint16_t RegisterAddr, uint8_t RegisterAddrSize, uint8_t *Data, uint16_t DataSize);
void I2C1_Slave_Register_Init(void);

#endif /* INC_I2C_FUNCTIONS_H_ */
