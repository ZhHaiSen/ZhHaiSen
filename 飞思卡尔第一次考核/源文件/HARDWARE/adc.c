#include "adc.h"
#include "delay.h"

extern float parameter = 0;
extern u16 value = 0;

void  GPIO_ADC_Init(void)
{ 	
		ADC_InitTypeDef ADC_InitStructure; 
		GPIO_InitTypeDef GPIO_InitStructure;
 
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_ADC1, ENABLE);	
 
		RCC_ADCCLKConfig(RCC_PCLK2_Div6);   
                         
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		
		GPIO_Init(GPIOC, &GPIO_InitStructure);	
 
		ADC_DeInit(ADC1);  
 
		ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	
		ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	
		ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	
		ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	
		ADC_InitStructure.ADC_NbrOfChannel = 1;	
		ADC_Init(ADC1, &ADC_InitStructure);	   
  
		ADC_Cmd(ADC1, ENABLE);	

		ADC_StartCalibration(ADC1);	 
 
		while(ADC_GetCalibrationStatus(ADC1));	 
}		

u16 Get_ADCValue(u8 channel)   
{
		ADC_RegularChannelConfig(ADC1, channel, 1, ADC_SampleTime_239Cycles5 );	
  
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);		
	 
		while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));
	
		return ADC_GetConversionValue(ADC1);
	
}
 
u16 Get_ADCAverage(u8 channel,u8 time)
{
		u32 temp = 0;
		u8 i;
		for(i=0;i<time;i++)
		{
				temp += Get_ADCValue(channel);
				delay_ms(5);
		}
		return temp/time;
} 	 

void ADC_Volt(void)
{
		value = Get_ADCAverage(ADC_Channel_10,10);
		parameter = (float)value*(5.0/4096);
		parameter = parameter * 4;
}

void ADC_Ampere(void)
{
		value = Get_ADCAverage(ADC_Channel_11,10);
		parameter = (float)value*(5.0/4096);
		parameter = parameter * 40;
}

void ADC_Ohm(void)
{
		value = Get_ADCAverage(ADC_Channel_12,10);
		parameter = (float)value*(5.0/4096);
		parameter = parameter * 5 / (7.5 - parameter);
}
