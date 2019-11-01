#include "key.h"
#include "adc.h"
#include "delay.h"

void GPIO_KEY_Init(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
	
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
		GPIO_Init(GPIOB, &GPIO_InitStructure);
} 

void EXTIX_Init(void)
{
 	  EXTI_InitTypeDef EXTI_InitStructure;
 	  NVIC_InitTypeDef NVIC_InitStructure;
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//外部中断，需要使能AFIO时钟
	
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource0);
		EXTI_InitStructure.EXTI_Line = EXTI_Line0;
		EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
		EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
		EXTI_Init(&EXTI_InitStructure);

		GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);
		EXTI_InitStructure.EXTI_Line = EXTI_Line1;
		EXTI_Init(&EXTI_InitStructure);
	
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource2);
		EXTI_InitStructure.EXTI_Line = EXTI_Line2;
		EXTI_Init(&EXTI_InitStructure);
	
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource3);
		EXTI_InitStructure.EXTI_Line = EXTI_Line3;
		EXTI_Init(&EXTI_InitStructure);
		
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource4);
		EXTI_InitStructure.EXTI_Line = EXTI_Line4;
		EXTI_Init(&EXTI_InitStructure);
		
		NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
		NVIC_Init(&NVIC_InitStructure);
	
		NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
		NVIC_Init(&NVIC_InitStructure);

		NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
		NVIC_Init(&NVIC_InitStructure);
		
		NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;
		NVIC_Init(&NVIC_InitStructure);
		
		NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x04;
		NVIC_Init(&NVIC_InitStructure);
}

void EXTI0_IRQHandler(void)
{
		
		if(KEY1 == 0)
		{
				delay_ms(10);
				if(KEY1 == 0)
				{
						ADC_Volt();
				}
		}
		EXTI_ClearITPendingBit(EXTI_Line7);
}

void EXTI1_IRQHandler(void)
{
		if(KEY2 == 0)
		{
				delay_ms(10);
				if(KEY2 == 0)
				{	
						ADC_Ampere();
				}
		}
		EXTI_ClearITPendingBit(EXTI_Line8);
}

void EXTI2_IRQHandler(void)
{
		if(KEY3 == 0)
		{
				delay_ms(10);
				if(KEY3 == 0)
				{		
						ADC_Ohm();
				}
		}
		EXTI_ClearITPendingBit(EXTI_Line9);
}

void EXTI3_IRQHandler(void)
{
		if(KEY4 == 0)
		{
				delay_ms(10);
				if(KEY4 == 0)
				{
						parameter = 0.0;
				}
		}
		EXTI_ClearITPendingBit(EXTI_Line10);
}

void EXTI4_IRQHandler(void)
{
		if(KEY5 == 0)
		{
				delay_ms(10);
				if(KEY5 == 0)
				{
						parameter = 0.0;
				}
		}
		EXTI_ClearITPendingBit(EXTI_Line11);
}
