/*
 * LTR-329ALS-01_DS_V1.c
 *
 *  Created on: Oct 12, 2020
 *      Author: selim.ozcan
 */

#include "LTR-329ALS-01_DS_V1.h"

// ********************************************************************************************************************************
			//		  ALS_CONTROL = GainControl + ResetFunction + ModeSelection
			/*		ALS_CONTR Register
			 * 	 SW ( software reset ayarı )
			 * 	 ALS Mode ( standby-mode veya active-mode ayarı ),
			 *	 ALS Gain setting yapabilmek için kullanılır. Kazanç 1x 2x 4x 8x   48x 96x şeklinde ayarlanabilir.
*/// ******************************************************************************************************************************


/*	  LTR_Sensor_Init
*	  Gain durumu, Integration time, Measurement Time Rate, Part_id ve Manufacturer_id registerlardan okuma yapılır
*/

LTR_sensor LTR;
void LTR_Sensor_Init(LTR_sensor *LTR_Sensor){
	HAL_Delay(1000);
	ALS_ModeSelect(LTR_Sensor,1);
	HAL_Delay(10);

	ALS_GainRead(LTR_Sensor);
	ALS_IntTimeBitRead(LTR_Sensor);		// okuma yapılan data maskelenir ve Integration Time bitleri kullanılır
	ALS_MeasRateBitRead(LTR_Sensor);      // okuma yapılan data maskelenir ve Measurement Repeat Rate bitleri kullanılır

	Part_Id(LTR_Sensor);
	Manufac_Id(LTR_Sensor);
}


/*	  ALS_CONTR_Read
*	  Control Registerindan okuma işlemi yapılır.
*/
uint8_t ALS_CONTR_Read(void){
	uint8_t Data;	// ALS_CONTR register'ından okunacak olan Data
	while(I2C2_Master_Read_from_Register(LTR_Address, ALS_CONTR, 1, &Data, 1)!=I2C_OK);
	return Data;
}

/*	  ALS_CONTR_GainSet
*	  Gain durumu kontrol edilir ve istenilen gain durumu ALS_CONTR register'a yazılır
*/
int8_t ALS_CONTR_GainSet (LTR_sensor *LTR_Sensor, uint8_t Gain){
		/* Gain=1 ise sensör 1x olarak set edilir	(default)
		 * Gain=2 ise sensör 2x olarak set edilir
		 * Gain=4 ise sensör 4x olarak set edilir
		 * Gain=8 ise sen8sör 8x olarak set edilir
		 * Gain=5 ise geçersiz
		 * Gain=6 ise geçersiz
		 * Gain=48 ise sensör 48x olarak set edilir
		 * Gain=96 ise sensör 96x olarak set edilir
		 */
	uint8_t GainReadData;
	uint8_t newDataGain;
	newDataGain = ALS_CONTR_Read();	// Gain Register ından okunan data değeri
	GainReadData = newDataGain & (0xE3);		//// okunan data ile maskeleme işlemi yapılır (0x11100011)
	uint8_t wrtData;		// ALS_CONTR register'ına yazılacak olan Data
		if (Gain==1 || Gain == 2 || Gain==4 || Gain == 8 || Gain==48 || Gain == 96 ){
			if     (Gain == 1){					// Gain = 1x -> 00000000
				wrtData = GainReadData;		// GainReadData değerine ilgili bit değeri yazılır ve gain 1x e set edilir.
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_CONTR, 1, &wrtData, 1)!=I2C_OK);	//
			}
			else if(Gain == 2){					// Gain = 2x -> 00000100
				wrtData = GainReadData | (0x04);		// GainReadData değerine ilgili bit değeri yazılır ve gain 2x e set edilir.
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_CONTR, 1, &wrtData, 1)!=I2C_OK);
			}
			else if(Gain == 4){					// Gain = 4x -> 00001000
				wrtData = GainReadData | (0x08);		// GainReadData değerine ilgili bit değeri yazılır ve gain 4x e set edilir.
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_CONTR, 1, &wrtData, 1)!=I2C_OK);
			}
			else if(Gain == 8){					// Gain = 8x -> 00001100
				wrtData = GainReadData | (0x0C);		// GainReadData değerine ilgili bit değeri yazılır ve gain 8x e set edilir.
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_CONTR, 1, &wrtData, 1)!=I2C_OK);
			}
			else if(Gain == 48){				// Gain = 48x -> 00011000
				wrtData = GainReadData | (0x18);		// GainReadData değerine ilgili bit değeri yazılır ve gain 48x e set edilir.
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_CONTR, 1, &wrtData, 1)!=I2C_OK);
			}
			else if(Gain == 96){										// Gain = 96x -> 00011100
				wrtData = GainReadData | (0x1C);		// GainReadData değerine ilgili bit değeri yazılır ve gain 96x e set edilir.
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_CONTR, 1, &wrtData, 1)!=I2C_OK);
			}

				if (ALS_CONTR_Read() == Gain){	// Data doğru bir şekilde gönderilmiş mi? kontrol et
					LTR_Sensor->Gain = Gain;
					return GainSet_OK;				// return = 1 ise Gönderme işlemi doğru bir şekilde gerçekleşmiştir
				}
				else{

					return GainSet_Not_OK;			// return = 0 ise Gönderme işleminde hata oluşmuştur
				}
		}
			else {
				return GainSet_IsNotCorrect;		// return = -1 ise Gain değeri {1,2,4,8,48,96} değerlerinden herhangi biri değildir.
			}
}

