/*
 * I2C_Functions.c
 *
 *
 */

#include "I2C_Functions.h"

I2C_Struct I2C1_Slave;
I2C_Struct I2C2_Master;

int i2c_flag = 0;

void _I2C_Struct_Init(I2C_Struct *myI2C){
	myI2C->RegisterAddr = 0;
	myI2C->RegisterAddrSize = 0;
	myI2C->Data = 0;
	myI2C->DataSize = 0;
	myI2C->SlaveAddr = 0;
	myI2C->State = I2C_READY;
	myI2C->Lock = UNLOCKED;
}

void I2C2_Master_Register_Init(void)
{
	RCC->APBENR1 |= (1<<22);				// Enable I2C2 Peripheral Clock
	RCC->IOPENR |= (1<<0);					// Enable GPIOA Peripheral Clock
	GPIOA->MODER &= ~((3<<22) | (3<<24));	// Enable Alternate Functions for PA11 and PA12
	GPIOA->MODER |= (2<<22) | (2<<24);
	GPIOA->OTYPER |= (1<<11) | (1<<12);		// Enable Open-Drain Output for PA11 and PA12
	GPIOA->OSPEEDR |= (3<<22) | (3<<24);	// Enable Very-High Speed Output for PA11 and PA12
	GPIOA->PUPDR |= (1<<22) | (1<<24);		// Enable Pull-Up Resistors for PA11 and PA12
	GPIOA->AFR[1] &= ~((7<<12) | (7<<16));		// Enable I2C1 Alternate Function for PA11 and PA12
	GPIOA->AFR[1] |= (6<<12) | (6<<16);		// Enable I2C1 Alternate Function for PA11 and PA12
	RCC->CCIPR &= ~(3<<14);					// Set SYSCLK as I2C2 Clock
	RCC->CCIPR |= (1<<14);
	I2C2->CR1 &= ~(1<<0);					// Disable I2C2 Peripheral
	I2C2->TIMINGR = 0x10C71026;				// I2C Timing for 64 Mhz/400 kHz Fast Mode with analog filter, no digital filter
	I2C2->CR1 |= (1<<0);					// Enable I2C1 Peripheral
	_I2C_Struct_Init(&I2C2_Master);
}

void I2C1_Slave_Register_Init(void)
{
	RCC->APBENR1 |= (1<<21);				// Enable I2C1 Peripheral Clock
	RCC->IOPENR |= (1<<0);					// Enable GPIOA Peripheral Clock
	GPIOA->MODER &= ~((3<<18) | (3<<20));	// Enable Alternate Functions for PA9 and PA10
	GPIOA->MODER |= (2<<18) | (2<<20);
	GPIOA->OTYPER |= (1<<9) | (1<<10);		// Enable Open-Drain Output for PA9 and PA10
	GPIOA->OSPEEDR |= (3<<18) | (3<<20);	// Enable Very-High Speed Output for PA9 and PA10
	GPIOA->PUPDR |= (1<<18) | (1<<20);		// Enable Pull-Up Resistors for PA9 and PA10
	GPIOA->AFR[1] &= ~((7<<4) | (7<<8));		// Enable I2C1 Alternate Function for PA9 and PA10
	GPIOA->AFR[1] |= (6<<4) | (6<<8);		// Enable I2C1 Alternate Function for PA9 and PA10
	RCC->CCIPR &= ~(3<<12);					// Set SYSCLK as I2C1 Clock
	RCC->CCIPR |= (1<<12);
	I2C1->CR1 &= ~(1<<0);					// Disable I2C1 Peripheral
	I2C1->TIMINGR = 0x10C71026;//0x10F57DAC;				// I2C Timing for 64 Mhz/100 kHz Standart Mode with analog filter, no digital filter
	I2C1->CR1 |= (1<<17);					// Disable Clock Stretching
	I2C1->OAR1 &= ~(1<<10);					// 7-Bit Slave Address Mode
	I2C1->OAR1 &= ~(127<<1);				// Set 7-Bit Slave Address to 0xC0
	I2C1->OAR1 |= (48<<1);
	I2C1->OAR1 |= (1<<15);					// Enable Slave Own Address
	I2C1->CR1 |= (1<<0);					// Enable I2C1 Peripheral
	I2C1->CR1 |= (1<<3);					// Enable Address Match Interrupt
	NVIC_SetPriority(I2C1_IRQn, 0);			// Set Priority of I2C1_IRQn to 0
	NVIC_EnableIRQ(I2C1_IRQn);				// Enable I2C1_IRQn
	_I2C_Struct_Init(&I2C1_Slave);
}

