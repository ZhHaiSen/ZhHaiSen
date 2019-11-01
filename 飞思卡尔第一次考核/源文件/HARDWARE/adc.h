#ifndef __ADC_H
#define __ADC_H

#include "sys.h"

extern float parameter;
extern u16 value;

void  GPIO_ADC_Init(void);
u16 Get_ADCValue(u8 channel);
u16 Get_ADCAverage(u8 channel,u8 time);
void ADC_Volt(void);
void ADC_Ampere(void);
void ADC_Ohm(void);

#endif