/*	  ALS_GainRead
*	  Gain durumu kontrol edilir ve Lux hesabında kullanılan Gain değeri set edilir.
*/
uint8_t ALS_GainRead(LTR_sensor *LTR_Sensor){
	uint8_t Data;	// ALS_STATUS register'ından okunacak olan Gain Data
	uint8_t Gain;
	while(I2C2_Master_Read_from_Register(LTR_Address, ALS_STATUS, 1, &Data, 1)!=I2C_OK);
	uint8_t newDataGain = Data & (0x70);		//// okunan data ile maskeleme işlemi yapılır (0x01110000)
		if 	   (newDataGain == 0x00){						// Gain = 1x -> 00000000
			Gain=1;
		}
		else if(newDataGain == 0x10){						// Gain = 2x -> 00010000
			Gain=2;
		}
		else if(newDataGain == 0x20){						// Gain = 4x -> 00100000
			Gain=4;
		}
		else if(newDataGain == 0x30){						// Gain = 8x -> 00110000
			Gain=8;
		}
		else if(newDataGain == 0x60){						// Gain = 48x -> 01100000
			Gain=48;
		}
		else if(newDataGain == 0x70){						// Gain = 96x -> 01110000
			Gain=96;
		}
		LTR_Sensor->Gain=Gain;
	return Gain;
}

/*	  ALS_ResetFunction
*	  Sensör reset fonksiyonu
*/
void ALS_ResetFunction(LTR_sensor *LTR_Sensor, uint8_t reset){
	/*
	* reset = 0 ise initial startup iptal edilir ( default )
	* reset = 1 ise initial startup aktiftir
	*/
	uint8_t Data;		// ALS_CONTR register'ından okunacak olan Reset Data
	uint8_t maskedData;	// Maskeleme sonrası kullanılacak olan Data
	uint8_t wrtData;
	while(I2C2_Master_Read_from_Register(LTR_Address, ALS_CONTR, 1, &Data, 1)!=I2C_OK);
	maskedData = Data & (0xFD);							//  maskeleme işlemi yapılır  (0x11111101)

		if 		(reset == 0){								//	not-reset			//  00000000
			wrtData = maskedData | (0x00);
			while(I2C2_Master_Write_to_Register(LTR_Address, ALS_CONTR, 1, &wrtData, 1)!=I2C_OK);
		}
		else if (reset == 1){								//	reset				//  00000010
			wrtData = maskedData | (0x02);
			while(I2C2_Master_Write_to_Register(LTR_Address, ALS_CONTR, 1, &wrtData, 1)!=I2C_OK);
			HAL_Delay(200);								// Initial start-up time delay 100ms (min)
		}
		LTR_Sensor->reset = reset;
}

