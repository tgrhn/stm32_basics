/*
 * LighLevelDefine.h
 *
 *
 */

#ifndef INC_LTR_329ALS_01_DS_V1_H_
#define INC_LTR_329ALS_01_DS_V1_H_

#include "I2C_Functions.h"
#include "main.h"
#include "math.h"

/*************************************************************************************************************************************
 *
 * 										LTR329ALS Ambient Light Level Sensor Address
 *
 ***********************************************************************************************************************************s*/

#define LTR_Address			0x29	// Sensör I2C adresi  0x29H << 1 = 0x52			LTR-329ALS-01_DS_V1


	// Ambient Light Level Sensor Register Set
#define ALS_CONTR			0X80		//  R/W
#define ALS_MEAS_RATE		0X85		//  R/W
#define PART_ID 			0X86		//  Read only
#define MANUFAC_ID			0X87		//  Read only
#define ALS_DATA_CH1_0		0X88		//  Read only
#define ALS_DATA_CH1_1		0X89		//  Read only
#define ALS_DATA_CH0_0		0X8A		//  Read only
#define ALS_DATA_CH0_1		0X8B		//  Read only
#define ALS_STATUS			0X8C		//  Read only

// Sensör ile ilgili değişkenlerini tutmak için oluşturulan struct yapısı

typedef struct  {
	uint8_t Part_id;
	uint8_t Manuf_id;
	uint8_t Gain;	 	 // Kazanç, 0.01 luxtan 64k lux a kadar aralığa sahip kazanç değerleri elde edilmesini sağlar,
	uint16_t iTime;		 // integration Time bilgisi
	uint8_t mRateBit;
	uint16_t mRate;		 // Measurement Rate kaç saniyede bir ölçüm yapılacağı bilgisi
	uint8_t reset;	 	 //	Reset modu sistemi resetler
	uint8_t mode; 		 //	mode değişkeni standby- aktif mode arasında geçiş yapmamızı sağlar
	uint16_t CH1;		 // 0. kanaldan okunan 8er bitlik değerlerin birleştirilmesiyle oluşan 16 bitlik değer
	uint16_t CH0;	 	 // 1. kanaldan okunan 8er bitlik değerlerin birleştirilmesiyle oluşan 16 bitlik değer
	uint8_t Data_Valid;	 // Datanın geçerli veya geçersiz olması durumunu kontrol eder  Valid(0) or InValid (1)
	uint8_t NEW_Data;	 // Data yeni mi eski mi kontrol edilir, NEW_Data = 1 henüz okunmamış anlamındadır

	uint64_t lux;			 // Sensörden yapılan ölçüm değeri
	uint64_t ratio;		 // lux hesabında kullanılan parametre
	uint64_t PFactor;		 // Sensör önünde (varsa) delik veya camın etkisi

}LTR_sensor;
extern LTR_sensor LTR;



#define GainSet_OK			  1
#define GainSet_Not_OK		  0
#define GainSet_IsNotCorrect -1

#define IntTimeSet_OK			  1
#define IntTimeSet_Not_OK		  0
#define IntTimeSet_IsNotCorrect  -1

#define MeasureTimeSet_OK			  1
#define MeasureTimeSet_Not_OK		  0
#define MeasureTimeSet_IsNotCorrect  -1

#define DataValid		 1
#define DataNotValid  	 0



//		_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ 	FUNCTIONS	_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
extern void LTR_Sensor_Init(LTR_sensor *LTR_Sensor);
extern uint8_t ALS_CONTR_Read(void);		// Gain durumu CONTROL Register üzerinden kontrol edilir
extern int8_t ALS_CONTR_GainSet (LTR_sensor *LTR_Sensor, uint8_t Gain); // Gain durumu kontrol edilir ve istenilen gain durumu ALS_CONTR register'a yazılır
extern uint8_t ALS_GainRead(LTR_sensor *LTR_Sensor);						// Gain durumu kontrol edilir ve Lux hesabında kullanılacak Gain değeri set edilir.
extern void ALS_ResetFunction(LTR_sensor *LTR_Sensor, uint8_t reset);	// Reset durumu kontrol edilir ve istenilen reset durumu ALS_CONTR register'a yazılır
extern void ALS_ModeSelect(LTR_sensor *LTR_Sensor, uint8_t mode);	// Mode durumu kontrol edilir ve istenilen mode durumu ALS_CONTR register'a yazılır

extern uint8_t ALS_IntTimeRead(void);		// integration Time kontrol edilir ve Lux hesabında kullanılacak integration Time set edilir.
extern void ALS_IntTimeBitRead (LTR_sensor *LTR_Sensor);
extern int8_t ALS_IntTimeSet(LTR_sensor *LTR_Sensor,float iTime);	// Integration time durumu kontrol edilir ve istenilen Integration time durumu ALS_MEAS_RATE register'a yazılır
extern uint8_t ALS_MeasRateRead (void);		// Measurement Rate durumu kontrol edilir ve istenilen Measurement Rate durumu ALS_MEAS_RATE register'a yazılır
extern void ALS_MeasRateBitRead (LTR_sensor *LTR_Sensor);
extern int8_t ALS_MeasRateSet (LTR_sensor *LTR_Sensor,uint16_t mRate);	// Measurement Rate durumu kontrol edilir ve istenilen Measurement Rate durumu ALS_MEAS_RATE register'a yazılır

extern void Part_Id(LTR_sensor *LTR_Sensor);								// Device Part_id okuması yapılır
extern void Manufac_Id(LTR_sensor *LTR_Sensor);						// Device Manufacture_id okuması yapılır

extern uint8_t ALS_GetData (LTR_sensor *LTR_Sensor); // ALS Ölçüm değerleri CH0L, CH0H, CH1L ve CH1H register'larından okuma yapılır ve -
													// 16 bitlik CH0 ve CH1 data değerleri LuxCalc fonksiyonunda kullanılmak üzere oluşturulur.

extern uint8_t ALS_StatusDataValid(LTR_sensor *LTR_Sensor);		// Data geçerli mi geçersiz mi kontrol edilir. Valid(default)
extern void ALS_StatusNewOrOld(LTR_sensor *LTR_Sensor);		// Data yeni mi eski mi kontrol edilir, NEW_Data = 1 henüz okunmamış anlamındadır
extern float LuxCalc ( LTR_sensor *LTR_Sensor );			// CHO ve CH1 den okunan değerler kullanılarak lux hesabı yapılır





#endif /* INC_LTR_329ALS_01_DS_V1_H_ */











