I2CStatusTypeDef I2C2_Master_Write_to_Register(uint8_t SlaveAddr, uint16_t RegisterAddr, uint8_t RegisterAddrSize, uint8_t *Data, uint16_t DataSize){
	if (I2C2_Master.State == I2C_READY)
	{
		__I2C_Lock(&I2C2_Master);
		I2C2_Master.State = I2C_BUSY;
		// No reload, Number of Bytes are cleared, 7-bit addressing, Slave Address is cleared
		I2C2->CR2 &= ~((1<<24) | (255<<16) | (1<<11) | (1023<<0));
		I2C2->CR2 &= ~(1<<10); 				// Master Write
		I2C2->CR2 |= (1<<25); 				// Generate Auto Stop
		I2C2->CR2 |= ((RegisterAddrSize+DataSize)<<16);	// Number of Register Address Bytes and Data Bytes
		I2C2->CR2 |= (SlaveAddr<<1);		// Set Slave Address
		I2C2->CR2 |= (1<<13);				// Set Start Bit. Start Bit and Slave Address are Sent.
		I2C2_Master.RegisterAddr = RegisterAddr;
		I2C2_Master.RegisterAddrSize = RegisterAddrSize;
		I2C2_Master.Data = Data;
		I2C2_Master.DataSize = DataSize;
		I2C2_Master.SlaveAddr = SlaveAddr;

		while(!(I2C2->ISR & (1<<1)));
		if(I2C2_Master.RegisterAddrSize == 2){
			I2C2->TXDR = (uint8_t)((I2C2_Master.RegisterAddr& 0xFF00) >> 8);
			I2C2_Master.RegisterAddrSize--;
			while(!(I2C2->ISR & (1<<1)));
		}
		else if(I2C2_Master.RegisterAddrSize == 1){
			I2C2->TXDR = (uint8_t)(I2C2_Master.RegisterAddr & 0x00FF);
			I2C2_Master.RegisterAddrSize--;
			while(!(I2C2->ISR & (1<<1)));
		}
		while(I2C2_Master.DataSize > 1){
			I2C2->TXDR = *(I2C2_Master.Data);
			I2C2_Master.DataSize--;
			I2C2_Master.Data++;
			while(!(I2C2->ISR & (1<<1)));
		}
		I2C2->TXDR = *(I2C2_Master.Data);
		I2C2_Master.DataSize--;
		while(!(I2C2->ISR & (1<<5)));
		I2C2->ICR |= (1<<5);
		I2C2_Master.State = I2C_READY;
		__I2C_Unlock(&I2C2_Master);
		return I2C_OK;
	}
	else
	{
		return I2C_BUSY;
	}
}