/*	  ALS_ModeSelect
*	  Aktif mode Standby mode seçimi yapılması için gerekli fonksiyon
*/
void ALS_ModeSelect(LTR_sensor *LTR_Sensor, uint8_t mode){
	/*
	* mode=0 ise stand-by mode (default)
	* mode=1 ise active mode
	*/
		uint8_t Data;	// ALS_CONTR register'ından okunacak olan Mode Data
		uint8_t maskedData;	// Maskeleme sonrası kullanılacak olan Data
		uint8_t wrtData;
		while(I2C2_Master_Read_from_Register(LTR_Address, ALS_CONTR, 1, &Data, 1)!=I2C_OK);
		maskedData = Data & (0xFE);							//  maskeleme işlemi yapılır  (0x11111110)

		if		(mode == 0){								//	Standby-mode			// 00000000
			wrtData = maskedData | (0x00);
			while(I2C2_Master_Write_to_Register(LTR_Address, ALS_CONTR, 1, &wrtData, 1)!=I2C_OK);
		}

		else if (mode == 1)	{								// Active mode				// 00000001
			wrtData = maskedData | (0x01);
			while(I2C2_Master_Write_to_Register(LTR_Address, ALS_CONTR, 1, &wrtData, 1)!=I2C_OK);
			HAL_Delay(9); 									// wait 10ms (max) - wakeup time from standby
	}
		LTR_Sensor->mode = mode;
}

/********************************************************************************************************************************
	 * 	 ALS_MEAS_RATE Register  ==  ALS_IntegrationSet + ALS_Meas_Rate
	 * 	 Integrasyon zamanını ve ALS Measurement periyodik ölçüm zamanını ayarlamaya yarar. ALS_DATA registerleri arasında tekrar eder.
	 * 	 ALS Integrasyon zamanı ALS Measurement Repeat Rate e eşit veya küçük olmalıdır.
	 * 	 Res_Res_Int_Int_Int_Meas_Meas_Meas_
// ******************************************************************************************************************************
 */

/*	  ALS_IntTimeRead
*	  ALS_MEAS_RATE register'ından okunacak olan Integration Time Data
*/
uint8_t ALS_IntTimeRead (void){
	uint8_t Data;
	while(I2C2_Master_Read_from_Register(LTR_Address, ALS_MEAS_RATE, 1, &Data, 1)!=I2C_OK);
	return Data;
}
/*	  ALS_IntTimeBitRead
*	  ALS_MEAS_RATE register'ından Integration Time Bitlerinin okunması
*/
void ALS_IntTimeBitRead (LTR_sensor *LTR_Sensor){
	uint8_t Data;
	uint8_t MaskedData;
	while(I2C2_Master_Read_from_Register(LTR_Address, ALS_MEAS_RATE, 1, &Data, 1)!=I2C_OK);
	MaskedData = Data&(0x38);
	if (MaskedData==0){
		LTR_Sensor->iTime=100;
	}
	else if (MaskedData==8){
		LTR_Sensor->iTime=50;
	}
	else if (MaskedData==16){
		LTR_Sensor->iTime=200;
	}
	else if (MaskedData==24){
		LTR_Sensor->iTime=400;
	}
	else if (MaskedData==32){
		LTR_Sensor->iTime=150;
	}
	else if (MaskedData==40){
		LTR_Sensor->iTime=250;
	}
	else if (MaskedData==48){
		LTR_Sensor->iTime=300;
	}
	else if (MaskedData==56){
		LTR_Sensor->iTime=350;
	}
	LTR_Sensor->iTime=LTR_Sensor->iTime/100;
}

/*	  ALS_IntTimeSet
*	  Integration time durumu kontrol edilir ve istenilen Integration time durumu ALS_MEAS_RATE register'a yazılır
*/
int8_t ALS_IntTimeSet(LTR_sensor *LTR_Sensor, float iTime){
	uint8_t iTimeMaskedData;
	uint8_t wrtData;
	iTimeMaskedData=ALS_IntTimeRead() & (0xC7);	// okunan data ile maskeleme işlemi yapılır (0x11000111)
	if(iTime == 100 || iTime == 50 || iTime == 200 || iTime == 400 || iTime == 150 || iTime == 250 || iTime == 300 || iTime == 350)	{
			if	  (iTime == 100){								// iTime = 100ms -> 00000000
				wrtData = iTimeMaskedData | (0x00);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if(iTime == 50){								// iTime = 50ms -> 00001000
				wrtData = iTimeMaskedData | (0x08);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if(iTime == 200){								// iTime = 200ms -> 00010000
				wrtData = iTimeMaskedData | (0x10);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if(iTime == 400){								// iTime = 400ms -> 00011000
				wrtData = iTimeMaskedData | (0x18);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if(iTime == 150){								// iTime = 150ms -> 00100000
				wrtData = iTimeMaskedData | (0x20);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if(iTime == 250){								// iTime = 250ms -> 00101000
				wrtData = iTimeMaskedData | (0x28);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if(iTime == 300){								// iTime = 300ms -> 00110000
				wrtData = iTimeMaskedData | (0x30);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if(iTime == 3.50){								// iTime = 350ms -> 00111000
				wrtData = iTimeMaskedData | (0x38);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			LTR_Sensor->iTime=(float)(iTime/100);	// Lux hesaplamasında 0.5-1-1.5-2-2.5-3-3.5 değerleri kullanılacaktır.
			if (ALS_IntTimeRead() == wrtData){		// yazılan datayı tekrar oku dogru yazılmış mı kontrol et

				return IntTimeSet_OK;				// return = 1 ise Gönderme işlemi doğru bir şekilde gerçekleşmiştir
			}
			else{
				return IntTimeSet_Not_OK;			// return = 0 ise Gönderme işleminde hata oluşmuştur
			}
		}
		else {
			return IntTimeSet_IsNotCorrect;			// return = -1 ise Integration time değeri girilmesi gereken değerlerden herhangi biri değildir.
		}
}

/*	  ALS_MeasRateRead
*	  ALS_MEAS_RATE register'ından okunacak olan MeasureTime Data
*/
uint8_t ALS_MeasRateRead (void){
	uint8_t Data;
	while(I2C2_Master_Read_from_Register(LTR_Address, ALS_MEAS_RATE, 1, &Data, 1)!=I2C_OK);
	return Data;
}
/*	  ALS_MeasRateBitRead
*	  ALS_MEAS_RATE register'ından Measurement Rate Time Bitlerinin okunması
*/
void ALS_MeasRateBitRead (LTR_sensor *LTR_Sensor){
	uint8_t Data;
	uint8_t MaskedData;
	while(I2C2_Master_Read_from_Register(LTR_Address, ALS_MEAS_RATE, 1, &Data, 1)!=I2C_OK);
	MaskedData = Data&(0x07);
	if      (MaskedData==0){
		LTR_Sensor->mRate=50;
	}
	else if (MaskedData==1){
		LTR_Sensor->mRate=100;
	}
	else if (MaskedData==2){
		LTR_Sensor->mRate=200;
	}
	else if (MaskedData==3){
		LTR_Sensor->mRate=500;
	}
	else if (MaskedData==4 ){
		LTR_Sensor->mRate=1000;
	}
	else if (MaskedData==5 || MaskedData == 6 || MaskedData == 7){
		LTR_Sensor->mRate=2000;
	}
}


/*	  ALS_MeasRateSet
*	  Measurement Rate durumu kontrol edilir ve istenilen Measurement Rate durumu ALS_MEAS_RATE register'a yazılır
*/
int8_t ALS_MeasRateSet (LTR_sensor *LTR_Sensor,uint16_t mRate){
		int8_t mRateMaskedData;
		mRateMaskedData = ALS_MeasRateRead() & (0xF8);		// okunan data ile maskeleme işlemi yapılır (0x11111000)
		uint8_t wrtData;
		if(mRate == 50 || mRate == 100 || mRate == 200 || mRate == 500 || mRate == 1000 || mRate == 2000){
			if		(mRate == 50){								// mRate = 50ms -> 00000000
				wrtData = mRateMaskedData | (0x00);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if (mRate == 100){								// mRate = 100ms -> 00000001
				wrtData = mRateMaskedData | (0x01);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if (mRate == 200){								// mRate = 200ms -> 00000010
				wrtData = mRateMaskedData | (0x02);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if (mRate == 500){								// mRate = 500ms -> 00000011
				wrtData = mRateMaskedData | (0x03);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if (mRate == 1000){								// mRate = 1000ms -> 00000100
				wrtData = mRateMaskedData | (0x04);
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}
			else if (mRate == 2000 || mRate == 2000 || mRate == 2000){	// mRate = 2000ms -> 00000---101,110,111
				wrtData = mRateMaskedData | (0x05);  	// | 0x06 | 0x07 |
				while(I2C2_Master_Write_to_Register(LTR_Address, ALS_MEAS_RATE, 1, &wrtData, 1)!=I2C_OK);
			}

			LTR_Sensor->mRate = mRate;
		if (ALS_MeasRateRead() == wrtData){		// yazılan datayı tekrar oku dogru yazılmış mı kontrol et
			return MeasureTimeSet_OK;			// return = 1 ise Gönderme işlemi doğru bir şekilde gerçekleşmiştir
		}
		else{
			return MeasureTimeSet_Not_OK;		// return = 0 ise Gönderme işleminde hata oluşmuştur
		}
	}
	else {
		return MeasureTimeSet_IsNotCorrect;		// return = -1 ise Measurement Rate değeri girilmesi gereken değerlerden herhangi biri değildir.
	}
}
/*	  Part_Id
*	  Part_id okuması yapılır.
*/
void Part_Id(LTR_sensor *LTR_Sensor){			// part id = 0x0AH , revision id 0x00H	// revision identification
	uint8_t Data;
	while(I2C2_Master_Read_from_Register(LTR_Address, PART_ID, 1, &Data, 1)!=I2C_OK);
	LTR_Sensor->Part_id=Data;
}
/*	  Manufac_Id
*	  Device üretim id sini verir
*/
void Manufac_Id(LTR_sensor *LTR_Sensor){
	uint8_t Data;
	while(I2C2_Master_Read_from_Register(LTR_Address, MANUFAC_ID, 1, &Data, 1)!=I2C_OK);
	LTR_Sensor->Manuf_id=Data;
}

	// ********************************************************************************************************************************
				/*	 		  ALS_DATA_CH1 Register
				 *   ALS_DATA registeri grup olarak okunmalıdır ve küçükten büyüğe doğru okunmalıdır.
				 *   ( ilk 0x88,  daha sonra  0x89 )
	*/// ******************************************************************************************************************************
/*	  ALS_GetData
*	  CH0 ve CH1 üzerinden ALS ölçümleri yapılır
*	  NEW_Data değişkeni Datanın eski mi yeni mi olduğunu kontrol eder,
*	  Yeni Data gelinceye kadar conversion yapılmaz
*	  Data okuma sırası CH1L, CH1H, CH0L, CH0H Şeklinde olmalıdır.
*/
uint8_t ALS_GetData (LTR_sensor *LTR_Sensor){
	uint16_t CH1;	//	CH1, CH1 register'inda (ALS_DATA_CH1 0x88 ve 0x89) bulunan ALS olcum degeri
	uint16_t CH0;	//	CH0, CH0 register'inda (ALS_DATA_CH0 0x8A ve 0x8B) bulunan ALS olcum degeri
	uint16_t value1;
	uint16_t value0;
	uint8_t Data10;	//CH1L				// Data okuma sırası CH1L, CH1H, CH0L, CH0H Şeklinde olmalıdır.
	uint8_t Data11; //CH1H
	uint8_t Data00; //CH0L
	uint8_t Data01; //CH0L

	//while(LTR_Sensor->NEW_Data ==0){ 				// NEW_Data = 1 ise data yenidir , okumaya başla
	//	ALS_StatusNewOrOld(&LTR);
	//}

		while(I2C2_Master_Read_from_Register(LTR_Address, ALS_DATA_CH1_0, 1, &Data10, 1)!=I2C_OK);	// ALS measurement CH1 data, lower byte
		while(I2C2_Master_Read_from_Register(LTR_Address, ALS_DATA_CH1_1, 1, &Data11, 1)!=I2C_OK);	// ALS measurement CH1 data, upper byte
		while(I2C2_Master_Read_from_Register(LTR_Address, ALS_DATA_CH0_0, 1, &Data00, 1)!=I2C_OK);	// ALS measurement CH0 data, lower byte
		while(I2C2_Master_Read_from_Register(LTR_Address, ALS_DATA_CH0_1, 1, &Data01, 1)!=I2C_OK);	// ALS measurement CH0 data, upper byte

		value1 =(uint16_t)(Data11<<8);		//	Data10 ve Data11 in toplami ile 16 bitlik deger
		CH1 =(uint16_t)(value1|Data10);		//	CH1, CH1 register'inda (ALS_DATA_CH1 0x88 ve 0x89) bulunan ALS olcum degeri,
		value0 =(uint16_t)(Data01<<8); 		//	Data10 ve Data11 in toplami ile 16 bitlik deger
		CH0 =(uint16_t)(value0|Data00);		//	CH0, CH0 register'inda (ALS_DATA_CH0 0x8A ve 0x8B) bulunan ALS olcum degeri

		LTR_Sensor->CH1 = CH1;
		LTR_Sensor->CH0 = CH0;	// CH0 ve CH1 değerlerini kaydet, işleme geçilebilir.

	 	while (LTR_Sensor->NEW_Data==0){
			ALS_StatusNewOrOld(&LTR);
		}

		ALS_StatusDataValid(&LTR);
		if (LTR_Sensor->Data_Valid == 1){		// DataValid == 1 ise Data geçerlidir (Valid)
			return DataValid;
			//lux=LuxCalc(&LTR);
			}
		else{		// DataValid == 0 ise Data geçerli değildir (InValid)
			return DataNotValid;		// Data geçerli değil ise NEW_Data kontrolü yapılmalıdır
			}		// ALS_New Data is invalid, discard and wait for new ALS Data

}
// ********************************************************************************************************************************
			/* 		  ALS_Status Register ( Read Only )
			 *    ALS_Status register , ALS data statüsü hakkındaki bilgileri depolar.
			 *    New data , henüz bir data okumua işleminin yapılmadığı anlamına gelir.
			 *    Ölçüm yapıldıktan sonra data, data register'ına yazılır. Data statü biti Lojik 1 olur.
			 *    Data register'ından okuma yapıldığında, data statü biti Lojik 0 olur.
*///********************************************************************************************************************************

/*	  ALS_StatusDataValid
*	  CH0,CH1 kanallarından okunan Data'nın geçerli olup olmadığını kontrol eder.
*/
uint8_t ALS_StatusDataValid(LTR_sensor *LTR_Sensor){					//Data Valid(0) or InValid (1), Valid(default)
	uint8_t maskedData;
	uint8_t Data;		// ALS_MEAS_RATE register'ından okunacak olan MeasureTime Data
	while(I2C2_Master_Read_from_Register(LTR_Address, ALS_STATUS, 1, &Data, 1)!=I2C_OK);
	maskedData = Data&(0x80);						// okunan data ile maskeleme işlemi yapılır (0x10000000)
		if	(maskedData==0x00){
			LTR_Sensor->Data_Valid = 1;							// 0x00 ise Valid
		}
		else{
			LTR_Sensor->Data_Valid = 0;							// Data Not Valid
		}

		return LTR_Sensor->Data_Valid;
}

/*	  ALS_StatusNewOrOld
*	  Data yeni mi eski mi kontrol edilir, NEWData = 1 henüz okunmamıştır.
*/
void ALS_StatusNewOrOld(LTR_sensor *LTR_Sensor){
	uint8_t maskedData;
	uint8_t Data;									// NEW data ( first time data is being read )
	while(I2C2_Master_Read_from_Register(LTR_Address, ALS_STATUS, 1, &Data, 1)!=I2C_OK);
	maskedData = Data & (0x04);						// okunan data ile maskeleme işlemi yapılır (0x00000100)
		if		(maskedData == 0x00){
			LTR_Sensor->NEW_Data = 0;	// NEWData =  0 Data okunmuş, eski data konumundadır.
		}
		else if (maskedData == 0x04)
		{
			LTR_Sensor->NEW_Data = 1;	 // Data yeni mi eski mi kontrol edilir, NEW_Data =0 henüz okunmamıştır.
		}
}



/*	  LuxCalc
*	  LuxCalc fonksiyonunda integrationTime, CH0 ve CH1 den elde edilen değerler ile lux hesabı yapılır
*	  Fonksiyonun çıktısı hesaplanan (float)lux değeridir.
*	  Hesaplama formülleri Datasheet'te belirtilen Appendix A ekinde mevcuttur.
*/
float LuxCalc ( LTR_sensor *LTR_Sensor ){

	if ( (float)(LTR_Sensor->CH1 + LTR_Sensor->CH0)>=0 ) {
				LTR_Sensor->ratio = (float)(((float)LTR_Sensor->CH1)/((float)LTR_Sensor->CH0 + (float)LTR_Sensor->CH1));

			if 		((float)LTR_Sensor->ratio < 0.45){
				LTR_Sensor->lux =(float)(((1.7743 * (float)LTR_Sensor->CH0) + (float)(1.1059 * (float)LTR_Sensor->CH1))/((float)LTR_Sensor->Gain/(float)LTR_Sensor->iTime));
			}
			else if ((float)LTR_Sensor->ratio >= 0.45 && LTR_Sensor->ratio < 0.64){
				LTR_Sensor->lux = (float)(((4.2785 * (float)LTR_Sensor->CH0) - (float)(1.9548 * (float)LTR_Sensor->CH1))/((float)LTR_Sensor->Gain/(float)LTR_Sensor->iTime));
			}
			else if ((float)LTR_Sensor->ratio < 0.85 && LTR_Sensor->ratio >= 0.64){
				LTR_Sensor->lux = (float)(((0.5926 * (float)LTR_Sensor->CH0) + (float)(0.1185 * (float)LTR_Sensor->CH1))/((float)LTR_Sensor->Gain/(float)LTR_Sensor->iTime));
			}
		else
			{
			LTR_Sensor->lux = 0;
			}
		}
	   return LTR_Sensor->lux;
}





/*		//			lux calculation for device in open air WITH aperture or window above the device
float LuxCalcPFactor (LTR_sensor *LTR_Sensor){	//lux calculation with aperture or window above the device
		if ( (float)(LTR_Sensor->CH1 + LTR_Sensor->CH0) >= 0 ) {
			LTR_Sensor->ratio = (float)(LTR_Sensor->CH1 / (LTR_Sensor->CH0 + LTR_Sensor->CH1));

			if (LTR_Sensor->ratio < 0.45){
				LTR_Sensor->lux =(((1.7743 * LTR_Sensor->CH0) + (1.1059 * LTR_Sensor->CH1))/(LTR_Sensor->Gain/LTR_Sensor->iTime/LTR_Sensor->PFactor));
			}
			else if( LTR_Sensor->ratio >= 0.45 && LTR_Sensor->ratio < 0.64){
				LTR_Sensor->lux = (((4.2785 * LTR_Sensor->CH0) - (1.9548 * LTR_Sensor->CH1))/(LTR_Sensor->Gain/LTR_Sensor->iTime/LTR_Sensor->PFactor));
			}
			else if (LTR_Sensor->ratio < 0.85 && LTR_Sensor->ratio >= 0.64){
				LTR_Sensor->lux = (((0.5926 * LTR_Sensor->CH0) + (0.1185 * LTR_Sensor->CH1))/(LTR_Sensor->Gain/LTR_Sensor->iTime/LTR_Sensor->PFactor));
			}
		else
			{
			LTR_Sensor->lux = 0;
			}
		}
	   return LTR_Sensor->lux;
}

*/
/*
		//	Lux to Lumen Calculation
		//  Lumen = lux * a;				veya  		lumen = lux * 4 * pi * r * r ;
		//  a = yüzey alanı (metrekare) ,			 r = yarıçap (metre)


		//	Lux to Candela Calculation
		//	Cd = lux * d * d;
		//  d = distance from light source ( meter )

*/