I2CStatusTypeDef I2C2_Master_Read_from_Register(uint8_t SlaveAddr, uint16_t RegisterAddr, uint8_t RegisterAddrSize, uint8_t *Data, uint16_t DataSize){
	if (I2C2_Master.State == I2C_READY)
	{
		__I2C_Lock(&I2C2_Master);
		I2C2_Master.State = I2C_BUSY;
		// No reload, Number of Bytes are cleared, 7-bit addressing, Slave Address is cleared
		I2C2->CR2 &= ~((1<<24) | (255<<16) | (1<<11) | (1023<<0));
		I2C2->CR2 &= ~ (1<<10); 				// Master Write
		I2C2->CR2 &= ~(1<<25); 				// Not Generate Auto Stop
		I2C2->CR2 |= ((RegisterAddrSize)<<16);	// Number of Register Address Bytes and Data Bytes
		I2C2->CR2 |= (SlaveAddr<<1);		// Set Slave Address
		I2C2->CR2 |= (1<<13);				// Set Start Bit. Start Bit and Slave Address are Sent.
		I2C2_Master.RegisterAddr = RegisterAddr;
		I2C2_Master.RegisterAddrSize = RegisterAddrSize;
		I2C2_Master.Data = Data;
		I2C2_Master.DataSize = DataSize;
		I2C2_Master.SlaveAddr = SlaveAddr;

		while(!(I2C2->ISR & (1<<1)));
		if(I2C2_Master.RegisterAddrSize == 2){
			I2C2->TXDR = (uint8_t)((I2C2_Master.RegisterAddr& 0xFF00) >> 8);
			I2C2_Master.RegisterAddrSize--;
			while(!(I2C2->ISR & (1<<1)));
		}
		else if(I2C2_Master.RegisterAddrSize == 1){
			I2C2->TXDR = (uint8_t)(I2C2_Master.RegisterAddr & 0x00FF);
			I2C2_Master.RegisterAddrSize--;
		}
		while(!(I2C2->ISR & (1<<6)));

		I2C2->CR2 &= ~((1<<24) | (255<<16) | (1<<11) | (1023<<0));
		I2C2->CR2 |= (1<<10); 				// Master Read
		I2C2->CR2 |= (1<<25); 				// Generate Auto Stop
		I2C2->CR2 |= (DataSize<<16);	// Number of Register Address Bytes and Data Bytes
		I2C2->CR2 |= (SlaveAddr<<1);		// Set Slave Address
		I2C2->CR2 |= (1<<13);				// Set Start Bit. Start Bit and Slave Address are Sent.

		while(I2C2_Master.DataSize > 0){
			while(!(I2C2->ISR & (1<<2)));
			*(Data) = I2C2->RXDR;
			I2C2_Master.DataSize--;
			I2C2_Master.Data++;
		}
		while(!(I2C2->ISR & (1<<5)));
		I2C2->ICR |= (1<<5);
		I2C2_Master.State = I2C_READY;
		__I2C_Unlock(&I2C2_Master);
		return I2C_OK;
	}
	else
	{
		return I2C_BUSY;
	}
}

uint8_t RegisterAddr = 0;
uint8_t b;
void __attribute__ ((interrupt, used)) I2C1_IRQHandler(void)
{
	__I2C_Lock(&I2C1_Slave);
	if((I2C1->ISR) & (1<<3))				// If Address Matched
	{
		I2C1->ICR |= (1<<3);
		while(!(I2C1->ISR & (1<<2)));
		RegisterAddr = I2C1->RXDR;
		while((!(I2C1->ISR & (1<<2)))&&(!(I2C1->ISR & (1<<1))));
		if(I2C1->ISR & (1<<2)){
			if(RegisterAddr == 0x20){	// Set Backlight Level
				Received_DutyData[0] = I2C1->RXDR;
				while(!(I2C1->ISR & (1<<2)));
				Received_DutyData[1] = I2C1->RXDR;
				while(!(I2C1->ISR & (1<<5)));
				I2C1->ICR |= (1<<5);
				level_set_flag = 1;
			}
		}
		else if(I2C1->ISR & (1<<1)){
			if(RegisterAddr == 0x66){ 	// Send Ambient Brightness

				I2C1->TXDR = LTR_TransmitData[0];
				while(!(I2C1->ISR & (1<<1)));
				I2C1->TXDR = LTR_TransmitData[1];
				while(!(I2C1->ISR & (1<<5)));
				I2C1->ICR |= (1<<5);
			}
			if(RegisterAddr == 0x22){ 	// Send BL Level
				Send_Backlight_Level();

				I2C1->TXDR = BL_TransmitData[0];
				while(!(I2C1->ISR & (1<<1)));
				I2C1->TXDR = BL_TransmitData[1];
				while(!(I2C1->ISR & (1<<5)));
				I2C1->ICR |= (1<<5);
			}
		}
		I2C1->ICR |= (1<<3);
	}
	__I2C_Unlock(&I2C1_Slave);
}
